// ChangeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBank.h"
#include "ChangeDlg.h"
#include "afxdialogex.h"


// CChangeDlg �Ի���

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


// CChangeDlg ��Ϣ�������


void CChangeDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


BOOL CChangeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
