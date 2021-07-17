#include "contrat.h"
#include<iostream>
using namespace std;

Contrat::Contrat( int idb , int idc , float com)
{
    ID_Bien=idb;
    ID_Client=idc ;
    comission = com;
    QSqlQuery maxid;
    maxid.prepare("select max(id_contrat) from contrat");
    maxid.exec();
    maxid.next();
    qDebug()<<"max id "<<maxid.value(0).toInt() ;
    ID_contrat =maxid.value(0).toInt()+1 ;

   // ID_contrat= 2 ;




}
void Contrat::creer()
{
    cout << "\n Comission  : ";
    cin >> comission;
}
void Contrat::afficher_contrat()
{
    cout << " ID du contrat 	: " << ID_contrat << endl;
    cout << " ID Client 	: " << ID_Client << endl;
    cout << " ID Bien 	: " << ID_Bien << endl;
    cout << " Comission du contrat est : " << comission << endl;
}
Contrat::~Contrat(void)
{
}
int Contrat::getId_contrat()
{
    return ID_contrat;
}

float Contrat::getComission()
{
    return comission;
}
void Contrat::setId_contrat(int id)
{
    ID_contrat = id;
}
void Contrat::setComission(float c)
{
    comission = c;
}
bool Contrat::ADD_DB(){

    QSqlQuery  query;
    query.prepare("INSERT INTO contrat(id_contrat,id_bien,ID_CLIENT,comission)  "
                        "VALUES(?,?,?,?) ");

    qDebug()<<"ADD DB CONTRAT";


    query.bindValue(0,ID_contrat);
    query.bindValue(1,ID_Bien);
    query.bindValue(2,ID_Client);
    query.bindValue(3,(double)comission);
    qDebug()<<"comission : "<<comission ;


    return    query.exec();


}
