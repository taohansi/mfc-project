// calculatorDlg.h : 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialog
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_StringInput;
public:
	CString m_StringOutput;
public:
	afx_msg void OnEnChangeEdit2();
public:
	afx_msg void OnBnClickedButtonequation();
	afx_msg void OnBnClickedButtonnumber1();
	afx_msg void OnBnClickedButtonnumber2();
	afx_msg void OnBnClickedButtonnumber3();
	afx_msg void OnBnClickedButtonnumber4();
	afx_msg void OnBnClickedButtondot();
	afx_msg void OnBnClickedButtonnumber5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonnumber9();
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButtonsubscrab();
	afx_msg void OnBnClickedButtontime();
	afx_msg void OnBnClickedButtondivide();
	afx_msg void OnBnClickedButton1parameter();
	afx_msg void OnBnClickedButtonparamater2();
	afx_msg void OnBnClickedButtonlg();
	afx_msg void OnBnClickedButtonln();
	afx_msg void OnBnClickedButtonarc();
	afx_msg void OnBnClickedButtonsin();
	afx_msg void OnBnClickedButtoncos();
	afx_msg void OnBnClickedButtontan();
	afx_msg void OnBnClickedButtonnumber0();
	afx_msg void OnBnClickedButtonnumber7();
	afx_msg void OnBnClickedButtonnumber8();
	afx_msg void OnBnClickedButtonmod();
	afx_msg void OnBnClickedButtondekete();
	afx_msg void OnBnClickedButtonempty();
	afx_msg void OnBnClickedButtonpow();
	afx_msg void OnBnClickedButtonanswer();
	afx_msg void OnBnClickedButton1();
};
