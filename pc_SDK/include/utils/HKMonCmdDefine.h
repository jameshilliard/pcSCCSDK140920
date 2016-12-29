#pragma once
#include <time.h>

#define HK_KEY_MONSERVER "HKMONServer"

enum _HK_RES_TYPE
{
	HK_RES_AUDIO=1,     
	HK_RES_VIDEO=2,
	HK_RES_AUDIOVIDEO=3,
	HK_RES_REC=4,       //¼��
	HK_RES_PALY=5,      //�㲥
	HK_RES_AUDIOIN=6,	//��
	HK_RES_AUDIOOUT=7,	//˵
	HK_RES_MRS=8,
};

//¼���ļ���������..
enum _FILE_FRAME_DATA_TYPE
{
	HK_MRS_MPEG4 = 1,
	HK_MRS_MJPEG = 2,
	HK_MRS_H264 = 3,
	HK_MRS_G723 = 4,
	HK_MRS_G729 = 5,
};

enum _HK_MON_OPERATION_CODE
{
	HK_MON_REGISTER = 101,			//��ȡMONҵ����Ϣ
	HK_MON_FRIENDNOTIFY = 102,		//֪ͨ��������  (һ��)
	HK_MON_MOREFRIENDONLINE = 103,	//�����������(��¼ʱ)

	HK_MON_GETITEM = 104,			//��ȡ�ļ����б�
	HK_MON_ADDFILE = 105,			//����ļ���
	HK_MON_UPDATEFILE = 106,		//�޸��ļ�������
	HK_MON_DELETEFILE =107,			//ɾ���ļ���
	HK_MON_UPDATEDEVNAME = 108,		//�û��޸���Դ����
    HK_MON_MOVEDEV = 109,			//�û��ƶ���Դ
	HK_MON_DEVRESOLUTION = 110,		//�޸���Դ�ֱ��ʣ�������
	HK_MON_UPDATEDEVRATE = 111,		//�޸���Դ֡��
	HK_MON_UPDATECOMPRESS = 112,	//�޸���Դѹ����ʽ

	HK_MON_DEVCONFIGINFO = 113,		//��Դ������Ϣ
	HK_MON_SHOOTINGINFO = 114,		//��ʱץ�Ĳ�ѯ
	HK_MON_UPDATESHOOINFO = 115,	//��ʱץ������
	HK_MON_CONTROLPT = 116,			//��̨����
	HK_MON_CONTROLFOCUS = 117,		//���۵�����ɢ��,�Զ�,�۽���
	HK_MON_CONTROLFU = 118,			//���� ��/Զ
	HK_MON_FINDCARDINFO = 119,		//SD��״̬�رտ���
	HK_MON_FINDCARDINFORET = 120,	//SD��״̬��Ϣ��ѯ�ķ���
	HK_MON_FORMATCARD = 121,		//SD����ʽ��
	HK_MON_FORMATCARDRET = 122,		//SD����ʽ���ķ���
	HK_MON_QUERYPHOTODOW = 123,		//SD��Ƭ����
	HK_MON_QUERYPHOTOLIST = 124,	//SD��Ƭ�ļ�����Ƭ
	HK_MON_DELETEPHOTO = 125,		//SDɾ����Ƭ
	HK_MON_DELETEPHOTORET = 126,	//SDɾ����Ƭ�ķ���
	HK_MON_PHOTODOWN = 127,			//��Ƭ����
	HK_MON_PHOTODOWNRET = 128,		//��Ƭ���صķ���
	HK_MON_ALARMNOTIFY = 129,		//����֪ͨ
	HK_MON_ALARMNOTIFYRET = 130,	//����֪ͨ
	HK_MON_CARDLOSTREPORT = 131,	//SD����ʧ����
	HK_MON_CARDLOSTREPORTRET = 132,	//SD����ʧ����ķ���
	HK_MON_REPLAYVIDEO = 133,		//Զ��¼��
	HK_MON_STOPREPLAYVIDEO = 134,	//ֹͣ¼��
	HK_MON_FINDMRS = 135,			//������Դ
	HK_MON_PLAYMRS = 136,			//�㲥��Դ
	HK_MON_PLAYORSTOP = 137,		//��ͣ/��ʼ�㲥
	HK_MON_MRSDOWN = 138,			//��Դ����
	HK_MON_DELETEMRS = 139,			//ɾ����Դ

	HK_MON_INVITE = 140,			//�����Ự
	HK_MON_INVITERESULT = 141,		//�Է�ͬ����ǽ���
	HK_MON_INVITEACK = 142,       
	HK_MON_CANCEL  = 143,			//ȡ���Ի�
	HK_MON_CANCELACK = 144,			//ȡ���Ự�ķ���
	HK_MON_BYE  = 145,				//�����Ự  
	HK_MON_BYEACK = 146, 

	HK_MON_UNREGISTER = 147,		//ע��
	HK_MON_SUBSCRIBE = 148,			//����
	HK_MON_NOTIFY = 149,			//֪ͨ
	HK_MON_FRIENDOFFLINE = 150,		//�����û�����
	
	HK_MON_SET = 151,
	HK_MON_GET = 152,
	HK_MON_GOTOANCHOR = 153,		//���ٶ�λ 
	HK_MON_SENSITIVITY = 154,		//�������ж�����

	//�������ܵ�    0609
	HK_MON_GETDEVLIST =		155,	//��ȡ�ҵ��豸�б�
	HK_MON_ADDDEV =			156,	//����ҵ��豸
	HK_MON_DELETEDEV =		157,	//ɾ���ҵ��豸
	HK_MON_UPDATEDEVPASSW = 158,	//�޸��豸�Ĺ�������
	HK_MON_TRANSFERRIGHT =	159,	//ת���豸
	HK_MON_GETDEVRIGHT =	160,	//��ȡ�豸��Ȩ��
	HK_MON_UPDATEDEVRIGHT = 161,	//�޸��豸��Ȩ��
	HK_MON_UPDATEDEVALIAS = 162,	//�޸��豸�ı���
	HK_MON_GETRIGHTLIST =	163,	//��ȡȨ���б�
	HK_KEY_UPDATEDEVRIGHT = 164,	//�޸�Ȩ���б�
	HK_MON_DELETEUSRBYLIST =165,	//ɾ��ĳ���û�����Ȩ���б��У�
	HK_MON_SEARCHUSR =		166,	//ģ�������û������������Ȩ���б��У�
	HK_MON_ADDUSERTOLIST =	167,	//���ĳ���û���Ȩ���б�

	HK_MON_CONTRAST =	168,		//�����豸�ĶԱȶ�
	HK_MON_EXPOSURE =	169,		//�����豸���ع��
	HK_MON_SATURATION = 170,		//�����豸�ı��Ͷ�
	HK_MON_BRIGHTNESS = 171,		//�����豸������
	HK_MON_COLOR =		172,		//�����豸��ɫ��
	HK_MON_SHARPNESS =	173,		//�����豸�����
	HK_MON_ADDMONDEV =	174,		//����б��У�����豸
	HK_MON_ADDDEVBYPROBLEM = 175,	//����б��У�����豸ʱ����֤��ʽ�����⣬������֤

	HK_MON_DELMONDEV =	176,		//����б��У�ɾ���豸
	HK_MON_SEARCHDEV =	177,		//����б��У������豸
	HK_MON_DEVINFO =	178,		//����б��У���ѯ�豸��ϸ��Ϣ
	HK_MON_SEARCHALARMSET = 179,	//��ȡ����������Ϣ
	HK_MON_RECINFOREAD =	180,	//��ȡ¼����Ϣ
	HK_MON_UPDATEALARMORRECINFO=181,//¼��������Ե����á�¼��ƻ�����
	HK_MON_SEARCHALERTRECORD =	182,//������¼��ѯ
	HK_MON_SEARCHVISTDEV =		183,//�豸���ʲ�ѯ
	HK_MON_SEARCHSOURCEINFO =	184,//�����㲥��Դ
	HK_MON_MRS =			185,	//�ύmrs��������Ϣ
	HK_MON_MRSSYN =			186,	//�ύMRS������¼������� ͬ��
	HK_MON_MRSSYNRET =		187,	//�ύMRSͬ���ķ���
	HK_MON_SEARCHINSEEDEV =	188,	//�����ж��������ڷ��ʵ��豸
	HK_MON_UPDATEDEVRIGHTRET=189,	//ת���豸��ȷ�ϵķ���
	HK_MON_ADDDEVNOTIFY =	190,    //���豸����������豸ʱ�������豸ͬ��������б���׼�Ŀ¼
	HK_MON_DELETEDEVINFO =	191,	//ɾ��¼���¼�뱨����¼
	HK_MON_DEVVIDEOINFO =	192,	//¼����Ϣ��¼����..
	HK_MON_DEVVIDEOREVERSAL=193,	//����ͼ��ת...
	HK_MON_MONTOMRSINFO =	194,	//MON��������Ϣͬ����MRS������.
	HK_MON_GETALARMVIDEOINFO=195,	//��ȡ����¼����Ϣ..
	HK_MON_MRSDELETEFILE =	196,	//�ռ��С����ɾ���ļ���¼
	HK_WEB_USERSTARTMRS =	197,	//�û�����¼�������.
	HK_MON_CALLPROBLEM =	198,	//����������֤..
	HK_MON_PHONEINFO =		199,	//���ŷ���..
	HK_WEB_GETITEM =		200,	//WEB��ȡ�û������б�..
	HK_WEB_USERLOGINSTATUS =201,	//WEB��¼��MON���������������豸��״̬.
	HK_MON_LPTSPEED	=		202,	//��̨�ٶȿ���..
	HK_MON_AGREEMENT =		203,	//Э�飺PELCO-D/PELCO-P
	HK_MON_BAUDRATE =		204,	//�����ʣ�2400/9600/4800
	HK_MON_DEVIOARAM =		205,	//�豸IO�˿�����..
	HK_MON_GETDEVPOPEDOM=	206,	//��ȡ�û������豸��Ȩ��
	HK_MON_SETALARMINFO =	207,	//���ñ���������Ϣ
	HK_MON_FINDPUBLICDEV=	208,	//�������й������豸.
	HK_WEB_BROADCASTINFO=	209,	//�㲥��Ϣweb->monserver->ui
	HK_MON_FREQUENCY =		210,	//�����豸��Ƶ��
	HK_MON_AUTOLPTSPEED=	211,	//��̨ˮƽ�Զ�ת��
	HK_MON_MYDEVUPDATE=		212,	//�����豸����������ߣ�֪ͨ������.
	HK_MON_PTTOGGLE =		213,	//��̨�л����ң�����
	HK_MON_SETVBR =			214,	//VBR����
	HK_MON_ALARM_EMAIL_TEST=215,	//�����ʼ�����
	HK_MON_DEV_IRATE=		216,	//�޸��豸I֡���
	HK_MON_DEV_RESOLUTION = 217,	//�޸ķֱ���
	HK_MON_DEV_TRANSLATE =	218,	//͸������
	HK_MON_DEV_NETPROXY =	219,	//����poxy�޸�
	HK_MON_DEV_SHAREADDR =	220,	//����WEB����ҳ��
	HK_MON_CLOSE_SHAREADDR=	221,	//�ر�WEB����ҳ��
	HK_MON_DEV_INTERNET =	222,	//�رտ�������������
	HK_MON_SET_LOCAL_PORT=	223,	//���ö˿�
	HK_MRS_DRIVE_NOTIFY	=	224,	//¼��������������
	HK_MON_DEV_IRORSIGNAL = 225,	//���źŵ�IR����ر�
	HK_MON_DEV_PRESET     = 226,	//�������õ���Ԥ��λ
	HK_MON_DEV_SD_SET     = 227,	//����SD�������Ϣ
	HK_MON_SET_DEV_APERTURE=228,	//��Ȧ����
	HK_MON_SET_VBRORCBR	   =229,	//����ģʽ 0:CBR 1:VBR
	HK_MON_SET_RESET_PARAM =230,	//�����ָ�Ĭ��ֵ
	HK_MON_SET_IO_IN	   =231,	//�豸IO����.����
	HK_MON_SET_ALARM_RNG   =232,	//������������
	HK_MON_SET_ACCESS_PWD  =233,	//�޸����÷�������
	HK_MON_ADD_SHARE_ANY   =234,	//�����豸
	HK_MON_SET_FTPSERVER  = 235,	//����SD��FTP��������

	HK_MON_SET_DEVPARAM = 236,
	HK_MON_GET_DEVPARAM = 237,

	HK_MON_PPOE = 238,				//PPOE����
	HK_MON_RESTORATION_PARAM=239,	//�ָ�Ĭ�ϲ���

	//-------voip-------
	HK_VOIP_GETITEM =	301,	//��ȡVOIP��ϵ�б�..
	HK_VOIP_GETMYITEM = 302,	//��ȡ�ҵ�VOIPȺ��.
	HK_VOIP_ADDMYVOIP = 303,	//����ҵ�VOIPȺ��.
	HK_VOIP_ADDUSER =	304,	//���VOIPȺ��Ա
	HK_VOIP_DELUSER =	305,	//ɾ��VOIPȺ��Ա
	HK_VOIP_UPDATEUSER=	306,	//�޸�VOIPȺ��Ա
	HK_VOIP_UPDATEPASSWD=307,	//�޸�VOIPȺ����.

	//--------mrs-----------
	HK_MRS_GTEMYITEM =	400,	//��ȡ�ҵ�MRS����������
	HK_MRS_GETITEM =	401,	//��ȡָ�����������û�
	HK_MRS_ADDMYMRS =	402,	//����ҵ�¼�������
	HK_MRS_DELMYMRS =	403,	//ɾ���ҵ�¼�������
	HK_MRS_MRSTOUSER =	404,	//ת���ҵ�¼�������
	HK_MRS_ADDUSERTOMRS=405,	//����û���ָ��¼�������
	HK_MRS_UPDATEUSER = 406,	//�޸��û���¼���������Ϣ
	HK_MRS_DELUSER =	407,	//��¼�������ɾ���û�
	HK_MRS_UPDATEPASW =	408,	//�޸�¼��������Ĺ�������
	HK_MRS_ADDDEVMRS =	409,	//����豸��ָ��¼�������
	HK_MRS_DELETEDEVMRS=410,	//ɾ��¼��������е��豸
	HK_MRS_GETMRSDEV =	411,	//��ȡָ�����������豸
	HK_MRS_GETREADINDEX = 412,	//��ȡ�ļ�����

	//--------dev-----------
	HK_DEV_REGISTER =	  500,	//�豸ע��MONҵ��
	HK_DEV_UPDATEPASSWD = 501,	//�����豸��������������
	HK_DEV_RESYSTEM	= 502,		//�����������豸

	//--------local server mrs-------
	HK_MRS_LOCAL_VIDEOSET =			600,	//���ñ��ط�����¼������
	HK_MRS_LOCAL_VIDEOREAD =		601,	//��ȡ���ط�����¼������
	HK_MRS_LOCAL_UPDATEPASWD =		602,	//����¼�����������
	HK_MRS_LOCAL_GETVIDEOINFO =		603,	//��ȡ¼���¼��֧�ַ�ҳ
	HK_MRS_LOCAL_DELETEVIDEOINFO=	604,	//ɾ��¼��Ƿ���֧�ֶ���
	HK_MRS_LOCAL_SETSERVERTIME =	605,	//����ʱ��

	//---------wifi-------------------
	HK_WIFI_START =			700,	//��ȡȡwifi���ӵ�
	HK_WIFI_STOP =			701,	//ֹͣwifi����
	HK_WIFI_CONNECT =		702,	//��ȡwifi����״̬
	HK_WIFI_GET_WIFIINFO =	703,	//

	//------------phone--------------
	HK_PHONE_GET_DEV_PARAM= 800,	//��ȡ
	HK_PHONE_SET_DEV_PARAM= 801,	//����
	HK_GET_PHONE_DEVPARAM = 802,	//��ȡ������
	HK_SET_PHONE_DEVPARAM = 803,	//���ø�����
	HK_PHONE_RESTORE = 804,			//�ָ�������restore
	HK_GET_PHONE_SDPARAM = 805,		//��ȡSD����
	HK_SET_PHONE_SDPARAM = 806,		//����SD����

	//--------re----------------------
	HK_MRS_RE_LOCAL_VIDEO_REC= 900,	//��¼���������ȡ���ݷ���
};

#ifdef __cplusplus
typedef struct _SOURCE_INFO
{
	
	std::string    sessionId;	//��Դsid
	int   type;					//����
	std::string    devId;		//�豸��
	std::string    nodeId;		//�ڵ���


	_SOURCE_INFO(void)
	{
		sessionId ="";
		type =0;
		devId = "";
		nodeId = "";

	}

	_SOURCE_INFO & operator = ( const _SOURCE_INFO & rSInfo )
	{
		if( this == &rSInfo )
		{
			return *this;

		}
		this->sessionId = rSInfo.sessionId;
		this->type = rSInfo.type;
		this->devId = rSInfo.devId;
		this->nodeId = rSInfo.nodeId;
		return *this;

	}

	bool operator == ( const _SOURCE_INFO & rSInfo )const
	{
		if(rSInfo.sessionId == sessionId)
		{
			return true;
		}
		return false;

	}



}SOURCE_INFO;

typedef struct _SID_INFO
{
	//std::string    sid;           
	std::string    fromid;	     //������
	int    uiprama;              //�����ߴ���UI����
	std::string    devid;       //�����ߣ��豸ID��
	std::string    callid ;      //�ỰID
	time_t     beginTime;      //��ʼʱ��


	_SID_INFO(void)
	{
		//sid = "";
		fromid ="";
		devid = "";
		callid = "";
		uiprama = 0;
		beginTime = 0;

	}

	_SID_INFO & operator = ( const _SID_INFO & rSInfo )
	{
		if( this == &rSInfo )
		{
			return *this;

		}
		this->uiprama = rSInfo.uiprama;
		this->fromid = rSInfo.fromid;
		this->devid = rSInfo.devid;
		this->callid = rSInfo.callid;
		this->beginTime = rSInfo.beginTime;
		return *this;

	}


}SID_INFO;

typedef struct _SUB_TYPE
{
	int subOnlineFlag;   //�Ƿ������ߵ���Ϣ
	int subOffLineFlag;  //�Ƿ������ߵ���Ϣ
	int subAlarmFlag;    //�Ƿ��屨����Ϣ
	int devStatus;       //�豸״̬

	_SUB_TYPE(void)
	{
		subOnlineFlag =0;
		subOffLineFlag = 0;
		subAlarmFlag = 0;
		devStatus = 0;

	}

	_SUB_TYPE & operator = ( _SUB_TYPE & rStype )
	{
		if( this == &rStype )
		{
			return *this;

		}
		this->subOnlineFlag = rStype.subOnlineFlag;
		this->subOffLineFlag = rStype.subOffLineFlag;
		this->subAlarmFlag = rStype.subAlarmFlag;
		this->devStatus = rStype.devStatus;
		return  *this;

	}
}SUB_TYPE;
#endif

#define HK_KEY_FROM_TEMP	"idtemp"
#define HK_KEY_CHANNEL		"channel"
#define HK_KEY_PT			"ControlPT"		//��̨���Ʋ���
#define HK_KEY_FOCUS		"Focus"			//����
#define HK_KEY_VOIDEID		"VoideId"		//¼��id
#define HK_KEY_TREEPID      "parendid"		//����û���֯�ṹ��ʱ,�û���parentid
#define HK_KEY_TREEID       "formid"		//�ļ���ID
#define HK_KEY_TREENAME     "formname"		//�ļ�����
#define HK_KEY_TREETYPE     "TreeType"		//�ڵ�����,(�ļ���,ֱ�ӽڵ�,��)
#define HK_KEY_DEVID         "devid"		//�豸ID(MD5ֵ)
#define HK_KEY_DEVNAME       "DEVNAME"		//�豸����
#define HK_KEY_TEMPVALUE	 "TempValue"
#define HK_KEY_CALLINGSDP    "INGSDP"		
#define HK_KEY_CALLEDSDP     "EDSDP"
#define HK_KEY_NODETYPE      "NodeType"
#define HK_KEY_SWITCH        "SWITCH"		//�豸״̬��¼��(int)��ʾһ���豸���ж��ٸ�����ͨ��.
#define HK_KEY_SENSITIVITY	 "Sensitivity"	//���ж�ֵ
#define HK_KEY_SOLOMONSID    "DEVSID"		//�豸��SID

#define HK_KEY_SIDVOID		 "SIDVOID"		//¼��SID
#define HK_KEY_MEDIATYPE     "MEDIATYPE"	//ý������
#define HK_KEY_VIDEONAME     "VideoName"	//¼���ļ�����

#define HK_KEY_ALIAS         "alias"        //����
#define HK_KEY_ADDR			 "addr"			//��ַ
#define HK_KEY_EMAIL		 "email"		//��������
#define HK_KEY_PHONE		 "phone"		//�绰
#define HK_KEY_REMARK		 "remark"		//��ע��Ϣ
#define HK_KEY_ADMINID		 "adminid"		//������id
#define HK_KEY_FILEFLAG      "fileFlag"     //�ļ���ʶ   0���ļ�����û���豸 1���ļ����������豸 2 �ļ����������ļ���

//#define HK_KEY_VIDEORES      "videoRes"	//��Ƶ��Դ
//#define HK_KEY_AUDIORES      "audioRes"	//��Ƶ��Դ
//#define HK_KEY_SUBTYPE       "subType"	//�������� 0 ȫ���ģ� 1 ĳһ�û��Ķ��� 2 ĳһ�豸�Ķ���
#define HK_KEY_RESTYPE       "resType"		//��Դ����
#define HK_KEY_ALLARRIBUTE   "allAttribute"	//��������
#define HK_KEY_CURRATTRIBUTE "currAttribute"//��ǰ����

#define HK_KEY_MAC1         "mac1"
#define HK_KEY_MAC2			"mac2"
#define HK_KEY_POINTX        "pointX"        //X����
#define HK_KEY_POINTY        "pointY"        //Y����

#define HK_KEY_FRISTFROMID   "fristFromid"   //�׼�formid
#define HK_KEY_FRIENDID      "friendid"      //����ID
#define HK_KEY_FRIENDNAME    "friendName"    //������

#define HK_KEY_ACCEPT          "Accept"      //ͬ����Ǿܾ� 1 ͬ�� ��0 �ܾ�
#define HK_KEY_VER             "ver"         //�汾��
#define HK_KEY_MYVER           "myver"       //�汾��

#define HK_KEY_DEVALIAS        "devAlias"		//�豸����
#define HK_KEY_ADMINDID        "admindid"		//������
#define HK_KEY_FUCTION         "fuction"		//�Ƿ�ͨ�������ܣ�0��û�п�ͨ��1����ͨ��
#define HK_KEY_AUTHSTATUS      "authstatus"		//��֤��ʽ��0��˽�С�1�����⡣2��������
#define HK_KEY_PROBLEM         "problem"		//��֤��ʽΪ����ʱ���������û�������֤���⡣
#define HK_KEY_SOLUTION        "solution"		//������֤�Ĵ�.
#define HK_KEY_POPEDOM         "popedom"		//��֤��ʽ����Ӧ��Ȩ��.(0��˽�У�1��������2������¼��3���������(ָ����̨���ֱ��ʵȵȡ�)
#define HK_KEY_NEWPASSWD       "newpasswd"		//������
#define HK_KEY_FRIENDID        "friendid"		//����ID
#define HK_KEY_NEWPOPEDOM      "newPopedom"		//�µ���֤��ʽ
#define HK_KEY_ISALERT_SENSE   "isAlertSens"	//�Ƿ�����������̽
#define HK_KEY_ALERT_SENSE     "alertSens"		//�������ж�
#define HK_KEY_ALERT_LONGTIME  "alertLongTime"	//��������ʱ��
#define HK_KEY_ALERT_TYPE      "alertType"		//������ʽ��ץͼ��¼���ʼ���
#define HK_KEY_ALERT_VIDEOTIME "alertVideoTime" //����¼��ʱ�䳤��
#define HK_KEY_AHEAD_IMAGETIME "aheadImageTime" //��ǰץ��ʱ��
#define HK_KEY_CAPTUREFR       "captureFR"      //ץͼƵ��
#define HK_KEY_ALERT_IMAGETIME "alertImageTime" //����ץͼʱ�䳤��
#define HK_KEY_ALERT_EMAIL     "alertEmail"     //����������
#define HK_KEY_REEMAIL			"reEmail"		//�ʼ�������
#define HK_KEY_SMTPSERVER		"smtpServer"	//SMTP������
#define HK_KEY_SMTPUSER			"smtpUser"		//STMP�û�
//#define HK_KEY_ALERT_TIME      "alertTime"    //����ʱ��
#define HK_KEY_EMAIL_SD_ERROR    "sderror"		//sd�������Ƿ��ʼ�
#define HK_KEY_EMAIL_MOVE_ALARM  "sdmove"       //sd���ƶ�����Ƿ��ʼ�
#define HK_KEY_EMAIL_INFO        "emailinfo"    //�ʼ�����

#define HK_KEY_FTPSERVER		"ftpserver"		//FTP������
#define HK_KEY_FTPUSER			"ftpuser"		//ftp�û�
#define HK_KEY_PPPOEID			"pppoeid"

#define HK_KEY_REC_ID          "recID"          //��¼���
#define HK_KEY_ALERT_TIME      "alertTime"      //����ʱ��
#define HK_KEY_VIDEO_NUMID     "videoRecID"     //����¼����
#define HK_KEY_IMAGE_RECPATH   "imageRecPath"   //����ץ��ͼ�񱣴��ļ���
#define HK_KEY_ALERT_INFO      "alertInfo"      //��������
#define HK_KEY_BEGINE_TIME     "beginTime"      //��ʼʱ��
#define HK_KEY_END_TIME        "endTime"        //����ʱ��
#define HK_KEY_VISIT_INFO      "visitInfo"      //������Ϣ
#define HK_KEY_DEVPARAM        "devParam"       //�����豸��صĲ���(�ֱ��ʡ��ع�ȡ�֡�ʵ�)
#define HK_KEY_WEEK_DAY        "week_day"       //���ڼ�
#define HK_KEY_ALERTINFO       "alertInfo"
#define HK_KEY_RECINFO         "recInfo"
#define HK_KEY_LOCALORREMOTE   "localOrRemote"  //�ǲ��ұ��ػ���Զ�� 1 ����  2��Զ��

#define HK_KEY_REC_NAME        "recName"        //�ļ�����
#define HK_KEY_REC_FILE        "recFile"        //¼���ļ�λ��
#define HK_KEY_USERID          "userid"         //
#define HK_KEY_DAYINFO         "dayInfo"
#define HK_KEY_CODETYPE        "codeType"       //ѹ�����ͣ�0��MPEG-4 1:  MJPEG  2:  H263    3: H264��

#define HK_KEY_COMPRESS			"Compress"		//��Ƶѹ����ʽ
#define HK_KEY_SHARPNESS		"sharpness"		//���
#define HK_KEY_HUE				"hue"			//ɫ��
#define HK_KEY_BRIGHTNESS		"brightness"	//����
#define HK_KEY_SATURATION		"saturation"	//���Ͷ�
#define HK_KEY_EXPOSURE			"exposure"		//�ع��
#define HK_KEY_CONTRAST			"contrast"		//�Աȶ�
#define HK_KEY_RATE				"rate"			//֡��
#define HK_KEY_IRATE			"irate"			//��֡��
#define HK_KEY_RESOLU			"Reselution"	//�ֱ���(����)
#define HK_KEY_FREQUENCY		"frequency"		//Ƶ��
#define HK_KEY_AUTOPT			"autopt"		//��̨�Զ�ת��
#define HK_KEY_QUALITE			"qualite"		//��Ƶ����
#define HK_KEY_BITRATE			"bitrate"		//�ֱ���
#define HK_KEY_LANPORT			"lanport"
#define HK_KEY_WANENABLE		"wannetable"

#define HK_KEY_MAX_FILESIZE    "maxfilesize"    //¼���ļ��������ֵ
#define HK_KEY_ALERT_SPACE     "alertSpace"     //¼��ռ侯��ֵ����λM��
#define HK_KEY_ALERT_DEAL      "alertDeal"      //�ﵽ����ֵʱ�Ĵ���ʽ��1��ֹͣ¼�� 0�����������¼���ļ���
#define HK_KEY_IS_RECAUDIO     "isRecAudio"     //�Ƿ�¼��������0���� 1���ǣ�
#define HK_KEY_MRSSYN          "mrsSyn"         //�Ƿ��Ѿ�ͬ����MRS��0����1��ͬ��
#define HK_KEY_PAGESIZE        "pagesize"       //ÿҳ�ж�������¼
#define HK_KEY_CURRENTPAGE     "currentpage"    //��ǰҳ
#define HK_KEY_LISTCOUNT       "listCount"      //�ܹ���������¼
#define HK_KEY_ISRECFLAG       "isRecFlag"      //�Ƿ��Ѿ���¼��0û�С�1��¼��
#define HK_KEY_FILEMAX		   "filemax"		//¼���ѯ���ص��ļ���С
#define HK_KEY_USER_ID         "userid"         //�豸�ۿ��ߵ�ID
#define HK_KEY_USER_MRS        "user_mrs"       //�û��Ƿ���¼������� 0 û�У� 1 ��

#define HK_KEY_TOTALTIME		"total_time"	//¼���ļ���ʱ��

#define HK_KEY_VOIPID		"voipid"		//VOIPȺID
#define HK_KEY_VOIPNUM		"voipnum"		//Ⱥ��Ա���к���
#define HK_KEY_MRSNAME		"mrsname"		//¼�����������
#define HK_KEY_MRSMYSERVER	"mrsmyserver"	//�ҵ�¼�������
#define HK_KEY_MRSSERVER	"mrserver"		//���˸��ҷ����¼�������
#define HK_KEY_IOCOUNT		"iocount"		//�ڼ���io��

#define HK_KEY_IOHIGHORLOW	"highorlow"		//����io�ڸߵ͵� ���
#define HK_KEY_IOIN			"ioin"			//io����
#define HK_KEY_CBRORVBR		"cbrorvbr"		//CBR or VBR
#define HK_KEY_SIGNAL		"signal"		//�źŵƴ򿪹ر�

//--------wifi---------------------
#define HK_WIFI_OPENORCLOSE	"isopen"		//�Ƿ���WIFI������1���ر�0
#define HK_WIFI_SID			"wifisid"
#define HK_WIFI_CHANNEL		"wifichn"
#define HK_WIFI_SAFETYPE	"safetype"     //none,wep��wpa
#define HK_WIFI_SAFEOPTION	"safeoption"   // open����share ֻ��wepʱ��Ч
#define HK_WIFI_KEYTYPE		"keytype"      // ascii����hex
#define HK_WIFI_ARRKEY		"arrkey"
#define HK_WIFI_ARRKEYBIS	"arrkeybits"
#define HK_WIFI_ENC			"wifienc"
#define HK_WIFI_AUTH		"wifiauth"
#define HK_WIFI_PASSWORD	"wifipassword"
#define HK_WIFI_DEVICE		"wifidev"
#define HK_WIFI_ENCRYTYPE   "encrytype"	//key
#define HK_WIFI_COMMENT		"COMMENT"

#define HK_WIFI_ENCAES      "AES"
#define HK_WIFI_ENCTIP      "TKIP"
#define HK_WIFI_VALUES_NONE		"none"
#define HK_WIFI_VALUES_WEP		"wep"

//none,wep��wpa
//open����share ֻ��wepʱ��Ч
//ascii����hex

#define HK_WIFI_VALUES_AUTO		"auto"

#define HK_WIFI_VALUES_WPA		"wpa"
#define HK_WIFI_VALUES_OPEN		"open"
#define HK_WIFI_VALUES_SHARE	"share"
#define HK_WIFI_VALUES_WPA2		"wpa2"

#define HK_WIFI_VALUES_ASCII	"ascii"	
#define HK_WIFI_VALUES_HEX		"hex"

#define HK_DEV_TYPE  502