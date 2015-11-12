
// SharingWifi.cpp : 定义应用程序的类行为。
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


// CSharingWifiApp 构造

CSharingWifiApp::CSharingWifiApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CSharingWifiApp 对象

CSharingWifiApp theApp;


// CSharingWifiApp 初始化

BOOL CSharingWifiApp::InitInstance()
{
	CWinApp::InitInstance();

	m_pMainWnd = new CSharingWifiDlg();
	m_pMainWnd->CreateEx(0, _T("SHARINGWIFIDLG"), _T(""), WS_POPUPWINDOW | WS_THICKFRAME | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL);
	m_pMainWnd->ShowWindow(SW_SHOW);

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	//return FALSE;
	return TRUE;
}

