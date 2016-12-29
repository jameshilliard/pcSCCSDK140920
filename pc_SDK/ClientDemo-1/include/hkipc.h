#ifndef _HK_IPC_H_
#define _HK_IPC_H_

#define RECBUF_LEN 100

//extern "C"
//{

#include "utils/HKCmdPacket.h"
#include "utils/HKMonCmdDefine.h"
#include "utils/HKCmdDefine.h"

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
    HK_CMD_IP_INFO = 201,	//��ȡ����IP��Ϣ
    HK_CMD_SD_INFO = 202,	//��ȡSD��������Ϣ
    HK_CMD_VIDEO_INFO=203,	//��ȡ��Ƶ��������Ϣ
    HK_CMD_WIFI_IP_INTO=204,//��ȡ���߸���Ϣ
    HK_CMD_GET_SENS = 205,  //��ȡ����������Ϣ
    HK_CMD_GET_DEV_TYPE=206,//��ȡ�豸����
    HK_CMD_GET_AREA_INFO=207,//��ȡ���򱨾���Ϣ
    HK_CMD_GUTT
    
};

#define HK_GET_WIFI_SSID "301" //����������WIFI���ӵ㷵��

//�������ص��·���Ϣ�б�
//(*HKSYSTEMCALLBACK)(void *userData, int nCmd, char *cBuf, int iLen );
typedef enum
{
    HK_REGION_SERVER=101,		//ע���ط���userData, 101, 1(�ɹ�)/2(ʧ��)��0��
    HK_GET_ITEM = 102,			//��ȡ�û��豸�б�userData, 102, buf, len��
    HK_ADDDEV_INFO=103,			//�ύ����豸��Ϣ(userData, 103, result=%d;Count=%d;DevFlag=%s;audio=%s;devid=%s;alias=%s;, len)
    HK_DEV_OLINE=104,			//�豸���� (userData, 104, �豸ID�� 0)
    HK_DEV_OFFLINE=108,			//�豸���ߣ�userData, 104, �豸ID�� 0��
    HK_GET_SHARE_USER=109,		//��ȡ�豸�����û���userData,109, 0(û��)/user=%s;popedom=%d�� --Count(��������)��
    HK_DEL_SHARE_USER=110,		//ɾ�������û���userData, 110, 0(ʧ��)/1���ɹ�����0��
    HK_ADD_SHARE_USER=111,		//��ӷ����û���userData, 111, 0(ʧ��)/user=%s;popedom=%d���ɹ�����0��
    HK_UPDATE_DEV_NAME=112,		//�޸��豸����(userData, 112, 0(ʧ��)/1���ɹ�����0��
    HK_DEL_DEV = 113,			//ɾ���б��豸(userData, 113, 0(ʧ��)/1���ɹ�����0��
    HK_ADD_MYDEV=114,			//����Լ��豸(userData, 114, 0(ʧ��)/1���ɹ�����0��
    HK_UPDATE_ACCESSPWD=115,	//�޸ķ�������(userData, 115, 0(ʧ��)/1���ɹ�����0��
    HK_UPDATE_MANAGEMENT_PWD=116,//�޸Ĺ�������(userData, 116, 0(ʧ��)/1���ɹ�����0)
    
    HK_INVITE_DEV_SERVER = 105, //��������Ƶ�����ӷ���(userData,105,2/3/4/5/6, 0)
    HK_INVITE_DEV_VIDEO = 106,  //��������Ƶ�������ݡ�(userData, 106, 0(ʧ��)/1���ɹ�����0)
    
    
}HK_WAN_BACK_INFO;

extern "C"
{

//�ص�����
typedef void (*HKSYSTEMCALLBACK)(void *userData, int nCmd, char *cBuf, int iLen );
//ģ����سɹ� >0
EXPORTDECL_API int sccInitModel( void *userData, HKSYSTEMCALLBACK FunLogin/*,HKMIEDDATACALLBACK mdCallBack*/ );

EXPORTDECL_API void sccUnInitModel();


//�û���¼�ӿ�
//cahr *user;   �û���
//char *psw;	��¼����
//char *pHost;  ��¼��ַ���й�www.scc21.com������www.uipcam.com��
//�ص�(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );nCmd; 0 �ɹ���1�������3���粻ͨ��14 ����Ͽ�. cBuf =NULL,iLen=0;
//����-1ʧ��
EXPORTDECL_API int sccLogin( char *user,char *psw,char *pHost );

//������½/ע��
EXPORTDECL_API int sccLogOut();

//-------------------------------------------------------callback-----video-------------------------------------------------
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
//const char *cCallid ����ID
// unsigned int nCID ͨ��ID��
//char *pDataBuf,	��Ƶ����
//int nSize			��Ƶ���ݳ���
//short nRes		�ֱ���  �ο�enumVGAMode����
//short nEnType		��������  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5��6����H264)  
//short nfilp		��ת����  1:���·�ת; 2:���ҷ�ת; 3:�������ҷ�ת
//short nFreamType	֡���� (H264����) 2:Ϊ I֡������ΪP֡
//short fragx;		�����ݷְ����(3,2,1)��������.
//void *userData  
typedef void (*HKMIEDDATACALLBACK)(void *userData, SCC_MideData *pMideData );
//��ʼ����Ƶ���ݻص�
EXPORTDECL_API int hk_InitVideo(void *userData, HKMIEDDATACALLBACK mdCallBack);


//--------------------------------------------callback-------audio----------------------------------------------------

//��������
typedef void (*HKAUDIODATACALLBACK)(void *userData, unsigned int nCID, char *pDataBuf, int nSize);
//ע�������ص��ӿ�
EXPORTDECL_API int hk_InitAudio(void *userData, HKAUDIODATACALLBACK audioCallBack );

//ע���ط���
//�ص�(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd =101; cBufΪ1ע��ɹ���2ʧ��
//����-1ʧ��
EXPORTDECL_API int hk_RegionMonServer( );

//��ȡ�������豸�б��б����ݰ����豸ID���豸�������豸״̬�����豸�Ƿ��ǵ�ǰ�û��Ĺ����豸
//int nformid; Ԥ������0
//�ص� 102
EXPORTDECL_API int hk_GetItem(int nformid );


//�Զ��ύ�豸������Ϣ
//(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=104, cBufΪ�豸ID��iLenΪcBuf����

//�Զ��ύ�豸������Ϣ
//(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=108, cBufΪ�豸ID��iLenΪcBuf����

//����-1ʧ��
//������Ƶ����
//const char *cBuf; ��Ƶ����
//int iLen;			���ݳ���
//int lParam;		Ԥ������
EXPORTDECL_API int hk_AudioData( const char *cBuf, int iLen, int lParam );


//-----------------------------------------------------------------wan-video-audio-------------------------------------------

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
	(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=105, cBuf(devid=%s;flag=%d;)flag=1�������ӳɹ���flag=2û��Ȩ�޺��д��豸��8 �豸����,���ܺ���

	�����豸���������Ƿ�ɹ��ص�
	(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen ); nCmd=106, cBuf(devid=%s;flag=%d;)flag=1�ɹ���flag=2ʧ��

������Ƶ�������壺
	char Callid[40];	������ƵID��Ψһ��ʾ���ر���Ƶ��ʱ��Ҫ�õ���
	const char *cDevid; �豸id
	const char *cDevType;Ԥ������
	int iCount;			Ԥ������
****/
//���� �ɹ�>0
EXPORTDECL_API int sccWANCalling(short nMedType, short nStreamType, char Callid[40], char* cDevid, char* cDevType, int iCount);

//�豸��Ƶ����
#define HK_VIDEO_MPEG4 "MPEG4"
#define HK_VIDEO_H264  "H264"
#define HK_VIDEO_MJPEG "MJPEG"
#define HK_VIDEO_DVR   "hkdvr"

//ͨ���豸ID��������������Ƶ
//short nStreamType; 1��������0 ������
EXPORTDECL_API int sccWANDevidCalling(short nStreamType, char Callid[40], char* cDevid, char *cAccCode, char* cDevType, int iCount );

//�ر�����Ƶ
//char *cDevid; �豸id
//char *cCallid;�����豸ʱ���ص�Callid
//����-1ʧ��
EXPORTDECL_API int sccWANCloseCall( char* cDevid, char* cCallid );


//------------------------------------------------------------------lan------------------------------------------------
//���������ݻص�������������������ʹ������Ч
//const char *devid;	//�豸ID
//const char *devType;	//�豸����("hkdvr","H264",��MPEG4��...)
//int hkid;				//�������豸Ψһ��ʶ��������Ƶ��ʱ��Ҫ�õ�
//int iCount;			//�豸�ڵ��������豸��hkdvr���ͣ�����4·8·16·�ȡ���������Ϊ0.
//int iStatus;			//�豸״̬ 1��2���豸���ߣ�0���ߡ�10����Ͽ�
//char *audioType;		//PCM G726 G711 G729
typedef void (*HKLANCALLBACK)(void *userData, char *devid, char *devType, int hkid, int iCount,int iStatus,char *audioType );

//��ʼ���������ص�����
//Ϊ�շ��� -1
EXPORTDECL_API int hk_InitLAN(void *userData, HKLANCALLBACK FunlanLogin/*, HKMIEDDATACALLBACK mdCallBack*/);

//���¾������б�һ����ע����������ص�����������´˽ӿ�����ȡ�������ڵ��豸��
//���沢��һ���ֶ������б����ô˽ӿڡ�
//����-1ʧ��
EXPORTDECL_API int hk_LanRefresh();

//-------------------------------------------------Lan-video--audio-------------------------------------------------------
/***
	˵��������֧�ֶ�·��Ƶͬʱ�ۿ���һ·��Ƶͬʱ�� ˵.
	ʹ����Щ�ӿ�ǰ��Ӧ����ע��ö�Ӧ�����ݻص�����.
	short nMedType;		1 ��Ƶ���У�2 ��Ƶ����  ��(ipc->pc), 3 ��Ƶ���� ˵(pc->ipc)
������Ƶ���������壺
	char Callid[40];	����ID��Ψһ��ʾ���ر���Ƶ��ʱ��Ҫ�õ�
	int ihkid;			�豸Ψһ��ʾ���ύ���������ݵ�ʱ��õ��ġ�
	char *cDevType;		�������� hkdvr","H264",��MPEG4��...
	int iCount;			�豸��hkdvr����,���Ƕ�Ӧ��ͨ��������0��ʼ�������豸����Ϊ0.
������Ƶ���������壺
	char Callid[40];	������ƵID��Ψһ��ʾ���ر���Ƶ��ʱ��Ҫ�õ���
	int ihkid;			�豸Ψһ��ʾ���ύ���������ݵ�ʱ��õ��ġ�
	char *cDevType;		Ԥ������
	int iCount;			Ԥ������
***/
// ����,�ɹ�> 0
EXPORTDECL_API int	sccLANCalling( short nMedType, char Callid[40], int ihkid, const char *cDevType, int iCount); 

//�رվ���������Ƶ
//����-1ʧ��
EXPORTDECL_API int sccLANCloseCall(const char *Callid );

//�˳�������
//����-1ʧ��
EXPORTDECL_API int hk_UnInitLAN();


//---------------------------------------------------------2-lan-------------------------------------

//��ȡ�豸����Ϣ
//int nType==201; ��ȡ�̶�IP��Ϣ��
/***
        ����ֵ���ݰ���
            ip=%s;mask=%s;wet=%s;dns=%s;mac=%s;flag=%d;ver=%d;status=%d;
        flag==2 �̶�IP��flag==1 DHCP;
        ver==26X�豸�汾��
        status�豸�ĵ�¼״̬��200��¼�ɹ���1��������û�����3���粻ͨ
 ***/
//int nType==202;��ȡSD����Ϣ��
/***
        �������ݰ�: ����ֵ1��Ч��0�Ƿ�
            move=%d;outmove=%d;auto=%d;loopwr=%d;splite=%d;size=%d;use=%d;leftsize=%d;audio=%d;stream=%d;
        move    �ƶ�����¼��
        outmove �������¼��
        auto    �Զ�¼��
        loopwr  ѭ��д
        splite  �ָ��С
        size    SD����
        use     �Ѿ�ʹ�ô�С
        leftsizeʣ���С
        audio   ��Ƶ
	stream  0 ������ 1������
 ***/
//int nType==203;��ȡ��Ƶ��������
/***
        �������ݰ���
stream=%d;sha=%d;bri=%d;sat=%d;con=%d;rate=%d;enc=%d;sens=%d;iropen=%d;frequency=%d;speed=%d;hue=%d;exposure=%d;
		stream  �������� [16 2048]
        rate    ֡��  [1 30]
        enc     �ֱ��� 3��5; 9
        sha     ���  ֵ��1--63
        bri     ����     ...
        sat     ���϶�   ...
        con     �Աȶ�   ...
        sens    ������  0-10  0�ر�
		iropen  ir����1�أ�0��
		frequency 50,60,70
		speed   ��̨�ٶ�
		hue     ɫ��[1 63]
		exposure �����[1 63]
 ***/
//int nType==204;��ȡ����IP��Ϣ
/**
 *       �������ݰ���
 *           open=%d;ip=%s;mask=%s;wet=%s;dns=%s;mac=%s;flag=%d;sid=%s;satype=%s;keytype=%s;entype=%s;
 *       open    �����ر����ߡ�ֵ��1-��ʼ���ߣ�0-�ر�����
 *       sid     ����SSID
 *       satype  ���߰�ȫ����
 *       keytype ascii����hex(һ��������ǿ�)
 *       entype  ���ܷ�ʽ
 **/
//int nType==207
//HK_CMD_GET_AREA_INFO
/**
 *	�������ݰ�:
 *      count=%d;sens=%d;pointX0=45;pointY0=3546;pointX1=45;pointY1=3546;pointX2=45;pointY2=3546;
**/
//���� -1ʧ�ܣ������ɹ���ȡ����
EXPORTDECL_API int GetLanSysInfo(char devinfo[1024],int nType, const char *devid);

//����������IP���ã����óɹ��豸���Զ�����
//����-1ʧ��
/*
	const char *cIPinfo; ������ݸ�ʽ��
        ip=..;netwet=..;netmask=..;dns=..;mac=..;newmac=..;
        int flag;   flag==1 DHCP; flag==2 �̶�IP��
 */
EXPORTDECL_API int SetLanDevIP(int flag, unsigned int ihkid, const char *cIPinfo );


//�ص����� wifi SID����
typedef void (*HKWIFISIDCALLBACK)(void *userData, char *cBuf, int iLen );
EXPORTDECL_API int InitGetWifiSid(void *userData, HKWIFISIDCALLBACK FunWifiSid );

//��������ȡ�������ӵ㣨SSID��
//const char *cMac; �豸��MAC��ַ������ͨ��201��ȡ����
//unsigned int ulParam;

//�ص����� �������豸���߻ص�(����)
//void (*HKLANCALLBACK)( char *devid, char *devType, int hkid, int iCount,int iStatus );
/*
	char *devid;   devid=="301" �����ǻ�ȡ�������ӵ�����
	char *devType; �������ӵ����ݣ���ʽ��sid=%s;enc=%s;stype=%s:sid=%s;enc=%s;stype=%s:....:....:...:
	int hkid;  û�õ�
	int iCount; û�õ�
	int iStatus;û�õ�
*/
EXPORTDECL_API int DoLanGetWifiSid( unsigned int ihkid, const char *cMac, unsigned int ulParam );


//����������IP���ã����óɹ����豸���Զ�����
//����-1ʧ��
/*
        const char *cWifi; ������ݸ�ʽ��
        entype=..;sid=..;satype=..;option=..;keytype=..;pswd=..;mac=..;ip=..;netmsk=..;netwet=..;dns=..;
            entype  ���ܷ�ʽ AES/TKIP/û��Ϊ��
            satype  ���߰�ȫ����
            option  open����share����wepģʽ����Ч������Ϊ��
            keytype ascii����hex
            pswd    ��������/û��Ϊ��
            mac     �豸mac��ַ
        int flag��  flag==1 DHCP��ʽ��flag==2 �̶�IP��ʽ
        int isopen��isopen==1�������ߣ�isopen=0�ر�����
 */
EXPORTDECL_API int SetLanWifi( int flag, int isopen, unsigned int ihkid, const char *cWifi );

//--------------------------------------------------------------------------

//�������б�����豸
//const char *cDevid;   �豸ID
//const char *cAlias;   �豸����
//const char *cAccPwd;  �豸�ۿ�����
//int lParam; Ԥ��
//�ص�����--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//nCmd=103
//cBuf���� result=%d;Count=%d;DevFlag=%s;audio=%s;devid=%s;alias=%s;
//result = 1 �ɹ���2 ������豸ID�����ڣ�0 �Ѿ����ڴ��豸
//Count   ͨ������
//DevFlag �豸��Ӧ�����͡�
//audio   �豸��Ӧ����Ƶ����
EXPORTDECL_API int DoWanAddDev(const char *cDevid, const char *cAlias, const char *cAccPwd, int lParam );

//��������ӹ����豸()
//����-1ʧ��.	(HK_MON_ADDDEV)
//const cahr *devinfo;
    //devid;	�豸ID
    //pwd;		��������
    //alias;	�豸����
    //accpwd;	��������
    //popedom;��֤��ʽ����Ӧ��Ȩ��.(1��������3���������(ָ����̨���ֱ��ʵȵ�?)
    //devid=...;pwd=..;alias=...;accpwd=...;popedom=..;
//int lParam;Ԥ��

//�ص�����--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//��ӹ����豸�ɹ�ʧ��                     114       cBuf ==1�ɹ���0ʧ�ܡ�

//��˵���������豸�뻥�����б��Ƿֿ���ӣ�
//�û��б��д��豸�� �ղ���ϵͳ�·���103
//�û��б�û�д��豸��ϵͳ�·� 103��Ϣ���ύ�豸��Ϣ��
EXPORTDECL_API int DoWanAddMyDev( const char *cDevidInfo, int lParam );


//ɾ���������б�����
//const char *devid;	Ҫɾ�����豸ID
//�ص�����--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//                                      113       cBuf ==1�ɹ���0ʧ�ܡ�
EXPORTDECL_API int DoWanDeleteDev( const char *devid, int lParam );

//�޸��豸����  ����-1ʧ��
//const char *devid; �豸id
//const char *name;  �޸ĵı���
//unsigned int lParam; Ԥ��
//�ص�����--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//                                       112     cBuf ==1�ɹ���0ʧ�ܡ�
EXPORTDECL_API int DoWanUpdateDevName( const char *devid, const char *name, unsigned int lParam );


//ע���¼�û�
//hk_InitWAN(void *userData, HKSYSTEMCALLBACK FunLogin); ��ע�⣩��Ҫע��˻ص�����
//�ص�(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );nCmd; 0 �ɹ���9�Ѿ����ڴ��û�
EXPORTDECL_API int DoRegistrationUser( const char *username,const char *paswd,const char *jsEmail, const char *host );

//��¼�ɹ��� �޸��û���¼����
//�ص�(*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
                            //nCmd; 4 �ɹ���5ʧ��
EXPORTDECL_API int SysUpdatePasswd( const char *newPaswd );

//�޸��豸��������
//const char *cDevid; �豸id
//conat char *accPswd; Ҫ�޸ĵķ�������
//int iPopedom; (1��������3���������(ָ����̨���ֱ��ʵȵȡ�)
//int lParam; Ԥ��
EXPORTDECL_API int DoSetAccessPswd( const char *cDevid, const char *accPswd,int iPopedom, int lParam );

//�޸��豸��������
//����˵����cDevid=�豸ID��newpasswd=�����룻lParam=Ԥ��
//����-1 ʧ��
//�ص�����--void (*HKSYSTEMCALLBACK)(int nCmd, char *cBuf, int iLen );
//                                       112     cBuf ==1�ɹ���0ʧ�ܡ�
EXPORTDECL_API int DoMonUpdatePasswd( const char *cDevid, const char *newpasswd, unsigned int lParam );


//-----------------------------------------------callback SD DATA-----------------------------
// unsigned int nCID		ͨ��ID��
//char *pDataBuf, int nSize ��Ƶ��Ƶ���ݳ���
//short nRes				�ֱ���  �ο�enumVGAMode����
//short nEnType				��������  1:MPEG4 2:M_JPEG  4,5,6 :H264 (4,5��6����H264); ��Ƶ���� G729��66 G711-130 G726-258 PCM-514
//     (ע�⣺�������Ƶ���� nRes==0, nfile==0, nFreadType==0)
//short nfilp				��ת����  1 ���·�ת 2 ���ҷ�ת 3 �������ҷ�ת
//short nFreamType			֡���� 1Ϊ I֡������ΪP֡
//void *userData  
typedef void (*HKMIEDSDCALLBACK)(void *userData, unsigned int  nCID,char *pDataBuf, int nSize,short nRes,short nEnType,short nfilp,short nFreamType );
//��ʼ����Ƶ���ݻص�
EXPORTDECL_API int hk_InitSdData(void *userData, HKMIEDSDCALLBACK sdCallBack);

//-------------------------------------------------------������Ϣ�ύ�ص�--------------------------------------
//�ص�����
//int iFlag; ==0/�ƶ���ⱨ����==1 IO����
//int ilParm; Ԥ��
typedef void (*HKCALLBACKALARMINFO)(void *userData,int nCmd, char *cDevid, int iFlag, int ilParm );
//��ʼ��������Ϣ�ص�
EXPORTDECL_API int InitAlarmInfo(void *userData, HKCALLBACKALARMINFO AlarmInfoCallBack );

//--------------------------------------------------------------SD--------------------------------------------
//�ص�����
typedef void (*HKCALLBACKSDFILE)(void *userData,int nCmd, char *cBuf, int iCount );
//��ʼ��SD File
EXPORTDECL_API int InitSdFile(void *userData, HKCALLBACKSDFILE SdFileCallBack );

//��������ȡ�豸SD��¼���ļ�Ŀ¼
//int currentPage ��ǰ�ڼ�ҳ ��1��ʼ
//int pageSize    ��ҳ������(һ�λ�ȡ��������¼)
//����-1ʧ��
EXPORTDECL_API int DoLanReadSdData( int hkid, int currentPage, int pageSize, unsigned int ulParam );
//�ص�����:
//void (*HKCALLBACKSDFILE)(void *userData,int nCmd, char *cBuf, int iCount );
//         userData   304;   buf(name=..;nid=..;size=..;)   count--(����0û��) 

//����������SD���ļ�
//char Callid[40];  �����ļ�ID���ر�ʱ�õ� �þ�����Ƶ�رսӿڣ�hk_DoLanClose��
//char *cDowFile; ���ص��ļ���
//int ulParam; Ԥ��
EXPORTDECL_API int DoLanDowSdData( char Callid[40], int hkid, char * cDowFile, int ulParam );


//��������ȡSD��¼���ļ�Ŀ¼
//int currentPage ��ǰ�ڼ�ҳ ��1��ʼ
//int pageSize    ��ҳ������(һ�λ�ȡ��������¼)
//����-1ʧ��
EXPORTDECL_API int DoMonSDReadData( const char *devid, int currentPage, int pageSize, unsigned int lParam );
//�ص�����:
//void (*HKCALLBACKSDFILE)(void *userData,int nCmd, char *cBuf, int iCount );
//         userData   304;   buf(name=..;nid=..;size=..;)   count--(����0û��) 

//char Callid[40];  �����ļ�ID���ر�ʱ�õ� �û�������Ƶ�رսӿ�
//char *devid;   �豸id
//char *cDowFile;Ҫ�����ļ�����
//int ulParam; Ԥ��
//����-1ʧ��
EXPORTDECL_API int DoMonDowSdData( char Callid[40],char *devid, char *cDowFile,  int ulParam );


//---------------------------------------------lan----------------------------

//���򱨾�����
//int iCount; �������
//const char *cRng; ����������ʾ:
//pointX0=45;pointY0=3546;pointX1=45;pointY1=3546;pointX2=45;pointY2=3546;
//int iSensitivity; �������ж�
//int iResolu;	��ǰ�ֱ���
EXPORTDECL_API int DoLocalMonSetAlarmRng( int hkid, const char *devid, int iCount, const char *cRng, int iSensitivity, int iResolu, int nChennl );

//��ʽ��SD��
//const char *cParam; Ԥ������
EXPORTDECL_API void DoLocalMonFormatSD( unsigned int hkid, const char *cParam );

//����SD����������Ϣ.
//SDRecQC=1��������0������; 
//MoveRec	[0(close) 1(open)]	//�ƶ�����¼��
//OutMoveRec	//�������¼��
//AutoRec		//�Զ�¼��
//LoopWrite		//ѭ��д
//Splite		//�ļ��ָ��С
//sdAudioMux    //��Ƶ
//const char *cParam; ������������:
//SDRecQC=;OutMoveRec=;AutoRec=;LoopWrite=;Splite=;sdAudioMux=;MovRec=;
//����-1ʧ�ܣ������ɹ�
EXPORTDECL_API int DoLocalMonSetSdParam( unsigned int hkid, const char *devid, const char *cParam );

//��������ָ����
//int nOpt����ֵ����
enum scc_param	
{
	SCC_PTZ_UP=1,			//��̨��
	SCC_PTZ_DOWN=2,			//��̨��
	SCC_PTZ_LEFT=3,			//��̨����
	SCC_PTZ_RIGHT=4,		//��̨����
	SCC_FOCAL_NEAR=5,		//��������
	SCC_FOCAL_FAR =6,		//������Զ
	SCC_PTZ_STOP = 7,		//ֹͣ��̨,FU,ת��
	SCC_APERTURE_NEAR=8,	//��Ȧ����
	SCC_APERTURE_FAR=9,		//��Ȧ��Զ
	SCC_PTZ_CRUISE = 60,	//Ѳ��(int nTypeֵ: 1:��̨ˮƽѲ��, 2:��̨��ֱѲ��, 3:��̨ȫ��λѲ��)
	SCC_DEV_BRIGHTNESS=50,	//��������( [1 63] )
	SCC_DEV_COLOR =	51,		//ɫ��	  ( [1 63] )
	SCC_DEV_CONTRAST=52,	//�Աȶ�  ( [1 63] )	
	SCC_DEV_SATURATION=53,	//������  ( [1 63] )
	SCC_DEV_STREAM = 54,	//����    ( [16 4096] )
	SCC_DEV_QUALITY = 55,	//������Ƶ����(1:�� 2:�� 3:��) 
	SCC_DEV_RESOLUTION=56,	//�޸ķֱ���(ֵ�ο� enumVGAMode)
	SCC_DEV_FRAMERATE =57,	//�޸�֡��	([1 30])
	SCC_DEV_SENSITIVITY=59,	//�޸ı������ж�([0 10])
	SCC_UPSIDE_DOWN = 61,	//���·�ת
	SCC_HORIZONTALLY = 62,	//ˮƽ��ת
	SCC_GET_PRESET = 63,	//�ƶ���ĳ��Ԥ��λ [1 8]
	SCC_SET_PRESET = 64,	//����ĳ��Ԥ��λ   [1 8]
	SCC_SET_SPEED = 65,		//������̨�ٶ� [1(��) 10(��)]
	SCC_DEV_EXPOSING=66,	//�����   ( [1 63] )
	SCC_DEV_SHARPNESS=67,	//���	   ( [1 63] )
	SCC_DEV_FREQUENCY=70,	//Ƶ��     [50(PAL) 60(NTSC)]
	SCC_DEV_CBR_VBR = 106,	//����	   [0(CBR) 1(VBR)]
	SCC_DEFAULT_PARAM =107,	//�ָ�Ĭ����Ƶ����
	SCC_FACTORY_SET = 109,	//�ָ���������
	SCC_DEV_REBOOT = 110,	//�����豸

};

//�ġ���������
EXPORTDECL_API int sccSetLANInfo( char *pDev, unsigned int nHKid,unsigned int nOpt,int nType,int nChannel);
//int sccGetLANInfo( char *pDev, unsigned int nHKid,unsigned int nOpt,int nType,int nChannel);
EXPORTDECL_API int sccSetWANInfo( char *pDev,unsigned int nOpt,int nType,int nChannel);
//int sccGetWANInfo( char *pDev,unsigned int nOpt,int nType,int nChannel);





}

#endif//_HK_IPC_H_
