
// SharingWifi.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "SharingWifi.h"
#include "SharingWifiDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSharingWifiApp

BEGIN_MESSAGE_MAP(CSharingWifiApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSharingWifiApp ����

CSharingWifiApp::CSharingWifiApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CSharingWifiApp ����

CSharingWifiApp theApp;


// CSharingWifiApp ��ʼ��

BOOL CSharingWifiApp::InitInstance()
{
	CWinApp::InitInstance();

	m_pMainWnd = new CSharingWifiDlg();
	m_pMainWnd->CreateEx(0, _T("SHARINGWIFIDLG"), _T(""), WS_POPUPWINDOW | WS_THICKFRAME | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL);
	m_pMainWnd->ShowWindow(SW_SHOW);

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	//return FALSE;
	return TRUE;
}

