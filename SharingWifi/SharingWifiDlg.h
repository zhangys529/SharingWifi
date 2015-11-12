#pragma once
#include "ImageButton.h"

// CSharingWifiDlg

class CSharingWifiDlg : public CWnd
{
	DECLARE_DYNAMIC(CSharingWifiDlg)

public:
	CSharingWifiDlg();
	virtual ~CSharingWifiDlg();

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void PostNcDestroy();
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnClickedBtnMin();
	afx_msg void OnClickedBtnClose();
	afx_msg void OnExit();
	afx_msg LRESULT OnNotifyicon(WPARAM wParam, LPARAM lParam);

private:
	CImageButton m_cImgBtnMin;
	CImageButton m_cImgBtnClose;
	NOTIFYICONDATA m_sNotifyIconData;
};


