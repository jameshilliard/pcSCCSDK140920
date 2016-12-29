#pragma once
#ifdef WIN32
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <config.h>

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"

#include <libavformat/avformat.h>
#include <libavutil/dict.h>
}

typedef void (*PRC_av_register_all)(void);
typedef void (*PRC_avcodec_init)(void);
typedef void (*PRC_avcodec_register_all)(void);

typedef int (*PRC_avcodec_close)(AVCodecContext *avctx);
typedef void (*PRC_av_free)(void *ptr);

typedef AVCodec* (*PRC_avcodec_find_decoder)(enum CodecID id);

typedef AVCodecContext * (*PRC_avcodec_alloc_context)(void);

typedef AVFrame *(*PRC_avcodec_alloc_frame)(void);
typedef int (*PRC_avcodec_open)(AVCodecContext *avctx, AVCodec *codec);
typedef int (*PRC_avcodec_decode_video2)(AVCodecContext *avctx, AVFrame *picture,
										 int *got_picture_ptr,
										 AVPacket *avpkt);
typedef void (*PRC_av_init_packet)(AVPacket *pkt);

typedef void (*PRC_sws_freeContext)(struct SwsContext *swsContext);
typedef int (*PRC_avpicture_get_size)(enum PixelFormat pix_fmt, int width, int height);

typedef void *(*PRC_av_malloc)(size_t size) av_malloc_attrib av_alloc_size(1);

typedef struct SwsContext *(*PRC_sws_getContext)(int srcW, int srcH, enum PixelFormat srcFormat,
												 int dstW, int dstH, enum PixelFormat dstFormat,
												 int flags, SwsFilter *srcFilter,
												 SwsFilter *dstFilter, const double *param);

typedef int (*PRC_avpicture_fill)(AVPicture *picture, uint8_t *ptr,
								  enum PixelFormat pix_fmt, int width, int height);

typedef int (*PRC_sws_scale)(struct SwsContext *context, const uint8_t* const srcSlice[], const int srcStride[],
							 int srcSliceY, int srcSliceH, uint8_t* const dst[], const int dstStride[]);


class FF_SWSScale;
//#include "codec_define.h"
class AFX_EXT_CLASS HK264AndMJDec
{
public:
	HK264AndMJDec(int codecid);
	virtual ~HK264AndMJDec();
	int open_dec();
	int close_dec();
	int decode( int type,BYTE* inbuf,int len,BYTE **outbuf,int &nWidth, int &nHeight );
	int width_, height_;
private:
	int decodeMJ( int type,BYTE* inbuf,int len,BYTE **outbuf,int &nWidth, int &nHeight );
	int decodeH264( int type,BYTE* inbuf,int len,BYTE **outbuf,int &nWidth, int &nHeight );
protected:
	//int reconfig(int srctyppe,int srcwidth,int srcheight, int dsttype,int dstwidth,int dstheight,int overthrow = 0);
	//int execute(char *srcdata,int srclen,char *dstdata,int &dstlen);
	//int execute(FrameData1 *src,char *dstdata,int &dstlen);

	//// extra function
	//int src_data_ptr(char *&data,int &len);
	//int dst_data_ptr(char *&data,int &len);
	//void* src_picture_ptr( );
	//void* dst_picture_ptr( );
	//int fill_src_picture(char *y,char *u,char *v,int width,int height);
	//int fill_dst_picture(char *y,char *u,char *v,int width,int height);
private:
	int codecid_;
	AVCodec *codec_;
	AVCodecContext *codec_ctx_;
	AVFrame *picture_;
	bool  m_bFristDec;
	
// add by liuk
	int src_width_;
	int src_height_;
	int dst_width_;
	int dst_height_;

	int src_resolution_changed_; //如果分辨率发生改变，需要重新配置
	int dst_resolution_changed_; //如果分辨率发生改变，需要重新配置

	int overthrow_;
	int src_size_;
	int dst_size_;
	int srctype_;
	int dsttype_;
	int srcfftype_;
	int dstfftype_;
	uint8_t *src_picture_buf_ ;
	uint8_t *dst_picture_buf_;
	AVFrame *src_picture_ ;
	AVFrame *dst_picture_ ;
	struct SwsContext *img_convert_ctx_ ;
	FF_SWSScale *m_swsale;
	BYTE *m_pBackRgbBuf;
	
};

#endif