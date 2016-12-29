// ClientDemoDlg.h : ͷ�ļ�
//

#include "hkipc.h"
#pragma once


// CClientDemoDlg �Ի���
class CClientDemoDlg : public CDialog
{
// ����
public:
	CClientDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIENTDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	static void CClientDemoDlg::InitModel( void *userData, int nCmd, char *cBuf, int iLen );
	static void CClientDemoDlg::InitVideo( void *userData, SCC_MideData *pMideData );
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_strUsername;
	CString m_strPassword;
	CString m_strServer;
	CString m_strDevID;

	
	CString m_strACCode;
	afx_msg void OnDestroy();
};
