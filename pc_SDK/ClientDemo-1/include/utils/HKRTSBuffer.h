#pragma once
#include "RTSHead.h"

class AFX_EXT_CLASS HKRTSBuffer
{
public:
	HKRTSBuffer( unsigned short nLevel,RTSHead &rtsHead,char *pData,unsigned short nLen,bool bBlock );
	HKRTSBuffer( unsigned short nLevel,char *pData,unsigned short nLen,bool bBlock );
	virtual ~HKRTSBuffer();

	char *GetRTSBuffer()
	{
		return m_pDataBuf;
	}

	unsigned short GetRTSLevel()
	{
		return m_nLevel;
	}

	unsigned short GetRTSBufferSize()
	{
		return m_nLen;
	}

	RTSHead &GetRTSHead()
	{
		return m_rtsHead;
	}

	bool IsBlock()
	{
		return m_bBlock;
	}
	unsigned short GetType()
	{
		return m_nType;
	}
private:
	unsigned short  m_nLevel;
	unsigned short  m_nType;
	bool			m_bBlock;
	RTSHead			m_rtsHead;
	unsigned short	m_nLen;
	char			*m_pDataBuf;
};