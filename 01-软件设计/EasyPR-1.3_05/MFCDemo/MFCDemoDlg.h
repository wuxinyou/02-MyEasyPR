
// MFCDemoDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFCDemoDlg dialog
class CMFCDemoDlg : public CDialogEx
{
// Construction
public:
	CMFCDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void plateRecognize();
	void openCamera();
public:
	afx_msg void OnBnClickedSnapbtn();
	afx_msg void OnEnChangeEdit();
	CEdit m_chePai;

private:
	CRect rect;
	CStatic* pStc; //标识图像显示的Picture控件
	CDC* pDC; //视频显示控件设备上下文
	HDC hDC; //视频显示控件设备句柄
	CvCapture* capture; //视频获取结构

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
};
