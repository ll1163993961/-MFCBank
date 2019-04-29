
// MFCBankDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBank.h"
#include "MFCBankDlg.h"
#include "afxdialogex.h"
#include"AddDlg.h"
#include"ChangeDlg.h"
#include<fstream>
#include<iostream>
#include<list>
#include<string>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCBankDlg 对话框

//设计一个账户的结构体
typedef struct USERSTRUCT
{
	string name;
	string money;
}USER;
//定义一个存储全部账户的链表
list<USER> userlist;

void readuserinfo()
{
	ifstream infile("user.txt");//读文件,相对于程序来说是in
	while (true)//死循环将user.txt中的数据全部读入链表userlist
	{
		USER usertemp;//临时用户实例
		infile >> usertemp.name;
		infile >> usertemp.money;
		if (usertemp.name == "") { break; }
		userlist.push_back(usertemp);
	}
	infile.close();
}

void writeuserinfo()
		{
			ofstream outfile("user.txt");
			list<USER>::iterator iter;
			for (iter = userlist.begin();iter != userlist.end();iter++)
			{

				outfile << iter->name;
				outfile << "	";
				outfile << iter->money;
				outfile << endl;

			}
			outfile.close();
		}

CMFCBankDlg::CMFCBankDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCBANK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}

BEGIN_MESSAGE_MAP(CMFCBankDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCBankDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCBankDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCBankDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCBankDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCBankDlg 消息处理程序

BOOL CMFCBankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	readuserinfo();
	
	m_listctrl.InsertColumn(0, _T("姓名"), LVCFMT_LEFT,250);// 插入第1列的列名
	m_listctrl.InsertColumn(1, _T("资金"), LVCFMT_LEFT,250); // 插入第2列的列名
	list<USER>::iterator iter;
	for (iter = userlist.begin();iter != userlist.end();iter++)
	{
		
		LPCTSTR lpname=iter->name.c_str();
		m_listctrl.InsertItem(0, lpname); // 插入新的一行
		LPCTSTR lpmoney = iter->money.c_str();
		m_listctrl.SetItemText(0, 1, lpmoney);//插入行的第二列
	}

	//m_listctrl.InsertItem(0, _T("张三")); // 插入行
	//m_listctrl.SetItemText(0, 1, _T("888"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCBankDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCBankDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCBankDlg::OnBnClickedButton4()
{
	CAddDlg m_adddlg;
	if (m_adddlg.DoModal() == IDOK)
	{
		USER usertemp;//临时用户实例
		usertemp.name = g_addname;
		usertemp.money = g_addmoney;
		userlist.push_back(usertemp);
		writeuserinfo();	
		CMFCBankDlg::OnBnClickedButton1();
		}
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCBankDlg::OnBnClickedButton3()
{
	string tempname;
	POSITION pos = m_listctrl.GetFirstSelectedItemPosition();
	int nItem = m_listctrl.GetNextSelectedItem(pos);
	tempname = m_listctrl.GetItemText(nItem, 0);
	list<USER>::iterator iter;
	for (iter = userlist.begin();iter != userlist.end();iter++)
	{
		if (iter->name.compare(tempname) == 0)
		{
			g_changename = iter->name.c_str();
			g_changemoney = iter->money.c_str();
			CChangeDlg m_changedlg;
			m_changedlg.m_changename = g_changename;
			m_changedlg.m_changemoney = g_changemoney;
			if (m_changedlg.DoModal() == IDOK)
			{
				iter->name = m_changedlg.m_changename;
				iter->money = m_changedlg.m_changemoney;
				
			}
			writeuserinfo();
			CMFCBankDlg::OnBnClickedButton1();
			break;
		}
	}
	
	// TODO: 在此添加控件通知处理程序代码
}



void CMFCBankDlg::OnBnClickedButton1()
{
	m_listctrl.DeleteAllItems();
	list<USER> m_userlist;
	ifstream infile("user.txt");//读文件,相对于程序来说是in
	while (true)//死循环将user.txt中的数据全部读入链表userlist
	{
		USER usertemp;//临时用户实例
		infile >> usertemp.name;
		infile >> usertemp.money;
		if (usertemp.name == "") { break; }
		m_userlist.push_back(usertemp);
	}
	infile.close();
	list<USER>::iterator iter;
	for (iter = m_userlist.begin();iter != m_userlist.end();iter++)
	{
		LPCTSTR lpname = iter->name.c_str();
		m_listctrl.InsertItem(0, lpname); // 插入新的一行
		LPCTSTR lpmoney = iter->money.c_str();
		m_listctrl.SetItemText(0, 1, lpmoney);//插入行的第二列
		
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCBankDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	string tempname;
	POSITION pos = m_listctrl.GetFirstSelectedItemPosition();
	int nItem = m_listctrl.GetNextSelectedItem(pos);
	tempname=m_listctrl.GetItemText(nItem,0);
	list<USER>::iterator iter;
	for (iter = userlist.begin();iter != userlist.end();iter++)
	{
		if (iter->name.compare(tempname) == 0)
		{
			iter = userlist.erase(iter);
			break;
		}
	}
	writeuserinfo();
	CMFCBankDlg::OnBnClickedButton1();
	MessageBox("删除成功!");
}
