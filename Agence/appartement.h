#ifndef APPARTEMENT_H
#define APPARTEMENT_H
#include<iostream>
using namespace std;
#include "bien_immobilier.h"
class Appartement :public Bien_immobilier
{
    string immeuble;
    int num_etage;
    int nb_chambre;
public:
    Appartement(int = 0, string = "", float = 0, float = 0, int = 00, string = "", string = "",string="",int=00,int=00);
    ~Appartement();
    string getImmeuble();
    int getNum_etage();
    int getNb_chbre();
    void setImmeuble(string);
    void setNum_etage(int);
    void setNb_chbre(int);
    void setDispobile(string);
    void afficher_bien_immobilier(string);
    void Saisir();
    bool ADD_DB();
};



#endif // APPARTEMENT_H
