//-------------------------------lan-----------------------------------------------
enum enumVGAMode
{
	ENUM_NONE = 0,  
	ENUM_QQ720P=1,    /*320*180*/
	ENUM_CIF=2,       /*352x288*/
	ENUM_QVGA=3,      /*320x240*/
	ENUM_Q720P=4,		/*640*360*/
	ENUM_VGA=5,       /*640x480*/
	ENUM_D_ONE=6,     /*704x480*/
	ENUM_PAL_D1=7,    /*704x576*/
	ENUM_XVGA=8,      /*1024x768*/
	ENUM_720P = 9,    /*1280*720*/		
	ENUM_RESOLUTION_ALL,  
};

//设备视频类型
#define HK_VIDEO_MPEG4 "MPEG4"
#define HK_VIDEO_H264  "H264"
#define HK_VIDEO_MJPEG "MJPEG"
#define HK_VIDEO_DVR   "hkdvr"

//设备音频类型
#define HK_AUDIO_G729  "G729"
#define HK_AUDIO_G726  "G726"
#define HK_AUDIO_PCM   "PCM"
#define HK_AUDIO_G711  "G711"

//初始化局域网并注册回调函数
/***
  *  "CallbackFunForLanDate","(Ljava/lang/String;Ljava/lang/String;IIILjava/lang/String;)V"
  	参数说明：(1)设备ID,(2)设备类型(参照定义),(3)局域网唯一ID,(4)设备通道个数,(5)设备状态(1上线,0下线),(6)音频类型(参照定义)
***/
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_LanInit(JNIEnv* env, jobject thiz);

//搜索局域网内设备
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_LanPresent(JNIEnv* env, jobject thiz);

//jstring jsCallid 			呼叫ID
//jbyteArray pDataBuf,	视频数据
//int nSize							视频数据长度
//short nEnType					编码类型  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5，6都是H264)  
//short nRes						分辨率  参考enumVGAMode定义
//short nFreamType			帧类型 (H264码流) 2:为 I帧，其他为P帧
//short nfilp						翻转类型  1:上下翻转; 2:左右翻转; 3:上下左右翻转
//回调函数："CallbackFunForDataServer","(Ljava/lang/String;[BIIIII)V"
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_InitVideo( );

//局域网呼叫视频
//jint ihkid;					局域网唯一ID
//jstring jsDevType 	设备类型(参照定义)
//jint iCount					设备通道
//jint nType					1主码流，0子码流
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_DoLanInvite(JNIEnv* env, jobject thiz, jint ihkid, jstring jsDevType, jint iCount, jint nType );


//关闭视频音频
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_DoLanClose(JNIEnv* env, jobject thiz, jstring jsSid );


//-----------audio------------
//初始化听音频回调函数
//回调函数 
//"CallbackFunForAudioData","([BII)V"
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_InitAudio( JNIEnv* env, jobject thiz );

//音频听，ipc->pc
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_DoLanAudioInvite(JNIEnv* env, jobject thiz, jint ihkid, jstring jsDevType,jint iType, jint iCount );


//设备对码 
//指令：204 对码, 205 布防，206 撒防， 207 测试， 208 获取对码成功失败, 209 获取设备433状态
//jint nType; 	110
//jstring jsBufInfo;	指令
//jint nChannel;	码值
//208 获取对码成功失败,走局域网回调; 307 0继续获取,-1对码失败,大于0 码值成功.
//209 获取设备433状态, 走局域网回调; 308 0设备没连接433，1 撒防状态，2 布防状态
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_SetLanSysInfo(JNIEnv* env, jobject thiz, jint ihkid, jint nType, jstring jsBufInfo, jint nChannel );


//----------------------------------------------sa--------------------------------------------------
void CallbackFunForLanDate( char *devid, char *cDevType, int nID, int nChn, int iStatus, char *cTyepAudio )
{
		//这里一直会有局域网设备信息提交.
}

void CallbackFunForDataServer( char *cCallid, char *cData, int nSize, int nEntype, int nRes, int nFreamType, int nFilp )
{
		//呼叫视频成功，一直有数据出来.
}


int main()
{
		LanInit();	//初始化局域网功能.安卓端并注册一个回调函数
		LanPresent();	//搜索局域网设备.
		
		InitVideo();	//初始化视频数据回调.
		
		DoLanInvite( nID, cDevType, nChn, 1 );	//呼叫视频，这个接口的参数必须是CallbackFunForLanDate 函数提交上来的数据。
		while(1)
		{
			sleep 3;
		}
		return 0;	
}

//int iFlag=50,Brightness
//int iFlag=51,color
//52(R/W)      对比度
//53(R/W)      饱和度
//67(R/W)      锐度
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_DoMonSetLevel(JNIEnv* env, jobject thiz, jint iFlag, jstring jsDevid, jint level, jint nChannel)


//int iFlag=50,Brightness
//int iFlag=51,color
//52(R/W)      对比度
//53(R/W)      饱和度
//67(R/W)      锐度
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_DoLanMonSetLevel(JNIEnv* env, jobject thiz, jint iFlag, jstring jsDevid,jint hkid, jint level, jint nChannel);

//set wifiIP
//返回-1失败
/***
     const char *cWifi; 打包数据格式。
      entype=..;sid=..;satype=..;option=..;keytype=..;pswd=..;mac=..;ip=..;netmsk=..;netwet=..;dns=..;
        entype  加密方式 AES/TKIP/没有为空
        satype  无线安全类型
        option  open或者share，在wep模式下有效，其它为空
        keytype ascii或者hex
        pswd    无线密码/没有为空
        mac     设备mac地址
     int flag；  flag==1 DHCP方式;  flag==2 固定IP方式
     int isopen；isopen==1开启无线; isopen=0关闭无线
 ***/
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_SetLanWifi(JNIEnv* env, jobject thiz, jint flag,jint isopen, jint hkid, jstring jsWifi );



//获取设备信息
//jint nType; 204  获取设备WIFI信息("open=%d;ip=%s;mask=%s;wet=%s;dns=%s;mac=%s;flag=%d;sid=%s;satype=%s;keytype=%s;entype=%s;")
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_GetLanSysInfo(JNIEnv* env, jobject thiz, jint nType, jstring jsDevid );

//局域网退出
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_QuitLan(JNIEnv* env, jobject thiz )
