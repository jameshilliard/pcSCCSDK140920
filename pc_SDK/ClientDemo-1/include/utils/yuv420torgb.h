#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push) //保存对齐状态 
#pragma pack(2)//设定为4字节对齐 

typedef struct _bitmapinfoheader{
 int biSize;
 int biWidth;
 int biHeight;
 short biPlanes;
 short biBitCount;
 int biCompression;
 int biSizeImage;
 int biXPelsPerMeter;
 int biYPelsPerMeter;
 int biClrUsed;
 int biClrImportant;
} bitmapinfoheader;

typedef struct _bitmapfileheader {
 short bfType;
 int bfSize;
 short bfReserved1;
 short bfReserved2;
 int bfOffBits;
} bitmapfileheader;

#pragma pack(pop)//恢复对齐状态

// init the arrays for convertion

AFX_EXT_CLASS void yuv2rgb_init();
// doing the convert
AFX_EXT_CLASS int yuv2rgb_convert(unsigned char *src0,unsigned char *src1,
  unsigned char *src2, unsigned char *dst_ori, int width, int height);
// write to a file
AFX_EXT_CLASS int yuv2rgb_create_bmp_header(unsigned char *header, int xsize, int ysize);
AFX_EXT_CLASS void safe_packed_conv(unsigned char * x_ptr, int x_stride,
				 unsigned char * y_ptr, unsigned char * u_ptr, unsigned char * v_ptr,
				 int y_stride, int uv_stride,
				 int width, int height, int vflip
				 );

#ifdef __cplusplus
}
#endif

