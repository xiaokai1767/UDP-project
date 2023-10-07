
// KaoHeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KaoHe.h"
#include "KaoHeDlg.h"
#include "afxdialogex.h"
#include "tinyXml/tinyxml.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//void  U2G(const char* utf8,char *gb2312)
//{
//	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
//	wchar_t* wstr = new wchar_t[len + 1];
//	memset(wstr, 0, len + 1);
//	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
//	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
//	char buff[100];
//	char* str = new char[len + 1];
//	memset(str, 0, len + 1);
//	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
//	if (wstr)
//	{
//		delete wstr;
//		wstr = NULL;
//	}
//	memcpy(gb2312,str,len+1);
//	delete str;
//
//}
using namespace std;
struct ctrlCft
{

};
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKaoHeDlg �Ի���




CKaoHeDlg::CKaoHeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKaoHeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKaoHeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	DDX_Control(pDX, IDC_LIST1, log);
}

void CKaoHeDlg::Log(CString const &text)
{
	log.AddString(text);
}

BEGIN_MESSAGE_MAP(CKaoHeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CKaoHeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKaoHeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CKaoHeDlg::OnBnClickedButton1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CKaoHeDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CKaoHeDlg ��Ϣ�������

BOOL CKaoHeDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	LoadPage(0);

	CString text;
	for (int i = 0;i<2;i++)
	{
		text.Format(_T("��%02dҳ"),i);
		m_Tab.InsertItem(i,text);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CKaoHeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CKaoHeDlg::OnPaint()
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
HCURSOR CKaoHeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}











bool CKaoHeDlg::LoadPage(int page)
{
	//��ȡexe��ַ���������ģ�����ɶ��˼��
	CString strExePath;
	GetModuleFileName(NULL , strExePath.GetBufferSetLength(MAX_PATH+1) , MAX_PATH);
	strExePath.ReleaseBuffer();
	int nPos = strExePath.ReverseFind(L'\\');
	strExePath = strExePath.Left(nPos);

	//����exe��ַ��xml//////////////////////////////
	CString path;
	path.Format(_T("\\XML\\config%02d.xml"),page+1);
	path = strExePath+path;
	////////////////////////////////////////////////



	TiXmlDocument xmlDoc;
	int ret = xmlDoc.LoadFile(path.GetBuffer(0));
	if(!ret)
	{
		MessageBox("XML��ʧ��");
		return false;
	}

	TiXmlElement* xml_root = xmlDoc.RootElement();
	if (nullptr == xml_root)
	{
		MessageBox("�޸��ڵ�");
		return false;
	}



	//ɾ������ԭ����Ϣ��
	for (auto it = m_nodePool.begin(); it != m_nodePool.end();  it++)
	{
		it->nameS->DestroyWindow();
		delete it->nameS;
		it->p->DestroyWindow();
		delete it->p;
	}
	m_nodePool.clear();



	TiXmlElement* element2 = xml_root->FirstChildElement("FRAME");
	TiXmlElement* element3 = element2->FirstChildElement("CTRL");
	//�����ݱ��������ڽṹ���ڣ�




	while(nullptr != element3)
	{
		int type = atoi(element3->Attribute("type"));
		ctrlCfg info;
		info.type = type;
		info.nameStatic = element3->Attribute("nameStatic");
		info.nameS = new CStatic();
		
		switch (type)
		{
		case 1: info.p = new CEdit();break;
		case 2:
		case 3: 
			{
				info.p = new CComboBox();
				TiXmlElement* element4 = element3->FirstChildElement("enum");
				while (nullptr!=element4)
				{
					CString name = element4->Attribute("name");
					int val = atoi(element4->Attribute("val"));
					info.comboxList.insert(pair<CString,int>(name,val));
					element4 = element4->NextSiblingElement();
				}
			}
			break;
		default:break;
		}
		m_nodePool.push_back(info);
		element3 = element3->NextSiblingElement();
	}
	//xml������ɣ�


	int staticId = 3000;
	int ctrlId = 6000;
	int vDistance = 80; //ԽСԽ����
	int hDistance = 30;  //Խ������Խ����
	int lx = 10+hDistance,ly = 20+vDistance,rx = 150+hDistance , ry= 45+vDistance;	
	int lx2 = 10+hDistance,ly2 = 0+vDistance,rx2 = 100+hDistance , ry2= 18+vDistance;

	for (auto it = m_nodePool.begin();it != m_nodePool.end();it++)
	{
		(it->nameS)->Create(it->nameStatic,WS_CHILD|WS_VISIBLE,CRect(lx2,ly2,rx2,ry2),this,staticId++);
		switch (it->type)
		{
		case 1:((CEdit*)(it->p))->Create(EN_HSCROLL|WS_CHILD|WS_VISIBLE|ES_WANTRETURN|ES_AUTOHSCROLL,	CRect(lx,ly,rx,ry),this,ctrlId++); break;
		case 2: break;
		case 3: 
			{
				((CComboBox*)(it->p))->Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST,	CRect(lx,ly,rx,ry),this,ctrlId++);
				for (auto itCbox = it->comboxList.begin();itCbox != it->comboxList.end();itCbox++)
				{
					((CComboBox*)(it->p))->AddString(itCbox->first);
				}
				((CComboBox*)(it->p))->SetCurSel(0);
			}break;
		default:break;
		}
		ly += 60;
		ry += 60;
		ly2 += 60;
		ry2 += 60;

	}
	xmlDoc.Clear();

 	}





//���η���
void CKaoHeDlg::OnBnClickedButton1()
{
	int del = log.GetCount();
	for (int i = del;i>=0;i--)
	{
		log.DeleteString(i);
	}
	

	CString FaSong[100];
	int i = 0;
	for (int Id = 6000;Id <6000+m_nodePool.size();Id++)
	{
		GetDlgItemText(Id,FaSong[i]);
		i++;
	}
	for (int i = 0;i<100;i++)
	{
		Log(FaSong[i]);
	}
}


//һ������
void CKaoHeDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CKaoHeDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int Index = m_Tab.GetCurSel();
	
	LoadPage(Index);
	//CString text;
	//text.Format(_T("��%02dҳ"),Index);
	//Log(text);
}
