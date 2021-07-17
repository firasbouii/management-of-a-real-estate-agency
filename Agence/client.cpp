#include"client.h"
#include"date.h"
#include<iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>

using namespace std;
//int id_counters = 0;
Client::Client(int ID, string No, string PR, string  E, int NU,  int num , string quar , string ville, int j, int m, int a) :  Nom(No), Prenom(PR), Email(E), Num_Tel(NU), Date_Naissance(j, m, a) , adresse(num,quar,ville)
{

    QSqlQuery myquery("select  max(id_client) from client");

    myquery.next();

    int Client_id_counter =myquery.value(0).toInt()+1 ;

    Id_Client = Client_id_counter;


}
Client::~Client()
{
    //dtor
}
void Client::Afficher()
{
    cout << "ID CLIENT           :" ;
    cout << Id_Client << endl;
    cout << "NOM                 : ";
    cout << Nom << endl;
    cout << "Prenom              : ";
    cout << Prenom << endl;
    cout << "Email               : ";
    cout << Email << endl;
    cout << "Num_Tel             : ";
    cout << Num_Tel << endl;
    adresse.afficher("INFORMATION CLIENT : ");
    cout << "Date De Naissance   : ";
    Date_Naissance.afficher();
}

void Client::Saisir()
{
    cout << "Saisie Du  Client : " << endl;
    cout << "TAPER : " << endl;
    cout << "NOM               : ";
    cin >> Nom;
    cout << "Prenom            : ";
    cin >> Prenom;
    cout << "Email             : ";
    cin >> Email;
    cout << "Num_Tel           : ";
    cin >> Num_Tel;
    cout << "Adresse           : ";
    adresse.saisir();

    Date_Naissance.saisir();
}


//**************************PARTIE BD****************************************

bool Client::ADD_DB()
{
    QSqlQuery  query;
    query.prepare("INSERT INTO Client(ID_CLIENT,NOM,PRENOM,EMAIL,NUM_TEL,ADRESSE,DATE_NAISSANCE)  "
                        "VALUES (?,?,?,?,?,?,to_date(?,'DD/MM/YYYY'))");




    query.bindValue(0,Id_Client);
    query.bindValue(1,QString::fromStdString(Nom));
    query.bindValue(2,QString::fromStdString(Prenom));
    query.bindValue(3,QString::fromStdString(Email));
    query.bindValue(4,Num_Tel);
    query.bindValue(5,QString::number(adresse.getNumero())+" "+QString::fromStdString(adresse.getQuartier())+" "+QString::fromStdString(adresse.getVille()));
   // query.bindValue(":j",QString::number(Date_Naissance.getJour()));
   // query.bindValue(":m",QString::number(Date_Naissance.getMois()));
   // query.bindValue(":a",QString::number(Date_Naissance.getANNEE()));
    QString ch=QString::number(Date_Naissance.getJour())+'/'+QString::number(Date_Naissance.getMois())+'/'+QString::number(Date_Naissance.getANNEE());
    qDebug()<<"testing  : "<<ch;
    query.bindValue(6,ch);
    return    query.exec();

    qDebug()<<"-----------**********----------***********--------"<< QString::fromStdString(Nom) ;


}
