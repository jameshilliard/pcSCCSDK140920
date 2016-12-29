#pragma  once

#ifndef  WIN32
#include <pthread.h>
#endif

class AFX_EXT_CLASS HKEvent
{
public:
	HKEvent( bool bManualReset = false );
	virtual ~HKEvent();
	void SetHKEvent();
	bool WaitHKEvent( unsigned int nlTimeOut ); // 0 s
	void ReSetHKEvent();

private:
bool   m_bReset;
#ifdef WIN32
	HANDLE m_hEvent;
#else
	pthread_mutex_t m_mutex_t;
	pthread_cond_t	m_cond_t;
	bool			m_bSignaled;
#endif
};