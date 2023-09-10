#include "RES_NUM.h"
#include "Media.h"

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include<fstream>


using namespace std;

RES_NUM::RES_NUM()
{
  type = "RES_NUM";
}

RES_NUM::~RES_NUM(void)
{
}

void RES_NUM ::ajouter(void)
{
  Media::ajouter();
    
  cout << "Format : ";
  getline(cin,format);
  cout << "Chemin d'acces : ";
  getline(cin,path);
  cout << "Taille : ";
  getline(cin,taille);
  cout <<"** "<< format << " cree(e) **"<<endl;

}

void RES_NUM::detailler(void)
{
  Media::detailler();

  cout << "Format : " << format << endl;
  cout << "Chemin d'acces : "<<path<<endl;
  cout << "Taille : "<<taille<<endl;
  cout << endl;
}

bool RES_NUM::contient(string recherche)
{
  if (Media::contient(recherche) == true) return true;
  else if (format.find(recherche)<format.size()) return true;
  else if (path.find(recherche)<path.size()) return true;
  else if (taille.find(recherche)<taille.size()) return true;
  else return false;
}

void RES_NUM::sauvegarder(ostream &os)
{
  Media::sauvegarder(os);
  os << format << endl;
  os << path << endl;
  os << taille << endl;
}

istream & RES_NUM::charger(istream &is)
{
  Media::charger(is);
  getline(is,format);
  getline(is,path);
  getline(is,taille);
  return is;
}

