#if !defined(AFX_DLG_EXE_H__BB437EAB_4726_49D5_95A3_37A7CE062CE8__INCLUDED_)
#define AFX_DLG_EXE_H__BB437EAB_4726_49D5_95A3_37A7CE062CE8__INCLUDED_

#include "Exemplaire.h"	// Added by ClassView
#include "Dlg_Ouvr.h"
#include <list>
using namespace std;
// Dlg_Exe.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_Exe dialog

class CDlg_Exe : public CDialog
{
// Construction
public:
	CDlg_Exe(CWnd* pParent = NULL);   // standard constructor
	CDlg_Ouvr *ptr_dlgoeuv;
	list<CExemplaire>& At_List_Exe();
// Dialog Data
	//{{AFX_DATA(CDlg_Exe)
	enum { IDD = IDD_DLG_EXE };
	CComboBox	m_titre;
	UINT	m_ref;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_Exe)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	list<CExemplaire> list_exe;
	

	// Generated message map functions
	//{{AFX_MSG(CDlg_Exe)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_EXE_H__BB437EAB_4726_49D5_95A3_37A7CE062CE8__INCLUDED_)
