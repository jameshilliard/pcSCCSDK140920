package x1.Studio.Core;

import android.util.Log;

public class OnlineService {
	public static String loglog="VIDEO";
	
	public String HK_VIDEO_MPEG4 = "MPEG4";
	public String HK_VIDEO_H264 = "H264";
	public String HK_VIDEO_MJPEG = "MJPEG";
	public String HK_VIDEO_DVR = "hkdvr";
		 
	
	public String devusername = "E320955";
	public String devpsw = "3176";
	
	static{
		//调用顺序如下，否则会出错
		System.loadLibrary("chinalink");
		System.loadLibrary("system");
		System.loadLibrary("captetown");
	}
	
	//用户登录接口
	//cahr *user;   用户名
	//char *psw;	登录密码
	//char *pHost;  登录地址（中国www.scc21.com，国外www.uipcam.com）
	//并注册回调函数
	//"CallbackFunForComData","(IIILjava/lang/String;)V");
	//(lparam nCmd len buf);nCmd; 0 成功，1密码错误，3网络不通，14 网络断开. buf =NULL,len=0;
	//返回-1失败
	public native int sccLogin(String username,String password,String host );
	public  void CallbackFunForComData(int lparam,int ncmd,int len,String buf){
		Log.v(loglog, "CallbackFunForComData来啦");
		Log.v(loglog, "call cmd:"+ncmd);
		switch(ncmd){
		case 0:
			Log.v(loglog, "success");
			
			int initv_re = InitVideo();
			Log.v(OnlineService.loglog,"initv_re:"+initv_re);
			
	
			String get = sccWANDevidCalling(1,devusername,devpsw,HK_VIDEO_H264,0);
			Log.v(OnlineService.loglog, "c click get:"+get);
			break;
		case 1:
			Log.v(loglog, "密码错误");
			break;
		case 3:
			Log.v(loglog, "网络不通");
			break;
		case 14:
			Log.v(loglog, "网络断开");
			break;
		}
	}
	
	//jstring jsCallid 			呼叫ID
	//jbyteArray pDataBuf,	视频数据
	//int nSize							视频数据长度
	//short nEnType					编码类型  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5，6都是H264)  
	//short nRes						分辨率  参考enumVGAMode定义
	//short nFreamType			帧类型 (H264码流) 2:为 I帧，其他为P帧
	//short nfilp						翻转类型  1:上下翻转; 2:左右翻转; 3:上下左右翻转
	//回调函数："CallbackFunForDataServer","(Ljava/lang/String;[BIIIII)V"
	//此方法是用来注册回调函数
	public native int InitVideo( );
	public  void CallbackFunForDataServer(String jscallid,byte[] pdatabuf,
			int nsize,int ntype,int nres,int nfreamtype,int nflip){
		
		Log.v(loglog, "视频数据来了，ID是："+jscallid);
	}
	
	//呼叫视频
	//short nMedType;		1 视频呼叫，2 音频呼叫  听(ipc->pc), 3 音频呼叫 说(pc->ipc)
	//short nStreamType; 1主码流，0 子码流
	//char cDevid;  		呼叫的设备id，列表获取的cDevid数据
	//char *cDevType;		呼叫类型"H264","hkdvr","MPEG4"获取列表的时候的设备类型
	//int iCount;			DVR设备的通道号，从0开始。不是DVR为0
	//返回char Callid[40];	呼叫id,关闭的时候要使用
	//回调函数,此回调函数在登录时己注册
	//" ","(IIILjava/lang/String;)V");(lparam nCmd len buf);
	//lparam=105,cBuf(devid), nCmd=1建立连接成功，flag=2没有权限呼叫此设备，8 设备不线,不能呼叫
	public native String sccWANCalling(int nMedType, int nStreamType, String jsDevid,
			String jsDevType, int iCount);
//	public void CallbackFunForComData(int lparam, int ncmd , int len,String buf){
//		
//	}
	
	
	//通过设备ID与访问密码呼叫视频
	//short nStreamType; 1主码流，0 子码流
	//jstring jsDevid;	设备ID
	//jstring jsAccCode 设备访问密码
	//jstring jsDevType	设备视频类型
	//jint iCount				通道号NVR，DVR 从1开始计算
	//返回值: Callid[40]  呼叫id,关闭的时候要使用
	//呼叫设备建立数据是否成功回调
	//"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf);
	//lparam=106,cBuf(devid), nCmd=1成功，flag=2失败
	public native String sccWANDevidCalling(int nStreamType, String jsDevid, String jsAccCode,
			String jsDevType, int iCount );
	
	
	//关闭音视频
	//char *cDevid; 设备id
	//char *cCallid;呼叫设备时返回的Callid
	//返回-1失败
	//JNIEXPORT jint JNICALL 
	//Java_x1_Studio_Core_OnlineService_sccWANCloseCall( jstring jsDevid, jstring jsCallid );
	public native int sccWANCloseCall(String jsdevid,String jscallid);
	
	
	//以下为音频
	//初始化音频数据回调
	//回调："CallbackFunForAudioData","([BII)V"); //buf(数据)  len(长度)  nCid(预留)
	//JNIEXPORT jint JNICALL
	//Java_x1_Studio_Core_OnlineService_InitAudio( );
	public native int InitAudio();
	public  void CallbackFunForAudioData(byte[] buf,int len, int ncid){
		Log.v(loglog, "音频数据来了");
	}
	
	
	
	
	//接收音频数据
	//jbyte *Data; 		音频数据
	//jint iLen;			数据长度
	//jint lParam;		预留参数
	 //JNIEXPORT jint JNICALL
	//Java_x1_Studio_Core_OnlineService_AudioData(jbyte *Data, jint iLen, jint lParam );
	public native int AudioData(byte[] data, int ilen, int lparam);
	
}
