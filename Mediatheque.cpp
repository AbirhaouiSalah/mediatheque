#include "Mediatheque.h"
#include "Media.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "CD.h"
#include "DVD.h"
#include "LIVRE.h"
#include "RES_NUM.h"
#include "REVUE.h"
#include "VHS.h"



#define TAILLE 100

using namespace std;



Mediatheque::Mediatheque()
{
  liste_ok  = (Media**) new Media[TAILLE];
  liste_neg = (Media**) new Media[TAILLE];

  taille_liste_ok = 0;
  taille_liste_neg = 0;
  id_session = 0;
}

Mediatheque::~Mediatheque()
{

}


void Mediatheque::ADD(string _type)
{
  
  Media *nx_media = new Media();
 // Media *nx_media = new Media();
 
  if (!_type.compare("CD"))
    {
      CD *A = new CD();
      nx_media = A;   
    }
  else if (!_type.compare("DVD"))
    {
       DVD *A = new DVD();
       nx_media = A;
    }

  else if (!_type.compare("LIVRE"))
    {
      LIVRE *A = new LIVRE();
      nx_media = A;
    }

  else if (!_type.compare("RES_NUM"))
    {
      RES_NUM *A = new RES_NUM();
      nx_media = A;
    }

  else if (!_type.compare("REVUE"))
    {
      REVUE *A= new REVUE();
      nx_media = A;
    }

  else if (!_type.compare("VHS"))
    {
      VHS *A = new VHS();
      nx_media = A;
    }
  
  else 
    {
      cout<<"type de Mediatheque inconnu"<<endl;
    }
    
  this->rebuild();			                      // Reconsitution de la mediatheque avant d'ajouter un Mediatheque
  nx_media->ajouter();		                    // Completion manuelle du nx Mediatheque	
  nx_media->gen_ID(id_session);           	  // Creation de l'identifiant du Mediatheque
  liste_ok[taille_liste_ok] = nx_media;     	// Sauvegarde du Mediatheque dans le mdiatheque
  taille_liste_ok++;				                  // Incrementation de la taille de la mediatheque
  id_session++;					                      // Incrementation de l'identifiant

}
void Mediatheque::SAVE(const string  &nom_fichier)
{
          

  unsigned int i;
  ofstream fichier;

  this->rebuild();					// Reconstitution de la mediatheque

  fichier.open(nom_fichier.c_str(), ios::out);	//ouverture du fichier en ecriture

  for (i=0;i<taille_liste_ok;i++)				// Parcourt de la mediatheque
    {
      liste_ok[i]->sauvegarder(fichier);		// sauvegarde du ieme Mediatheque
    }

  fichier.close();							// fermeture du fichier
  cout <<"** Mediatheque sauvegardee dans le fichier "<<nom_fichier<<" **"<<endl;
  cout<<"###################################################" << endl;
  cout<<"########    SAVE éxecuter avec succes   ###########"<<endl;  
  cout<<"###################################################" << endl;
   
}

bool Mediatheque::LOAD(const string &nom_fichier)
{

  Media *nx_media = new Media();
  ifstream fichier,tmp;
  string type;
  string etat;

  fichier.open(nom_fichier.c_str(), ios::in);

  if (fichier.fail())
    {
      cout << "Fichier non trouve." << endl;
      return 0;
    }

  this->RESET();					// Reinitialisation de la mediathque avent de faire un chargement

  while (getline(fichier,type))
    {
     if (!type.compare("CD"))
          {
            CD *A = new CD();
            nx_media = A;   
          }
  else if (!type.compare("DVD"))
          {
            DVD *A = new DVD();
            nx_media = A;
          }

  else if (!type.compare("LIVRE"))
          {
            cout << "executer avec succes " << type <<endl;
            LIVRE *A = new LIVRE();
            nx_media = A;
          }

  else if (!type.compare("RES_NUM"))
          {
            RES_NUM *A = new RES_NUM();
            nx_media = A;
          }

  else if (!type.compare("REVUE"))
          {
            REVUE *A= new REVUE();
            nx_media = A;
          }

  else if (!type.compare("VHS"))
          {
            VHS *A = new VHS();
            nx_media = A;
          }
  
      nx_media->charger(fichier);
      id_session = (nx_media->get_id() > id_session) ? nx_media->get_id() : id_session;
      nx_media->detailler();

      liste_ok[taille_liste_ok] = nx_media;			// sauvgarde du Mediatheque dans le mediatheque
      taille_liste_ok++;
      
    }
    id_session++;
    cout<<"LOAD éxecuter avec succes"<<endl;
    return true; 
}
unsigned int Mediatheque::SEARCH(string chaine)
{
          
  unsigned int i=0,nbr=0;

  for(i=0;i<taille_liste_ok;i++)				// Parcour de la mediatheque
    {
      if(liste_ok[i]->contient(chaine) == false) // Test si le Mediatheque contient la chaine
    {
      liste_neg[taille_liste_neg]=liste_ok[i];	// Transfert du Mediatheque qui ne correspond pas a la recherche dans "taille_liste_neg"
      liste_ok[i] = NULL;					// Pointeur NULL
      taille_liste_neg++;					// Incrementation de la taille de la liste des Mediatheque ne correspondant pas a la recherche
    }
      else
    nbr++;							// Incrementation de la variable indiquant le nombre de resultat
    }

  this->reorganize();						// Reorganisation de la mediatheque
  
  cout<<"###################################################" << endl;
  cout<<"########    SEARCH éxecuter avec succes   ##########"<<endl;  
  cout<<"###################################################" << endl;

  return nbr;

}


void Mediatheque :: CLEAR()
{
  
}

void Mediatheque::LIST(void)
{
           

  unsigned int i;

  if (taille_liste_ok == 0)			// Verification que la mediatheque n'est pas vide
    {
      cout << "Aucun Mediatheque trouve." << endl;
      return;
    }

  cout << "Debut du listage" << endl;

  for (i=0;i<taille_liste_ok;i++)
    {
      cout << endl;				// Retour a la ligne de mise en forme
      cout << "Media " << i << " : "<< endl << endl;
      liste_ok[i]->lister();			// Listage
    }

  cout << "Fin du listage" << endl;
  cout<<"LIST éxecuter avec succes"<<endl; 
}

void Mediatheque::SHOW_ID(unsigned int id)
{
            

  unsigned int i;

  i=position_media(id_session);			// Recuperation de la poistion du Mediatheque dans la mediatheque ayant pour identifiant "id"

  if (i != taille_liste_ok)			// Verification que l'identifiant demande existe
    { 
      liste_ok[i]->detailler();		// Detaillage du Mediatheque
      cout << endl;				// Pour la mise en forme dans le terminal
    }
  else
    cout << "Aucun Mediatheque associe a l'identifiant : "<< id << endl;
    cout<<"éxecuter avec succes"<<endl;
}

void Mediatheque::DELET_ID(unsigned int id)
{
     


  unsigned int i;

  this->rebuild();			// Reconstituion de ma mediatheque

  i=position_media(id);			// Recuperation de la poistion du Mediatheque dans la mediatheque ayant pour identifiant "id"

  if (i != taille_liste_ok)			// Verification que l'identifiant existe
    {
      delete liste_ok[i];			// Suppression du Mediatheque
      liste_ok[i] = NULL;			// Pointeur NULL
      this->reorganize();		// Reorganisation de ma mediatheque
      cout <<"**  "<<id<<" a ete supprime **" << endl;
    }
  else
    {cout << "Aucun Mediatheque associe  a cette identifiant." << endl;}
cout<<"éxecuter avec succes"<<endl;     
}

void Mediatheque::rebuild(void)	{// Reconstruciton
  unsigned int i;

  for(i=0;i<taille_liste_neg;i++)
    {
      liste_ok[taille_liste_ok] = liste_neg[i];
      taille_liste_ok++;
    }
  taille_liste_neg = 0;
  cout<<"rebuild éxecuter avec succes"<<endl;
}

void Mediatheque::reorganize(void)
{
            

  unsigned int i,j,t;

  t = 0;
  j = taille_liste_ok;

  for(i=0;i<j;i++)
    {
      if (liste_ok[i] != NULL)
    {
      liste_ok[t] = liste_ok[i];
      t++;
    }
      taille_liste_ok = t;
    }
    cout<<"reorganise éxecuter avec succes"<<endl;
}

void Mediatheque::RESET()
{    cout<<"éxecuter avec succes"<<endl;    

    
  unsigned int i;

  this->rebuild();	// Reconsitution de la mediatheque

  for(i=0;i<taille_liste_ok;i++)	// Parcours de la mediatheque
    {
      delete liste_ok[i];		// Suppression du ieme Mediatheque
      liste_ok[i] = NULL;		// Pointeur NULL
    }

  id_session = 0;

  taille_liste_ok = 0;			// Reinitialisation de la taille de le mediatheque
  cout <<"** Le reset a ete effectue **" << endl;
  
}



unsigned int Mediatheque::position_media(unsigned int id)
{
        cout<<"éxecuter avec succes"<<endl;    


  unsigned int i,position_media = taille_liste_ok; // initialisation de la position sur la taille max qui est realite un pointeur null car pas encore affecte

  for(i=0;i<taille_liste_ok;i++)				// Parcour de la mediatheque
    {
      if (liste_ok[i]->get_id() == id_session)			// Test de l'id du ieme Mediatheque
    {
      position_media = i;				// memorisation de l'indice
      break;						// break de la boucle
    }
    }
  return position_media;					// Retour de la poistion du Mediatheque
  
}





void Mediatheque::HELP(void)
{
  cout << "Vous pouvez saisir les fonction suivantes : "<<endl;
  cout << "          * ADD(_type) type = {CD, DVD, LIVRE, RES_NUM, REVUE, VHS}"<<endl;
  cout << "          * BYE"<<endl;
  cout << "          * CLEAR"<<endl;
  cout << "          * DELETE_ID(_ID) ID = {int}" <<endl;
  cout << "          * HELP" <<endl;
  cout << "          * LIST" <<endl;
  cout << "          * LOAD(_filename) filename = {nom du fichier}" <<endl;
  cout << "          * RESET"<<endl;
  cout << "          * SAVE(_filename) filename = {nom du fichier}" <<endl;
  cout << "          * SEARCH(_string) string = {texte}" <<endl;
  cout << "          * SHOW(_ID) ID = {identifiant}" <<endl;
}






