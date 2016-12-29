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
		//����˳�����£���������
		System.loadLibrary("chinalink");
		System.loadLibrary("system");
		System.loadLibrary("captetown");
	}
	
	//�û���¼�ӿ�
	//cahr *user;   �û���
	//char *psw;	��¼����
	//char *pHost;  ��¼��ַ���й�www.scc21.com������www.uipcam.com��
	//��ע��ص�����
	//"CallbackFunForComData","(IIILjava/lang/String;)V");
	//(lparam nCmd len buf);nCmd; 0 �ɹ���1�������3���粻ͨ��14 ����Ͽ�. buf =NULL,len=0;
	//����-1ʧ��
	public native int sccLogin(String username,String password,String host );
	public  void CallbackFunForComData(int lparam,int ncmd,int len,String buf){
		Log.v(loglog, "CallbackFunForComData����");
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
			Log.v(loglog, "�������");
			break;
		case 3:
			Log.v(loglog, "���粻ͨ");
			break;
		case 14:
			Log.v(loglog, "����Ͽ�");
			break;
		}
	}
	
	//jstring jsCallid 			����ID
	//jbyteArray pDataBuf,	��Ƶ����
	//int nSize							��Ƶ���ݳ���
	//short nEnType					��������  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5��6����H264)  
	//short nRes						�ֱ���  �ο�enumVGAMode����
	//short nFreamType			֡���� (H264����) 2:Ϊ I֡������ΪP֡
	//short nfilp						��ת����  1:���·�ת; 2:���ҷ�ת; 3:�������ҷ�ת
	//�ص�������"CallbackFunForDataServer","(Ljava/lang/String;[BIIIII)V"
	//�˷���������ע��ص�����
	public native int InitVideo( );
	public  void CallbackFunForDataServer(String jscallid,byte[] pdatabuf,
			int nsize,int ntype,int nres,int nfreamtype,int nflip){
		
		Log.v(loglog, "��Ƶ�������ˣ�ID�ǣ�"+jscallid);
	}
	
	//������Ƶ
	//short nMedType;		1 ��Ƶ���У�2 ��Ƶ����  ��(ipc->pc), 3 ��Ƶ���� ˵(pc->ipc)
	//short nStreamType; 1��������0 ������
	//char cDevid;  		���е��豸id���б��ȡ��cDevid����
	//char *cDevType;		��������"H264","hkdvr","MPEG4"��ȡ�б��ʱ����豸����
	//int iCount;			DVR�豸��ͨ���ţ���0��ʼ������DVRΪ0
	//����char Callid[40];	����id,�رյ�ʱ��Ҫʹ��
	//�ص�����,�˻ص������ڵ�¼ʱ��ע��
	//" ","(IIILjava/lang/String;)V");(lparam nCmd len buf);
	//lparam=105,cBuf(devid), nCmd=1�������ӳɹ���flag=2û��Ȩ�޺��д��豸��8 �豸����,���ܺ���
	public native String sccWANCalling(int nMedType, int nStreamType, String jsDevid,
			String jsDevType, int iCount);
//	public void CallbackFunForComData(int lparam, int ncmd , int len,String buf){
//		
//	}
	
	
	//ͨ���豸ID��������������Ƶ
	//short nStreamType; 1��������0 ������
	//jstring jsDevid;	�豸ID
	//jstring jsAccCode �豸��������
	//jstring jsDevType	�豸��Ƶ����
	//jint iCount				ͨ����NVR��DVR ��1��ʼ����
	//����ֵ: Callid[40]  ����id,�رյ�ʱ��Ҫʹ��
	//�����豸���������Ƿ�ɹ��ص�
	//"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf);
	//lparam=106,cBuf(devid), nCmd=1�ɹ���flag=2ʧ��
	public native String sccWANDevidCalling(int nStreamType, String jsDevid, String jsAccCode,
			String jsDevType, int iCount );
	
	
	//�ر�����Ƶ
	//char *cDevid; �豸id
	//char *cCallid;�����豸ʱ���ص�Callid
	//����-1ʧ��
	//JNIEXPORT jint JNICALL 
	//Java_x1_Studio_Core_OnlineService_sccWANCloseCall( jstring jsDevid, jstring jsCallid );
	public native int sccWANCloseCall(String jsdevid,String jscallid);
	
	
	//����Ϊ��Ƶ
	//��ʼ����Ƶ���ݻص�
	//�ص���"CallbackFunForAudioData","([BII)V"); //buf(����)  len(����)  nCid(Ԥ��)
	//JNIEXPORT jint JNICALL
	//Java_x1_Studio_Core_OnlineService_InitAudio( );
	public native int InitAudio();
	public  void CallbackFunForAudioData(byte[] buf,int len, int ncid){
		Log.v(loglog, "��Ƶ��������");
	}
	
	
	
	
	//������Ƶ����
	//jbyte *Data; 		��Ƶ����
	//jint iLen;			���ݳ���
	//jint lParam;		Ԥ������
	 //JNIEXPORT jint JNICALL
	//Java_x1_Studio_Core_OnlineService_AudioData(jbyte *Data, jint iLen, jint lParam );
	public native int AudioData(byte[] data, int ilen, int lparam);
	
}
