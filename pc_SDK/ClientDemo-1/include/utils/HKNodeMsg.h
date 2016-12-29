#pragma  once
#include "RTSHead.h"
#include "HKAutoLock.h"
#include <list>

class AFX_EXT_CLASS HKNodeMsg
{
public:
	HKNodeMsg( unsigned short nMsgType,unsigned int nEPID,unsigned int nDstID,unsigned int nStatus );
	HKNodeMsg( unsigned short nMsgType,unsigned int nEPID,unsigned short nLevel,RTSHead &rtsHead,char *pBuf,unsigned short nLen );
	virtual ~HKNodeMsg();
	char *GetDataBuf(){ return m_pDataBuf; };
	unsigned short GetDataSize(){ return m_nSize; };
	RTSHead &GetRTSHead(){return m_rtsHead;}
	unsigned short GetMsgType(){ return m_nMsgType; };
	unsigned short GetLevel(){ return m_nLevel; };
	unsigned short GetStatus(){ return m_nStatus; };
	unsigned int   GetDstID(){ return m_nDstID; };
	unsigned int   GetEPID(){ return m_nEPID; };

protected:
private:
	char				*m_pDataBuf;
	RTSHead				m_rtsHead;
	unsigned short		m_nSize;
	unsigned short		m_nMsgType;
	unsigned short		m_nLevel;
	unsigned short		m_nStatus;
	unsigned int		m_nDstID;
	unsigned int		m_nEPID;
};

typedef std::list<HKNodeMsg*> HKNodeMsgList;

class AFX_EXT_CLASS HKNodeMsgPool
{
public:
	HKNodeMsgPool();
	virtual ~HKNodeMsgPool();

	virtual void PushNodeMsg( HKNodeMsg* pNodeMsg );
	virtual HKNodeMsg* PopNodeMsg( void );
	virtual bool IsEmpty(void);
	virtual int GetPoolSize( void );// return real size;
	virtual void ClearPool(void);
private:
	HKNodeMsgList				m_NodeMsgPool;
	HKCritSection				*m_pCritSec;
};