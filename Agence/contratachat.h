#ifndef CONTRATACHAT_H
#define CONTRATACHAT_H
#include "contrat.h"
#include"date.h"
#include<iostream>
using namespace std;
class ContratAchat :public Contrat
{
    Date Date_Vente;
    double Mont_a_payer;
    double Valeur_Contrat; //
public:

    ContratAchat(int=-1 /*id bien */ , int =-1 /*id_client*/ , float=0,int=0 ,int = 0,int = 0, double = 0, double = 0);

    void creer();

    void afficher_contrat();

    double getMont_a_payer();



    double getValeur_contrat();

    void setMont_a_payer();

    void setValeur_contrat(double);

    ~ContratAchat(void);
    bool  ADD_DB();





};

#endif // CONTRATACHAT_H
