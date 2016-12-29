#ifndef __HKCRITSECTION_H__
#define __HKCRITSECTION_H__

class AFX_EXT_CLASS HKCritSection
{
public:
	HKCritSection( void );
	virtual ~HKCritSection( void );
	void Lock( void );
	void Unlock( void );
protected:
	void Get();
	void Release();
	void Wait();
	void Notify();
	void NotifyAll();
private:
#ifdef WIN32
	CRITICAL_SECTION    m_CritSection;
#else
	pthread_mutex_t		m_pMutex;
#endif
};
#endif