#pragma  once
#include <string>
#include "HKDataBase.h"
#include "HKCmdPacket.h"


AFX_EXT_CLASS char *EncodeBuf( char *pBuf,int nSize,unsigned int nMask,unsigned short nVer );
AFX_EXT_CLASS char *DecodeBuf( char *pBuf,int nSize,unsigned int nMask,unsigned short nVer );
#ifdef WIN32
AFX_EXT_CLASS std::string HKSW2A(std::wstring& strW);
AFX_EXT_CLASS std::string HKSW2A(const wchar_t* szW);
AFX_EXT_CLASS std::wstring HKSA2W(std::string& strA);
AFX_EXT_CLASS std::wstring HKSA2W(const char* szA);
#endif
AFX_EXT_CLASS char *EncodeStr( char *pBuf );
AFX_EXT_CLASS char *DecodeStr( char *pBuf );

AFX_EXT_CLASS void HKSleep( unsigned int nTM );
AFX_EXT_CLASS void HKUSleep( unsigned int nTM );//微秒

AFX_EXT_CLASS bool  GetHKAppPath( wchar_t* szSysFile );
AFX_EXT_CLASS void  SetHKAppPath( wchar_t* szSysFile );

AFX_EXT_CLASS unsigned long HKMSGetTick();
AFX_EXT_CLASS unsigned int   HKMakeTokenID( unsigned short HPid,unsigned short LPid );
AFX_EXT_CLASS unsigned short HKGetHPid( unsigned int SID );
AFX_EXT_CLASS unsigned short HKGetLPid( unsigned int SID );
AFX_EXT_CLASS std::string    HKGetNow();
AFX_EXT_CLASS void HKEqualHostInfo( HKHOSTInfo &rHostInfoA,HKHOSTInfo &rHostInfoB );
AFX_EXT_CLASS bool CheckMacAddr(char *mac_addr_string);
AFX_EXT_CLASS char* skip_spaces(char *s);
AFX_EXT_CLASS int  HKGetTimeZone();
//AFX_EXT_CLASS wchar_t* ASCIItoUNICODE( const char* source );
//AFX_EXT_CLASS char* UNICODEtoASCII( const wchar_t* source );
//AFX_EXT_CLASS wchar_t* ASCIItoUNICODE( int length, const char* source );
//AFX_EXT_CLASS char* UNICODEtoASCII(int length, wchar_t* source);
AFX_EXT_CLASS int conf_get_int(const char* cf, const char* nm);
AFX_EXT_CLASS char* conf_get(const char* cf, const char* nm, char val[], size_t len);
AFX_EXT_CLASS void* conf_set_int(const char* cf, const char* nm, int val);
AFX_EXT_CLASS void* conf_set(const char* cf, const char* nm, const char* val);
typedef void ( *wifiCALLBACK )( unsigned short nWifiState,char *param );
AFX_EXT_CLASS int StartWifiAP( HKFrameHead* hf,wifiCALLBACK wificb );
AFX_EXT_CLASS int ScanWifiAP( HKFrameHead* hf );
AFX_EXT_CLASS void StopWifi();
AFX_EXT_CLASS int GetWifiStatus();
AFX_EXT_CLASS int InitWifiAP();

AFX_EXT_CLASS void  SetShowMode( unsigned short nMode );
AFX_EXT_CLASS short GetShowMode();

AFX_EXT_CLASS void  SetDDVideoDirect( unsigned short _enable_direct );
AFX_EXT_CLASS short GetDDVideoDirect();


enum
{
	WIFIST_NONE = 0,
	WIFIST_FAIL,
	WIFIST_OK,
};
enum
{
        INFACE_NONE = 0,
        INFACE_RAUSB0 = 2,
        INFACE_RA0  = 3
};
#ifdef WIN32
enum
{
	EPROM_NULL,
	EPROM_0x80    =10,
	EPROM_0x1fe0,
};
//UVC
AFX_EXT_CLASS int IS264Iframe(BYTE *buffer, int length);

AFX_EXT_CLASS BOOL UVCOpen();
AFX_EXT_CLASS BOOL UVCClose();
AFX_EXT_CLASS BOOL UVCISValidate( unsigned short nIndex );
AFX_EXT_CLASS BOOL UVCReadMyData( char *pID,char *pPwd,char *psvr );
AFX_EXT_CLASS BOOL UVCReadMyBuf( char *pstrID );
AFX_EXT_CLASS BOOL UVCWriteMyData( char *pstrID );


AFX_EXT_CLASS int SipcRead( char * data,short nSize );

AFX_EXT_CLASS int SipcWriteROM80( char * data );
AFX_EXT_CLASS int SipcReadROM80( char * data );

AFX_EXT_CLASS int SipcWrite1B58( char * data );
AFX_EXT_CLASS int SipcRead1B58( char * data );

AFX_EXT_CLASS int SipcReadROM1FE0( char * data );
AFX_EXT_CLASS int SipcWriteROM1FE0( char * data );
AFX_EXT_CLASS int SipcGetVMCDevCount( );
AFX_EXT_CLASS BOOL SipcAttachUVCDeviceByIndex( int Index );
AFX_EXT_CLASS void SipcDetachUVCDeviceALL();


AFX_EXT_CLASS std::wstring ASCIItoUNICODE( const std::string &str );
AFX_EXT_CLASS std::string  UNICODEtoASCII( const std::wstring &str );

AFX_EXT_CLASS std::string WCharToChar( const std::wstring &wstr );
AFX_EXT_CLASS std::string WCharToUTF8( const std::wstring &wstr );
AFX_EXT_CLASS std::wstring UTF8ToWChar( const std::string &str );
AFX_EXT_CLASS void  GetHKDirectoryW( wchar_t* szSysFile,unsigned short nLen );
AFX_EXT_CLASS void  GetHKMONDirectoryW( wchar_t* szSysFile,unsigned short nLen );

AFX_EXT_CLASS void  GetHKDirectoryA( char* szSysFile,unsigned short nLen );
AFX_EXT_CLASS int  GetHKAPPNameW( wchar_t* szSysFile );
AFX_EXT_CLASS long HKGetFileSize( const char *filename );
enum
{
	DEVDSP_MJ=1,
	DEVDSP_SHD,//单码流
	DEVDSP_DHD//多码流
};

#define	DEVOPT_V		0x01
#define DEVOPT_A		0x02
#define DEVOPT_TF		0x04
#define DEVOPT_PT		0x08
#define DEVOPT_ZOOM		0x10

enum
{
	DEVOPTS_V = 1,
	DEVOPTS_V_A,
	DEVOPTS_V_A_TF, 
	DEVOPTS_V_A_PT,
	DEVOPTS_V_A_TF_PT,
	DEVOPTS_V_A_PTZ,
	DEVOPTS_V_A_TF_PTZ
};

#define DEVIDVAILMINSIZE  9
AFX_EXT_CLASS int  GetDspByID( const char *pDevID );
AFX_EXT_CLASS bool CheckIDOpt( const char *pDevID,unsigned int nOpt );

#endif