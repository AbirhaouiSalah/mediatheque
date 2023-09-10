// Livre.h: interface for the CLivre class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIVRE_H__7E4E026B_1811_437F_B61E_812FBDF928E0__INCLUDED_)
#define AFX_LIVRE_H__7E4E026B_1811_437F_B61E_812FBDF928E0__INCLUDED_

#include "Oeuvre.h"

class CLivre: public COeuvre
{
private:
	UINT isbn;
	CString auteur ;
public:
	CLivre();
	virtual ~CLivre();
	CLivre(CString,CString,vector<CExemplaire>,UINT,CString);
	UINT& AtIsbn();
	CString& AtAuteur();
};

#endif // !defined(AFX_LIVRE_H__7E4E026B_1811_437F_B61E_812FBDF928E0__INCLUDED_)
