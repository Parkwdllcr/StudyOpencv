
// CStringAndstringcharDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CStringAndstringchar.h"
#include "CStringAndstringcharDlg.h"
#include "afxdialogex.h"
#include <string>
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCStringAndstringcharDlg 对话框



CCStringAndstringcharDlg::CCStringAndstringcharDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CSTRINGANDSTRINGCHAR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCStringAndstringcharDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCStringAndstringcharDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCStringAndstringcharDlg 消息处理程序

BOOL CCStringAndstringcharDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//区别一下CString,string,char*,
	//<string>,<string.h>,<cstring>
	//char*的最后一个字符'\0'表示字符串的结束标志
	char ch1[12] = "he3lo wrold";//必须是[12],如果是[11]会因为少了空间报错
	char temp[] = "string";
	char* pch1, * pch2 = temp;//如果直接赋值"string"会报const char*的值不能用于初始化char*类型的实体
	char* pch3, * pch4;
	pch3 = &ch1[2];//将ch1[2]的地址赋值给pch3;
	char ch = 'c';
	pch4 = &ch;
	pch1 = ch1;
	//可以得到
	// ch1 = he3lo wrold
	//pch1 = hello wrold
	//pch2 = string
	//pch3 = 3lo wrold
	//*pch3 = 3
	//*pch4 = c

	std::string s1 = "this";
	std::string s2 = std::string("is");
	std::string s3, s4;
	s3 = std::string("a").append("string");
	s4 = s1 + s2 + s3;
	int n = s4.size();
	s4.insert(s4.end() - 7, 1, ' ');
	s4.append(4, 'g');

	std::vector<char> ch1Vec{ '1','2','3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'A' ,'B' };
	std::vector<char>::iterator iter = ch1Vec.begin() + 3;
	int nCount = 0;
	for (;iter != ch1Vec.end();iter++)
	{
		nCount++;
	}
	char* pch12 = "01234";
	std::string str = "56789A";
	CString ctrs1(pch12), ctrs2(str.c_str()), cstr3("Program");
	CString cstr4, cstr5;
	cstr4 = ctrs1 + ctrs2 + cstr3;
	cstr5 = ctrs1 + " " + ctrs2 + " " + cstr3;



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCStringAndstringcharDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCStringAndstringcharDlg::OnPaint()
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
HCURSOR CCStringAndstringcharDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

