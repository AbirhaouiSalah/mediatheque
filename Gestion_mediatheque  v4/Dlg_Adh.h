#if !defined(AFX_DLG_ADH_H__1F0A2A3B_2667_4778_B299_99D7B466B562__INCLUDED_)
#define AFX_DLG_ADH_H__1F0A2A3B_2667_4778_B299_99D7B466B562__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_Adh.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_Adh dialog

#include "Adherent.h"
#include <list>

using namespace std;

class CDlg_Adh : public CDialog
{
// Construction
public:
	void rafraichir();
	CDlg_Adh(CWnd* pParent = NULL);   // standard constructor
	list<CAdherent>& At_List_Adh();
	void save(CArchive&);
	void load(CArchive&);
// Dialog Data
	//{{AFX_DATA(CDlg_Adh)
	enum { IDD = IDD_DLG_ADH };
	CListCtrl	m_list_adh;
	CString	m_adr;
	UINT	m_age;
	CString	m_email;
	UINT	m_mat;
	CString	m_nom;
	CString	m_prenom;
	UINT	m_find;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_Adh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CAdherent					Adh_Courant;
	list<CAdherent>::iterator	adh_pos;
	list<CAdherent>				list_adh;
	
	// Generated message map functions
	//{{AFX_MSG(CDlg_Adh)
	afx_msg void OnAdd();
	afx_msg void OnPrev();
	afx_msg void OnNext();
	afx_msg void OnModify();
	afx_msg void OnDelete();
	afx_msg void OnFind();
	afx_msg void OnLister();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_ADH_H__1F0A2A3B_2667_4778_B299_99D7B466B562__INCLUDED_)
