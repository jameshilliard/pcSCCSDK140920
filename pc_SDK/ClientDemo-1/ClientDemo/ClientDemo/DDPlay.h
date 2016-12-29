// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DDPLAY_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DDPLAY_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

#pragma  once

#ifdef DDPLAY_EXPORTS
#define DDPLAY_API __declspec(dllexport)
#else
#define DDPLAY_API __declspec(dllimport)
#endif

#include <ddraw.h>

enum
{
	dptype_i420,
	dptype_yuv2,
	dptype_uyvu,
	dptype_yv12,
};

//typedef struct tagczoomscale
//{
//	POINT potNew1;
//	POINT potNew2;
//	POINT potOld1;
//	POINT potOld2;
//}CZOOMSCALE, *PCZOOMSCALE;

// �����Ǵ� DDPlay.dll ������

#define  USE_YUV 0
#define  USE_RGB 1
class DDPLAY_API CDDPlay 
{
public:
	CDDPlay(void);
	~CDDPlay();

public:
	int Init(HWND hwnd, unsigned int ImageWidth, unsigned int ImageHeight,int VideoFormat = dptype_i420);
	int Draw(char *buffer);

	void Uninit();

protected:
	int DrawBmp(char* buffer);
	int DrawDirect(char* buffer);


	int _enable_direct;
	BITMAPINFO _bitmap_info;
	long _format_convert;
	char* _rgb;

private:
	LPDIRECTDRAW7        _lpDirectDraw7;
	LPDIRECTDRAWSURFACE7 _lpddSurface7Primary;
	LPDIRECTDRAWCLIPPER  _lpddClipper;
	LPDIRECTDRAWSURFACE7 _lpddSurface7Overlay;
	HWND _hPlayWnd;
	unsigned int _ImageWidth;
	unsigned int _ImageHeight;
	int _dptype;//��Ƶ��ʽ
};
