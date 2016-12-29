#pragma  once
#include "utils/HKCritSectionEX.h"

#define  _READ_LOCK			1
#define  _WRITE_LOCK		0
#define  _RWLOCK_TIMEOUT	120000

class AFX_EXT_CLASS HKAutoRWLock
{
public:
	HKAutoRWLock( HKCritSectionEX *csEX,short nXLock );
	virtual ~HKAutoRWLock( void );
protected:
private:
	HKCritSectionEX *m_pCriSecEX;
	short	m_nXLock;
};