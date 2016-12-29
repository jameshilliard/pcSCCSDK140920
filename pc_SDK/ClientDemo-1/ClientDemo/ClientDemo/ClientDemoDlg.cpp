// ClientDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "ClientDemoDlg.h"
//extern "C" {
//#include "hkipc.h"
//}

#include "utils/h264Dec.h"
#include "utils/HKUtilAPI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "DDPlay.h"

// CClientDemoDlg 对话框

int m_bisLogin;

HK264AndMJDec  *m_pHK264Dec = NULL; // use for h264 decode;
CDDPlay        *m_pDDPlay = NULL;
HWND			g_hWnd = NULL;
unsigned short  g_nW = 0;
unsigned short  g_nH = 0;

CClientDemoDlg::CClientDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDemoDlg::IDD, pParent)
	, m_strUsername(_T("luozhi"))
	, m_strPassword(_T("123456"))
	, m_strServer(_T("www.scc21.com"))
	, m_strDevID(_T("E318409"))
	, m_strACCode(_T("5173"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USENAME, m_strUsername);
	DDX_Text(pDX, IDC_PSW, m_strPassword);
	DDX_Text(pDX, IDC_SERVER, m_strServer);
	DDX_Text(pDX, IDC_DEVID, m_strDevID);
	DDX_Text(pDX, IDC_EDITACCESS, m_strACCode);
}

BEGIN_MESSAGE_MAP(CClientDemoDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CClientDemoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientDemoDlg::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CClientDemoDlg 消息处理程序

BOOL CClientDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_bisLogin=0;

	SetShowMode( USE_YUV );
	m_pHK264Dec = new HK264AndMJDec( CODEC_ID_H264 );
	m_pHK264Dec->open_dec();
	m_pDDPlay =  new CDDPlay();
	g_hWnd = GetDlgItem( IDC_BUTTONVIDEO )->m_hWnd ;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CClientDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CClientDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CClientDemoDlg::OnBnClickedOk()
{
	UpdateData( );
	m_bisLogin = 1;
	sccInitModel( NULL, &InitModel );
	// TODO: 在此添加控件通知处理程序代码
	std::string strUer = CW2A( m_strUsername );
	std::string strPsw = CW2A( m_strPassword );
	std::string strSrv = CW2A( m_strServer );
	sccLogin( (char*)strUer.c_str(),(char*)strPsw.c_str(),(char*)strSrv.c_str() );
	//OnOK();
}

void CClientDemoDlg::InitModel( void *userData, int nCmd, char *cBuf, int iLen )
{
	CString strMsg;
	if ( nCmd==0 && m_bisLogin==1 )
	{	
		strMsg.Format( L"Login successful !" );
		AfxMessageBox( strMsg );
		
	}
	else if( m_bisLogin ==1 )
	{
		strMsg.Format( L"Login successful !" );
		AfxMessageBox( strMsg );
	}
}


//const char *cCallid 呼叫ID
// unsigned int nCID 通道ID号
//char *pDataBuf,	视频数据
//int nSize			视频数据长度
//short nRes		分辨率  参考enumVGAMode定义
//short nEnType		编码类型  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5，6都是H264)  
//short nfilp		翻转类型  1:上下翻转; 2:左右翻转; 3:上下左右翻转
//short nFreamType	帧类型 (H264码流) 2:为 I帧，其他为P帧
//short fragx;		大数据分包组合(3,2,1)三包数据.
//void *userData  

void CClientDemoDlg::InitVideo( void *userData, SCC_MideData *pMideData )
{
	int iLen = pMideData->nSize;
	fprintf( stderr, "data len=%d..\n", iLen );
	
	if( m_pHK264Dec == NULL )
	{
		return;
	}
	BYTE *pYUVVideData = NULL;
	int nWith = 0;
	int nHeight = 0;
	m_pHK264Dec->decode( CODEC_ID_H264,(BYTE*)pMideData->pDataBuf,pMideData->nSize,&pYUVVideData,nWith,nHeight );
	
	if( g_nW == 0 )
	{
		m_pDDPlay->Init( g_hWnd,nWith,nHeight,dptype_yv12 );
	}
	else if( g_nW != nWith || g_nH != nHeight )
	{
		m_pDDPlay->Uninit();
		m_pDDPlay->Init( g_hWnd,nWith,nHeight,dptype_yv12 );
	}
	g_nW = nWith;
	g_nH = nHeight;
	if( m_pDDPlay->Draw( (char*)pYUVVideData ) < 0 )
	{
		m_pDDPlay->Uninit();
		m_pDDPlay->Init( g_hWnd,nWith,nHeight,dptype_yv12 );
		m_pDDPlay->Draw( (char*)pYUVVideData );
	}

}

static char Callid[64];
void CClientDemoDlg::OnBnClickedButton1()
{
	m_bisLogin=0;
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	hk_InitVideo(NULL, &InitVideo );
	std::string strDevID = CW2A( m_strDevID );
	std::string strACCode = CW2A( m_strACCode );
	sccWANDevidCalling( 1, Callid, (char*)strDevID.c_str(), (char*)strACCode.c_str(), HK_VIDEO_H264, 0 );
}

void CClientDemoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	std::string strDevID = CW2A( m_strDevID );
	sccWANCloseCall( (char*)strDevID.c_str(), Callid );
}

void CClientDemoDlg::OnDestroy()
{
	CDialog::OnDestroy();
	if( m_pHK264Dec != NULL )
	{
		delete m_pHK264Dec;
		m_pHK264Dec =NULL;
	}
	if( m_pDDPlay != NULL )
	{
		delete m_pDDPlay;
		m_pDDPlay = NULL;
	}
	// TODO: 在此处添加消息处理程序代码
}
