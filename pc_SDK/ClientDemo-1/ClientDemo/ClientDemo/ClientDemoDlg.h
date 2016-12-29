// ClientDemoDlg.h : 头文件
//

#include "hkipc.h"
#pragma once


// CClientDemoDlg 对话框
class CClientDemoDlg : public CDialog
{
// 构造
public:
	CClientDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIENTDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
