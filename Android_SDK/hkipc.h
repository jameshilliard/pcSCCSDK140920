//�û���¼�ӿ�
//cahr *user;   �û���
//char *psw;	��¼����
//char *pHost;  ��¼��ַ���й�www.scc21.com������www.uipcam.com��
//��ע��ص�����
//"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf);nCmd; 0 �ɹ���1�������3���粻ͨ��14 ����Ͽ�. buf =NULL,len=0;

//����-1ʧ��
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_sccLogin(jstring username,jstring password,jstring host );


//jstring jsCallid 			����ID
//jbyteArray pDataBuf,	��Ƶ����
//int nSize							��Ƶ���ݳ���
//short nEnType					��������  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5��6����H264)  
//short nRes						�ֱ���  �ο�enumVGAMode����
//short nFreamType			֡���� (H264����) 2:Ϊ I֡������ΪP֡
//short nfilp						��ת����  1:���·�ת; 2:���ҷ�ת; 3:�������ҷ�ת

//�ص�������"CallbackFunForDataServer","(Ljava/lang/String;[BIIIII)V"
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_InitVideo( );

//-----------------------------------------------------------------wan-video-audio-------------------------------------------

//��ʼ����Ƶ���ݻص�
//�ص���"CallbackFunForAudioData","([BII)V"); //buf(����)  len(����)  nCid(Ԥ��)
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_InitAudio( );

/*****
	˵��������֧�ֶ�·��Ƶͬʱ�ۿ���һ·��Ƶͬʱ�� ˵.
	ʹ����Щ�ӿ�ǰ��Ӧ����ע��ö�Ӧ�����ݻص�����.�������ɹ�����һ·��Ƶ����Ƶ�����յ����λص���Ϣ
	short nMedType;		1 ��Ƶ���У�2 ��Ƶ����  ��(ipc->pc), 3 ��Ƶ���� ˵(pc->ipc)
	short nStreamType; 1��������0 ������
������Ƶ�������壺
	char Callid[40];	����id,�رյ�ʱ��Ҫʹ��
	char cDevid;  		���е��豸id���б��ȡ��cDevid����
	char *cDevType;		��������"H264","hkdvr","MPEG4"��ȡ�б��ʱ����豸����
	int iCount;			DVR�豸��ͨ���ţ���0��ʼ������DVRΪ0
	"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf); lparam=105,cBuf(devid), nCmd=1�������ӳɹ���flag=2û��Ȩ�޺��д��豸��8 �豸����,���ܺ���

	�����豸���������Ƿ�ɹ��ص�
	"CallbackFunForComData","(IIILjava/lang/String;)V");(lparam nCmd len buf); lparam=106,cBuf(devid), nCmd=1�ɹ���flag=2ʧ��

������Ƶ�������壺
	char Callid[40];			������ƵID��Ψһ��ʾ���ر���Ƶ��ʱ��Ҫ�õ���
	const char *cDevid; 	�豸id
	const char *cDevType;	Ԥ������
	int iCount;						Ԥ������
****/
//����ֵ: Callid[40]
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_sccWANCalling(jint nMedType, jint nStreamType, jstring jsDevid, jstring jsDevType, jint iCount);

//�豸��Ƶ����
#define HK_VIDEO_MPEG4 "MPEG4"
#define HK_VIDEO_H264  "H264"
#define HK_VIDEO_MJPEG "MJPEG"
#define HK_VIDEO_DVR   "hkdvr"

//ͨ���豸ID��������������Ƶ
//short nStreamType; 1��������0 ������
//jstring jsDevid;	�豸ID
//jstring jsAccCode �豸��������
//jstring jsDevType	�豸��Ƶ����
//jint iCount				ͨ����NVR��DVR ��1��ʼ����
//����ֵ: Callid[40]
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_sccWANDevidCalling(jint nStreamType, jstring jsDevid, jstring jsAccCode, jstring jsDevType, jint iCount );


//�ر�����Ƶ
//char *cDevid; �豸id
//char *cCallid;�����豸ʱ���ص�Callid
//����-1ʧ��
JNIEXPORT jint JNICALL 
Java_x1_Studio_Core_OnlineService_sccWANCloseCall( jstring jsDevid, jstring jsCallid );

//������Ƶ����
//jbyte *Data; 		��Ƶ����
//jint iLen;			���ݳ���
//jint lParam;		Ԥ������
 JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_AudioData(jbyte *Data, jint iLen, jint lParam );

//��̨����
//jstring jsDevid;	�豸ID
//jint iPtz;				����ָ�� 0//��ͣ, 1 //����, 2 //����, 3 //����, 4 //����; 5-�����Զ�ɨ��, 6-�����Զ�ɨ��, 7-ȫ�Զ�ɨ��;
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

//�豸��Ƶ����
#define HK_VIDEO_MPEG4 "MPEG4"
#define HK_VIDEO_H264  "H264"
#define HK_VIDEO_MJPEG "MJPEG"
#define HK_VIDEO_DVR   "hkdvr"

//�豸��Ƶ����
#define HK_AUDIO_G729  "G729"
#define HK_AUDIO_G726  "G726"
#define HK_AUDIO_PCM   "PCM"
#define HK_AUDIO_G711  "G711"

//��ʼ����������ע��ص�����
/***
  *  "CallbackFunForLanDate","(Ljava/lang/String;Ljava/lang/String;IIILjava/lang/String;)V"
  	����˵����(1)�豸ID,(2)�豸����(���ն���),(3)������ΨһID,(4)�豸ͨ������,(5)�豸״̬(1����,0����),(6)��Ƶ����(���ն���)
***/
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_LanInit(JNIEnv* env, jobject thiz);

//�������������豸
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_LanPresent(JNIEnv* env, jobject thiz);

//jstring jsCallid 			����ID
//jbyteArray pDataBuf,	��Ƶ����
//int nSize							��Ƶ���ݳ���
//short nEnType					��������  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5��6����H264)  
//short nRes						�ֱ���  �ο�enumVGAMode����
//short nFreamType			֡���� (H264����) 2:Ϊ I֡������ΪP֡
//short nfilp						��ת����  1:���·�ת; 2:���ҷ�ת; 3:�������ҷ�ת
//�ص�������"CallbackFunForDataServer","(Ljava/lang/String;[BIIIII)V"
JNIEXPORT jint JNICALL Java_x1_Studio_Core_OnlineService_InitVideo( );

//������������Ƶ
//jint ihkid;					������ΨһID
//jstring jsDevType 	�豸����(���ն���)
//jint iCount					�豸ͨ��
//jint nType					1��������0������
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_DoLanInvite(JNIEnv* env, jobject thiz, jint ihkid, jstring jsDevType, jint iCount, jint nType );


//��̨����
//jint ihkid;		��������ID
//jint iPtz;		����ָ�� 0//��ͣ, 1 //����, 2 //����, 3 //����, 4 //����;
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_LanSetPTZ( JNIEnv* env, jobject thiz, jint ihkid, jint iPtz, jint nChannel );