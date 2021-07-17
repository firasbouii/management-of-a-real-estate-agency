#ifndef CONTRAT_H
#define CONTRAT_H
#include<iostream>

#include<qfloat16.h>
#include<QFloat16>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>
#include"typeinfo.h"
using namespace std;
class Contrat
{
    int ID_contrat;
    int ID_Bien ;
    int ID_Client ; //acheteur ou locataire

    float comission;
public:

    Contrat( int=-1 /*id bien */ , int =-1 /*id_client*/, float=0);
    int getId_contrat();
    float getComission();
    void setId_contrat(int);
    void setComission(float);
    int getID_Bien() { return ID_Bien ; }
    int getID_Client() { return ID_Client ; }
    void virtual creer();
    void virtual afficher_contrat();
    virtual~Contrat(void);
    bool virtual ADD_DB();
};


#endif // CONTRAT_H
