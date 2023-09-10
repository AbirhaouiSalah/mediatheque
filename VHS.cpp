#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include<fstream>

#include "VHS.h"
#include "Media.h"

using namespace std;

VHS::VHS()
{
  type = "VHS";
}

VHS::~VHS()
{
}

void VHS::ajouter()
{
  Media::ajouter();

  cout << "Duree : ";
  getline(cin,duree);
  cout << "Maison de production : ";
  getline(cin,maison_production);
  cout << "** VHS creee **" << endl;
  cout << endl;
}

void VHS::detailler(void)
{
  Media::detailler();

  cout << "Duree : "<<duree<<endl;
  cout << "Maison de production : "<<maison_production<<endl;
  cout << endl;
}

bool VHS::contient(string recherche)
{
  if (Media::contient(recherche) == true) return true;
  else if (duree.find(recherche)<duree.size()) return true;
  else if (maison_production.find(recherche)<maison_production.size()) return true;
  else return false;
}

void VHS::sauvegarder(ostream &os)
{
  Media::sauvegarder(os);
  os << duree << endl;
  os << maison_production << endl;
}

istream & VHS::charger(istream &is)
{
  Media::charger(is);
  getline(is,duree);
  getline(is,maison_production);
  return is;
}

