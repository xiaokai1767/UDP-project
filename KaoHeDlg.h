
// KaoHeDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <map>
#include <vector>
using namespace std;
struct ctrlCfg
{
	CWnd *p;
	int type;
	CStatic *nameS;
	CString nameStatic;
	map<CString,int> comboxList;
};
// CKaoHeDlg 对话框
class CKaoHeDlg : public CDialogEx
{
// 构造
public:
	CKaoHeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_KAOHE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	void Log(CString const &text);
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	bool LoadPage(int page);
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
private:
	CTabCtrl m_Tab;
	CListBox log;
	vector<ctrlCfg> m_nodePool;
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
