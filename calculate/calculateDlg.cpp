
// calculateDlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include<string>
#include"BigData.h"
#include"MyStack.h"
#include"functions.h"
#include "calculate.h"
#include "calculateDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculateDlg �Ի���



CcalculateDlg::CcalculateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, result);
}

BEGIN_MESSAGE_MAP(CcalculateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculateDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculateDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculateDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON18, &CcalculateDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculateDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON20, &CcalculateDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON17, &CcalculateDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON16, &CcalculateDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON23, &CcalculateDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON14, &CcalculateDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CcalculateDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON27, &CcalculateDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON11, &CcalculateDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculateDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON28, &CcalculateDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON10, &CcalculateDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculateDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculateDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON26, &CcalculateDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculateDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON21, &CcalculateDlg::OnBnClickedButton21)
END_MESSAGE_MAP()


// CcalculateDlg ��Ϣ�������

BOOL CcalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculateDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculateDlg::OnPaint()
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
HCURSOR CcalculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculateDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculateDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "2";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += " + ";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton18()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "( ";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += " )";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton20()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "-";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton17()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "7";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}



void CcalculateDlg::OnBnClickedButton16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "8";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton23()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "9";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "4";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}



void CcalculateDlg::OnBnClickedButton15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "5";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton27()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "6";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += " - ";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "1";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton28()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "3";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	result.SetWindowTextW(_T(""));
	UpdateData(FALSE);
}



void CcalculateDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += " * ";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}



void CcalculateDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += "0";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}



void CcalculateDlg::OnBnClickedButton26()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str, m_str1;
	result.GetWindowText(m_str);
	string str;
	str = CT2A(m_str);
	str = TransforToPostFix(str);
	BigData val = GetPostFixVal(str);
	if (val != BigData("0")) {
		val.data_ = ((val.ispositive == true) ? val.data_ : "-" + val.data_);
	}
	m_str1 = val.data_.c_str();
	m_str = m_str + '\r' + '\n' + " = " + m_str1;
	result.SetWindowTextW(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str = m_str.Left(m_str.GetLength() - 1);
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}


void CcalculateDlg::OnBnClickedButton21()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString m_str;
	result.GetWindowText(m_str);
	m_str += " / ";
	result.SetWindowTextW(_T(""));
	result.ReplaceSel(m_str);
	UpdateData(FALSE);
}
