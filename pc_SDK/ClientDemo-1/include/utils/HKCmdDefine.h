#pragma  once

// ver 10003
#define HK_VER 0x01

#define  HK_MAXBH  30
#define  HK_WARNBH 15
#define  HK_BTBH     29

enum _HK_AS_CODE
{
	HK_SRV_RES		= 100,
	HK_SRV_ROUTER	= 101,
	HK_SYS_REG      = 333,
	HK_SYS_REG_OK   = 334,
	HK_SYS_REG_FAIL = 335,
	HK_AS_IM        = 336,
	HK_AS_MONS      = 337,
	HK_AS_MRS		= 338,
	HK_AS_MCU       = 400,
	HK_AS_AAA		= 999,	
	HK_AS_EVENT     = 555,       
	HK_AS_PROXY	    = 777,
	HK_AS_SWITCH_1	= 1000,
	HK_AS_MON		= 10002,
	HK_AS_WEB		= 40001,
};

enum _HK_OPERATION_TYPE
{
	HK_AS_VALIDATE = 10,		//AS��֤���治�������ַ���
	HK_VALIDATE_OK = 11,
	HK_VALIDATA_FAIL = 12,

	HK_AS_STATUS = 13 ,			//ҵ����������������˳�
	HK_AS_UNREGISTER = 14,		//sys�˳�
	HK_AS_SUBSCRIBE = 15,		//����
	HK_AS_UNSUBSCRIBE = 16,		//�˶�
	HK_AS_NOTIFY = 17,			//֪ͨ

    HK_RS_EVENT = 18,
	HK_VPIPE_NOTIFY_OK = 19,
	HK_VPIPE_NOTIFY_FAIL = 20,
	HK_RS_SET = 21,
	HK_MCU_STATUS = 22,			//MCU״̬���޸�
    HK_AS_REAUTH = 23,			//������������֤

    HK_RS_NEW_VISITOR = 24,
	HK_AAA_UPDATEPASSWD = 25,	//�޸�����
	HK_AAA_UPDATEPC	=	26,		//�ֶ�����
	HK_AAA_GUSTMON = 27,		//�ο���Ϣ����
	HK_AAA_MONEYCARD = 28,		//��ֵ.
	HK_AAA_GETPOSTYPE = 29,		//��ȡ����.
	HK_AAA_ACCOUNTS = 30,		//�ͻ��������ʺ�(��¼�ɹ����)
	HK_AAA_ACTIVATION=31,		//�����ʺ�(��¼�ɹ����)

};

enum _HK_SUBTYPE
{
	HK_SUBTYPE_ALL =0,    //�������е�
	HK_SUBTYPE_EP,        //����ĳһ�û�
	HK_SUBTYPE_DEV,       //�����豸
	HK_SUBTYPE_SID,       //����SID
};

enum ToolBarStateWan
{
	All_False = 1,
	Except_7_T,
	Except_1_F,
	Except_2_F,
	Except_6_F,
	Except_1_T,
};

//��½ʧ�ܵ�ԭ��
enum _HK_UNREGISTER
{
	HK_LOGIN_SUCCESS,
	HK_PASSWD_FAIL = 1,
	HK_USER_RELOGIN= 2,
	HK_NET_OUT = 3,
	HK_UPDATE_PASWD_SUCCESS=4,	//�޸�����ɹ�
	HK_UPDATE_PASWD_FAIL=5,		//�޸�����ʧ��
    HK_CONNECT_SUCCESS=6,
	HK_UPDATE_PC=7,				//�ֶ�����
	HK_USER_EXPIRE=8,			//���ʺ��Ѿ�����.
	HK_USER_USE=9,				//�Ѿ������û�
	HK_USER_NOACTIVATION=10,	//�ʺ�û�м���..
	HK_MONEY_SUCCESS = 11,		//��ֵ�ɹ�
	HK_MONEY_FAIL = 12,			//��ֵʧ��
	HK_USER_NO_PHONE = 13,		//�û�δ��ͨ�ֻ�����
    HK_SIGN_TIME_OUT,
};

enum _HK_VOIP_TYPE
{
	HK_VOIP_RECALL=200,		//����
	HK_VOIP_RESUCCESS=201,	//�����ɹ�
	HK_VOIP_RESPONSION=202,	//Զ��Ӧ��
	HK_VOIP_CLOSECALL=203,	//Զ�˹Ҷ�
	HK_VOIP_OFFHOOK=204,	//ժ��
	HK_VOIP_KEYSTOKE=205,	//����
	HK_VOIP_CALLKEY=206,	//���м�
	HK_VOIP_BYECALL=207,	//�һ�
	HK_VOIP_OVERTIME=208,	//��ʱ
	HK_VOIP_DTMF=209,		//dtmf
	HK_VOIP_CALLBUSY=210,	//æ
};

enum _HK_CLIENT_TYPE
{
	HK_CLIENT_ALL = 999,	//���пͻ�����
	HK_CLIENT_SYSM = 1000,	//1.2�Ͽ�
	HK_CLIENT_NEWSYSM=1001,	//1.3�Ͽ�
	HK_CLIENT_TOP = 1010,	//���ü�
	HK_CLIENT_YDW = 1020,	//���Ϊ
	HK_CLIENT_ASD = 1030,	//������
	HK_CLIENT_DX = 1040,	//����
	HK_CLIENT_LIXUN = 1050,	//��Ѷ
	HK_CLIENT_SHENZHOU=1060,//����
	HK_CLIENT_EBAIJN = 1070,//E�ټ�
	HK_CLIENT_SUNCOMM = 1080, //SunComm
	HK_CLIENT_AT = 1090,
	HK_CLIENT_3GWU = 1091,    // ����3G ��
	HK_CLIENT_SINGCAM = 1092,    //�¼��� SINGCAM
	HK_CLIENT_WI = 1093,    //�¼��� SINGCAM
	HK_CLIENT_EASYN = 1094, // ��˳��
	HK_CLIENT_HBA = 1095, // ���ٰ�
	HK_CLIENT_HST = 1096, // ����ͨ
	HK_CLIENT_LY  = 1097,//����
	HK_CLIENT_SAVIT = 1098,//SAVIT ����
	HK_CLIENT_WISYS = 1099,// �ǻ۹�
	HK_CLIENT_TISG = 1100,  // ����
	HK_CLIENT_FRISTHD = 1101, //���ؿͻ�
	HK_CLIENT_MYP2P = 1102,  // �麣����
	HK_CLIENT_P2PCCTV = 1103,//����2
	HK_CLIENT_QEASY = 1104,   //����ʱ
	HK_CLIENT_IELINK = 1105,   //����
	HK_CLIENT_DXXX=1106,//��������
	HK_CLIENT_VIEWCAM=1107,//����henk
	HK_CLIENT_COSY=1108,//wendy �����ͻ�
	HK_CLIENT_CGV=1109,//suki �����ͻ�
	HK_CLIENT_AMS=1110,//����ʱ
	HK_CLIENT_KS=1111,//����
	HK_CLIENT_WEVIEW=1112,// ����
	HK_CLIENT_BLUESTORK=1113,// ��ΰ�۷����ͻ�
	HK_CLIENT_HZD=1114,// ���ڴ�
	HK_CLIENT_HZD1=1115,// ���ڴ�1
	HK_CLIENT_VONO=1116,// Զ���Ƽ�
	HK_CLIENT_BULBCAM=1117,// ������
	HK_CLIENT_PPVIEW=1118,// ������ľ
	HK_CLIENT_EDNET=1119,// lewis
	HK_CLIENT_PROFILE=1120,// greac
};

#define HK_KEY_FROM         "id"		//�豸��/�豸ID,�û���/�û�ID.
#define HK_KEY_FROMNOTE     "fromNote"  //���ͷ���½��
#define HK_KEY_PASSWORD     "Psw"		//�û�����,�豸����
#define HK_KEY_OLDPASSWD    "OldPsw"    //������
#define HK_KEY_TO           "To"		//�����豸ID
#define HK_KEY_TONOTE       "toNote"    //���շ��ĵ�½��
#define HK_KEY_ENCODE       "encode"    //����
#define HK_KEY_ERRORCOD     "errorcod"
#define HK_KEY_PORT         "Prot"		//�˿�
#define HK_NET_BOOTPROTO	"bootproto" //netconfig boot protocol
#define HK_NET_BOOTP_DHCP	"dhcp"		//dhcp configuration
#define HK_NET_BOOTP_STATIC	"static"	//static configuration
#define HK_NET_BOOTP_PPPOE  "PPPoE"     //Huqing 09-08 PPPoE configuration
#define HK_NET_DNS0	        "dns0"	    //dns
#define HK_NET_DNS1	        "dns1"	    //dns
#define HK_KEY_IP			"Ip"		//ip
#define HK_KEY_NETWET		"netwet"	//����
#define HK_KEY_NETMASK		"netmask"	//��������
#define HK_KEY_MACIP        "MacIP"     //Mac IP �����ַ
#define HK_KEY_NEWMACADDR   "NewMac"     //��MAC ��ַ
#define HK_KEY_DEVFLAG      "DevFlag"
#define HK_KEY_CHECKSEQ     "CheckSEQ"
#define HK_KEY_LOSTSEQ      "LostSEQ"
#define HK_KEY_VALUEN		"ValueN"	//������¼��ʱ���key��N��һ����ֵ
#define HK_KEY_ASCODE       "AsCode"
#define HK_KEY_ASPASSWORD	"AsPassword"
#define HK_KEY_ASNAME       "AsName"	//����������
#define HK_KEY_ASTYPE       "AsType"	//������������
#define HK_KEY_COUNT		"Count"		//����
#define HK_KEY_STATUS       "Status"	//״̬
#define HK_KEY_STATE        "status"	//״̬
#define HK_KEY_CALLID       "Callid"
#define HK_KEY_MONEYCARD	"moneycard"	//��ֵ����
#define HK_KEY_IPCDAY		"ipcday"	//ipc�ʺ�����
#define HK_KEY_NETINFO		"netinfo"
#define HK_KEY_PORXYIP		"porxyip"
#define HK_KEY_WIFISTATE	"wifistatus"
#define HK_KEY_INDEX		"index"

#define HK_KEY_PCHOST		"pchost"
#define HK_KEY_PHONEHOST	"phonehost"
#define HK_KEY_PICHOST		"pichost"

//2009/03/25 Vincent add
#define HK_KEY_CONNECT_TYPE			"Connect_Type"
#define HK_KEY_CONNECT_UDP_IP		"Connect_Udp_Ip"
#define HK_KEY_CONNECT_UDP_PORT		"Connect_Udp_Port"
#define HK_KEY_CONNECT_TCP_IP		"Connect_TCP_Ip"
#define HK_KEY_CONNECT_TCP_PORT		"Connect_TCP_Port"
#define HK_KEY_CONNECT_CURRENT		"Connect_Current"

#define HK_KEY_PROXY_TYPE			"Proxy_Type"
#define HK_KEY_PROXY_HTTP_USER		"Proxy_HTTP_User"
#define HK_KEY_PROXY_HTTP_PWD		"Proxy_HTTP_Pwd"
#define HK_KEY_PROXY_HTTP_IP		"Proxy_HTTP_Ip"
#define HK_KEY_PROXY_HTTP_PORT		"Proxy_HTTP_Port"
#define HK_KEY_PROXY_SOCKETS4_USER	"Proxy_SOCKETS4_User"
#define HK_KEY_PROXY_SOCKETS4_PWD	"Proxy_SOCKETS4_Pwd"
#define HK_KEY_PROXY_SOCKETS4_IP	"Proxy_SOCKETS4_Ip"
#define HK_KEY_PROXY_SOCKETS4_PORT	"Proxy_SOCKETS4_Port"
#define HK_KEY_PROXY_SOCKETS5_USER	"Proxy_SOCKETS5_User"
#define HK_KEY_PROXY_SOCKETS5_PWD	"Proxy_SOCKETS5_Pwd"
#define HK_KEY_PROXY_SOCKETS5_IP	"Proxy_SOCKETS5_Ip"
#define HK_KEY_PROXY_SOCKETS5_PORT	"Proxy_SOCKETS5_Port"
#define HK_KEY_PROXY_CURRENT		"Proxy_Current"
////////////////////////////////////////

#define HK_KEY_OPERATOR		  "operator"		//�Ự��ϵ//---rs----
#define HK_KEY_READ			  "read"			//��
#define HK_kEY_WRITE		  "write"			//д
#define HK_KEY_FROMSTR        "from"
#define HK_KEY_TOSTR          "to"
#define HK_KEY_TOUSER         "user"
#define HK_KEY_SIDNUM         "sidNum"
#define HK_KEY_SIDN           "sidN" 
#define HK_KEY_FROMSID        "fromsid"
#define HK_KEY_TOSID          "tosid"
#define HK_KEY_RESTYPEN       "resTypeN"
#define HK_KEY_DEVIDN         "devidN"
#define HK_KEY_NODEN          "nodeN"
#define HK_KEY_RESINFO        "resInfo"            
#define HK_KEY_RESOUCE        "resouce"
#define HK_RES_EXCLUSIVELY    "exclusively"     //0������ ��1���ǹ���
#define HK_KEY_VIDEOINFO	  "videoinfo"

#define HK_KEY_CALLRESN			"callResN"
#define HK_KEY_READADNWRITE		"readAndwrite"		//�ɶ���д
#define HK_KEY_OPN				"opN"				//
#define HK_KEY_FTN				"ftN"				//
#define HK_KEY_CALLN			"callN"
#define HK_KEY_INPUT			"input"
#define HK_KEY_ECHO				"echo"

#define HK_KEY_OUTPUT			"output"
#define HK_KEY_OUTECHO			"outecho"
#define HK_KEY_LANGUAGE			"language"		   //����
#define HK_KEY_RUNFAIL			"RUN_FAIL"
#define HK_KEY_SE_OP			"SessionAct"       // �Ự����
#define HK_VAL_SE_CREATE		"SessionCreate"    // �����Ự
#define HK_VAL_SE_DELETE		"SessionDelete"    // ɾ���Ự
#define HK_KEY_INVITE			"invite:"          //���뷽
#define HK_KEY_ACCPETOR			"Acceptor:"        //���ܷ�
//#define HK_KEY_RESOUCE		"Resouce:"         //��Դ
#define HK_KEY_NAME				"name"             //
#define HK_KEY_FLAG				"Flag"			   //�ɹ�ʧ�ܱ�� 1 �ɹ� 0 ʧ��
#define HK_KEY_UIPARAM			"lParam"		   //UI��ʶ,������,������Ӧ���ʱ��Ҫ������
#define HK_KEY_MAINCMD			"MainCmd"
#define HK_KEY_SUBCMD			"SubCmd"

#define HK_KEY_VERTYPE			"vertype"			//�����汾����.
#define HK_KEY_VERNUM			"verNum"			//�汾��
#define HK_KEY_USERTYPE			"userType"			//�û�����
#define HK_KEY_URL				"url"				//
#define HK_KEY_SUBNUM			"subNum"			//������Ŀ      //
#define HK_KEY_SUBRESOURCE		"subResource"		//����ĳһ��Դ
#define HK_KEY_SUBTYPE			"subType"			//�������� 0 ȫ���ģ� 1 ĳһ�û��Ķ��� 2 ĳһ�豸�Ķ���
#define HK_KEY_SUBVALUE			"subValue"			//��������Ϊ1ʱ����ʾ�����û�����Ϊ2ʱ��ʾ�豸��
#define HK_KEY_EVENT			"event"				//�����¼�
#define HK_EVENT_ONLINE			"eventOnline"		//���ߵĶ���
#define HK_EVENT_OFFLINE		"eventOffline"		//���ߵĶ���
#define HK_EVENT_ANY			"eventAny"
#define HK_KEY_ENFTP            "enftp"
#define HK_KEY_ENFIE            "enie"


#define HK_DEV_TYPE_IPC   2		//IPC�ʺ�
#define HK_DEV_TYPE_SIPC  3		//һ·SIPC�ʺ�
#define HK_DEV_TYPE_4SIPC 9		//��·SIPC�ʺ�
#define HK_DEV_TYPE_8SIPC 11	//��·SIPC�ʺ�
//#define HK_DEV_TYPE_2SIPC 13	//��·SIPC�ʺ�
#define HK_DEV_TYPE_DVR4  4		//��·DVR�ʺ�
#define HK_DEV_TYPE_MJPEG 5		//M_JPEG�ʺ�
#define  HK_DEV_TYPE_H264 7		//h264
#define HK_MRS_TYPE		  21	//¼��������ʺ�

#define HK_DEV_TYPE_DVRN	"4"
#define HK_DEV_TYPE_SIPCN	"3"

#define HK_VAL_H3G21			 "321"   // 3G �豸

#define HK_VAL_HKIPCAMEEX		"322"	 //������Դ����H264
#define HK_VAL_HKIPCAMEFHGM		"323"	 //������Դ����H264

#define HK_VAL_HKIPCAMEHXBQ     "331"    // ������Դ����H264
#define HK_VAL_HKIPCAMEHXGQ     "332"    // ������Դ����H264

#define HK_VAL_HKIPCAMETPSBQ    "351"    // ��������˼����H264
#define HK_VAL_HKIPCAMETPSGQ    "352"    // ��������˼����H264

#define HK_VAL_HKIPCAMEOJTBQ    "381"    // OJ����T H264
#define HK_VAL_HKIPCAMEOJTGQ    "382"    // OJT���� H264

#define HK_VAL_HKIPCAMEMJ       "311"    // MJARM9����

#define HK_VAL_HKIPCAME5350MJ       "312"    // MJARM9����
#define HK_VAL_HKIPCAME5350264       "313"    // MJARM9����


#define HK_VAL_MRSNAME			"hkmrs"			//¼�������
#define HK_VAL_HKIPCAME			"hkipcame"		//�豸

#define HK_VAL_HKDVR			"hkdvr"			//DVR
#define HK_VAL_HKDVRC			"hkdevc"		//DVRC
#define HK_VAL_HKSIPC			"hksipc"
#define HK_VAL_HKSIPCC			"hksipcc"		//SIPCC
#define HK_VAL_H264				"H264"
#define HK_VAL_MPEG4			"MPEG4"
#define HK_VAL_M_JPEG			"M_JPEG"

#define HK_EVENT_RESONLINE		"eventResOnline"		//VOIP���ߵĶ���
#define HK_EVENT_RESOFFLINE		"eventOffOnline"		//VOIP���ߵĶ���
#define HK_EVNET_INVITESTATUS	"eventInviteStatus"		//RS inviteACK�ķ���
#define HK_EVENT_INBAND_DATA_DESC "eventInbandDesc"  
#define HK_EVENT_FOCUS			"eventFocus"
#define HK_EVENT_ALARM			"alarm"					//����
#define HK_EVENT_INFO			"eventInfo"				//�����¼��������Ϣ
#define HK_KEY_HKIDSIZE			"HKIDSIZE"

#define HK_KEY_VPIPE			"HKVPipe"
#define HK_KEY_POS				"Pos"


//////--------------------------new add by ali
#define HK_KEY_EPID           "EPID"
#define HK_KEY_ICMD           "ICMD"
#define HK_KEY_HKID           "HKID"
#define HK_KEY_DSTHKID		  "DSTHKID"
#define HK_KEY_PIPEID         "PIPEID"
#define HK_KEY_NEXTHKID		  "NEXTID"
#define HK_KEY_EPNETINFO	  "EPNETINFO"
#define HK_KEY_HPOTO          "HPOTO"
#define HK_KEY_LPOTO          "LPOTO"
#define HK_KEY_LOCALINFO	  "LOCALINFO"
#define HK_KEY_NATINFO		  "NATINFO"
#define HK_KEY_SEQ			  "SEQ"
#define	HK_KEY_GUARDSEQ       "GUARDSEQ"
#define HK_KEY_TIME			  "TIME"	
#define HK_KEY_LOCALCNT		  "LOCALCNT"
#define HK_KEY_NATCNT		  "NATCNT"
#define HK_KEY_CONTYPE		  "CONTYPE"
#define HK_KEY_NPLAN		  "NPLAN"
#define HK_KEY_MSGTYPE		  "MSGTYPE"
//#define SERVERPROXY 1
//#define SERVERMCU   2
//#define SERVERMRS   4
#define MRS_SERVER    1		//������¼��
#define DEV_SDCARD    2		//SD��ץͼ
#define VIDEO_EMAIL   4		//�����ʼ�
#define ALERT_PHONE	  8		//����֪ͨ
#define ALERT_PLAN	  16	//�����ƻ�
#define HK_KEY_SZIE			 "HKSIZE"
#define HK_KEY_PROI			 "PROI"
#define HK_KEY_LEVEL         "LEVEL"

#define HK_KEY_EMAILCNT        "EPICNT"

#define HK_KEY_LOCALIP        "LOCALIP"
#define HK_KEY_LOCALPORT      "LOCALPORT"
#define HK_KEY_NATIP          "NATIP"
#define HK_KEY_NATPORT        "NATPORT"
#define HK_KEY_MAINID		  "MAINID"
#define  HK_KEY_IPTYPE        "IPTYPE"
#define HK_KEY_ROUNTID        "ROUNTID"
#define HK_KEY_OLDROUNTID     "OLDROUNTID"
#define HK_KEY_DATAID         "DATAID"
#define HK_KEY_CONLAN		  "ConLan"
#define HK_KEY_SERVERIP		  "ServerIP"		//MCU��IP
#define HK_KEY_SERVERPORT     "ServerPort"		//MCU��PORT

#define  HK_KEY_UDPSIZE       "UDPSize"
#define  HK_KEY_UDPPORT       "UDPPort"
#define  HK_KEY_TCPSIZE       "TCPSize"
#define  HK_KEY_TCPPORT       "TCPPort"


#define	HK_KEY_GETWAY		  "GetWay"

#define	HK_KEY_WIFIDATAENC		  "WifiDataEnc"   // AES TKIP
#define	HK_KEY_WIFISAFETYPE		  "WifiSafeType"  // WEP,WAP,WAP2

#define HK_KEY_SDENABLESD        "EnableSD"
#define HK_KEY_SDMOVEREC         "MoveRec"		//�ƶ�����¼��
#define HK_KEY_SDOUTMOVEREC      "OutMoveRec"	//�������¼��
#define HK_KEY_SDAUTOREC         "AutoRec"		//�Զ�¼��
#define HK_EKY_SDLOOPREC         "LoopWrite"	//ѭ��д
#define HK_EKY_SDSPILTE          "Splite"		//�ļ��ָ��С
#define HK_EKY_SDALLSIZE         "AllSize"		//SD�ܴ�С
#define HK_KEY_SDHAVEUSE         "HaveUse"		//�Ѿ�ʹ�ô�С
#define HK_KEY_SDLEFTUSE         "LeftSize"		//���д�С
#define HK_KEY_SDAUDIOMUX        "sdAudioMux"
#define HK_KEY_SDRCQC             "SDRecQC"


#define HK_KEY_VIDEOTFINFO	  "tfinfo"



