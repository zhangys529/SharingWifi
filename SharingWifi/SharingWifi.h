
// SharingWifi.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSharingWifiApp: 
// �йش����ʵ�֣������ SharingWifi.cpp
//

class CSharingWifiApp : public CWinApp
{
public:
	CSharingWifiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSharingWifiApp theApp;