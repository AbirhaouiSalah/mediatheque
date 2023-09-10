
#include <cstdlib>
#include <iostream>
#include <string>

#include "REVUE.h"

using namespace std;

REVUE::REVUE()
{
  type = "REVUE";

}

REVUE::~REVUE()
{
}

void REVUE::ajouter(void)
{
  string nb_article_tmp;
  string numero_tmp;
  string liste_nom_article_tmp = NULL;

   LIVRE::ajouter();
    cout << "Editeur : ";
    getline(cin,editeur);

    cout<< "Nombre d'articles ";
    getline(cin,nb_article_tmp);
    nb_article=atoi(nb_article_tmp.c_str());

    for (int i = 0; i < nb_article; i++)
    {
    string nom_article;    
    cout << "veuillez remplire le nom de l'article numéro " << to_string(i) <<":";
    getline(cin,nom_article);
    liste_nom_article_tmp += nom_article + ".";
    }
    liste_nom_article = liste_nom_article_tmp;
    cout << endl;
}

void REVUE::detailler()
{

  LIVRE::detailler();

    cout << "Editeur : "<< editeur<<endl;
    cout << "Nombre d'article : "<< nb_article<<endl;

    cout << endl;
}

bool REVUE::contient(string recherche)
{
  string nb_article_tmp;


  if (LIVRE::contient(recherche) == true) return true;
  else if (editeur.find(recherche)<editeur.size()) return true;
  else if (nb_article_tmp.find(recherche)<nb_article_tmp.size())
  {return true;
  nb_article = atoi(nb_article_tmp.c_str());}

  else return false;
}

void REVUE::sauvegarder(ostream &os)
{

  LIVRE::sauvegarder(os);

    os << editeur << endl;
    os << nb_article<< endl;
    os << liste_nom_article<< endl;
}

istream & REVUE::charger(istream &is)
{

    LIVRE::charger(is);
    string nb_article_tmp;

    getline(is,editeur);
    getline(is,nb_article_tmp);
    nb_article = atoi(nb_article_tmp.c_str());
    return is;
}

