#pragma  once

class AFX_EXT_CLASS HKDataBuffer
{
public:
	HKDataBuffer();
	HKDataBuffer( const char *chData,unsigned short nLen,unsigned short nType = 0 );
	virtual ~HKDataBuffer();

	char *GetDataBuffer()
	{
		return m_pDataBuf;
	}
	unsigned short GetBufferSize()
	{
		return m_nLen;
	}
	unsigned int GetBufferTime()
	{
		return m_nTm;
	}
	unsigned int GetBufferType()
	{
		return m_nType;
	}
private:
	unsigned int   m_nTm;
	unsigned short m_nLen;
	char * m_pDataBuf;	
	unsigned short m_nType;
};