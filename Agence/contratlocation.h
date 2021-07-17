#ifndef CONTRATLOCATION_H
#define CONTRATLOCATION_H
#include<iostream>
using namespace std;
#include "contrat.h"
#include"date.h"
#include"bien_immobilier.h"
class ContratLocation :	public Contrat
{
    float const pourcentage_loc = 0.5;
    Date Date_Debut;
    Date Date_Fin;
    double Valeur_Contrat;
    double Mont_a_payer;


public:
    ContratLocation(int=-1 /*id bien */ , int =-1 /*id_client*/ ,float=0, float const =0,  int = 0, int = 0, int = 0, int = 0, int = 0, int= 0, double=0);
    void creer();
    void afficher_contrat();
    void setMont_a_payer();
    Date getDate_deb();
    Date getDate_fin();
    void setDate_deb(Date);
    void setDate_fin(Date);
    ~ContratLocation(void);
    bool ADD_DB();
};



#endif // CONTRATLOCATION_H
