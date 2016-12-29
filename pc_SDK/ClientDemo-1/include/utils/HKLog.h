#pragma  once

#define L_ERR    0
#define L_WARN   1
#define L_INFO   2
#define L_DBG    3


	/* log facility (see syslog(3)) */
#define L_FAC  LOG_DAEMON
	/* priority at which we log */
#define DPRINT_PRIO LOG_DEBUG

#define LOG_NAME "HKLog"


#ifdef __cplusplus
extern "C"
{
#endif

AFX_EXT_CLASS void LOG_Init( const char *name );
AFX_EXT_CLASS void LOG_UNInit();

AFX_EXT_CLASS void LOG_SetLevel( unsigned short nLogLevel );
AFX_EXT_CLASS unsigned short LOG_GetLevel();
AFX_EXT_CLASS int  LOG_IsStderr();
AFX_EXT_CLASS void LOG_Foreground();
AFX_EXT_CLASS void LOG_Background();
AFX_EXT_CLASS void LOG_Print( int level,const char *fn,const char *fu,int nLine,const char* fmt,... );
AFX_EXT_CLASS  void LOG_InitBroadCast( int level );
AFX_EXT_CLASS  void LOG_UnInitBroadCast();
#ifndef WIN32	

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>

AFX_EXT_CLASS void dprint (int level, const char* fct, char* file, int line, char* fmt, ...);

AFX_EXT_CLASS void vlog( int level, const char * fmt,... );

#ifdef _DEBUG
#define LOG_PRINT(level, args... ) dprint( level, __FUNCTION__, __FILE__, __LINE__, ##args )
#else
#define LOG_PRINT(level,fmt, ... ) log_print( level ,fmt, __VA_ARGS__ )
#endif


#define HKLOG(level, fmt, args...)  LOG_Print( level,__FILE__, __FUNCTION__, __LINE__,fmt, ##args );
#else
#define HKLOG( level, fmt, ... ) LOG_Print( level,__FILE__, __FUNCTION__, __LINE__,fmt, __VA_ARGS__);
#endif

#ifdef __cplusplus
}
#endif
