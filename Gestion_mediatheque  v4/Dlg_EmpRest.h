#if !defined(AFX_DLG_EMPREST_H__D0DEEB0D_A27F_4F3C_BCA1_F7A4A55E35B1__INCLUDED_)
#define AFX_DLG_EMPREST_H__D0DEEB0D_A27F_4F3C_BCA1_F7A4A55E35B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_EmpRest.h : header file
//
#include "Dlg_Adh.h"
#include "Dlg_Ouvr.h"
#include "Dlg_Exe.h"

/////////////////////////////////////////////////////////////////////////////
// CDlg_EmpRest dialog

class CDlg_EmpRest : public CDialog
{
// Construction
public:
	CDlg_EmpRest(CWnd* pParent = NULL);   // standard constructor
	CDlg_Adh *ptr_dlgAdh;
	CDlg_Ouvr *ptr_dlgoeuv;
	// Dialog Data
	//{{AFX_DATA(CDlg_EmpRest)
	enum { IDD = IDD_EMPR_REST };
	CListBox	m_list_adh;
	CComboBox	m_empl;
	CComboBox	m_empc;
	CComboBox	m_mat_adh;
	CString	m_rest_exe;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_EmpRest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_EmpRest)
	afx_msg void OnRest();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComAdh();
	afx_msg void OnEmpruntl();
	afx_msg void OnEmpruntc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_EMPREST_H__D0DEEB0D_A27F_4F3C_BCA1_F7A4A55E35B1__INCLUDED_)
