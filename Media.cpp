#include"Media.h"

#include"stdio.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include<fstream>


using namespace std;

Media::Media()
{
}

void Media::gen_ID(unsigned int id)
{
   ID = id;
}

unsigned int Media::get_id(void)
{
  return  ID;
}

void Media::ajouter()
{
  cout << "Titre : ";
  getline(cin,titre);
  cout << "Auteur : ";
  getline(cin,auteur);
  cout << "Etat : ";
  getline(cin,etat);

  nb_total=0;
  while(nb_total == 0)
    {
    cout << "Nombre d'exemplaires achetes : ";
    getline(cin,nombre_total);
    nb_total = atoi(nombre_total.c_str());
    cout << "ok" <<endl;
    if (nb_total == 0)
      {
        cout << "ERREUR : la valeur entree est soit egale a 0 soit n'est pas un entier." << endl;
        nombre_total = "0";
      }
    nb_restant=nb_total;
    }
}




void Media::lister(void)
{
  Media::detailler();
}

void Media::detailler(void)
{ 
  cout<<"###################################################" << endl;
  cout<<"###################################################" << endl;
  cout<< "Type : "<<type<<endl;
  cout << "Identifiant : " << ID  << endl;
  cout << "Titre : "<<titre<<endl;
  cout << "Auteur : "<<auteur<<endl;
  cout << "Etat : "<<etat<<endl;
  cout << "Nombres d'exemplaires achetes :" << nb_total<<endl;
  cout << "Nombre d'exemplaires restant :" << nb_restant<<endl;
  cout<<"###################################################" << endl;
  cout<<"###################################################" << endl;
}

bool Media::contient(string recherche)
{
  if (etat.find(recherche) < etat.size()) return true;
  else if (type.find(recherche) < type.size()) return true;
  else if (titre.find(recherche)<titre.size()) return true;
  else if (auteur.find(recherche)<auteur.size()) return true;
  else return false;
}

void Media::sauvegarder(ostream &os)
{
  os << type<< endl;
  os << ID<< endl;
  os << etat<< endl;
  os << titre << endl;
  os << auteur << endl;
  os << nb_total << endl;
  os << nb_restant << endl;
}

istream&  Media::charger(istream &is)
{
  string n;
  getline(is,n);
  ID = atoi(n.c_str());
  getline(is,etat);
  getline(is,titre);
  getline(is,auteur);
  getline(is,nombre_total);
  nb_total = atoi(nombre_total.c_str());
  getline(is,nombre_restant);
  nb_restant = atoi(nombre_restant.c_str());
  return is;
}



Media::~Media()
{
}

