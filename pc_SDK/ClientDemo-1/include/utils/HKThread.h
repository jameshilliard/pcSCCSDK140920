#ifndef  __HKTHREAD_H__
#define  __HKTHREAD_H__
#include "utils/HKEvent.h"
#include "utils/HKLog.h"
class AFX_EXT_CLASS HKThread
{
public:
	HKThread( void );
	virtual ~HKThread( void );
	bool  StartHKThread( void );
	void  WaitForHKThread( void );
protected:
	virtual void ThreadMain( void ) = 0;
	static 
#ifdef WIN32
	DWORD WINAPI
#else
	void *
#endif
	_ThreadRand( void*pParam )
	{
#ifndef WIN32
		HKLOG( L_INFO,"Start New Thread" );
#endif
		( ( HKThread* )pParam )->_BeginThread();
		return 0;
	}
	void _BeginThread( void );
private:
#ifdef WIN32
	HANDLE	 
#else
	pthread_t
#endif
	m_hThread;
	unsigned long	m_ThreadID;
	HKEvent			m_hEvent;
};
#endif