#ifndef _HK_IPC_H_
#define _HK_IPC_H_

#define RECBUF_LEN 100

enum enumVGAMode
{
	ENUM_NONE = 0,  
	ENUM_QQ720P=1,    /*320*180*/
	ENUM_CIF=2,       /*352x288*/
	ENUM_QVGA=3,      /*320x240*/
	ENUM_Q720P=4,	  /*640*360*/
	ENUM_VGA=5,       /*640x480*/
	ENUM_D_ONE=6,     /*704x480*/
	ENUM_PAL_D1=7,    /*704x576*/
	ENUM_XVGA=8,      /*1024x768*/
	ENUM_720P = 9,    /*1280*720*/		
	ENUM_SXGA=10,     /*1280x1024*/
	ENUM_RESOLUTION_ALL,  
};

enum _CMD_SET_
{
    HK_CMD_SENSITIVITY = 101,
    HK_CMD_QUALITE = 102,
    HK_CMD_SHARPNESS=103,
    HK_CMD_BRIGHTNESS=104,
    HK_CMD_SATURATION=105,
    HK_CMD_CONTRAST = 106,
    HK_CMD_RESTPARAM = 107,
    HK_CMD_RATE = 108,
    HK_CMD_IP_INFO = 201,  //获取有线IP信息
    HK_CMD_SD_INFO = 202,  //获取SD卡配置信息
    HK_CMD_VIDEO_INFO=203, //获取视频各参数信息
    HK_CMD_WIFI_IP_INTO=204,//获取无线各信息
    HK_CMD_GET_SENS = 205,  //获取报警开关信息
    HK_CMD_GET_DEV_TYPE=206,//获取设备类型
    HK_CMD_GET_ALARM_EMAIL_INFO=207,//获取邮件报警参数
    HK_CMD_GUTT
    
};

//局域网回调下发信息列表
//(*HKLANCALLBACK)(void *userData, char *devid, char *devType, int hkid, int iCount,int iStatus,char *audioType );
//回调函数数据形式
//(void *userData, char *devid, char *devType, int hkid, int iCount,int iStatus,char *audioType );
//userData,  301, (Sid;Enc;SafeType:Sid;Enc;SafeType:...),0,0,0,NULL
#define HK_GET_WIFI_SSID "301" //局域网搜索WIFI连接点返回


//互联网回调下发信息列表
//(*HKSYSTEMCALLBACK)(void *userData, int nCmd, char *cBuf, int iLen );
typedef enum
{
    HK_REGION_SERVER=101,   //注册监控服务（userData, 101, 1(成功)/2(失败)，0）
    HK_GET_ITEM = 102,      //获取用户设备列表（userData, 102, buf, len）
    HK_ADDDEV_INFO=103,     //提交添加设备信息(userData, 103, result=%d;Count=%d;DevFlag=%s;audio=%s;devid=%s;alias=%s;, len)
    HK_DEV_OLINE=104,       //设备上线 (userData, 104, 设备ID， 0)
    HK_DEV_OFFLINE=108,     //设备下线（userData, 104, 设备ID， 0）
    HK_GET_SHARE_USER=109,  //获取设备分享用户（userData,109, 0(没有)/user=%s;popedom=%d， --Count(个数减减)）
    HK_DEL_SHARE_USER=110,  //删除分享用户（userData, 110, 0(失败)/1（成功），0）
    HK_ADD_SHARE_USER=111,  //添加分享用户（userData, 111, 0(失败)/user=%s;popedom=%d（成功），0）
    HK_UPDATE_DEV_NAME=112, //修改设备别名(userData, 112, 0(失败)/1（成功），0）
    HK_DEL_DEV = 113,       //删除列表设备(userData, 113, 0(失败)/1（成功），0）
    HK_ADD_MYDEV=114,       //添加自己设备(userData, 114, 0(失败)/1（成功），0）
    HK_UPDATE_ACCESSPWD=115,//修改访问密码(userData, 115, 0(失败)/1（成功），0）
    
    HK_INVITE_DEV_SERVER = 105, //呼叫音视频，连接服务。(userData,105,2/3/4/5/6, 0)
    HK_INVITE_DEV_VIDEO = 106,  //呼叫音视频连接数据。(userData, 106, 0(失败)/1（成功），0)
    
    
}HK_WAN_BACK_INFO;


//回调函数
typedef void (*HKSYSTEMCALLBACK)(void *userData, int nCmd, char *cBuf, int iLen );
//模块加载成功 >0
int sccInitModel( void *userData, HKSYSTEMCALLBACK FunLogin/*,HKMIEDDATACALLBACK mdCallBack*/ );

void sccUnInitModel();

//-----------------------------------------------video-----------------------------
// unsigned int nCID    通道ID号，不通视频数据不同的ID 号
//char *pDataBuf,
//int nSize         视频数据长度
//short nRes        分辨率  参考enumVGAMode定义
//short nEnType     编码类型  1:MPEG4 2:M_JPEG  4,5,6 :H264 (4,5，6都是H264)
//short nfilp       翻转类型  1 上下翻转 2 左右翻转 3 上下左右翻转
//short nFreamType  帧类型 1为 I帧，其他为P帧
//void *userData  
//typedef void (*HKMIEDDATACALLBACK)(void *userData, const char *cCallid, unsigned int nCID,char *pDataBuf, int nSize,short nRes,short nEnType,short nfilp,short nFreamType );
//初始化视频数据回调
//int hk_InitVideo(void *userData, HKMIEDDATACALLBACK mdCallBack);

//-------------------------------------------callback---video-------------------------------------------------
typedef struct SCC_MideData_v2
{
	char *pCallid;
	unsigned int nCID;
	char *pDataBuf;
	unsigned int nSize;
	short nRes;
	short nEnType;
	short nfilp;
	short nFreamType;
	short fragx;
	char *next;
}SCC_MideData;
//const char *cCallid 呼叫ID
//unsigned int nCID 	通道ID号
//char *pDataBuf,			视频数据
//int nSize						视频数据长度
//short nRes					分辨率  参考enumVGAMode定义
//short nEnType				编码类型  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5，6都是H264)
//short nfilp					翻转类型  1:上下翻转; 2:左右翻转; 3:上下左右翻转
//short nFreamType		帧类型 (H264码流) 2:为 I帧，其他为P帧
//short fragx;				预留
//void *userData
typedef void (*HKMIEDDATACALLBACK)(void *userData, SCC_MideData *pMideData );
//初始化视频数据回调
int hk_InitVideo(void *userData, HKMIEDDATACALLBACK mdCallBack);


//-------------------------------------------------audio----------------------------------------------------

//语音数据
typedef void (*HKAUDIODATACALLBACK)(void *userData, unsigned int nCID, char *pDataBuf, int nSize);
//注册语音回调接口
int hk_InitAudio(void *userData, HKAUDIODATACALLBACK audioCallBack );


//用户登录接口
//cahr *username;   用户名
//char *passwordk;  登录密码
//char *host;   		登录地址（www.scc21.com）
//回调(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );nCmd; 0 成功，1密码错误，3网络不通，13此用户未开通手机访问，14 网络断开. cBuf =NULL,iLen=0;
//返回-1失败
int sccLogin( char * username,char *password,char *host );

//用户注销
//返回-1调用失败
int sccLogOut( );

//注册监控服务
//回调(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd =101; cBuf为1注册成功，2失败
//返回-1失败
int hk_RegionMonServer( );

//获取互联网设备列表，列表数据包括设备ID，设备别名，设备状态，此设备是否是当前用户的管理设备
//int nformid; 预留。给0
//回调 102
int hk_GetItem(int nformid );


//---------------------------------------------wan-video-audio-------------------------------------------

/*****
 说明：现在支持多路视频同时观看，一路音频同时听 说.
 使用这些接口前都应该先注册好对应的数据回调函数.互联网成功连接一路视频或音频都会收到两次回调信息
 short nMedType;			1 视频呼叫，2 音频呼叫  听(ipc->pc), 3 音频呼叫 说(pc->ipc)
 short nStreamType;  	1	主码流，0 子码流
 呼叫视频参数意义：
 char Callid[40];		呼叫id,关闭的时候要使用
 char cDevid;  			呼叫的设备id，列表获取的cDevid数据
 char *cDevType;		呼叫类型"H264","hkdvr","MPEG4"获取列表的时候的设备类型
 int iCount;				DVR设备的通道号，从0开始。不是DVR为0
 (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=105, cBuf(devid=%s;flag=%d;)flag=1建立连接成功，flag=2没有权限呼叫此设备，8 设备不线,不能呼叫
 
 呼叫设备建立数据是否成功回调
 (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=106, cBuf(devid=%s;flag=%d;)flag=1成功，flag=2失败
 
 呼叫音频参数意义：
 char Callid[40];       呼叫视频ID，唯一标示，关闭音频的时候要用到。
 const char *cDevid;    设备id
 const char *cDevType;  预留参数
 int iCount;						预留参数
 ****/
//返回 成功>0
int sccWANCalling(short nMedType, short nStreamType, char Callid[40], char* cDevid, char* cDevType, int iCount);

//设备视频类型
#define HK_VIDEO_MPEG4 "MPEG4"
#define HK_VIDEO_H264  "H264"
#define HK_VIDEO_MJPEG "MJPEG"
#define HK_VIDEO_DVR   "hkdvr"

//通过设备ID与访问密码呼叫视频
//short nStreamType; 1主码流，0 子码流
int sccWANDevidCalling(short nStreamType, char Callid[40], char* cDevid, char *cAccCode, char* cDevType, int iCount );

//关闭音视频
//char *cDevid; 	设备id
//char *cCallid;	呼叫设备时返回的Callid
//返回-1失败
int sccWANCloseCall( char* cDevid, char* cCallid );

//---------------------------------------------------------------------------------

//自动提交设备上线信息
//(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=104, cBuf为设备ID，iLen为cBuf长度

//自动提交设备下线信息
//(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=108, cBuf为设备ID，iLen为cBuf长度


//返回-1失败
//接收界面音频数据
//const char *cBuf; 音频数据
//int iLen;         数据长度
//int lParam;       预留参数
int hk_AudioData( const char *cBuf, int iLen, int lParam );


//------------------------------------------------lan-------------------------------------------
//局域网数据回调函数，在整个局域网使用期有效
//const char *devid;		//设备ID
//const char *devType;	//设备类型("hkdvr","H264",“MPEG4”...)
//int hkid;							//局域网设备唯一标识，呼叫视频的时候要用到
//int iCount;						//设备节点数，如设备是hkdvr类型，就有4路8路16路等。。其它类型为0.
//int iStatus;  				//设备状态 1，2是设备上线，0下线。10网络断开
//char *audioType; 			//PCM G726 G711 G729
typedef void (*HKLANCALLBACK)(void *userData, char *devid, char *devType, int hkid, int iCount,int iStatus,char *audioType );

//初始化局域网回调函数
//为空返回 -1
int hk_InitLAN(void *userData, HKLANCALLBACK FunlanLogin/*, HKMIEDDATACALLBACK mdCallBack*/);

//更新局域网列表，一般在注册完局域网回调函数后调用下此接口来获取局域网内的设备。
//界面并做一个手动更新列表，调用此接口。
//返回-1失败
//int iType; 0 正常点击刷新，1 点home或者电源调用.
int hk_LanRefresh( int iType );

//-------------------------------------------------Lan-video--audio-------------------------------------------------------
/***
 说明：现在支持多路视频同时观看，一路音频同时听 说.
 使用这些接口前都应该先注册好对应的数据回调函数.
 short nMedType;		1 视频呼叫，2 音频呼叫  听(ipc->pc), 3 音频呼叫 说(pc->ipc)
 呼叫视频各参数意义：
 char Callid[40];		呼叫ID，唯一标示，关闭视频的时候要用到
 int ihkid;					设备唯一标示，提交局域网数据的时候得到的。
 char *cDevType;		呼叫类型 hkdvr","H264",“MPEG4”...
 int iCount;				设备是hkdvr类型,就是对应的通道数，从0开始。其它设备类型为0.
 呼叫音频各参数意义：
 char Callid[40];		呼叫视频ID，唯一标示，关闭音频的时候要用到。
 int ihkid;					设备唯一标示，提交局域网数据的时候得到的。
 char *cDevType;		预留参数
 int iCount;				预留参数
 ***/
// 返回,成功> 0
int	sccLANCalling( short nMedType, char Callid[40], int ihkid, const char *cDevType, int iCount);

//关闭局域网音视频
//返回-1失败
int sccLANCloseCall(const char *Callid );

//退出局域网
//返回-1失败
int hk_UnInitLAN();

//---------------------------------------------------------2-lan-------------------------------------

//局域网获取设备视频各参数 （获取的数据暂时保存在SO中。是接口GetLanSysInfo 203的数据）
//返回-1失败
//int nType==0; 	获取设备视频各参数
//int nType==108  获取SD卡各参数
//int nType==HK_CMD_GET_ALARM_EMAIL_INFO(207),获取报警邮箱参数
int GetLanSysDevInfo( unsigned int ihkid, const char *cDevid, int nType );

//获取设备各信息
//int nType==201; 获取固定IP信息。
/*
        返回值数据包：
            ip=%s;mask=%s;wet=%s;dns=%s;mac=%s;flag=%d;ver=%d;status=%d;
        flag==2 固定IP；flag==1 DHCP;
        ver==26X设备版本号
        status设备的登录状态，200登录成功，1密码或者用户错误，3网络不通
 */
//int nType==202;获取SD卡信息。
/*
        返回数据包: 所有值1有效，0是否
            move=%d;outmove=%d;auto=%d;loopwr=%d;splite=%d;size=%d;use=%d;leftsize=%d;audio=%d;
        move    移动报警录像
        outmove 输出报警录像
        auto    自动录像
        loopwr  循环写
        splite  分割大小
        size    SD容量
        use     已经使用大小
        leftsize剩余大小
        audio   音频
 */
//int nType==203;获取视频各参数。
/*
        返回数据包：
            stream=%d;sha=%d;bri=%d;sat=%d;con=%d;rate=%d;enc=%d
        stream  码流设置 值：5-优; 4-良; 3-好; 2-中; 1-差； 自定义（注意，当码流值大于 5 时就是自定义）
        rate    帧率  值：  1--15  //优-15； 良-12；好-10； 中-8；差-6； 自定义可用户可输入
        enc     分辨率 3-320*240；5-640*480 //优-5；良-5；好-5；中-5；差-3
        sha     锐度  值：1--63
        bri     亮度     ...
        sat     饱合度   ...
        con     对比度   ...
        sen     报警度  0-5  0关闭
 */
//int nType==204;获取无线IP信息
/**
 *    返回数据包：
 *        open=%d;ip=%s;mask=%s;wet=%s;dns=%s;mac=%s;flag=%d;sid=%s;satype=%s;keytype=%s;entype=%s;
 *      open    开启关闭无线。值：1-开始无线，0-关闭无线
 *      sid     无线SSID
 *      satype  无线安全类型
 *      keytype ascii或者hex(一般情况都是空)
 *      entype  加密方式
 **/
//int nType==207;   局域网内邮箱报警设置
/**
 * port=%d;count=%d;ioin=%d;sderror=%d;sdmove=%d;entype=%d;sedmail=%s;reemail=%s;smtpser=%s;user=%s;pwd=%s;emailinfo=%s;
 * port;    端口
 * count;   抓拍图像张数[0 3];
 * ioin;    IO报警抓拍[0 1]
 * sderror  SD卡错误[0 1]
 * sdmove   移动侦测[1 0]
 * entype   邮件发送协议 0-NO; 1-SSL; 2-TLS;
 * sedmail  发送者邮箱
 * reemail  接收都邮箱
 * smtpser  发送邮件服务器
 * user     发送者邮箱用户
 * pwd      发送者邮箱密码
 * emailinfo邮件发送信息
 **/
//返回 -1失败，其它成功获取参数
int GetLanSysInfo(char devinfo[1024],int nType, const char *devid);

//局域网有线IP设置，设置成功设备会自动重启
//返回-1失败
/*
    const char *cIPinfo; 打包数据格式：
        ip=..;netwet=..;netmask=..;dns=..;mac=..;newmac=..;
    int flag;   flag==1 DHCP; flag==2 固定IP。
 */
int SetLanDevIP(int flag, unsigned int ihkid, const char *cIPinfo );


//回调函数 wifi SID数据
typedef void (*HKWIFISIDCALLBACK)(void *userData, char *cBuf, int iLen );
int InitGetWifiSid(void *userData, HKWIFISIDCALLBACK FunWifiSid );

//局域网获取无线连接点（SSID）
//const char *cMac; 设备的MAC地址，可以通过201获取到。
//unsigned int ulParam;
//回调函数 局域网设备上线回调(共用)
//void (*HKLANCALLBACK)( char *devid, char *devType, int hkid, int iCount,int iStatus );
/**
 * char *devid;   devid=="301" 代表是获取无线连接点数据
 * char *devType; 无线连接点数据；格式：sid=%s;enc=%s;stype=%s:sid=%s;enc=%s;stype=%s:....:....:...:
 * int hkid;    没用到
 * int iCount;  没用到
 * int iStatus; 没用到
 **/
int DoLanGetWifiSid( unsigned int ihkid, const char *cMac, unsigned int ulParam );

//局域网无线IP设置，设置成功后设备会自动重启
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
        int flag；  flag==1 DHCP方式；flag==2 固定IP方式
        int isopen；isopen==1开启无线，isopen=0关闭无线
 ***/
int SetLanWifi( int flag, int isopen, unsigned int ihkid, const char *cWifi );


//返回-1失败
/***
 功能一：
    int nType=0;    局域网设置各设备视频参数
    const char *cBufInfo; 打包数据格式。
        devid=..;stream=...;sha=...;bri=...;sat=...;con=...;rate=...enc=..;
        stream  码流设置 值：5-优; 4-良; 3-好; 2-中; 1-差； 自定义（宝义五个档次让用户可以选择，如果选择自定义下面的帧率，分辨率让用户可选择）
        rate    帧率  1--15  //优-15； 良-12；好-10； 中-8；差-6； 自定义可用户可输入
        enc     分辨率 3-320*240；5-640*480 //优-5；良-5；好-5；中-5；差-3；自定义可用户选择
        sha     锐度  值：1--63
        bri     亮度     ...
        sat     饱合度   ...
        con     对比度   ...
    int nChannel; 预留参数
 
 功能二：
    int nType=107;  恢复默认参数
 功能三：   
    int nType=108
    const char *cBufInfo; 打包数据格式
    move=..;outmove=..;auto=..;loopwr=..;splite=..;audio=..;
    move    0/1 移动报警录像
    outmove 0/1 输出报警录像
    auto    0/1 自动录像
    loopwr  0/1 循环写
    splite  0/200MB 分割大小
    audio   0/1 音频
 功能四：
    int nType=201; 重新启动设备
 功能五：
    int nType=202; 恢复出厂设置
 功能六：
    int nType=106; 手动升级设备
 ***/
int SetLanSysInfo( unsigned int ihkid, int nType, const char *cBufInfo, int nChannel );


//------------------------------------互联网 新增接口---------------------------------------
//互联网获取设备视频各参数 (此接口从设备端获取的数据先存在SO端，等GetLanSysDevInfo(203)接口从本地SO获取数据)
//返回-1失败
//int nType==0;   设备视频各参数
//int nType==108  获取SD卡各参数
int GetWanSysDevInfo( const char *cDevid, int nType );

//互联网设置设备视频参数
//返回-1失败
/***
    const char *cBufInfo; 打包数据格式。
        devid=..;stream=...;sha=...;bri=...;sat=...;con=...;rate=...;enc=..;

        stream  码流设置 值：5-优; 4-良; 3-好; 2-中; 1-差； 自定义（宝义五个档次让用户可以选择，如果选择自定义下面的帧率，分辨率让用户可选择）
        rate    帧率  1--15  //优-15； 良-12；好-10； 中-8；差-6； 自定义可用户可输入
        enc     分辨率 3-320*240；5-640*480 //优-5；良-5；好-5；中-5；差-3；自定义可用户选择
        sha     锐度  值：1--63
        bri     亮度     ...
        sat     饱合度   ...
        con     对比度   ...
    int nType=0;
    int nChannel; 预留参数
 
 功能二：
 int nType=107;  恢复默认参数
 功能三：设置SD卡参数
 const char *cBufInfo; 打包数据格式
    move=..;outmove=..;auto=..;loopwr=..;splite=..;audio=..;
    move    0/1 移动报警录像
    outmove 0/1 输出报警录像
    auto    0/1 自动录像
    loopwr  0/1 循环写
    splite  0/200MB 分割大小
    audio   0/1 音频
 功能四：
    int nType=106;  升级设备程序
 ***/
int SetWanSysInfo( int nType, const char *cDevid, const char *cBufInfo, int nChannel );


//通过注册时邮箱重置用户密码。
//const char *username; 要找回密码的用户
//const char *cEmail;注册用户填写的邮箱
//const char *host; 登录连接服务器地址
int DoFindUserPasswd( const char *username,const char *cEmail, const char *host );
//--------------------------------------------------------------------------

//互联网列表添加设备
//const char *cDevid;   设备ID
//const char *cAlias;   设备别名
//const char *cAccPwd;  设备观看密码
//int lParam; 预留
//回调函数--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//nCmd=103
//cBuf数据 result=%d;Count=%d;DevFlag=%s;audio=%s;devid=%s;alias=%s;
//result = 1 成功；2 输入的设备ID不存在；0 已经存在此设备
//Count   通道个数
//DevFlag 设备对应的类型。
//audio   设备对应的音频类型
int DoWanAddDev(const char *cDevid, const char *cAlias, const char *cAccPwd, int lParam );


//删除互联网列表数据
//const char *devid;	要删除的设备ID
//回调函数--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//                                      113       cBuf ==1成功，0失败。
int DoWanDeleteDev( const char *devid, int lParam );

//修改设备别名  返回-1失败
//const char *devid; 设备id
//const char *name;  修改的别名
//unsigned int lParam; 预留
//回调函数--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//                                       112     cBuf ==1成功，0失败。
int DoWanUpdateDevName( const char *devid, const char *name, unsigned int lParam );


//注册登录用户
//hk_InitWAN(void *userData, HKSYSTEMCALLBACK FunLogin); （注意）先要注册此回调函数
//回调(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );nCmd; 0 成功，9已经存在此用户
int DoRegistrationUser( const char *username,const char *paswd,const char *jsEmail, const char *host );

//登录成功后 修改用户登录密码
//回调(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
                            //nCmd; 4 成功，5失败
int SysUpdatePasswd( const char *newPaswd );

//修改设备访问密码
//const char *cDevid; 设备id
//conat char *accPswd; 要修改的访问密码
//int iPopedom; (1：允许看，3：允许操作(指调云台，分辨率等等…)
//int lParam; 预留
int DoSetAccessPswd( const char *cDevid, const char *accPswd,int iPopedom, int lParam );


//--------------------------报警信息提交回调-------------
//回调函数
//
//int ilParm; 预留
typedef void (*HKCALLBACKALARMINFO)(void *userData,int nCmd, int iCount, char *cBuf, int ilParm );
//初始化报警信息回调
int InitAlarmInfo(void *userData, HKCALLBACKALARMINFO AlarmInfoCallBack );

//-------------------------------push info re--------------------------------------------

//get push phone Param
int hk_GetPushPhoneParam( const char *cToke );

//get push linst info
int hk_GetPushInfo( int currPage, int pageSize );

//Registration push phone
int hk_DoRegistrationPushPhone(const char* cToke,const char* cClient,int phoneType,int offline,int alarm,int ioalarm);
//---------------------------------------SD-----------------------------
// unsigned int nCID 通道ID号，不通视频数据不同的ID 号
//char *pDataBuf,
//int nSize         音频视频数据长度
//short nRes        分辨率  参考enumVGAMode定义
//short nEnType     编码类型  1:MPEG4 2:M_JPEG  4,5,6 :H264 (4,5，6都是H264); 音频类型 G729—66 G711-130 G726-258 PCM-514
//     (注意：如果是音频数据 nRes==0, nfile==0, nFreadType==0)
//short nfilp       翻转类型  1 上下翻转 2 左右翻转 3 上下左右翻转
//short nFreamType  帧类型 2为 I帧，其他为P帧
//void *userData
typedef void (*HKMIEDSDCALLBACK)(void *userData, unsigned int  nCID,char *pDataBuf, int nSize,short nRes,short nEnType,short nfilp,short nFreamType );
//初始化视频数据回调
int hk_InitSdData(void *userData, HKMIEDSDCALLBACK sdCallBack);

//回调函数
typedef void (*HKCALLBACKSDFILE)(void *userData,int nCmd, char *cBuf, int iCount );
//初始化SD File
int InitSdFile(void *userData, HKCALLBACKSDFILE SdFileCallBack );

//局域网读取设备SD卡录像文件目录
//int currentPage 当前第几页 从1开始
//int pageSize    第页多少条(一次获取多少条记录)
//返回-1失败
int DoLanReadSdData( int hkid, int currentPage, int pageSize, unsigned int ulParam );
//回调函数:
//void (*HKCALLBACKSDFILE)(void *userData,int nCmd, char *cBuf, int iCount );
//         userData   304;   buf(name=..;nid=..;size=..;)   count--(等于0没有) 

//局域网下载SD卡文件
//char Callid[40];  下载文件ID，关闭时用到 用局域视频关闭接口（hk_DoLanClose）
//char *cDowFile; 下载的文件名
//int ulParam; 预留
int DoLanDowSdData( char Callid[40], int hkid, char *cDowFile, int ulParam );


//互联网获取SD卡录像文件目录
//int currentPage 当前第几页 从1开始
//int pageSize    第页多少条(一次获取多少条记录)
//返回-1失败
//回调函数:
//void (*HKCALLBACKSDFILE)(void *userData,int nCmd, char *cBuf, int iCount );
//         userData   304;   buf(name=..;nid=..;size=..;)   count--(等于0没有)
int DoMonSDReadData( const char *devid, int currentPage, int pageSize, unsigned int lParam );


//char Callid[40];  下载文件ID，关闭时用到 用互联网视频关闭接口（hk_DoMonCloseDialog）
//char *devid;   设备id
//char *cDowFile;要下载文件名称
//int ulParam; 预留
//返回-1失败
int DoMonDowSdData( char Callid[40],char *devid, char *cDowFile,  int ulParam );

//delete sd file
//iDel==0 delete one; iDel==1 delete all;
//lan
int DoLocalMonDeletePhoto( int hkid, int iDel, char *cFileName );

//wan
int DoMonDeletePhoto( char *cDevid, int iDel, char *cFileName );

//参数设置指定集
//int nOpt参数值定义
enum scc_param
{
	SCC_PTZ_UP=1,           //云台上
	SCC_PTZ_DOWN=2,         //云台下
	SCC_PTZ_LEFT=3,         //云台向左
	SCC_PTZ_RIGHT=4,        //云台向右
	SCC_FOCAL_NEAR=5,       //焦聚拉近
	SCC_FOCAL_FAR =6,       //焦聚拉远
	SCC_PTZ_STOP = 7,       //停止云台,FU,转动
	SCC_APERTURE_NEAR=8,	//光圈拉近
	SCC_APERTURE_FAR=9,     //光圈拉远
	SCC_PTZ_CRUISE = 60,	//巡航(int nType值: 1:云台水平巡航, 2:云台垂直巡航, 3:云台全方位巡航)
	SCC_DEV_BRIGHTNESS=50,	//亮度设置( [1 63] )
	SCC_DEV_COLOR =	51,     //色彩	  ( [1 63] )
	SCC_DEV_CONTRAST=52,	//对比度  ( [1 63] )
	SCC_DEV_SATURATION=53,	//饱各度  ( [1 63] )
	SCC_DEV_STREAM = 54,	//码流    ( [16 4096] )
	SCC_DEV_QUALITY = 55,	//设置视频质量(1:好 2:中 3:差)
	SCC_DEV_RESOLUTION=56,	//修改分辨率(值参考 enumVGAMode)
	SCC_DEV_FRAMERATE =57,	//修改帧率	([1 30])
	SCC_DEV_SENSITIVITY=59,	//修改报警敏感度([0 10])
	SCC_UPSIDE_DOWN = 61,	//上下翻转
	SCC_HORIZONTALLY = 62,	//水平翻转
	SCC_GET_PRESET = 63,	//移动到某个预置位 [1 8]
	SCC_SET_PRESET = 64,	//设置某个预置位   [1 8]
	SCC_SET_SPEED = 65,     //设置云台速度 [1(慢) 10(愉)]
	SCC_DEV_EXPOSING=66,	//爆光度   ( [1 63] )
	SCC_DEV_SHARPNESS=67,	//锐度	   ( [1 63] )
	SCC_DEV_FREQUENCY=70,	//频率     [50(PAL) 60(NTSC)]
	SCC_DEV_CBR_VBR = 106,	//设置	   [0(CBR) 1(VBR)]
	SCC_DEFAULT_PARAM =107,	//恢复默认视频参数
	SCC_FACTORY_SET = 109,	//恢复出厂设置
	SCC_DEV_REBOOT = 110,	//重启设备
    
	//邮箱报警设置
	/**
	 * const char *cBuf;
	 * port=%d;count=%d;ioin=%d;sderror=%d;sdmove=%d;sedemail=%s;reemail=%s;smtpser=%s;user=%s;pwd=%s;emailinfo=%s;flag=;entype=%d;
	 * port;    端口
	 * count;   抓拍图像张数[0 3];
	 * ioin;    IO报警抓拍[0 1]
	 * sderror  SD卡错误[0 1]
	 * sdmove   移动侦测[1 0]
	 * sedmail  发送者邮箱
	 * reemail  接收都邮箱
	 * smtpser  发送邮件服务器
	 * user     发送者邮箱用户
	 * pwd      发送者邮箱密码
	 * emailinfo邮件发送信息
	 * flag     1发送测试邮件，0不发送
	 * entype   邮件发送协议 0-NO; 1-SSL; 2-TLS;
	 **/
	SCC_DEV_EMAIL_ALARM = 200,	//设置邮箱报警
	/**
	 * const char *cBuf;
	 * port=%d;ftpserver=%s;ftpuser=%s;ftppswd=%s;codetype=%s;
	 **/
	SCC_DEV_FTP       = 201,	//设置FTP
	SCC_DEV_AUDIO_ALARM=202,	//声音报警开关 0关闭; 1 低, 2 中, 3高,
	SCC_DEV_THERMAL_ALARM=203,	//热感应报警开关 0关闭; 1 开启
};

//参数设置
int sccSetLANInfo( char *pDev, unsigned int nHKid,unsigned int nOpt,char *cBuf, int nValues,int nChannel);
int sccSetWANInfo( char *pDev,unsigned int nOpt, char *cBuf, int nValues,int nChannel);

int sccGetLANInfo( char *pDev, unsigned int nHKid,unsigned int nOpt,int nType,int nChannel);
int sccGetWANInfo( char *pDev,unsigned int nOpt,int nType,int nChannel);


#endif//_HK_IPC_H_

/*
Two kinds of ways to get the video data:
One:
1.sccInitModel
2.sccLogin
3.hk_RegionMonServer
4.hk_GetItem
5.hk_InitVideo
6.sccWANCalling

Two:  By accessing password access                   
1.sccInitM
2.sccLogin
5.hk_InitVideo
6.sccWANCalling
*/