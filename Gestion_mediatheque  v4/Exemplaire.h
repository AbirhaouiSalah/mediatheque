// Exemplaire.h: interface for the CExemplaire class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXEMPLAIRE_H__E5220AC0_B286_4FB6_B54F_C4D12FB41DBB__INCLUDED_)
#define AFX_EXEMPLAIRE_H__E5220AC0_B286_4FB6_B54F_C4D12FB41DBB__INCLUDED_

#include "Oeuvre.h"
//#include "Cd.h"

class COeuvre;
//class Clivre;
//class CCd;

class CExemplaire  
{
	UINT ref;
	COeuvre* ptr;
public:
	CExemplaire();
	CExemplaire(const CExemplaire&);
	UINT& AtRef();
	COeuvre& AtPtr();
	virtual ~CExemplaire();

};

#endif // !defined(AFX_EXEMPLAIRE_H__E5220AC0_B286_4FB6_B54F_C4D12FB41DBB__INCLUDED_)
