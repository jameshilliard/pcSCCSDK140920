//用户登录接口
//cahr *user;   用户名
//char *psw;	登录密码
//char *pHost;  登录地址（中国www.scc21.com，国外www.uipcam.com）
//并注册回调函数
//"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf);nCmd; 0 成功，1密码错误，3网络不通，14 网络断开. buf =NULL,len=0;

//返回-1失败
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_sccLogin(jstring username,jstring password,jstring host );


//jstring jsCallid 			呼叫ID
//jbyteArray pDataBuf,	视频数据
//int nSize							视频数据长度
//short nEnType					编码类型  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5，6都是H264)  
//short nRes						分辨率  参考enumVGAMode定义
//short nFreamType			帧类型 (H264码流) 2:为 I帧，其他为P帧
//short nfilp						翻转类型  1:上下翻转; 2:左右翻转; 3:上下左右翻转

//回调函数："CallbackFunForDataServer","(Ljava/lang/String;[BIIIII)V"
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_InitVideo( );

//-----------------------------------------------------------------wan-video-audio-------------------------------------------

//初始化音频数据回调
//回调："CallbackFunForAudioData","([BII)V"); //buf(数据)  len(长度)  nCid(预留)
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_InitAudio( );

/*****
	说明：现在支持多路视频同时观看，一路音频同时听 说.
	使用这些接口前都应该先注册好对应的数据回调函数.互联网成功连接一路视频或音频都会收到两次回调信息
	short nMedType;		1 视频呼叫，2 音频呼叫  听(ipc->pc), 3 音频呼叫 说(pc->ipc)
	short nStreamType; 1主码流，0 子码流
呼叫视频参数意义：
	char Callid[40];	呼叫id,关闭的时候要使用
	char cDevid;  		呼叫的设备id，列表获取的cDevid数据
	char *cDevType;		呼叫类型"H264","hkdvr","MPEG4"获取列表的时候的设备类型
	int iCount;			DVR设备的通道号，从0开始。不是DVR为0
	"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf); lparam=105,cBuf(devid), nCmd=1建立连接成功，flag=2没有权限呼叫此设备，8 设备不线,不能呼叫

	呼叫设备建立数据是否成功回调
	"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf); lparam=106,cBuf(devid), nCmd=1成功，flag=2失败

呼叫音频参数意义：
	char Callid[40];			呼叫视频ID，唯一标示，关闭音频的时候要用到。
	const char *cDevid; 	设备id
	const char *cDevType;	预留参数
	int iCount;						预留参数
****/
//返回值: Callid[40]
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_sccWANCalling(jint nMedType, jint nStreamType, jstring jsDevid, jstring jsDevType, jint iCount);

//设备视频类型
#define HK_VIDEO_MPEG4 "MPEG4"
#define HK_VIDEO_H264  "H264"
#define HK_VIDEO_MJPEG "MJPEG"
#define HK_VIDEO_DVR   "hkdvr"

//通过设备ID与访问密码呼叫视频
//short nStreamType; 1主码流，0 子码流
//jstring jsDevid;	设备ID
//jstring jsAccCode 设备访问密码
//jstring jsDevType	设备视频类型
//jint iCount				通道号NVR，DVR 从1开始计算
//返回值: Callid[40]
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_sccWANDevidCalling(jint nStreamType, jstring jsDevid, jstring jsAccCode, jstring jsDevType, jint iCount );


//关闭音视频
//char *cDevid; 设备id
//char *cCallid;呼叫设备时返回的Callid
//返回-1失败
JNIEXPORT jint JNICALL 
Java_x1_Studio_Core_OnlineService_sccWANCloseCall( jstring jsDevid, jstring jsCallid );

//接收音频数据
//jbyte *Data; 		音频数据
//jint iLen;			数据长度
//jint lParam;		预留参数
 JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_AudioData(jbyte *Data, jint iLen, jint lParam );

//云台控制
//jstring jsDevid;	设备ID
//jint iPtz;				控制指定 0//暂停, 1 //向左, 2 //向右, 3 //向上, 4 //向下; 5-左右自动扫描, 6-上下自动扫描, 7-全自动扫描;
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_SetPTZ( JNIEnv* env, jobject thiz, jstring jsDevid, jint iPtz, jint nChannel );

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


//云台控制
//jint ihkid;		局域网内ID
//jint iPtz;		控制指定 0//暂停, 1 //向左, 2 //向右, 3 //向上, 4 //向下;
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_LanSetPTZ( JNIEnv* env, jobject thiz, jint ihkid, jint iPtz, jint nChannel );