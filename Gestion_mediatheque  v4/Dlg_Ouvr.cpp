// Dlg_Ouvr.cpp : implementation file
//

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Dlg_Ouvr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_Ouvr dialog


CDlg_Ouvr::CDlg_Ouvr(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Ouvr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Ouvr)
	m_artiste = _T("");
	m_auteur = _T("");
	m_isbn = 0;
	m_resume = _T("");
	m_titre = _T("");
	m_duree = 0;
	m_find = _T("");
	m_lref1 = 0;
	m_lref2 = 0;
	m_lref3 = 0;
	m_cref1 = 0;
	m_cref2 = 0;
	m_cref3 = 0;
	//}}AFX_DATA_INIT
}


void CDlg_Ouvr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Ouvr)
	DDX_Control(pDX, IDC_LIST_C, m_liste_cd);
	DDX_Control(pDX, IDC_LIST_L, m_liste_livre);
	DDX_Text(pDX, IDC_ARTISTE, m_artiste);
	DDX_Text(pDX, IDC_AUTEUR, m_auteur);
	DDX_Text(pDX, IDC_ISBN, m_isbn);
	DDX_Text(pDX, IDC_RESUME, m_resume);
	DDX_Text(pDX, IDC_TITRE, m_titre);
	DDX_Text(pDX, IDC_DUREE, m_duree);
	DDX_Text(pDX, IDC_FIND, m_find);
	DDX_Text(pDX, IDC_LREF1, m_lref1);
	DDX_Text(pDX, IDC_LREF2, m_lref2);
	DDX_Text(pDX, IDC_LREF3, m_lref3);
	DDX_Text(pDX, IDC_CREF1, m_cref1);
	DDX_Text(pDX, IDC_CREF2, m_cref2);
	DDX_Text(pDX, IDC_CREF3, m_cref3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_Ouvr, CDialog)
	//{{AFX_MSG_MAP(CDlg_Ouvr)
	ON_BN_CLICKED(IDC_SUPP, OnSupp)
	ON_BN_CLICKED(IDC_MODIF, OnModif)
	ON_BN_CLICKED(IDC_AJOUT, OnAjout)
	ON_BN_CLICKED(IDC_VALID, OnValid)
	ON_BN_CLICKED(IDC_LISTER, OnLister)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_BN_CLICKED(IDC_PREV, OnPrev)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_NEXTC, OnNextc)
	ON_BN_CLICKED(IDC_PREVC, OnPrevc)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_MODIFC, OnModifc)
	ON_BN_CLICKED(IDC_SUPPC, OnSuppc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_Ouvr message handlers

void CDlg_Ouvr::OnSupp() 
{
	// TODO: Add your control notification handler code here
	list_livre.erase(livre_pos);
	livre_pos=list_livre.begin();
}

void CDlg_Ouvr::OnModif() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_titre!="")
	{
		livre_courant.AtResume()=m_resume;
		livre_courant.AtIsbn()=m_isbn;
		livre_courant.AtAuteur()=m_auteur;

		for(livre_pos=list_livre.begin();livre_pos!=list_livre.end();livre_pos++)
			if(livre_pos->AtTitre()==livre_courant.AtTitre())
				*livre_pos=livre_courant;
	}
	else 
		MessageBox("Vous devez préciser un livre","Avertissment",MB_ICONEXCLAMATION);

}

void CDlg_Ouvr::OnAjout() 
{
	// TODO: Add your control notification handler code here
	
	CButton *pRadio=(CButton*)GetDlgItem(IDC_RADIO_LIVRE);
	bool existe=false;
	UpdateData(true);
	CExemplaire temp;

	if(m_titre!="")
	{
		if(m_resume!="")
		{
			if (pRadio->GetCheck()==1)
			{
				if(m_isbn!=0)
				{
					if(m_auteur!="")
					{
						for(livre_pos=list_livre.begin();livre_pos!=list_livre.end();livre_pos++)
							if(livre_pos->AtTitre()==m_titre)
									existe=true;
						for(cd_pos=list_cd.begin();cd_pos!=list_cd.end();cd_pos++)
							if(cd_pos->AtTitre()==m_titre)
									existe=true;
						if(existe==false)
						{
							livre_courant.AtTitre()=m_titre;
							livre_courant.AtResume()=m_resume;
							livre_courant.AtIsbn()=m_isbn;
							livre_courant.AtAuteur()=m_auteur;
						
							temp.AtRef()=m_lref1;
							temp.AtPtr()=livre_courant;
							livre_courant.AtExemplaire().push_back(temp);
							
							temp.AtRef()=m_lref2;
							temp.AtPtr()=livre_courant;
							livre_courant.AtExemplaire().push_back(temp);

							temp.AtRef()=m_lref3;
							temp.AtPtr()=livre_courant;
							livre_courant.AtExemplaire().push_back(temp);

							list_livre.push_back(livre_courant);
							
							livre_pos=list_livre.begin();
							m_titre="";
							m_resume="";
							m_isbn=0;
							m_auteur="";
							m_lref1=0;
							m_lref2=0;
							m_lref3=0;
							UpdateData(false);
							GetDlgItem(IDC_ISBN)->EnableWindow(false);
							GetDlgItem(IDC_AUTEUR)->EnableWindow(false);
							GetDlgItem(IDC_LREF1)->EnableWindow(false);
							GetDlgItem(IDC_LREF2)->EnableWindow(false);
							GetDlgItem(IDC_LREF3)->EnableWindow(false);
							GetDlgItem(IDC_VALID)->EnableWindow(true);
						
						}
						else 
							MessageBox("Désolé il exsite déjà un oeuvre avec ce titre","Avertissment",MB_ICONEXCLAMATION);
					}
					else
						MessageBox("vous dever remplir le champ auteur","Avertissment");
				}
				else
					MessageBox("vous dever remplir le champ isbn","Avertissment");
			}
			else
			{
				if(m_duree!=0)
				{
					if(m_artiste!="")
					{
						for(cd_pos=list_cd.begin();cd_pos!=list_cd.end();cd_pos++)
							if(cd_pos->AtTitre()==m_titre)
									existe=true;
						for(livre_pos=list_livre.begin();livre_pos!=list_livre.end();livre_pos++)
							if(livre_pos->AtTitre()==m_titre)
									existe=true;

						if(existe==false)
						{
							cd_courant.AtTitre()=m_titre;
							cd_courant.AtResume()=m_resume;
							cd_courant.AtDuree()=m_duree;
							cd_courant.AtArtiste()=m_artiste;
							
							temp.AtRef()=m_cref1;
							temp.AtPtr()=cd_courant;
							cd_courant.AtExemplaire().push_back(temp);
							
							temp.AtRef()=m_cref2;
							temp.AtPtr()=cd_courant;
							cd_courant.AtExemplaire().push_back(temp);

							temp.AtRef()=m_cref3;
							temp.AtPtr()=cd_courant;
							cd_courant.AtExemplaire().push_back(temp);
							list_cd.push_back(cd_courant);
						
							cd_pos=list_cd.begin();
							m_titre="";
							m_resume="";
							m_duree=0;
							m_artiste="";
							m_cref1=0;
							m_cref2=0;
							m_cref3=0;
							UpdateData(false);

							this->GetDlgItem(IDC_DUREE)->EnableWindow(false);
							this->GetDlgItem(IDC_ARTISTE)->EnableWindow(false);
							this->GetDlgItem(IDC_CREF1)->EnableWindow(false);
							this->GetDlgItem(IDC_CREF2)->EnableWindow(false);
							this->GetDlgItem(IDC_CREF3)->EnableWindow(false);
							this->GetDlgItem(IDC_VALID)->EnableWindow(true);

						
						}
						else 
							MessageBox("Désolé il exsite déjà un oeuvre avec ce titre","Avertissment",MB_ICONEXCLAMATION);
					}
					else
						MessageBox("vous dever remplir le champ artiste","Avertissment");
				}	
				else	
					MessageBox("vous dever remplir le champ duree","Avertissment");
			}
		}
		else
				MessageBox("vous dever remplir le champ résumé","Avertissment");
	}
	else
			MessageBox("vous dever remplir le champ titre","Avertissment");

}


BOOL CDlg_Ouvr::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->GetDlgItem(IDC_ISBN)->EnableWindow(false);
	this->GetDlgItem(IDC_AUTEUR)->EnableWindow(false);
	this->GetDlgItem(IDC_DUREE)->EnableWindow(false);
	this->GetDlgItem(IDC_ARTISTE)->EnableWindow(false);
	this->GetDlgItem(IDC_LREF1)->EnableWindow(false);
	this->GetDlgItem(IDC_LREF2)->EnableWindow(false);
	this->GetDlgItem(IDC_LREF3)->EnableWindow(false);
	this->GetDlgItem(IDC_CREF1)->EnableWindow(false);
	this->GetDlgItem(IDC_CREF2)->EnableWindow(false);
	this->GetDlgItem(IDC_CREF3)->EnableWindow(false);


	for(int i=0;i<4;i++)m_liste_livre.DeleteColumn(0);
	m_liste_livre.InsertColumn(0, "Titre",	LVCFMT_LEFT,100,	0);
	m_liste_livre.InsertColumn(1, "Résumé",	LVCFMT_LEFT,135	,0);
	m_liste_livre.InsertColumn(2, "Isbn",	LVCFMT_LEFT,50	,0);
	m_liste_livre.InsertColumn(3, "Auteur",	LVCFMT_LEFT,100	,0);

	for(i=0;i<4;i++)m_liste_cd.DeleteColumn(0);
	m_liste_cd.InsertColumn(0, "Titre",	LVCFMT_LEFT,100,	0);
	m_liste_cd.InsertColumn(1, "Résumé",	LVCFMT_LEFT,135	,0);
	m_liste_cd.InsertColumn(2, "Durée",	LVCFMT_LEFT,50	,0);
	m_liste_cd.InsertColumn(3, "Artiste",	LVCFMT_LEFT,100	,0);
	
	this->rafraichir();
	cd_pos=NULL;
	livre_pos=NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDlg_Ouvr::OnValid() 
{
	// TODO: Add your control notification handler code here
	CButton *pRadio=(CButton*)GetDlgItem(IDC_RADIO_LIVRE);
	
	if (pRadio->GetCheck()==1)
	{
		this->GetDlgItem(IDC_ISBN)->EnableWindow(true);
		this->GetDlgItem(IDC_AUTEUR)->EnableWindow(true);
		this->GetDlgItem(IDC_LREF1)->EnableWindow(true);
		this->GetDlgItem(IDC_LREF2)->EnableWindow(true);
		this->GetDlgItem(IDC_LREF3)->EnableWindow(true);
		this->GetDlgItem(IDC_VALID)->EnableWindow(false);

	}
	else
	{
		this->GetDlgItem(IDC_DUREE)->EnableWindow(true);
		this->GetDlgItem(IDC_ARTISTE)->EnableWindow(true);
		this->GetDlgItem(IDC_CREF1)->EnableWindow(true);
		this->GetDlgItem(IDC_CREF2)->EnableWindow(true);
		this->GetDlgItem(IDC_CREF3)->EnableWindow(true);
		this->GetDlgItem(IDC_VALID)->EnableWindow(false);
	}
}


void CDlg_Ouvr::rafraichir()
{
	
	CString sDuree;
	CString sIsbn;
	int i;

	m_liste_cd.DeleteAllItems();	
	m_liste_livre.DeleteAllItems();
	
	for(livre_pos=list_livre.begin(),i=0;livre_pos!=list_livre.end();livre_pos++,i++)
	{
		sIsbn.Format("%d",livre_pos->AtIsbn());
		m_liste_livre.InsertItem(i,livre_pos->AtTitre());
		m_liste_livre.SetItem(i,1,LVIF_TEXT,livre_pos->AtResume(),0,0,0,0);
		m_liste_livre.SetItem(i,2,LVIF_TEXT,sIsbn,0,0,0,0);
		m_liste_livre.SetItem(i,3,LVIF_TEXT,livre_pos->AtAuteur(),0,0,0,0);
 
	}
	
	for(cd_pos=list_cd.begin(),i=0;cd_pos!=list_cd.end();cd_pos++,i++)
	{
		sDuree.Format("%d",cd_pos->AtDuree());
		m_liste_cd.InsertItem(i,cd_pos->AtTitre());
		m_liste_cd.SetItem(i,1,LVIF_TEXT,cd_pos->AtResume(),0,0,0,0);
		m_liste_cd.SetItem(i,2,LVIF_TEXT,sDuree,0,0,0,0);
		m_liste_cd.SetItem(i,3,LVIF_TEXT,cd_pos->AtArtiste(),0,0,0,0);
	}

}

void CDlg_Ouvr::OnLister() 
{
	// TODO: Add your control notification handler code here
	this->rafraichir();
}


void CDlg_Ouvr::OnSearch() 
{
	// TODO: Add your control notification handler code here
	bool trouve=false;
	UpdateData(true);
	for(livre_pos=list_livre.begin();livre_pos!=list_livre.end();livre_pos++)
	{
		if(livre_pos->AtTitre()==m_find)
		{		
			m_titre=livre_pos->AtTitre();
			m_resume=livre_pos->AtResume();
			m_isbn=livre_pos->AtIsbn();
			m_auteur=livre_pos->AtAuteur();
			trouve=true;
			UpdateData(false);	
		}
	}
	for(cd_pos=list_cd.begin();cd_pos!=list_cd.end();cd_pos++)
	{
		if(cd_pos->AtTitre()==m_find)
		{		
			m_titre=cd_pos->AtTitre();
			m_resume=cd_pos->AtResume();
			m_duree=cd_pos->AtDuree();
			m_artiste=cd_pos->AtArtiste();;
			trouve=true;
			UpdateData(false);	
		}
	}
	if(trouve==false)
	{
		CString string =  _T ("Pas d'oeuvre avec ce titre");
		MessageBox(string, _T ("Inexistant"), MB_ICONEXCLAMATION|MB_OK);
	}
}

list<CLivre>& CDlg_Ouvr::At_List_Livre()
{
	return list_livre;
}


list<CCd>& CDlg_Ouvr::At_List_Cd()
{
	return list_cd;
}

void CDlg_Ouvr::OnPrev() 
{
	// TODO: Add your control notification handler code here
	if(livre_pos==NULL)
			MessageBox("La liste est vide","Avertissment");
	else
	if(livre_pos!= list_livre.begin())
	{
		livre_pos--;
		m_titre=livre_pos->AtTitre();
		m_resume=livre_pos->AtResume();
		m_isbn=livre_pos->AtIsbn();
		m_auteur=livre_pos->AtAuteur();
		m_lref1=livre_pos->AtExemplaire().at(0).AtRef();
		m_lref2=livre_pos->AtExemplaire().at(1).AtRef();
		m_lref3=livre_pos->AtExemplaire().at(2).AtRef();
		UpdateData(false);
	}
	else
		MessageBox("Avertissment","vous êtes sur le premier élément");	
}

void CDlg_Ouvr::OnNext() 
{
	// TODO: Add your control notification handler code here
	
	if(livre_pos==NULL)
		MessageBox("La liste est vide","Avertissment");
	else
		if(livre_pos!= list_livre.end())
		{
			m_titre=livre_pos->AtTitre();
			m_resume=livre_pos->AtResume();
			m_isbn=livre_pos->AtIsbn();
			m_auteur=livre_pos->AtAuteur();
			m_lref1=livre_pos->AtExemplaire().at(0).AtRef();
			m_lref2=livre_pos->AtExemplaire().at(1).AtRef();
			m_lref3=livre_pos->AtExemplaire().at(2).AtRef();
			UpdateData(false);
			livre_pos++;
		}
		else
			MessageBox("vous êtes sur le dernier élément","Avertissment");

}

void CDlg_Ouvr::OnNextc() 
{
	// TODO: Add your control notification handler code here
	if(cd_pos==NULL)
			MessageBox("La liste est vide","Avertissment");
	else
	if(cd_pos!= list_cd.end())
	{
		m_titre=cd_pos->AtTitre();
		m_resume=cd_pos->AtResume();
		m_duree=cd_pos->AtDuree();
		m_artiste=cd_pos->AtArtiste();
		m_cref1=cd_pos->AtExemplaire().at(0).AtRef();
		m_cref2=cd_pos->AtExemplaire().at(1).AtRef();
		m_cref3=cd_pos->AtExemplaire().at(2).AtRef();
		UpdateData(false);
		cd_pos++;
	}
	else
		MessageBox("vous êtes sur le dernier élément","Avertissment");
}

void CDlg_Ouvr::OnPrevc() 
{
	// TODO: Add your control notification handler code here
	if(cd_pos==NULL)
		MessageBox("La liste est vide","Avertissment");
	else
	if(cd_pos!= list_cd.begin())
	{
		cd_pos--;
		m_titre=cd_pos->AtTitre();
		m_resume=cd_pos->AtResume();
		m_duree=cd_pos->AtDuree();
		m_artiste=cd_pos->AtArtiste();
		m_cref1=cd_pos->AtExemplaire().at(0).AtRef();
		m_cref2=cd_pos->AtExemplaire().at(1).AtRef();
		m_cref3=cd_pos->AtExemplaire().at(2).AtRef();
		UpdateData(false);
	}
	else
		MessageBox("Avertissment","vous êtes sur le premier élément");	
}

void CDlg_Ouvr::OnModifc() 
{
	// TODO: Add your control notification handler code here
		
	if(m_titre!="")
	{
		cd_courant.AtResume()=m_resume;
		cd_courant.AtDuree()=m_duree;
		cd_courant.AtArtiste()=m_artiste;

		for(cd_pos=list_cd.begin();cd_pos!=list_cd.end();cd_pos++)
		if(cd_pos->AtTitre()==cd_courant.AtTitre())
			*cd_pos=cd_courant;
	}
	else 
		MessageBox("Vous devez préciser un cd","Avertissment",MB_ICONEXCLAMATION);
}

void CDlg_Ouvr::OnSuppc() 
{
	// TODO: Add your control notification handler code here
	list_cd.erase(cd_pos);
	cd_pos=list_cd.begin();	
}
