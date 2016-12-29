// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DDPLAY_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// DDPLAY_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。

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

// 此类是从 DDPlay.dll 导出的

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
	int _dptype;//视频格式
};
