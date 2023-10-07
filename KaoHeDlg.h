
// KaoHeDlg.h : ͷ�ļ�
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
// CKaoHeDlg �Ի���
class CKaoHeDlg : public CDialogEx
{
// ����
public:
	CKaoHeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_KAOHE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	void Log(CString const &text);
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
