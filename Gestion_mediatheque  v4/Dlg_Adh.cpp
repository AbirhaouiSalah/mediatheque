// Dlg_Adh.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Dlg_Adh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_Adh dialog


CDlg_Adh::CDlg_Adh(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Adh::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Adh)
	m_adr = _T("");
	m_age = 0;
	m_email = _T("");
	m_mat = 0;
	m_nom = _T("");
	m_prenom = _T("");
	m_find = 0;
	//}}AFX_DATA_INIT

}


void CDlg_Adh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Adh)
	DDX_Control(pDX, IDC_LIST_ADH, m_list_adh);
	DDX_Text(pDX, IDC_ADR, m_adr);
	DDX_Text(pDX, IDC_AGE, m_age);
	DDX_Text(pDX, IDC_EMAIL, m_email);
	DDX_Text(pDX, IDC_MAT, m_mat);
	DDX_Text(pDX, IDC_NOM, m_nom);
	DDX_Text(pDX, IDC_PRENOM, m_prenom);
	DDX_Text(pDX, IDC_SEARCH, m_find);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Adh, CDialog)
	//{{AFX_MSG_MAP(CDlg_Adh)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_PREV, OnPrev)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_LISTER, OnLister)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_Adh message handlers

void CDlg_Adh::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	bool existe=false;
	if(m_mat!=0)
	{
		if(m_nom!="")
		{
			if(m_prenom!="")
			{
				if(m_age!=0)
				{
					if(m_adr!="")
					{
						if(m_email!="")
						{
							for(adh_pos=list_adh.begin();adh_pos!=list_adh.end();adh_pos++)
								if(adh_pos->AtMat()==m_mat)
									existe=true;
							if(existe==false)
							{
								this->Adh_Courant.AtMat()=m_mat;
								this->Adh_Courant.AtNom()=m_nom;
								this->Adh_Courant.AtPrenom()=m_prenom;
								this->Adh_Courant.AtAge()=m_age;
								this->Adh_Courant.AtAdr()=m_adr;
								this->Adh_Courant.AtEmail()=m_email;
	
								this->list_adh.push_back(Adh_Courant);
	
								adh_pos=list_adh.begin();

								m_mat=0;
								m_nom="";
								m_prenom="";
								m_age=0;
								m_adr="";
								m_email="";
							}
							else 
								MessageBox("Désolé il exsite déjà un adhérent avec ce matricule","Avertissment",MB_ICONEXCLAMATION);
						}
						else
							MessageBox("vous dever remplir le champ email","Avertissment",MB_ICONEXCLAMATION);
					}
					else
						MessageBox("vous dever remplir le champ adresse","Avertissment",MB_ICONEXCLAMATION);
				}
				else
					MessageBox("vous dever remplir le champ age","Avertissment",MB_ICONEXCLAMATION);
			}
			else
				MessageBox("vous dever remplir le champ prenom","Avertissment",MB_ICONEXCLAMATION);
		}	
		else
			MessageBox("vous dever remplir le champ nom","Avertissment",MB_ICONEXCLAMATION);
	}
	else
		MessageBox("vous dever remplir le champ matricule","Avertissment",MB_ICONEXCLAMATION);
						
	UpdateData(false);
}

void CDlg_Adh::OnPrev() 
{
	// TODO: Add your control notification handler code here
	if(adh_pos==NULL)
			MessageBox("La liste est vide","Avertissment");
	else
	if(adh_pos!= list_adh.begin())
	{
		adh_pos--;
		m_mat=adh_pos->AtMat();
		m_nom=adh_pos->AtNom();
		m_prenom=adh_pos->AtPrenom();
		m_age=adh_pos->AtAge();
		m_adr=adh_pos->AtAdr();
		m_email=adh_pos->AtEmail();
		UpdateData(false);
	}
	else
		MessageBox("vous êtes sur le premier élément","Avertissment");
}

void CDlg_Adh::OnNext() 
{
	// TODO: Add your control notification handler code here
	
	if(adh_pos==NULL)
			MessageBox("La liste est vide","Avertissment");
	else
		if(adh_pos!=list_adh.end())
		{
			m_mat=adh_pos->AtMat();
			m_nom=adh_pos->AtNom();
			m_prenom=adh_pos->AtPrenom();
			m_age=adh_pos->AtAge();
			m_adr=adh_pos->AtAdr();
			m_email=adh_pos->AtEmail();
			UpdateData(false);
			adh_pos++;
		}
		else	
			MessageBox("vous êtes sur le dernier élément","Avertissment");
}

void CDlg_Adh::OnModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	Adh_Courant.AtNom()=m_nom;
	Adh_Courant.AtPrenom()=m_prenom;
	Adh_Courant.AtAge()=m_age;
	Adh_Courant.AtAdr()=m_adr;
	Adh_Courant.AtEmail()=m_email;
	
	list<CAdherent>::iterator i;
	for(i=list_adh.begin();i!=list_adh.end();i++)
		if(i->AtMat()==Adh_Courant.AtMat())
			*i=Adh_Courant;		
}

void CDlg_Adh::OnDelete() 
{
	// TODO: Add your control notification handler code here
	list_adh.erase(adh_pos);
	adh_pos=list_adh.begin();
	
}

 void CDlg_Adh::OnFind() 
{
	// TODO: Add your control notification handler code here
	bool trouve=false;
UpdateData(true);
	for(adh_pos=list_adh.begin();adh_pos!=list_adh.end();adh_pos++)
	{
		if(adh_pos->AtMat()==m_find)
		{		
			MessageBox(_T ("Veuillez consulter ses informations dans les champs au dessus"), _T ("Adhérent trouvé"), MB_OK);
			m_mat=adh_pos->AtMat();
			m_nom=adh_pos->AtNom();
			m_prenom=adh_pos->AtPrenom();
			m_age=adh_pos->AtAge();
			m_adr=adh_pos->AtAdr();
			m_email=adh_pos->AtEmail();
			trouve=true;
			UpdateData(false);	
		}
	}
	
	if(trouve==false)
	{
		CString string =  _T ("Pas d'adhérent avec ce matricule");
		MessageBox(string, _T ("Inexistant"), MB_ICONEXCLAMATION|MB_OK);
	}
}

void CDlg_Adh::OnLister() 
{
	// TODO: Add your control notification handler code here
	this->rafraichir();
}

BOOL CDlg_Adh::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	adh_pos=NULL;
	for(int i=0;i<6;i++)
		m_list_adh.DeleteColumn(0);

	m_list_adh.InsertColumn(0, "Matricule",	LVCFMT_CENTER,80,	0);
	m_list_adh.InsertColumn(1, "Nom",	LVCFMT_CENTER,70	,0);
	m_list_adh.InsertColumn(2, "Prénom",	LVCFMT_CENTER,70	,0);
	m_list_adh.InsertColumn(3, "Age",	LVCFMT_CENTER,50	,0);
	m_list_adh.InsertColumn(4, "Adresse",	LVCFMT_CENTER,125	,0);
	m_list_adh.InsertColumn(5, "Email",	LVCFMT_CENTER,85	,0);

	// TODO: Add extra initialization here
//	GetDlgItem(IDC_NEXT)->EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_Adh::rafraichir()
{
	CString sMat;
	CString sAge;
	int i;

	m_list_adh.DeleteAllItems();	
	
	for(adh_pos=list_adh.begin(),i=0;adh_pos!=list_adh.end();adh_pos++,i++)
	{
		sMat.Format("%d",adh_pos->AtMat());
		sAge.Format("%d",adh_pos->AtAge());
		m_list_adh.InsertItem(i,sMat);
		m_list_adh.SetItem(i,1,LVIF_TEXT,adh_pos->AtNom(),0,0,0,0);
		m_list_adh.SetItem(i,2,LVIF_TEXT,adh_pos->AtPrenom(),0,0,0,0);
		m_list_adh.SetItem(i,3,LVIF_TEXT,sAge,0,0,0,0);
		m_list_adh.SetItem(i,4,LVIF_TEXT,adh_pos->AtAdr(),0,0,0,0);
		m_list_adh.SetItem(i,5,LVIF_TEXT,adh_pos->AtEmail(),0,0,0,0);
 	}
}
list<CAdherent>& CDlg_Adh::At_List_Adh()
{
	return list_adh;
}

void CDlg_Adh::save(CArchive& ar)
{
	for(adh_pos=list_adh.begin();adh_pos!=list_adh.end();adh_pos++)
		adh_pos->save(ar);
}

void CDlg_Adh::load(CArchive& ar)
{
		for(adh_pos=list_adh.begin();adh_pos!=list_adh.end();adh_pos++)
			adh_pos->load(ar);
}