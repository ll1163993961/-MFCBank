// ChangeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBank.h"
#include "ChangeDlg.h"
#include "afxdialogex.h"


// CChangeDlg 对话框

IMPLEMENT_DYNAMIC(CChangeDlg, CDialogEx)

CChangeDlg::CChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_changename(_T(""))
	, m_changemoney(_T(""))
{

}

CChangeDlg::~CChangeDlg()
{
}

void CChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_changename);
	DDX_Text(pDX, IDC_EDIT2, m_changemoney);
}


BEGIN_MESSAGE_MAP(CChangeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChangeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CChangeDlg 消息处理程序


void CChangeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


BOOL CChangeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
