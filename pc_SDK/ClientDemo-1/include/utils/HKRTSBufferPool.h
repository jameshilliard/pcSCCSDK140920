#pragma  once
#include "HKRTSBuffer.h"
#include "HKAutoLock.h"
#include <list>

typedef std::list<HKRTSBuffer*> HKRTSBufferList;

class AFX_EXT_CLASS HKRTSBufferPool
{
public:
	HKRTSBufferPool();
	virtual ~HKRTSBufferPool();
	virtual void PushRTSBuffer( HKRTSBuffer* pRTSBuffer );
	virtual void PushRTSBufferAtFront( HKRTSBuffer* pRTSBuffer );
	virtual HKRTSBuffer* PopRTSBuffer( void );
	virtual int GetRTSPoolSize(void);
	virtual int GetPoolSize( void );// return real size;
	virtual void ClearRTSPool(void);
private:
	HKRTSBufferList          m_RTSBufferPool;
	HKCritSection            *m_pCritSec;
};