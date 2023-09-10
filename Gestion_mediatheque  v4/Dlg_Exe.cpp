// Dlg_Exe.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Dlg_Exe.h"
//#include "ivre.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_Exe dialog


CDlg_Exe::CDlg_Exe(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Exe::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Exe)
	m_ref = 0;
	//}}AFX_DATA_INIT
}


void CDlg_Exe::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Exe)
	DDX_Control(pDX, IDC_CMBTITRE, m_titre);
	DDX_Text(pDX, IDC_REF, m_ref);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_Exe, CDialog)
	//{{AFX_MSG_MAP(CDlg_Exe)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_Exe message handlers

void CDlg_Exe::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CExemplaire temp;
	list<CLivre>::iterator i;
	CString str,str1;

	int nIndex = m_titre.GetCurSel();
	if(nIndex!=LB_ERR) m_titre.GetLBText(nIndex,str);
	for(i=ptr_dlgoeuv->At_List_Livre().begin();i!=ptr_dlgoeuv->At_List_Livre().end();i++)
		if(i->AtTitre()==str)
		{
			temp.AtRef()=m_ref;
	//		temp.AtPtr()=(*i);
			list_exe.push_back(temp);
		}
		
	list<CCd>::iterator j;
	for(j=ptr_dlgoeuv->At_List_Cd().begin();j!=ptr_dlgoeuv->At_List_Cd().end();j++)
		if(j->AtTitre()==str)
		{
			temp.AtRef()=m_ref;
			//temp.AtPtr()=(*j);
			list_exe.push_back(temp);
		}

}

BOOL CDlg_Exe::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	list<CLivre>::iterator i;
	list<CCd>::iterator j;
	// TODO: Add extra initialization here
	CComboBox *pComboTitre=(CComboBox*)GetDlgItem(IDC_CMBTITRE);
	
	for(i=ptr_dlgoeuv->At_List_Livre().begin();i!=ptr_dlgoeuv->At_List_Livre().end();i++)
		pComboTitre->AddString(i->AtTitre());

	for(j=ptr_dlgoeuv->At_List_Cd().begin();j!=ptr_dlgoeuv->At_List_Cd().end();j++)
		pComboTitre->AddString(j->AtTitre());

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

list<CExemplaire>& CDlg_Exe::At_List_Exe()
{
	return list_exe;
}
