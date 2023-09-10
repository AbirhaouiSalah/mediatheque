#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>

#include "Mediatheque.h"

using namespace std;


int main(void)
{   
    int en = 1;
    unsigned int i;
    string command;
    unsigned int resultat=0;
    string login;


    Mediatheque *ma_Mediatheque = new Mediatheque();

    cout<<"###################################################" << endl;
    cout<<"########           Bonjour            #############" << endl;
    cout<<"####### bienvenue sur votre bibliotheque ##########" << endl;
    cout<<"########          numerique           #############" << endl;
    cout<<"###################################################" << endl;
    cout << endl;


    while(en == 1)
    {   
        cout<<"###################################################" << endl;
        cout<<"#############   admin ou client ? #################" << endl;
        cout<<"###################################################" << endl;
        cout << endl;
        cout << ":" ;
        getline(cin,login);


        if (login.compare("admin") == 0)
        {
            while(1)
            {
                cout << "Commande bibliothecaire: ";
                getline(cin,command);	// Recuperation de la commande saisie par l'utilisateur
                if (command.size() != 0)
                {
                    istringstream iss(command); // mise dans un flux
                    vector<string> command_function;
                    copy(istream_iterator<string>( iss ),istream_iterator<string>(),back_inserter( command_function ) ); // remplissage du tableau
                    
                    if (command_function[0].compare("LIST") == 0)
                    {
                        if (command_function.size() == 1)
                            {
                            ma_Mediatheque->LIST();
                            }
                        else if (command_function.size() == 2)
                        {
                            cout<<"###################################################" << endl;
                            cout<<"##### la fonction LIST ne prend pas d'argument ####" << endl;
                            cout<<"###################################################" << endl;
                        }                            
                    }

                    else if (command_function[0].compare("SHOW_ID") == 0)
                    {
                        if (command_function.size() >= 2)
                            for(i=1;i<command_function.size();i++)
                                ma_Mediatheque->SHOW_ID(atoi(command_function[i].c_str()));
                        else
                        
                            cout<<"###################################################" << endl;
                            cout<<"####  la fonction SHOW_ID a besoin d'argument  ####" << endl;
                            cout<<"###################################################" << endl;
                    }

                    else if (command_function[0].compare("SEARCH") == 0)
                    {
                        if (command_function.size() >= 2)
                        {
                            for(i=1;i<command_function.size();i++)
                            {
                                resultat = ma_Mediatheque->SEARCH(command_function[i]);
                                cout << "Il y a " << resultat << " media(s) correspondant a votre recherche." << endl;
                            }

                            ma_Mediatheque->LIST();
                        }
                        else
                        {
                            cout << "la fonction SEARCH a besoin d'argument"<<endl;
                            cout<<"###################################################" << endl;
                            cout<<"####  la fonction SEARCH a besoin d'argument   ####" << endl;
                            cout<<"####     essayez par exemple SEARCH toto       ####" << endl;
                            cout<<"###################################################" << endl;
                        }
                    }

                    else if (command_function[0].compare("CLEAR") == 0)
                    {
                        if (command_function.size() == 1)
                            ma_Mediatheque->rebuild();
                        else
                            cout << "la fonction CLEAR a besoin d'argument"<< endl;
                    }

                    else if (command_function[0].compare("SAVE") == 0)
                    {
                        if (command_function.size() == 2)
                            ma_Mediatheque->SAVE(command_function[1]);
                        else if (command_function.size() > 2)
                            cout << "Mauvais Argument (type, nombre...)"<< endl;
                        else
                            cout << "la fonction SAVE a besoin d'argument: Ressayez en rajoutant le nom du media"<< endl;
                    }

                    else if (command_function[0].compare("LOAD") == 0)
                    {
                        if (command_function.size() == 2)
                            {ma_Mediatheque->LOAD(command_function[1]);
                            }
                        else if (command_function.size() > 2)
                            {cout << "Mauvais Argument (type, nombre...)"<< endl;
                            }
                        else
                            {cout << "la fonction SEARCH a besoin d'argument"<<endl;
                            cout<<"###################################################" << endl;
                            cout<<"####  la fonction LOAD a besoin d'argument   ######" << endl;
                            cout<<"####     essayez par exemple media_XX.txt      ####" << endl;
                            cout<<"###################################################" << endl;
                            }
                    }

                    else if (command_function[0].compare("ADD") == 0)
                    {
                        if (command_function.size() == 2)
                        {
                            ma_Mediatheque->ADD(command_function[1]);
                            cout << "vous avez bien cree un(e) " << command_function[1];
                        }

                        else if (command_function.size() > 2)
                            cout << "Mauvais Argument "<< endl;
                        else
                            cout << "Argument Manquant: Ressayez en rajoutant le type de media a ajouter: cd dvd vhs revue ressource_numerique livre"<< endl;
                    }

                    else if (command_function[0].compare("DELET_ID") == 0)
                    {
                        if (command_function.size() >= 2)
                            for(i=1;i<command_function.size();i++)
                                ma_Mediatheque->DELET_ID(atoi(command_function[i].c_str()));
                        else
                            cout << "Argument Manquant: il faut rajouter l'id du media a supprimer , afin d'obtenir l'identifiant , effectuer une recherche avec search.  "<< endl;
                    }

                    else if (command_function[0].compare("RESET") == 0)
                    {
                        if (command_function.size() == 1)
                            ma_Mediatheque->RESET();
                        else
                            cout << "Erreur: reset ne requiert aucun argument"<< endl;
                    }

                    else if (command_function[0].compare("HELP") == 0)
                    {
                        if (command_function.size() == 1)
                            ma_Mediatheque->HELP();
                        else
                            cout << "Erreur: help ne requiert aucun argument "<< endl;
                    }

                    else if (command_function[0].compare("BYE") == 0)
                    {
                        if (command_function.size() == 1)
                        {   
                            
                            cout<<"BYE"<<endl;
                            break;
                        }
                        else
                            cout << "Erreur: Bye ne requiert aucun argument"<< endl;
                    }
                    else
                        cout << "Commande Inconnue, utilisez la commande help pour consulter les commandes disponibles ";
                    cout << endl;
                }

            }
        }

        else if (login.compare("user") == 0)
        {
            cout<<"Partiellement indisponible. Vous pouvez juste utiliser \"search\" pour consulter les medias disponibles";
            cout<<endl;
            while(1)
            {
                cout << "Commande bibliothecaire: ";
                getline(cin,command);	// Recuperation de la commande saisie par l'utilisateur
                if (command.size() != 0)
                {
                    istringstream iss(command); // mise dans un flux
                    vector<string> command_function;
                    copy(istream_iterator<string>( iss ),istream_iterator<string>(),back_inserter( command_function ) ); // remplissage du tableau
                    if (command_function[0].compare("SEARCH") == 0)
                    {
                        if (command_function.size() >= 2)
                        {
                            for(i=1;i<command_function.size();i++)
                            {
                                resultat = ma_Mediatheque->SEARCH(command_function[i]);
                                cout << "Il y a " << resultat << " media(s) correspondant a votre recherche." << endl;
                            }

                            ma_Mediatheque->LIST();
                        }
                        else
                            cout << "Argument Manquant"<<endl;
                    }
                    else if (command_function[0].compare("BYE") == 0)
                    {
                        if (command_function.size() == 1)
                        {   
                            
                            cout<<"BYE"<<endl;
                            cout << "ok" << endl;
                            break;
                        }
                        else
                            cout << "Erreur: Bye ne requiert aucun argument"<< endl;
                    }
                }
            }
            cout << "ok" << endl;
        }
       
        
        else if (login.compare("BYE") == 0)
        {   
            cout << "pour quitter la mediatheque veuillez confirmer votre choix en ressaisisant BYE sinn appui sur retour " << endl;
            getline(cin,command);
            if(command.compare("BYE")==0)
            {
            delete ma_Mediatheque;
            en = 0;
            break;
            }
        }

         else
        {
            cout<<"S'il vous plait, inserez admin ou user ou quit";
            cout<<endl;
        }
    }
}
