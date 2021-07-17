#ifndef MAISON_H
#define MAISON_H
#include<iostream>
using namespace std;
#include "Bien_immobilier.h"
class Maison :	public Bien_immobilier
{
    int nb_etage;
    int nb_chambre;
public:
    Maison(int = 0, string = "", float = 0, float = 0, int = 00, string = "", string = "", int=00, int=00);
    ~Maison();
    int getNb_etage();
    int getNb_chambre();
    void setNb_etage(int);
    void setNb_chambre(int);
    void setDispobile(string);
    void afficher_bien_immobilier(string);
    void Saisir();
    bool ADD_DB();
};


#endif // MAISON_H
