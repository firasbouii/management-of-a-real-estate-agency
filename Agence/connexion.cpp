#include "connexion.h"
#include<QDebug>


Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setHostName("localhost");
db.setDatabaseName("Agence");
//db.setDatabaseName("Driver={Agence};Server=127.0.0.1:1521;Uid=ep;Pwd=605605");
db.setUserName("System"); //inserer nom de l'utilisateur
db.setPassword("yacine");//inserer mot de passe de cet utilisateur
//db.setDatabaseName(QString("Driver={SQL Server};Database=Agence;Uid=System;Pwd=mrabetwashere2020;Trusted_Connection=yes;"));
qDebug() <<"*******  "<< db.open()  ;

if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
