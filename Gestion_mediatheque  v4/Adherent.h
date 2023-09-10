// Adherent.h: interface for the CAdherent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADHERENT_H__ED5FDD45_0F35_40BC_BAB5_540EBA203409__INCLUDED_)
#define AFX_ADHERENT_H__ED5FDD45_0F35_40BC_BAB5_540EBA203409__INCLUDED_

#include "Exemplaire.h"
#include <vector>
using namespace std;

class CAdherent  
{
private :
	UINT matricule,age;
	CString nom,prenom,adresse,email;
	vector<CExemplaire> Exp_emprunte;
public:
	CAdherent();
	virtual ~CAdherent();
	CAdherent(CString,CString ,CString, CString, UINT ,UINT,vector<CExemplaire> );
	CString& AtNom();	
	CString& AtPrenom();	
	CString& AtAdr();	
	CString& AtEmail();	
	UINT& AtAge();	
	UINT& AtMat();
	vector<CExemplaire>& AtExemplaire();
	void AddExemplaire(CExemplaire);
	void RemoveExemplaire(CExemplaire);
	void save(CArchive&);
	void load(CArchive&);
};

#endif // !defined(AFX_ADHERENT_H__ED5FDD45_0F35_40BC_BAB5_540EBA203409__INCLUDED_)
