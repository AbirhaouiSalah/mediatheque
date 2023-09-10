// Adherent.cpp: implementation of the CAdherent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Adherent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdherent::CAdherent()
{

}

CAdherent::~CAdherent()
{

}


CAdherent::CAdherent(CString n,CString p ,CString a, CString e, UINT m  ,UINT ag,vector<CExemplaire> Ex)
{
	nom=n;
	prenom=p;
	adresse=a;
	email=e;
	matricule=m;
	age=ag;
	Exp_emprunte=Ex;
}

UINT& CAdherent::AtMat()
{
	return matricule;
}

UINT& CAdherent::AtAge()
{
	return age;
}

CString& CAdherent::AtNom()
{
	return nom;
}

CString& CAdherent::AtPrenom()
{
	return prenom;
}
CString& CAdherent::AtEmail()
{
	return email;
}
CString& CAdherent::AtAdr()
{
	return adresse;
}
void CAdherent::AddExemplaire(CExemplaire e)
{
	Exp_emprunte.push_back(e);
}

void CAdherent::RemoveExemplaire(CExemplaire e)
{
	vector<CExemplaire>::iterator i;
	for(i=Exp_emprunte.begin();i!=Exp_emprunte.end();i++)
		if(i==&e)
			Exp_emprunte.erase(i);
}

vector<CExemplaire>& CAdherent::AtExemplaire()
{
	return Exp_emprunte;
}
void CAdherent::save(CArchive &ar)
{
	ar<<matricule;
	ar<<age;
	ar<<nom;
	ar<<prenom;
	ar<<adresse;
	ar<<email;
	//Exp_emprunte.save(ar);
}

void CAdherent::load(CArchive &ar)
{
	ar>>matricule;
	ar>>age;
	ar>>nom;
	ar>>prenom;
	ar>>adresse;
	ar>>email;
	//Exp_emprunte.load(ar);
}
