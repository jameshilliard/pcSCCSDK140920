// DDPlay.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "DDPlay.h"
#include <memory>


DDPIXELFORMAT ddpfOverlayFormats[] = 
{   
	{sizeof(DDPIXELFORMAT), DDPF_FOURCC,MAKEFOURCC('I','4','2','0'),0,0,0,0,0},  // yv420
	{sizeof(DDPIXELFORMAT), DDPF_FOURCC,MAKEFOURCC('Y','U','Y','2'),0,0,0,0,0},  // YUY2
	{sizeof(DDPIXELFORMAT), DDPF_FOURCC,MAKEFOURCC('U','Y','V','Y'),0,0,0,0,0},  // UYVY
	{sizeof(DDPIXELFORMAT), DDPF_FOURCC,MAKEFOURCC('Y','V','1','2'),0,0,0,0,0},  // yv12
};

//media_video_mode_t videoModes[] = 
//{
//	VIDEO_MODE_YUY2,
//	VIDEO_MODE_UYVY,
//};

CDDPlay::CDDPlay()
: _lpDirectDraw7(NULL)
,_lpddSurface7Primary(NULL)
,_lpddClipper(NULL)
,_lpddSurface7Overlay(NULL)
,_enable_direct(0)
,_rgb(0)
{
}

CDDPlay::~CDDPlay()
{

}


int CDDPlay::Init(HWND hwnd, 
				  unsigned int ImageWidth, 
				  unsigned int ImageHeight,
				  int VideoFormat)
{
	HRESULT res = DirectDrawCreateEx(
		NULL, (VOID**)&_lpDirectDraw7, IID_IDirectDraw7, NULL);
	if( FAILED(res))
		return -1;

	DDCAPS  capsDrv;
	ZeroMemory(&capsDrv, sizeof(capsDrv));
	capsDrv.dwSize = sizeof(capsDrv);
	res = _lpDirectDraw7->GetCaps(&capsDrv, NULL);
	if (FAILED(res))
	{
		_lpDirectDraw7->Release();
		_lpDirectDraw7 = NULL;
		return -1;
	}
	_ImageWidth = ImageWidth;
	_ImageHeight = ImageHeight;
	_hPlayWnd = hwnd;
	res = _lpDirectDraw7->SetCooperativeLevel(NULL, DDSCL_NORMAL);
	if (FAILED(res))
	{
		_lpDirectDraw7->Release();
		_lpDirectDraw7 = NULL;
		return -1;
	}

	DDSURFACEDESC2  ddsd;
	ZeroMemory(&ddsd, sizeof(DDSURFACEDESC2));
	ddsd.dwSize  = sizeof(DDSURFACEDESC2);
	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	res = _lpDirectDraw7->CreateSurface(&ddsd, &_lpddSurface7Primary, NULL );
	if (FAILED(res))
	{
		_lpDirectDraw7->Release();
		_lpDirectDraw7 = NULL;
		return -1;
	}

	res = _lpDirectDraw7->CreateClipper(0, &_lpddClipper, NULL);
	if (FAILED(res))
	{
		_lpddSurface7Primary->Release();
		_lpddSurface7Primary = NULL;
		_lpDirectDraw7->Release();
		_lpDirectDraw7 = NULL;
		return -1;
	}

	res = _lpddClipper->SetHWnd(0, hwnd);
	if (FAILED(res))
	{
		_lpddClipper->Release();
		_lpddClipper = NULL;
		_lpddSurface7Primary->Release();
		_lpddSurface7Primary = NULL;
		_lpDirectDraw7->Release();
		_lpDirectDraw7 = NULL;
		return -1;
	}

	_lpddSurface7Primary->SetClipper(_lpddClipper);

	DDSURFACEDESC2  ddsdOverlay;
	ZeroMemory(&ddsdOverlay, sizeof(DDSURFACEDESC2));
	ddsdOverlay.dwSize  = sizeof(DDSURFACEDESC2);
	ddsdOverlay.ddsCaps.dwCaps = 
		DDSCAPS_OFFSCREENPLAIN;
	ddsdOverlay.dwFlags= 
		DDSD_CAPS | DDSD_HEIGHT | 
		DDSD_WIDTH | DDSD_PIXELFORMAT;
	ddsdOverlay.dwWidth           = ImageWidth;
	ddsdOverlay.dwHeight          = ImageHeight;
	ddsdOverlay.ddpfPixelFormat = ddpfOverlayFormats[VideoFormat];
	res = _lpDirectDraw7->CreateSurface(&ddsdOverlay, &_lpddSurface7Overlay, NULL);
	if (FAILED(res))
	{
		_lpddClipper->Release();
		_lpddClipper = NULL;
		_lpddSurface7Primary->Release();
		_lpddSurface7Primary = NULL;
		_lpDirectDraw7->Release();
		_lpDirectDraw7 = NULL;
		return -1;
	}

	
	_enable_direct = 1;

	return 0;
}

int CDDPlay::Draw(char *buffer)
{
		DrawDirect(buffer);


	return 0;
}

void CDDPlay::Uninit()
{
	if (_lpddSurface7Overlay)
	{
		_lpddSurface7Overlay->Release();
		_lpddSurface7Overlay = NULL;
	}
	if (_lpddSurface7Primary)
	{
		_lpddSurface7Primary->Release();
		_lpddSurface7Primary = NULL;
	}
	if (_lpddClipper)
	{
		_lpddClipper->Release();
		_lpddClipper  = NULL;
	}
	if (_lpDirectDraw7)
	{
		_lpDirectDraw7->Release();
		_lpDirectDraw7 = NULL;
	}
	return;
}

int CDDPlay::DrawDirect(char* buffer)
{
	DDSURFACEDESC2 desc;
	HRESULT res;

	if (_lpDirectDraw7 && _lpddSurface7Primary && _lpddSurface7Overlay)
	{

		ZeroMemory(&desc, sizeof(DDSURFACEDESC2));
		desc.dwSize     = sizeof(DDSURFACEDESC2);

		res = _lpddSurface7Overlay->Lock(NULL, &desc, 
			DDLOCK_SURFACEMEMORYPTR | DDLOCK_WRITEONLY | DDLOCK_WAIT, NULL);
		if(FAILED(res)) 
		{
			return -1;
		}

		int size = desc.dwWidth*desc.dwHeight;
		char* y = buffer;
		char* v = buffer + size;
		char* u = v + size/4;

		char *descy = (char *) desc.lpSurface;
		char *descu = (char*)desc.lpSurface + desc.lPitch * desc.dwHeight;
		char *descv = (char*)descu + desc.lPitch * desc.dwHeight/4;


		for(int i = 0; i < desc.dwHeight; i++)
		{
			memcpy(descy + i*desc.lPitch,y + i*desc.dwWidth,desc.dwWidth);
		}
		for(int i =0;i<  desc.dwHeight / 2; i ++)
		{
			memcpy(descu + i*desc.lPitch /2 ,u+ i*desc.dwWidth/2,desc.dwWidth / 2);
			memcpy(descv + i*desc.lPitch /2 ,v+ i*desc.dwWidth/2,desc.dwWidth / 2);
		}


		/*for(int i = 0; i < desc.dwHeight; i++)
		{
			memcpy(descy + i*desc.lPitch,y + i*desc.dwWidth,desc.dwWidth);
		}
		for(int i =0;i<  desc.dwHeight / 2; i ++)
		{
			memcpy(descu + i*desc.lPitch /2 ,u+ i*desc.dwWidth/2,desc.dwWidth / 2);
		}
		for(int i =0;i<  desc.dwHeight / 2; i ++)
		{
			memcpy(descv + i*desc.lPitch /2 ,v+ i*desc.dwWidth/2,desc.dwWidth / 2);
		}*/

		//memcpy((char *) desc.lpSurface,
		//	buffer,
		//	desc.dwWidth*desc.dwHeight*1.5);


		_lpddSurface7Overlay->Unlock(NULL);

		RECT destRect;
		GetClientRect(_hPlayWnd,&destRect);

		POINT               pt;
		pt.x = pt.y = 0;
		ClientToScreen( _hPlayWnd, &pt );
		OffsetRect(&destRect, pt.x, pt.y);

		RECT srcRect;
		srcRect.left = 0;
		srcRect.right = _ImageWidth;
		srcRect.top = 0;
		srcRect.bottom = _ImageHeight;

		res = _lpddSurface7Primary->Blt(
			&destRect,_lpddSurface7Overlay,&srcRect, 
			DDBLT_ASYNC | DDBLT_WAIT, NULL);
	}

	return 0;
}