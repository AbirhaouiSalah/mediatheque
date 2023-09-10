// Dlg_EmpRest.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Dlg_EmpRest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_EmpRest dialog


CDlg_EmpRest::CDlg_EmpRest(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_EmpRest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_EmpRest)
	m_rest_exe = _T("");
	//}}AFX_DATA_INIT
}


void CDlg_EmpRest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_EmpRest)
	DDX_Control(pDX, IDC_LISTExe, m_list_adh);
	DDX_Control(pDX, IDC_COMB_EMPL, m_empl);
	DDX_Control(pDX, IDC_COMB_EMPC, m_empc);
	DDX_Control(pDX, IDC_COM_ADH, m_mat_adh);
	DDX_CBString(pDX, IDC_COMB_RES, m_rest_exe);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_EmpRest, CDialog)
	//{{AFX_MSG_MAP(CDlg_EmpRest)
	ON_BN_CLICKED(IDC_REST, OnRest)
	ON_CBN_SELCHANGE(IDC_COM_ADH, OnSelchangeComAdh)
	ON_BN_CLICKED(IDC_EMPRUNTL, OnEmpruntl)
	ON_BN_CLICKED(IDC_EMPRUNTC, OnEmpruntc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_EmpRest message handlers


BOOL CDlg_EmpRest::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString str;
	list<CAdherent>::iterator i;
	list<CLivre>::iterator l;
	list<CCd>::iterator c;
	
	CComboBox *pComboMat=(CComboBox*)GetDlgItem(IDC_COM_ADH);
	for(i=ptr_dlgAdh->At_List_Adh().begin();i!=ptr_dlgAdh->At_List_Adh().end();i++)
	{
		str.Format("%d",i->AtMat());
		pComboMat->AddString(str);
	}

	CComboBox *pComboEmpc=(CComboBox*)GetDlgItem(IDC_COMB_EMPC);
	CComboBox *pComboEmpl=(CComboBox*)GetDlgItem(IDC_COMB_EMPL);
	
	for(l=ptr_dlgoeuv->At_List_Livre().begin();l!=ptr_dlgoeuv->At_List_Livre().end();l++)
		pComboEmpl->AddString(l->AtTitre());

	for(c=ptr_dlgoeuv->At_List_Cd().begin();c!=ptr_dlgoeuv->At_List_Cd().end();c++)
		pComboEmpc->AddString(c->AtTitre());
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_EmpRest::OnSelchangeComAdh() 
{
	// TODO: Add your control notification handler code here
	CString str,sMat;
	list<CAdherent>::iterator i;
	vector<CExemplaire>::iterator j;
	CComboBox *pComboMat=(CComboBox*)GetDlgItem(IDC_COM_ADH);
	int nIndex=pComboMat->GetCurSel();
	if(nIndex!=LB_ERR)
		pComboMat->GetLBText(nIndex,str);
	CComboBox *pComboRest=(CComboBox*)GetDlgItem(IDC_COMB_RES);

	pComboRest->Clear();
//	m_list_adh.Delete();
	
	for(i=ptr_dlgAdh->At_List_Adh().begin();i!=ptr_dlgAdh->At_List_Adh().end();i++)
	{	
		sMat.Format("%d",i->AtMat());
		if(sMat==str)
		{	
			for(j=i->AtExemplaire().begin();j!=i->AtExemplaire().end();j++)
			{
				pComboRest->AddString(j->AtPtr().AtTitre());
				m_list_adh.AddString(j->AtPtr().AtTitre());
			}
		}
	}
}

void CDlg_EmpRest::OnRest() 
{
	// TODO: Add your control notification handler code here
	CString str,str1,str2,sMat;
	list<CAdherent>::iterator i;
	vector<CExemplaire>::iterator j;
	list<CLivre>::iterator k;
	list<CCd>::iterator l;
	CExemplaire temp;
	CComboBox *pComboMat=(CComboBox*)GetDlgItem(IDC_COM_ADH);
	CComboBox *pComboRest=(CComboBox*)GetDlgItem(IDC_COMB_RES);
	int nIndex=pComboMat->GetCurSel();
	if(nIndex!=LB_ERR)
		pComboMat->GetLBText(nIndex,str);

	int nIndex2=pComboRest->GetCurSel();
	if(nIndex2!=LB_ERR)
		pComboMat->GetLBText(nIndex,str1);
	for(i=ptr_dlgAdh->At_List_Adh().begin();i!=ptr_dlgAdh->At_List_Adh().end();i++)
	{	
		sMat.Format("%d",i->AtMat());
		if(sMat==str)
		{	
			for(j=i->AtExemplaire().begin();j!=i->AtExemplaire().end();j++)
			{
				str2.Format("%d",j->AtPtr().AtTitre());
				if(str2==str1)
				{
					temp.AtRef()=j->AtRef();
					temp.AtPtr()=j->AtPtr();
					i->RemoveExemplaire(*j);
					for(k=ptr_dlgoeuv->At_List_Livre().begin();k!=ptr_dlgoeuv->At_List_Livre().end();k++)
						if(k->AtTitre()==temp.AtPtr().AtTitre())
							k->AtExemplaire().push_back(temp);
					for(l=ptr_dlgoeuv->At_List_Cd().begin();l!=ptr_dlgoeuv->At_List_Cd().end();l++)
						if(l->AtTitre()==temp.AtPtr().AtTitre())
							l->AtExemplaire().push_back(temp);					
				}
			}
		}
	}
}

void CDlg_EmpRest::OnEmpruntl() 
{
	// TODO: Add your control notification handler code here
	CComboBox *pComboMat=(CComboBox*)GetDlgItem(IDC_COM_ADH);
	CComboBox *pComboLivre=(CComboBox*)GetDlgItem(IDC_COMB_EMPL);
	int nIndex=pComboMat->GetCurSel();
	int nIndex2=pComboLivre->GetCurSel();
	CString str,sMat,sLiv;
	list<CAdherent>::iterator i;
	list<CLivre>::iterator j;
	
	CExemplaire temp;
	if(nIndex!=LB_ERR)
		pComboMat->GetLBText(nIndex,str);

	for(i=ptr_dlgAdh->At_List_Adh().begin();i!=ptr_dlgAdh->At_List_Adh().end();i++)
	{
		sMat.Format("%d",i->AtMat());
		if(sMat==str)
		{
			if(nIndex2!=LB_ERR)
				pComboLivre->GetLBText(nIndex2,sLiv);
			for(j=ptr_dlgoeuv->At_List_Livre().begin();j!=ptr_dlgoeuv->At_List_Livre().end();j++)
				if(j->AtTitre()==sLiv)
				{	
					if(j->AtExemplaire().empty()==false)
					{
						temp.AtRef()=j->AtExemplaire().back().AtRef();
						temp.AtPtr()=j->AtExemplaire().back().AtPtr();
						j->AtExemplaire().pop_back();
						i->AddExemplaire(temp);
					}
					else
						MessageBox("Cet oeuvre n'est plus au stock","Avertissment",MB_ICONEXCLAMATION);
				}
		}
	}

}

void CDlg_EmpRest::OnEmpruntc() 
{
	// TODO: Add your control notification handler code here
	CComboBox *pComboMat=(CComboBox*)GetDlgItem(IDC_COM_ADH);
	CComboBox *pComboCd=(CComboBox*)GetDlgItem(IDC_COMB_EMPC);
	int nIndex=pComboMat->GetCurSel();
	int nIndex2=pComboCd->GetCurSel();
	CString str,sMat,sCd;
	list<CAdherent>::iterator i;
	list<CCd>::iterator j;
	
	CExemplaire temp;
	if(nIndex!=LB_ERR)
		pComboMat->GetLBText(nIndex,str);

	for(i=ptr_dlgAdh->At_List_Adh().begin();i!=ptr_dlgAdh->At_List_Adh().end();i++)
	{
		sMat.Format("%d",i->AtMat());
		if(sMat==str)
		{
			if(nIndex2!=LB_ERR)
				pComboCd->GetLBText(nIndex2,sCd);
			for(j=ptr_dlgoeuv->At_List_Cd().begin();j!=ptr_dlgoeuv->At_List_Cd().end();j++)
				if(j->AtTitre()==sCd)
				{	
					if(j->AtExemplaire().empty()==false)
					{
						temp.AtRef()=j->AtExemplaire().back().AtRef();
						temp.AtPtr()=j->AtExemplaire().back().AtPtr();
						j->AtExemplaire().pop_back();
						i->AddExemplaire(temp);
					}
					else
						MessageBox("Cet oeuvre n'est plus au stock","Avertissment",MB_ICONEXCLAMATION);
				}
		}
	}
}
