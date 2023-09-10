#if !defined(AFX_DLG_OUVR_H__18EE14D3_1159_4054_B488_145E98EE29C8__INCLUDED_)
#define AFX_DLG_OUVR_H__18EE14D3_1159_4054_B488_145E98EE29C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_Ouvr.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_Ouvr dialog



#include "Livre.h"
#include "Cd.h"
#include <list>
using namespace std;
class CDlg_Ouvr : public CDialog
{
// Construction
public:
	void rafraichir();
	CDlg_Ouvr(CWnd* pParent = NULL);   // standard constructor
	list<CLivre>& At_List_Livre();
	list<CCd>& At_List_Cd();
// Dialog Data
	//{{AFX_DATA(CDlg_Ouvr)
	enum { IDD = IDD_OEUVRE };
	CListCtrl	m_liste_cd;
	CListCtrl	m_liste_livre;
	CString	m_artiste;
	CString	m_auteur;
	UINT	m_isbn;
	UINT	m_lref1;
	UINT	m_lref2;
	UINT	m_lref3;
	CString	m_resume;
	CString	m_titre;
	UINT	m_duree;
	CString	m_find;

	UINT	m_cref1;
	UINT	m_cref2;
	UINT	m_cref3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_Ouvr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_Ouvr)
	afx_msg void OnSupp();
	afx_msg void OnModif();
	afx_msg void OnAjout();
	virtual BOOL OnInitDialog();
	afx_msg void OnValid();
	afx_msg void OnLister();
	afx_msg void OnSearch();
	afx_msg void OnPrev();
	afx_msg void OnNext();
	afx_msg void OnNextc();
	afx_msg void OnPrevc();
	afx_msg void OnModifc();
	afx_msg void OnSuppc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
		list<CLivre> list_livre;
		list<CCd> list_cd;
		CLivre livre_courant;
		CCd  cd_courant;
		list<CLivre>::iterator  livre_pos;
		list<CCd>::iterator cd_pos;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_OUVR_H__18EE14D3_1159_4054_B488_145E98EE29C8__INCLUDED_)
