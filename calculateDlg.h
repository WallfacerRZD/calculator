
// calculateDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CcalculateDlg �Ի���
class CcalculateDlg : public CDialogEx
{
// ����
public:
	CcalculateDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit result;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton21();
};
