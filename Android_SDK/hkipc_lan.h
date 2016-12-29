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


//�ر���Ƶ��Ƶ
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_DoLanClose(JNIEnv* env, jobject thiz, jstring jsSid );


//-----------audio------------
//��ʼ������Ƶ�ص�����
//�ص����� 
//"CallbackFunForAudioData","([BII)V"
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_InitAudio( JNIEnv* env, jobject thiz );

//��Ƶ����ipc->pc
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_DoLanAudioInvite(JNIEnv* env, jobject thiz, jint ihkid, jstring jsDevType,jint iType, jint iCount );


//�豸���� 
//ָ�204 ����, 205 ������206 ������ 207 ���ԣ� 208 ��ȡ����ɹ�ʧ��, 209 ��ȡ�豸433״̬
//jint nType; 	110
//jstring jsBufInfo;	ָ��
//jint nChannel;	��ֵ
//208 ��ȡ����ɹ�ʧ��,�߾������ص�; 307 0������ȡ,-1����ʧ��,����0 ��ֵ�ɹ�.
//209 ��ȡ�豸433״̬, �߾������ص�; 308 0�豸û����433��1 ����״̬��2 ����״̬
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_SetLanSysInfo(JNIEnv* env, jobject thiz, jint ihkid, jint nType, jstring jsBufInfo, jint nChannel );


//----------------------------------------------sa--------------------------------------------------
void CallbackFunForLanDate( char *devid, char *cDevType, int nID, int nChn, int iStatus, char *cTyepAudio )
{
		//����һֱ���о������豸��Ϣ�ύ.
}

void CallbackFunForDataServer( char *cCallid, char *cData, int nSize, int nEntype, int nRes, int nFreamType, int nFilp )
{
		//������Ƶ�ɹ���һֱ�����ݳ���.
}


int main()
{
		LanInit();	//��ʼ������������.��׿�˲�ע��һ���ص�����
		LanPresent();	//�����������豸.
		
		InitVideo();	//��ʼ����Ƶ���ݻص�.
		
		DoLanInvite( nID, cDevType, nChn, 1 );	//������Ƶ������ӿڵĲ���������CallbackFunForLanDate �����ύ���������ݡ�
		while(1)
		{
			sleep 3;
		}
		return 0;	
}

//int iFlag=50,Brightness
//int iFlag=51,color
//52(R/W)      �Աȶ�
//53(R/W)      ���Ͷ�
//67(R/W)      ���
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_DoMonSetLevel(JNIEnv* env, jobject thiz, jint iFlag, jstring jsDevid, jint level, jint nChannel)


//int iFlag=50,Brightness
//int iFlag=51,color
//52(R/W)      �Աȶ�
//53(R/W)      ���Ͷ�
//67(R/W)      ���
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_DoLanMonSetLevel(JNIEnv* env, jobject thiz, jint iFlag, jstring jsDevid,jint hkid, jint level, jint nChannel);

//set wifiIP
//����-1ʧ��
/***
     const char *cWifi; ������ݸ�ʽ��
      entype=..;sid=..;satype=..;option=..;keytype=..;pswd=..;mac=..;ip=..;netmsk=..;netwet=..;dns=..;
        entype  ���ܷ�ʽ AES/TKIP/û��Ϊ��
        satype  ���߰�ȫ����
        option  open����share����wepģʽ����Ч������Ϊ��
        keytype ascii����hex
        pswd    ��������/û��Ϊ��
        mac     �豸mac��ַ
     int flag��  flag==1 DHCP��ʽ;  flag==2 �̶�IP��ʽ
     int isopen��isopen==1��������; isopen=0�ر�����
 ***/
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_SetLanWifi(JNIEnv* env, jobject thiz, jint flag,jint isopen, jint hkid, jstring jsWifi );



//��ȡ�豸��Ϣ
//jint nType; 204  ��ȡ�豸WIFI��Ϣ("open=%d;ip=%s;mask=%s;wet=%s;dns=%s;mac=%s;flag=%d;sid=%s;satype=%s;keytype=%s;entype=%s;")
JNIEXPORT jstring JNICALL
Java_x1_Studio_Core_OnlineService_GetLanSysInfo(JNIEnv* env, jobject thiz, jint nType, jstring jsDevid );

//�������˳�
JNIEXPORT jint JNICALL
Java_x1_Studio_Core_OnlineService_QuitLan(JNIEnv* env, jobject thiz )
