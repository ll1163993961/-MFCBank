
// MFCBank.h : PROJECT_NAME 应用程序的主头文件
//



#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMFCBankApp: 
// 有关此类的实现，请参阅 MFCBank.cpp
//

class CMFCBankApp : public CWinApp
{
public:
	CMFCBankApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFCBankApp theApp;

extern CString g_addname;
extern CString g_addmoney;
extern CString g_changename;
extern CString g_changemoney;