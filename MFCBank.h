
// MFCBank.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//



#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCBankApp: 
// �йش����ʵ�֣������ MFCBank.cpp
//

class CMFCBankApp : public CWinApp
{
public:
	CMFCBankApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCBankApp theApp;

extern CString g_addname;
extern CString g_addmoney;
extern CString g_changename;
extern CString g_changemoney;