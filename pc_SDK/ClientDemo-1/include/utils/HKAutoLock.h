#pragma  once

#include "HKCritSection.h"

class AFX_EXT_CLASS HKAutoLock
{
public:
	HKAutoLock( HKCritSection * );
	virtual ~HKAutoLock( void );
private:
	HKCritSection *m_pHKCritSec;
};
