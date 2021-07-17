#ifndef ENTREPOT_H
#define ENTREPOT_H
#include "bien_immobilier.h"
#include<iostream>
using namespace std;
class Entrepot :public Bien_immobilier
{
    string utilisation;
public:
    Entrepot(int = 0, string = "", float = 0, float = 0, int = 00, string = "", string = "",string="");
    ~Entrepot();
    string getUtilisation_entrepot();
    void setDispobile(string);
    void setUtilisation_entrepot(string);
    void afficher_bien_immobilier(string);
    void Saisir();
    bool ADD_DB();
};
#endif // ENTREPOT_H
