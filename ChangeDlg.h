#pragma once


// CChangeDlg �Ի���

class CChangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeDlg)

public:
	CChangeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_changename;
	CString m_changemoney;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
