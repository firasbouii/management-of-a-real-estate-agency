#ifndef TERRAIN_H
#define TERRAIN_H

#include<iostream>
using namespace std;
#include "Bien_immobilier.h"
class Terrain :public Bien_immobilier
{
    int num_inscription;
    string nature;    //terre agricole pour batiment .....
    string etat_terr;   //enregistre ou nn
public:
    Terrain(int = 0, string = "", float = 0, float = 0, int = 00, string = "", string = "",int=00,string="",string="");
    ~Terrain();
    string getNature();
    int getNum_inscri();
    void setNature(string);
    void setNum_inscr(int);
    void setDispobile(string);
    void afficher_bien_immobilier(string);
    void Saisir();
    bool ADD_DB();
};

#endif // TERRAIN_H
