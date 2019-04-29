// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBank.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// CAddDlg �Ի���

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_addname(_T(""))
	, m_addmoney(_T(""))
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_addname);
	DDX_Text(pDX, IDC_EDIT2, m_addmoney);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddDlg ��Ϣ�������


void CAddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	g_addname = m_addname;
	g_addmoney = m_addmoney;
	CDialogEx::OnOK();
}
