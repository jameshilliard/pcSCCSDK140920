#pragma once
#ifndef WIN32
#include <pthread.h>
#endif

class AFX_EXT_CLASS HKCritSectionEX
{
public:
	HKCritSectionEX();
	virtual ~HKCritSectionEX();
	void		RLock( unsigned int nTimeOut = 120000 );
	void		UNRLock();
		
	void		WLock( unsigned int nTimeOut = 120000 );
	void		UNWLock();

protected:
private:
#ifdef WIN32
	bool				m_wPriority;
	
	DWORD				m_ReadCount;   
	DWORD	 			m_ReadWaiting;

	DWORD				m_nWriteCount;
	DWORD				m_nWriteWaiting;

	HANDLE				m_readEvent; 
	HANDLE				m_writeEvent;

	CRITICAL_SECTION	m_rwcs;
#else
	pthread_rwlock_t	m_rwlock_;
#endif

};
