// Gestion_mediathequeDoc.h : interface of the CGestion_mediathequeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GESTION_MEDIATHEQUEDOC_H__7C72ECB4_FB04_4C1B_A0B0_B099C4DF4D72__INCLUDED_)
#define AFX_GESTION_MEDIATHEQUEDOC_H__7C72ECB4_FB04_4C1B_A0B0_B099C4DF4D72__INCLUDED_

#include "Dlg_Adh.h"	// Added by ClassView
#include "Dlg_Ouvr.h"
#include "Dlg_EmpRest.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGestion_mediathequeDoc : public CDocument
{
protected: // create from serialization only
	CGestion_mediathequeDoc();
	DECLARE_DYNCREATE(CGestion_mediathequeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGestion_mediathequeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	CDlg_Ouvr&		AtDlg_Ouvr();
	CDlg_Adh&		AtDlg_Adh();
	CDlg_EmpRest&	AtDlg_Emp();
	

	virtual ~CGestion_mediathequeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CDlg_Adh		dlg_des_adh;
	CDlg_Ouvr		dlg_des_ouevres ;
	CDlg_EmpRest	dlgEmp;
	

// Generated message map functions
protected:

	//{{AFX_MSG(CGestion_mediathequeDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GESTION_MEDIATHEQUEDOC_H__7C72ECB4_FB04_4C1B_A0B0_B099C4DF4D72__INCLUDED_)
