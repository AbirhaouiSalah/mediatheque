#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include<fstream>

#include "CD.h"
#include "Media.h"

using namespace std;


CD::CD() 
{  
    type = "CD" ;
}

void CD::ajouter(void)
{
   VHS::ajouter(); 

  string nb_piste_tmp;
  cout << "Nombre de piste : ";
  getline(cin,nb_piste_tmp);
  nb_piste=atoi(nb_piste_tmp.c_str());

  cout << endl;
}

void CD::detailler(void)
{
  VHS::detailler();

  cout << "Nombre de piste : "<<nb_piste<<endl;

  cout << endl;

}

bool CD::contient(string recherche)
{  string nb_piste_tmp;
  if (VHS::contient(recherche) == true) return true;

  else if (
           nb_piste_tmp.find(recherche)<nb_piste_tmp.size())
         {return true;
          nb_piste=atoi(nb_piste_tmp.c_str());}
  else return false;
}

void CD::sauvegarder(ostream &os)
{
  VHS::sauvegarder(os);

  os << nb_piste << endl;

}

istream & CD::charger(istream &is)
{
  VHS::charger(is);
  string nb_piste_tmp;
  getline(is,nb_piste_tmp);
  nb_piste=atoi(nb_piste_tmp.c_str());
  return is;
}

CD::~CD()
{
}
