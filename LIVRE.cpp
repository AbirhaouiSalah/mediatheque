#include "LIVRE.h"

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include<fstream>


using namespace std;



LIVRE::LIVRE()
{
  type = "LIVRE";
}

LIVRE::~LIVRE()
{
}

void LIVRE::ajouter(void)
{
  Media::ajouter();

  cout << "Annee de publication : ";
  getline(cin, annee_pub);
  cout << "Nombre de page : ";
  getline(cin, nb_page);
  cout << "Collection : ";
  getline(cin,collection);
  cout << "Resume : ";
  getline(cin,RESUME);
  cout << endl;
}




void LIVRE::detailler(void)
{
  Media::detailler();

  cout << "Annee de publication : "<<annee_pub<<endl;
  cout << "Nombre de page : "<<nb_page<<endl;
  cout << "Collection : "<<collection<<endl;

  cout<<"###################################################" << endl;
  cout << "Resume : "<<RESUME<<endl;
  cout<<"###################################################" << endl;

  cout << endl;
}

bool LIVRE::contient(string recherche)
{
  if (Media::contient(recherche) == true) return true;
  else if (annee_pub.find(recherche)<annee_pub.size()) return true;
  else if (nb_page.find(recherche)<nb_page.size()) return true;
  else if (collection.find(recherche)<collection.size()) return true;
  else if (RESUME.find(recherche)<RESUME.size()) return true;
  else return false;
}

void LIVRE::sauvegarder(ostream &os)
{
  Media::sauvegarder(os);
  os << annee_pub << endl;
  os << nb_page<< endl;
  os << collection<< endl;
  os << RESUME<< endl;
}

istream & LIVRE::charger(istream &is)
{
  Media::charger(is);
  getline(is,annee_pub);
  getline(is,nb_page);
  getline(is,collection);
  getline(is,RESUME);
  return is;
}

