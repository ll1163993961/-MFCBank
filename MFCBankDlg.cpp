
// MFCBankDlg.cpp : ʵ���ļ�
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


// CMFCBankDlg �Ի���

//���һ���˻��Ľṹ��
typedef struct USERSTRUCT
{
	string name;
	string money;
}USER;
//����һ���洢ȫ���˻�������
list<USER> userlist;

void readuserinfo()
{
	ifstream infile("user.txt");//���ļ�,����ڳ�����˵��in
	while (true)//��ѭ����user.txt�е�����ȫ����������userlist
	{
		USER usertemp;//��ʱ�û�ʵ��
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


// CMFCBankDlg ��Ϣ�������

BOOL CMFCBankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	readuserinfo();
	
	m_listctrl.InsertColumn(0, _T("����"), LVCFMT_LEFT,250);// �����1�е�����
	m_listctrl.InsertColumn(1, _T("�ʽ�"), LVCFMT_LEFT,250); // �����2�е�����
	list<USER>::iterator iter;
	for (iter = userlist.begin();iter != userlist.end();iter++)
	{
		
		LPCTSTR lpname=iter->name.c_str();
		m_listctrl.InsertItem(0, lpname); // �����µ�һ��
		LPCTSTR lpmoney = iter->money.c_str();
		m_listctrl.SetItemText(0, 1, lpmoney);//�����еĵڶ���
	}

	//m_listctrl.InsertItem(0, _T("����")); // ������
	//m_listctrl.SetItemText(0, 1, _T("888"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCBankDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCBankDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCBankDlg::OnBnClickedButton4()
{
	CAddDlg m_adddlg;
	if (m_adddlg.DoModal() == IDOK)
	{
		USER usertemp;//��ʱ�û�ʵ��
		usertemp.name = g_addname;
		usertemp.money = g_addmoney;
		userlist.push_back(usertemp);
		writeuserinfo();	
		CMFCBankDlg::OnBnClickedButton1();
		}
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void CMFCBankDlg::OnBnClickedButton1()
{
	m_listctrl.DeleteAllItems();
	list<USER> m_userlist;
	ifstream infile("user.txt");//���ļ�,����ڳ�����˵��in
	while (true)//��ѭ����user.txt�е�����ȫ����������userlist
	{
		USER usertemp;//��ʱ�û�ʵ��
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
		m_listctrl.InsertItem(0, lpname); // �����µ�һ��
		LPCTSTR lpmoney = iter->money.c_str();
		m_listctrl.SetItemText(0, 1, lpmoney);//�����еĵڶ���
		
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCBankDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	MessageBox("ɾ���ɹ�!");
}
