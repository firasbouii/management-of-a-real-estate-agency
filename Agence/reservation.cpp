#include "reservation.h"
#include<iostream>
using namespace std;
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>



Reservation::Reservation( int idc, int idb ):  ID_Client(idc)
{
    QSqlQuery myquery("select  max(id_reservation) from reservation");

    myquery.next();

    int Reserevation_id_counter =myquery.value(0).toInt()+1 ;

    ID_Reservation = Reserevation_id_counter;
    Etat ="Non_Accepte";

    ID_Bien_Imobbilier = idb;

}

Reservation::~Reservation()
{

}
/*
void Reservation::saisir()
{
    cout << "TAPER " << endl;
    ID_Reservation =id_counter
    int ID_Client;
    int ID_Bien_Imobbilier;
    string Etat;  //accepte ou non


}*/


void Reservation::Afficher_Res()
{
    cout << "ID_Reservation"<< ID_Reservation <<endl;
    cout << " ID_Client"<< ID_Client <<endl;
    cout << "ID_Bien_Imobbilier"<< ID_Bien_Imobbilier <<endl;
    cout << "Etat"<< Etat <<endl;

}



bool Reservation::ADD_DB(){
    QSqlQuery  query;
    query.prepare("INSERT INTO reservation(ID_reservation,id_client,id_bien_immobilier,etat)  "
                        "VALUES (?,?,?,?)");




    query.bindValue(0,ID_Reservation);
    query.bindValue(1,ID_Client);
    query.bindValue(2,ID_Bien_Imobbilier);
    query.bindValue(3,QString::fromStdString(Etat));

    return    query.exec();



}
