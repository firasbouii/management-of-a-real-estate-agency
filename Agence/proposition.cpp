#include "proposition.h"
#include<iostream>
using namespace std;

#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>
Proposition::Proposition( int idc, int idb ):  ID_Client(idc)
{

    QSqlQuery myquery("select  max(ID_Proposition) from Proposition");


    myquery.next();

    int Proposition_id_counter =myquery.value(0).toInt()+1 ;

    ID_Proposition = Proposition_id_counter;



    Etat ="Non_Accepte";
    ID_Bien_Imobbilier = idb;

}

Proposition::~Proposition()
{

}


void Proposition::Afficher_Prop()
{
    cout << "ID_Proposition"<< ID_Proposition <<endl;
    cout << " ID_Client"<< ID_Client <<endl;
    cout << "ID_Bien_Imobbilier"<< ID_Bien_Imobbilier <<endl;
    cout << "Etat"<< Etat <<endl;

}

bool Proposition::ADD_DB(){
    QSqlQuery  query;
    query.prepare("INSERT INTO proposition(ID_proposition,id_client,id_bien_immobilier,etat)  "
                        "VALUES (?,?,?,?)");





    query.bindValue(0,ID_Proposition);
    query.bindValue(1,ID_Client);
    query.bindValue(2,ID_Bien_Imobbilier);
    query.bindValue(3,QString::fromStdString(Etat));

    return    query.exec();









}

