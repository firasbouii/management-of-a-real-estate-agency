#ifndef BIEN_IMMOBILIER_H
#define BIEN_IMMOBILIER_H
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>
#include<iostream>
using namespace std;
#include"adresse.h"
class Bien_immobilier
{
protected :
    int id_imm;
    string etat;
    float superficie; //en m2
    float valeur; //en dinars
    Adresse lieu;
    string disponible ;
public:
    Bien_immobilier(int =0,string="",float=0,float=0, int = 00, string = "", string = "");
    ~Bien_immobilier();
    int getId();
    string geetEtat();
    float getSuperficie();
    float getValeur();
    Adresse getAdresse();
    void setId(int);
    void setEtat(string);            //modifier etat d'un bien
    void setSuperficie(float);
    void setValeur(float);          //modifier valeur d'un bien
    void setAdresse(Adresse);
    void setDispobile(string);
    void virtual afficher_bien_immobilier(string);
    void virtual Saisir();
    bool virtual ADD_DB();

};



#endif // BIEN_IMMOBILIER_H
