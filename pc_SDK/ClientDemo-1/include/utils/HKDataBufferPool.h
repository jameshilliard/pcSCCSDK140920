#pragma  once

#include "HKDataBuffer.h"
#include "HKAutoLock.h"
#include <list>

typedef std::list<HKDataBuffer*> HKDataBufList;

class AFX_EXT_CLASS HKDataBufferPool
{
public:
	HKDataBufferPool();
	virtual ~HKDataBufferPool();
	virtual void PushDataBuffer( HKDataBuffer* pDataBuffer );
	virtual HKDataBuffer* PopDataBuffer( void );
	virtual int GetPoolSize(void);
	virtual void ClearPool(void);
private:
	HKDataBufList            m_DataPool;
	HKCritSection            *m_pCritSec;
};