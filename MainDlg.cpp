#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::dodaj)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::izbrisi)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m.InsertColumn(0, "Title", LVCFMT_LEFT, 150);
	m.InsertColumn(1, "Year", LVCFMT_CENTER, 50);
	m.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::dodaj() {
	CString naslov, godina;
	GetDlgItemText(IDC_EDIT1, naslov);
	GetDlgItemText(IDC_EDIT2, godina);

	if (!naslov.IsEmpty() && !godina.IsEmpty()) {
		int count = m.GetItemCount();
		m.InsertItem(count, naslov);
		m.SetItemText(count, 1, godina);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
}

void MainDlg::izbrisi() {
	int x = m.GetNextItem(-1, LVNI_SELECTED);
	if (x != -1) {
		m.DeleteItem(x);
	}
}