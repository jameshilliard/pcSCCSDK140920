#pragma once

enum _HK_AAA_OPERATION_CODE
{
	HK_SYS_UNREGISTER=33, //ע��
	HK_SYS_DISCONNECT,    //�������磬SYS�˳�
	
};

#define HK_KEY_NUMBER		"Number"
//#define HK_KEY_ASCODE     "AsCode"		//����������
//#define HK_KEY_ASTYPE     "AsType"		//������������
//#define HK_KEY_ASNAME     "AsName"		//����������
//#define HK_KEY_ASPASSWORD "AsPassword"	//����������
#define HK_KEY_INNERCODE	"InnerCode"   
#define HK_KEY_RESULT       "Result"
#define HK_KEY_SERVERIP     "ServerIP"		//MCU��IP
#define HK_KEY_SERVERPORT   "ServerPort"	//MCU��PORT
#define HK_KEY_MCUNUM       "McuNum"
#define HK_KEY_MCUIPN       "McuIpN"
#define HK_KEY_MCUPORTN     "McuPortN"

#define HK_KEY_CAUSE        "cause"			 //��½ʧ�ܵ�ԭ��

#define HK_KEY_MCUPOTON     "McuPotoN"