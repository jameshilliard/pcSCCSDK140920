// ClientDemoDlg.cpp : ʵ���ļ�
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

// CClientDemoDlg �Ի���

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


// CClientDemoDlg ��Ϣ�������

BOOL CClientDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_bisLogin=0;

	SetShowMode( USE_YUV );
	m_pHK264Dec = new HK264AndMJDec( CODEC_ID_H264 );
	m_pHK264Dec->open_dec();
	m_pDDPlay =  new CDDPlay();
	g_hWnd = GetDlgItem( IDC_BUTTONVIDEO )->m_hWnd ;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CClientDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


//const char *cCallid ����ID
// unsigned int nCID ͨ��ID��
//char *pDataBuf,	��Ƶ����
//int nSize			��Ƶ���ݳ���
//short nRes		�ֱ���  �ο�enumVGAMode����
//short nEnType		��������  1:MPEG4; 2:M_JPEG  4,5,6 :H264 (4,5��6����H264)  
//short nfilp		��ת����  1:���·�ת; 2:���ҷ�ת; 3:�������ҷ�ת
//short nFreamType	֡���� (H264����) 2:Ϊ I֡������ΪP֡
//short fragx;		�����ݷְ����(3,2,1)��������.
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	hk_InitVideo(NULL, &InitVideo );
	std::string strDevID = CW2A( m_strDevID );
	std::string strACCode = CW2A( m_strACCode );
	sccWANDevidCalling( 1, Callid, (char*)strDevID.c_str(), (char*)strACCode.c_str(), HK_VIDEO_H264, 0 );
}

void CClientDemoDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ˴������Ϣ����������
}
