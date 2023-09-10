// Oeuvre.h: interface for the COeuvre class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OEUVRE_H__0D1E8517_CC6F_4189_B27C_28998F7C7F7B__INCLUDED_)
#define AFX_OEUVRE_H__0D1E8517_CC6F_4189_B27C_28998F7C7F7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Exemplaire.h"
#include <vector>
using namespace std;

class CExemplaire;


class COeuvre  
{
protected :
	CString titre , resume;
	vector<CExemplaire> Exemplaires;
public:
	COeuvre();
	virtual ~COeuvre();
	COeuvre(CString,CString,vector<CExemplaire>);
	CString& AtTitre();
	CString& AtResume();
	vector<CExemplaire>& AtExemplaire();
	
};

#endif // !defined(AFX_OEUVRE_H__0D1E8517_CC6F_4189_B27C_28998F7C7F7B__INCLUDED_)
