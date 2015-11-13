// SharingWifiDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SharingWifi.h"
#include "SharingWifiDlg.h"


// CSharingWifiDlg

IMPLEMENT_DYNAMIC(CSharingWifiDlg, CWnd)

CSharingWifiDlg::CSharingWifiDlg()
{
	m_cImgBtnMin.m_hWnd = NULL;
	m_cImgBtnClose.m_hWnd = NULL;
}

CSharingWifiDlg::~CSharingWifiDlg()
{
}


BEGIN_MESSAGE_MAP(CSharingWifiDlg, CWnd)
	ON_WM_CREATE()
	ON_WM_NCACTIVATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_WM_GETMINMAXINFO()
	ON_WM_HOTKEY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BTNMIN, OnClickedBtnMin)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnClose)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_MESSAGE(WM_NOTIFYICON, OnNotifyicon)
END_MESSAGE_MAP()



// CSharingWifiDlg 消息处理程序




BOOL CSharingWifiDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此添加专用代码和/或调用基类
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	if (GetClassInfoEx(cs.hInstance, cs.lpszClass, &wcex))
	{
		return TRUE;
	}
	wcex.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = AfxWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = cs.hInstance;
	wcex.hIcon = wcex.hIconSm = LoadIcon(cs.hInstance, MAKEINTRESOURCE(IDR_MAINFRAME));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = cs.lpszClass;
	return RegisterClassEx(&wcex);

	//return CWnd::PreCreateWindow(cs);
}


BOOL CSharingWifiDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (VK_ESCAPE == pMsg->wParam)
	{
		OnClose();
	}
	if (VK_RETURN == pMsg->wParam)
	{
		char szWndType[256];
		GetClassName(GetFocus()->m_hWnd, szWndType, 256);
		if (_T("Button") != szWndType)
		{
			pMsg->wParam = VK_TAB;
		}
	}
	if (VK_TAB == pMsg->wParam)
	{
		GetNextDlgTabItem(GetFocus())->SetFocus();
	}

	return CWnd::PreTranslateMessage(pMsg);
}


void CSharingWifiDlg::PostNcDestroy()
{
	// TODO:  在此添加专用代码和/或调用基类
	Shell_NotifyIcon(NIM_DELETE, &m_sNotifyIconData);
	delete this;

	CWnd::PostNcDestroy();
}


int CSharingWifiDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	RegisterHotKey(m_hWnd, 10001, MOD_ALT, 'Q');

	CenterWindow();

	ModifyStyle(WS_THICKFRAME, 0);

	//ShowWindow(SW_SHOW);

	if (NULL == m_cImgBtnMin.m_hWnd)
	{
		m_cImgBtnMin.Create(_T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDC_BTNMIN);
		m_cImgBtnMin.SetImage(lpCreateStruct->hInstance, IDB_BTNMIN, PNG, 1);
	}
	if (NULL == m_cImgBtnClose.m_hWnd)
	{
		m_cImgBtnClose.Create(_T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDC_BTNCLOSE);
		m_cImgBtnClose.SetImage(lpCreateStruct->hInstance, IDB_BTNCLOSE, PNG, 1);
	}

	m_sNotifyIconData.cbSize = sizeof(NOTIFYICONDATA);
	m_sNotifyIconData.hWnd = m_hWnd;
	m_sNotifyIconData.uID = IDR_MAINFRAME;
	m_sNotifyIconData.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	m_sNotifyIconData.uCallbackMessage = WM_NOTIFYICON;
	m_sNotifyIconData.hIcon = (HICON)GetClassLong(m_hWnd, GCL_HICON);
	strcpy_s(m_sNotifyIconData.szTip, 20, _T("wifi"));
	Shell_NotifyIcon(NIM_ADD, &m_sNotifyIconData);

	m_cEdit[0].Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP, CRect(100, 250, 200, 270), this, 10001);
	m_cEdit[0].SetFocus();
	m_cEdit[1].Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP | ES_PASSWORD, CRect(100, 280, 200, 300), this, 10001);

	return 0;
}


BOOL CSharingWifiDlg::OnNcActivate(BOOL bActive)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Invalidate();
	SendMessage(WM_NCPAINT, 0, 0);

	return CWnd::OnNcActivate(bActive);
}


void CSharingWifiDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	ModifyStyle(0, WS_CLIPCHILDREN);

	//HICON hIcon = (HICON)GetClassLong(m_hWnd, GCL_HICON);
	//if (hIcon)
	//{
	//	DrawIconEx(dc.m_hDC, 0, 0, hIcon, 20, 20, 0, 0, DI_NORMAL);
	//}

	CString strText;
	GetWindowText(strText);
	if (!strText.IsEmpty())
	{
		CFont font;
		font.CreateFont(17, 0, 0, 0, 550,
			false, false, false,
			GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, FF_SCRIPT,
			_T("微软雅黑"));
		CFont* pOldFont = dc.SelectObject(&font);
		int nOldBkMode = dc.SetBkMode(TRANSPARENT);

		dc.DrawText(strText, CRect(0, 0, 50, 17), DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_WORD_ELLIPSIS);
	
		dc.SetBkMode(nOldBkMode);
		dc.SelectObject(pOldFont);
	}
}


void CSharingWifiDlg::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	if (m_cImgBtnMin.m_hWnd)
	{
		m_cImgBtnMin.MoveWindow(cx - 21 - 21, 0, 21, 21);
	}
	if (m_cImgBtnClose.m_hWnd)
	{
		m_cImgBtnClose.MoveWindow(cx - 21, 0, 21, 21);
	}
}


void CSharingWifiDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	ShowWindow(SW_HIDE);

	//CWnd::OnClose();
}


void CSharingWifiDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	lpMMI->ptMinTrackSize.x = lpMMI->ptMaxTrackSize.x = lpMMI->ptMaxSize.x = 300;
	lpMMI->ptMinTrackSize.y = lpMMI->ptMaxTrackSize.y = lpMMI->ptMaxSize.y = 400;

	CWnd::OnGetMinMaxInfo(lpMMI);
}


void CSharingWifiDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (IsWindowVisible())
	{
		ShowWindow(SW_HIDE);
	}
	else
	{
		ShowWindow(SW_SHOW);
	}

	CWnd::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CSharingWifiDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);

	CWnd::OnLButtonDown(nFlags, point);
}


void CSharingWifiDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SendMessage(WM_NCLBUTTONDBLCLK, HTCAPTION, 0);

	CWnd::OnLButtonDblClk(nFlags, point);
}


void CSharingWifiDlg::OnClickedBtnMin()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
void CSharingWifiDlg::OnExit()
{
	Shell_NotifyIcon(NIM_DELETE, &m_sNotifyIconData);
	DestroyWindow();
}


afx_msg LRESULT CSharingWifiDlg::OnNotifyicon(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case WM_RBUTTONUP:
	{
						   LPPOINT lpPoint = new tagPOINT();
						   GetCursorPos(lpPoint);	// 得到鼠标位置
						   CMenu menu;
						   menu.CreatePopupMenu();	// 声明一个弹出式菜单
						   menu.AppendMenu(MF_STRING, IDC_EXIT, _T("退出"));	// 增加菜单项“退出”，点击则发送消息给主窗口将程序结束
						   SetForegroundWindow();
						   menu.TrackPopupMenu(TPM_LEFTALIGN, lpPoint->x, lpPoint->y, this);	// 确定弹出式菜单的位置
						   menu.Detach();	// 资源回收
						   menu.DestroyMenu();
						   delete lpPoint;
	}
		break;
	case WM_LBUTTONDOWN:
		SetForegroundWindow();
		ShowWindow(SW_NORMAL);
		break;
	default:
		break;
	}
	return 0;
}
