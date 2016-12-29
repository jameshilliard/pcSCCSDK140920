#pragma once


#define HK_KEY_IMSERVER	"HKIMServer"



enum _HK_IM_OPERATION_CODE
{
	
	HK_IM_IMREGISTER = 101 ,    //�Լ���IMҵ���ע����Ϣ
	HK_IM_GETBASEINFO = 102,          //��ȡ������Ϣ
	HK_IM_UPDATEBASEINFO = 103,       //�޸Ļ�����Ϣ 
	HK_IM_SETUSERSTATUS,        //�����û�״̬

	HK_IM_GETGRPOUPLIST,        //��ȡ���б�
	HK_IM_GETFRIENDLIST,        //��ȡ�����б�

	HK_IM_FRIENDNOTIFY,         //֪ͨ��������  (һ��)
	HK_IM_SEARCHFRIEND,         //��������
	HK_IM_ADDFRIEND,            //��Ӻ���
	HK_IM_GROUPINGFRIEND,       //���ѷ���
	HK_IM_MODIFYFRIENDNAME,     //�޸ĺ��ѱ�ע����
	HK_IM_DELETEFRIEND,         //ɾ������

	HK_IM_MOREFRIENDONLINE ,    //�����������(��¼ʱ)
	HK_IM_CREATGROUP,           //�½�����
	HK_IM_MODIFYGROUPNAME,      //�޸�����
	HK_IM_DELETEGROUP,          //ɾ����
	//HK_IM_IMINVITE,           //����һ������

	/////////////////
	HK_IM_ADDFRIENDANSER,       //��������֤�ķ���
	HK_IM_ADDFRIENDAUTH,        //��Է���֤�ķ���
	HK_IM_ADDFRIENDACCEPT ,     //��Է���֤��ʱ�򣬷��ظ��û�����ͬ����Ǿܾ�


	HK_IM_INVITE ,              //�����Ự
	HK_IM_INVITERESULT,         //�Է�ͬ����ǽ���
	HK_IM_ACK,
	HK_IM_CANCEL,               //�ر�ĳ����Դ
	HK_IM_CANCELACK,            //�ر�ĳ����Դ�ķ���
	HK_IM_BYE,                  //�ر������Ự
	HK_IM_BYEACK,               //�ر������Ự�ķ���
	HK_IM_FRIENDBASEINFO,       //��ȡ������ϸ��Ϣ

	

	HK_IM_UNREGISTER,           //ע��

	HK_IM_READCONFIGINFO,		//��ȡ������Ϣ
	HK_IM_UPDATECONFIGINFO,		//�޸�and����������Ϣ
	HK_IM_TRANSFERSFILE,        //�����ļ�
	HK_IM_FILERESULT,           //�Է����ܻ��Ǿܾ�
	HK_IM_FILEACK,              //�����ļ���ȷ��

	HK_IM_SUBSCRIBE,            //����
	HK_IM_NOTIFY,               //֪ͨ

	HK_IM_FRIENDOFFLINE,        //�����û�����
	HK_IM_CANCELFILE,           //ȡ���ļ�����  ��������
	HK_IM_BYEFILE,              //�ر��ļ����� �����У�
	HK_IM_UPORREADAUTH,         //��ȡ���޸���֤��ʽ   
	HK_IM_FILETRANSFINISH,      //�ļ�����ɹ�
	HK_IM_NOTIFYFRIENDSTATE,    //֪ͨ����ӵĺ��ѣ����û���״̬
	HK_IM_CANCELREQUST,         //ȡ�����󣨻�û���յ�ACKʱ��ȡ����
	
};

enum _HK_RES_TYPE
{
	HK_RES_TEXT=1,
	HK_RES_AUDIO,
	HK_RES_VIDEO,
	HK_RES_RESHOW,       //���ػ���
	HK_RES_FILE,         //�ļ�����
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

	_SOURCE_INFO & operator = (const  _SOURCE_INFO & rSInfo )
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
#endif


////////idiograph
#define HK_KEY_REALNAME        "realname"
#define HK_KEY_ALIAS           "alias"          //����
#define HK_KEY_IDIOGRAPH       "idiograph"      //����ǩ��
#define HK_KEY_AGE             "age"            //����
#define HK_KEY_SEX             "sex"            //�Ա�
#define HK_KEY_REMARK          "remark"         //��ע

#define HK_KEY_BIRTHDAY        "birthday"       //����
#define HK_KEY_COUNTRY         "country"        //����
#define HK_KEY_PROVINCE        "province"       //ʡ
#define HK_KEY_CITY            "city"           //����
#define HK_KEY_ADDR            "address"        //��ַ
#define HK_KEY_ZIPCODE         "zipcode"        //�ʱ�
#define HK_KEY_MOBILE          "mobile"         //�ֻ�
#define HK_KEY_PHONE           "pohone"         //�绰
#define HK_KEY_EMAIL           "email"          //����
//#define HK_KEY_STATE           "State"        //״̬
#define HK_KEY_GROUPID         "formid"         //��ID
#define HK_KEY_GROUPNAME       "formname"       //����
#define HK_KEY_FRIENDID        "friendid"       //����ID
#define HK_KEY_TYPE            "Type"           //����
#define HK_KEY_LOGINCOUNT      "Count"          //��¼����
#define HK_KEY_AUTHSTATUS      "Authstatus"     //��֤��ʽ 1�Ѿ����� 2 �Է���֤,3������֤,4����,5�ܾ�
#define HK_KEY_PROBLEM         "Problem"        //����
#define HK_KEY_SOLUTION        "Solution"       //��
#define HK_KEY_ACCEPT          "Accept"         //ͬ����Ǿܾ� 1 ͬ�� ��0 �ܾ�
#define HK_KEY_OLDGROUPID      "OldGroupid"                 
#define HK_KEY_FROMRES         "FromRes"                
#define HK_KEY_TORES           "ToRes"
#define HK_KEY_FRIENDNUM       "FriendNum"      //������

#define HK_KEY_CONFIGINFO		"configinfo"	//������Ϣ����

//--------------chat text-----
#define HK_KEY_CHATTEXT			"text"		//��������
#define HK_KEY_CHATTIME			"time"		//����ʱ��
#define HK_KEY_CHATTONAME		"toname"	//����������
#define HK_KEY_CHATFROMNAME		"fromname"	//����������
#define HK_KEY_CHATCOUNT		"rowCount"	//��ǰ�����ܹ��ж�������¼
#define HK_KEY_CHATPAGE			"pageCount"	//�ж���ҳ

//------------file-----------
#define HK_KEY_FILEFROM		 "FromFilePatch"	//�ļ�·��
#define HK_KEY_FILETO		 "ToFilePatch"		//�ļ�·��
//#define HK_KEY_VIDEORES    "videoRes"			//��Ƶ��Դ
//#define HK_KEY_AUDIORES    "audioRes"			//��Ƶ��Դ
#define HK_KEY_RESTYPE		 "resType"			//��Դ����
#define HK_KEY_ALLARRIBUTE   "allAttribute"		//��������
#define HK_KEY_CURRATTRIBUTE "currAttribute"	//��ǰ����

#define HK_KEY_FILESIZE        "fileSize"		//�ļ���С
#define HK_KEY_RESHOWFSID      "reshowFsid"		//����FROM Sid
#define HK_KEY_RESHOWTSID      "reshowTsid"		//���� TO SID




//2009/03/26 Vincent add
//���Ի�����
#define HK_KEY_TYPE_ADVANCED		"Type_Advanced"			//���� �߼�����
#define HK_KEY_TYPE_CONNECT			"Type_Connect"			//���� ����
#define HK_KEY_TYPE_HOTKEY			"Type_Hotkey"			//���� �ȼ�
#define HK_KEY_TYPE_SESSIONSTYLE	"Type_Sessionstyle"		//���� �Ự��ʽ
#define HK_KEY_TYPE_SESSIONSETTING	"Type_Sessionsetting"	//���� �Ự����
#define HK_KEY_TYPE_CALL			"Type_Call"				//���� ����
#define HK_KEY_TYPE_RING			"Type_Ring"				//���� ����
#define HK_KEY_TYPE_TIP				"Type_Tip"				//���� ��ʾ
#define HK_KEY_TYPE_STOPUSER		"Type_Stopuser"			//���� ��ֹ�û�
#define HK_KEY_TYPE_PRIVACY			"Type_Privacy"			//���� ��˽����
#define HK_KEY_TYPE_VIDEODEV		"Type_Videodev"			//���� ��Ƶ�豸
#define HK_KEY_TYPE_SOUNDDEV		"Type_sounddev"			//���� ��Ƶ�豸
#define HK_KEY_TYPE_ROUTINE			"Type_Routine"			//���� ����
#define HK_KEY_TYPE_SYSSETTING		"Type_Syssetting"		//���� ϵͳ����
#define HK_KEY_TYPE_CONTACT			"Type_Contact"			//���� ��ϵ��ʽ
#define HK_KEY_TYPE_BASEINFO		"Type_Baseinfo"			//���� ������Ϣ
#define HK_KEY_TYPE_FONTATTRITUBE	"Type_FontAttribute"	//���� ��������

//�߼�����
#define HK_KEY_VALUE_FILEPATH		"Value_Filepath"		//
#define HK_KEY_VALUE_MSGPATH		"Value_Msgpath"			//
#define HK_KEY_VALUE_VIDEOPATH		"Value_Videopath"		//	
#define HK_KEY_VALUE_DOWNTYPE		"Value_Downtype"		//	

//����
#define HK_KEY_VALUE_HIDEEXIT		"Value_Hideexit"		//
#define HK_KEY_VALUE_STOPMSG		"Value_Stopmsg"			//
#define HK_KEY_VALUE_STOPONLINE		"Value_Stoponline"		//
#define HK_KEY_VALUE_SENDMSG		"Value_Sendmsg"

//�Ự����
#define HK_KEY_VALUE_ALLOWWHO		"Value_Allowwho"		//

//�ȼ�
#define HK_KEY_VALUE_SENDMSG_H		"Value_Sendmsg_h"
#define HK_KEY_VALUE_SENDMSG_E		"Value_Sendmsg_e"
#define HK_KEY_VALUE_FINDUSER_H		"Value_Finduser_h"
#define HK_KEY_VALUE_FINDUSER_E		"Value_Finduser_e"
#define HK_KEY_VALUE_POPCLOSEWND_H	"Value_Popclosewnd_h"
#define HK_KEY_VALUE_POPCLOSEWND_E	"Value_Popclosewnd_e"
#define HK_KEY_VALUE_REFUSECALL_H	"Value_Refusecall_h"
#define HK_KEY_VALUE_REFUSECALL_E	"Value_Refusecall_e"
#define HK_KEY_VALUE_IGNORECALL_H	"Value_Ignorecall_h"
#define HK_KEY_VALUE_IGNORECALL_E	"Value_Ignorecall_e"
#define HK_KEY_VALUE_RESPONSION_H	"Value_Responsion_h"
#define HK_KEY_VALUE_RESPONSION_E	"Value_Responsion_e"
#define HK_KEY_VALUE_HOTENABLE		"Value_Hotenable"

//��ʾ
#define HK_KEY_VALUE_REMINDONLINE_P			"Value_Remindonline_p"
#define HK_KEY_VALUE_REMINDTEXTSESSION_P	"Value_Remindtextsession_p"
#define HK_KEY_VALUE_REMINDSENDFILE_P		"Value_Remindsendfile_p"
#define HK_KEY_VALUE_REMINDBIRTHDAY_P		"Value_Remindbirthday_p"
#define HK_KEY_VALUE_REMINDCONTACTINFO_P	"Value_Remindcontactinfo_p"
#define HK_KEY_VALUE_REMINDVIDEO_P			"Value_Remindvideo_p"
#define HK_KEY_VALUE_REMINDRING_P			"Value_Remindring_p"
#define HK_KEY_VALUE_REMINDONLINE_E			"Value_Remindonline_e"
#define HK_KEY_VALUE_REMINDTEXTSESSION_E	"Value_Remindtextsession_e"
#define HK_KEY_VALUE_REMINDSENDFILE_E		"Value_Remindsendfile_e"
#define HK_KEY_VALUE_REMINDBIRTHDAY_E		"Value_Remindbirthday_e"
#define HK_KEY_VALUE_REMINDCONTACTINFO_E	"Value_Remindcontactinfo_e"
#define HK_KEY_VALUE_REMINDVIDEO_E			"Value_Remindvideo_e"
#define HK_KEY_VALUE_REMINDRING_E			"Value_Remindring_e"

//�Ự��ʽ
#define HK_KEY_VALUE_STYLEFACE		"Value_Styleface"			//��ʾ����
#define HK_KEY_VALUE_STYLEACTFACE	"Value_Styleactface"		//��ʾ������
#define HK_KEY_VALUE_STYLETIME		"Value_Styletime"			//�ڼ�ʱ��Ϣ����ʾʱ��

//����
#define HK_KEY_VALUE_CALLALLOWWHO		"Value_Callallowwho"		//������˺���
#define HK_KEY_VALUE_CALLAUTORESPONSE	"Value_Callautoresponse"	//�Զ�Ӧ�����
#define HK_KEY_VALUE_CALLAUTOVIDEO		"Value_Callautovideo"		//�Զ����ҵ���Ƶ
#define HK_KEY_VALUE_CALLAUTOVIDEOED	"Value_Callautovideoed"		//�Զ������û�����Ƶ����

//����
#define HK_KEY_CONNECT_TYPE		"Connect_Type"
#define HK_KEY_CONNECT_UDP_IP	"Connect_Udp_Ip"
#define HK_KEY_CONNECT_UDP_PORT	"Connect_Udp_Port"
#define HK_KEY_CONNECT_TCP_IP	"Connect_TCP_Ip"
#define HK_KEY_CONNECT_TCP_PORT	"Connect_TCP_Port"
#define HK_KEY_CONNECT_CURRENT	"Connect_Current"

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

//��ϵ��Ϣ
#define HK_KEY_CONTACT_COUNTRY		"Value_Contactcountry"		//����
#define HK_KEY_CONTACT_PROVINCE		"Value_Contactprovince"		//ʡ
#define HK_KEY_CONTACT_CITY			"Value_Contactcity"			//����
#define HK_KEY_CONTACT_POST			"Value_Contactpost"			//�ʱ�
#define HK_KEY_CONTACT_ADDR			"Value_Contactaddr"			//��ַ
#define HK_KEY_CONTACT_TEL			"Value_Contacttel"			//�绰
#define HK_KEY_CONTACT_MOBILE		"Value_Contactmobile"		//�ֻ�
#define HK_KEY_CONTACT_EMAIL		"Value_Contactemail"		//����

//��������
#define HK_KEY_VALUE_FONTSIZE		"Value_Fontsize"
#define HK_KEY_VALUE_FONTMASK		"Value_Fontmask"
#define HK_KEY_VALUE_FONTEFFECTS	"Value_Fonteffects"
#define HK_KEY_VALUE_FONTHEIGHT		"Value_Fontheight"
#define HK_KEY_VALUE_FONTOFFSET		"Value_Fontoffset"
#define HK_KEY_VALUE_FONTCOLOR		"Value_Fontcolor"
#define HK_KEY_VALUE_FONTCHARSET	"Value_Fontcharset"
#define HK_KEY_VALUE_FONTPF			"Value_Fontpf"
#define HK_KEY_VALUE_FONTFACENAME	"Value_Fontfacename"

//��˽
#define HK_KEY_PRIVACY_TIMELONG		"Value_Privacytimelong"			//�Ự��Ϣ����ʱ��
#define HK_KEY_PRIVACY_SHOWMYSTATE	"Value_Privacyshowmystate"		//�Ƿ���ʾ�ҵ�״̬

//ϵͳͼ�������
#define HK_SYSIMAGE_ERROR		"sys_image_error"		//û�н��յ�ͼƬʱ��ʾ��ͼƬ������
#define HK_SYSIMAGE_WAIT		"sys_image_wait"		//���ڽ���ͼƬʱ��ʾ�ĵȴ�ͼƬ������
