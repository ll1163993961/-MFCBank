#pragma once


// CChangeDlg 对话框

class CChangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeDlg)

public:
	CChangeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_changename;
	CString m_changemoney;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
