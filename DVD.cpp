

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include<fstream>

#include "DVD.h"
#include "VHS.h"

using namespace std;

DVD::DVD()
{
  string type;
  type = "DVD";
}

DVD::~DVD()
{
}

void DVD::ajouter()
{
  VHS::ajouter();

  string nb_piste_tmp;
  cout << "Nombre de piste : ";
  getline(cin,nb_piste_tmp);
  nb_piste=atoi(nb_piste_tmp.c_str());

  cout << endl;
}

void DVD::detailler(void)
{
  VHS::detailler();

    cout << "Nombre de piste : "<<nb_piste<<endl;
    cout << endl;
}

bool DVD::contient(string recherche)
{ string nb_piste_tmp;

    if (VHS::contient(recherche) == true) return true;

  else if (nb_piste_tmp.find(recherche)<nb_piste_tmp.size())
         {return true;
          nb_piste=atoi(nb_piste_tmp.c_str());}

  else return false;
}

void DVD::sauvegarder(ostream &os)
{
  VHS::sauvegarder(os);

  os << nb_piste << endl;
}

istream & DVD::charger(istream &is)
{
  VHS::charger(is);

  string nb_piste_tmp;
  getline(is,nb_piste_tmp);
  nb_piste=atoi(nb_piste_tmp.c_str());
  return is;
}