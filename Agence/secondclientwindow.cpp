#include "secondclientwindow.h"
#include "ui_secondclientwindow.h"
#include"NewQTABdesign.h"
#include"clientwindow.h"
#include"bien_immobilier.h"
#include"maison.h"
#include"entrepot.h"
#include"terrain.h"
#include <QRegExpValidator>
#include"appartement.h"
#include"qtablewidget.h"
#include <QWidget>
#include"reservation.h"
#include"proposition.h"
#include<QMessageBox>
//************** variable globale********************
bool Rien=false ;
QString setTEXT="";
QString choix= "Type";

bool  Ventechecked=false  ;
bool  Locationchecked=false ;

bool RadioLocation = false ;
bool RadioVente = false ;


bool Details = false ;

//-------------- fin variable globale*-----------------------

secondclientwindow::secondclientwindow(QWidget *parent) : QWidget(parent), ui(new Ui::secondclientwindow)
{   ui->setupUi(this);
    ui->ClientTab->tabBar()->setStyle(new CustomTabStyle);
    ui->BienFrame->hide();
    ui->MaisontFrame->hide();
    ui->Entrepotframe->hide();
    ui->TerrainFrame->hide();
    ui->AppartemetFrame->hide();


    ui->Proposer->hide();
    ui->Bien_Adresse1->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->Bien_Adresse1 ));
    ui->Bien_Superficie->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->Bien_Superficie ));
    ui->Bien_Valeur->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->Bien_Valeur ));

    ui->A_Nb_Chamnre->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->A_Nb_Chamnre));
    ui->A_Etage->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->A_Etage ));


    ui->M_Nb_Etage->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->M_Nb_Etage ));
    ui->M_Nb_Chambre->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->M_Nb_Chambre ));

    ui->T_Num_Inscri->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->T_Num_Inscri ));


    ui->ClientTab->setTabText(0, "Reservations");
    ui->ClientTab->setTabText(1, "Catalogue");
    ui->ClientTab->setTabText(2, "Propositions");
    ui->ClientTab->setTabText(3, "Contrats");

    ui->LocationTable->setColumnCount(9);
    secondclientwindow::adjustTableSize2(ui->LocationTable,1);
    QStringList ContratLoc;
    ContratLoc << "Identifiant "  <<"Identifiant Client"<<"Identifiant bien"<<"Comission"<<"Pourcentage loc"<<"Valeur du bien" <<"à payer (dt)"<< "Date Debut"<<"Date Fin";
    ui->LocationTable->setHorizontalHeaderLabels(ContratLoc);

    ui->VenteTable->setColumnCount(7);
    secondclientwindow::adjustTableSize2(ui->VenteTable,1);
    QStringList ContratAchat;
    ContratAchat << "Identifiant "  <<"Identifiant Client"<<"Identifiant bien"<<"Comission"<<"Valeur du bien" <<"à payer (dt)"<< "Date  ";
    ui->VenteTable->setHorizontalHeaderLabels(ContratAchat);

    secondclientwindow::on_pushButton_clicked();







}
secondclientwindow::~secondclientwindow()
{delete ui;}

void secondclientwindow::setID(int id)
{  ID=id ;}

//************Information Client*********************

/*ui->testlabel->setText(QString::number(ID));
QSqlQuery ClientDataQuery ;
ClientDataQuery.prepare("select * from client where id_client=? ");
ClientDataQuery.bindValue(0,ID);
ClientDataQuery.exec();
ClientDataQuery.next();
qDebug()<<"*******************************************";
qDebug()<<ClientDataQuery.value(0)<<ClientDataQuery.value(1)<<ClientDataQuery.value(2);
ui->nom->setText(ClientDataQuery.value(1).toString());
ui->prenom->setText(ClientDataQuery.value(2).toString());
ui->Email->setText(ClientDataQuery.value(3).toString());
ui->NumTel->setText(ClientDataQuery.value(4).toString());*/
//--------------fin Information Client*----------------------

//***************test classe bienImmob*****************************

/*Bien_immobilier b(9999,"loué",520,200,45,"douarhicher","manouba");
b.setDispobile("disponible");
b.afficher_bien_immobilier("");
b.ADD_DB();

Maison m(9999,"loué",520,200,45,"douarhicher","manouba",20,2);
m.setDispobile("disponible");
m.afficher_bien_immobilier("maison");

m.ADD_DB();

Entrepot E(9999,"loué",520,200,45,"douarhicher","manouba","tmatem");
E.setDispobile("disponible");
E.afficher_bien_immobilier("Entrepot");

E.ADD_DB();

Appartement A(9999,"loué",520,200,45,"douarhicher","manouba","bolbol",2,3);
A.setDispobile("disponible");
A.afficher_bien_immobilier("Appartement");

A.ADD_DB();

Terrain T(9999,"loué",520,200,45,"douarhicher","manouba",526525,"kouribgar","parfait");
T.setDispobile("disponible");
T.afficher_bien_immobilier("Terrain");

T.ADD_DB();*/


//----------------------test classe bienImmob--------------------------



//************************* adjustTableSize**********************
void secondclientwindow::adjustTableSize()
{ QRect rect = ui->bien_table->geometry();
  int tableWidth = 2 + ui->bien_table->verticalHeader()->width();
   for(int i = 0; i < ui->bien_table->columnCount(); i++)
      {
       tableWidth += ui->bien_table->columnWidth(i);
      }

rect.setWidth(tableWidth);
rect.setHeight(235);
ui->bien_table->setGeometry(rect);
qDebug()<<"-*-*-*-"<<rect;



}




//-----------------------------adjustTableSize------------------------


//**********************************************catalogue + reserver un bien**********************************
/*
void secondclientwindow::on_radioEntrepot_clicked()
{

    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);
    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");


//aaaaaaaaaaaaaaaaa

    }

    myquery2.exec();

    qDebug()<<"***************************"<<myquery2.size();
    ui->bien_table->setColumnCount(7);
    this->adjustTableSize();
    int index = 0;
    ui->bien_table->setSortingEnabled(false);
    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);
         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(6).toString())); //6 not 5
         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
        index ++;

    }

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);

}

void secondclientwindow::on_radioAppartement_clicked()
{
    ui->bien_table->clearContents();
    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);

    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }


    myquery2.exec();
    qDebug()<<"***************************"<<myquery2.size();
    //ui->tablew2->setColumnCount(7)
    ui->bien_table->setColumnCount(8);

    ui->bien_table->setColumnWidth(0,40);
    ui->bien_table->setColumnWidth(1,40);
    ui->bien_table->setColumnWidth(2,40);
    ui->bien_table->setColumnWidth(3,40);
    ui->bien_table->setColumnWidth(5,90);
    ui->bien_table->setColumnWidth(6,40);
    ui->bien_table->setColumnWidth(7,40);
    this->adjustTableSize();


     int index = 0;

    ui->bien_table->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);

         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(6).toString())); //6 not 5
         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
         ui->bien_table->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));
        index ++;
    }
    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);
}

void secondclientwindow::on_radioMaison_clicked()
{
    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);



    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }
    myquery2.exec();


    ui->bien_table->setColumnCount(7);

    ui->bien_table->setColumnWidth(0,40);
    ui->bien_table->setColumnWidth(1,40);
    ui->bien_table->setColumnWidth(2,40);
    ui->bien_table->setColumnWidth(3,40);
    ui->bien_table->setColumnWidth(4,150);
    ui->bien_table->setColumnWidth(5,90);
    ui->bien_table->setColumnWidth(6,40);
    this->adjustTableSize();


     int index = 0;

    ui->bien_table->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);

         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(6).toString())); //6 not 5
         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
        index ++;

    }

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);


}

void secondclientwindow::on_radioTerrain_clicked()
{

    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);


    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }

    myquery2.exec();

    ui->bien_table->setColumnCount(8);

    ui->bien_table->setColumnWidth(0,40);
    ui->bien_table->setColumnWidth(1,40);
    ui->bien_table->setColumnWidth(2,40);
    ui->bien_table->setColumnWidth(3,40);
    ui->bien_table->setColumnWidth(4,150);
    ui->bien_table->setColumnWidth(5,90);
    ui->bien_table->setColumnWidth(6,150);
    ui->bien_table->setColumnWidth(7,150);
    this->adjustTableSize();


     int index = 0;

    ui->bien_table->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);

         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(6).toString())); //6 not 5
         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
         ui->bien_table->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));
        index ++;

    }

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);


}
*/ //normalement bech yetfasa5

void secondclientwindow::on_radioEntrepot_clicked()
{

    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);
    ui->bien_table->setColumnWidth(1,40);
    ui->bien_table->setColumnWidth(2,40);
    ui->bien_table->setColumnWidth(3,40);
    ui->bien_table->setColumnWidth(5,100);
    ui->bien_table->setColumnWidth(6,100);
    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){
        qDebug()<<"radio button";
        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? AND etat=?" );
       myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");


//aaaaaaaaaaaaaaaaa

    }

    myquery2.exec();

    qDebug()<<"***************************"<<myquery2.size();
    ui->bien_table->setColumnCount(7);
    QStringList BienColumnName;
    BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Utilisation";
    ui->bien_table->setHorizontalHeaderLabels(BienColumnName);

    int index = 0;
    ui->bien_table->setSortingEnabled(false);
    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);
         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString())); //6 not 5
         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
        index ++;

    }
    secondclientwindow::adjustTableSize2(ui->bien_table,1);

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);

}

void secondclientwindow::on_radioAppartement_clicked()
{
    ui->bien_table->clearContents();
    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);

    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }


    myquery2.exec();
    qDebug()<<"***************************"<<myquery2.size();
    //ui->tablew2->setColumnCount(7)
    ui->bien_table->setColumnCount(9);
    QStringList BienColumnName;
    BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nom d'immeuble"<<"Nombre d'etage"<<"Nombre de chambre";
    ui->bien_table->setHorizontalHeaderLabels(BienColumnName);
    myquery2.exec();
    qDebug()<<"***************************"<<myquery2.size();
    //ui->tablew2->setColumnCount(7)



   /* ui->bien_table->setColumnWidth(0,40);
    ui->bien_table->setColumnWidth(1,40);
    ui->bien_table->setColumnWidth(2,40);
    ui->bien_table->setColumnWidth(3,80);
    ui->bien_table->setColumnWidth(4,80);
    ui->bien_table->setColumnWidth(5,80);
    ui->bien_table->setColumnWidth(6,80);
    ui->bien_table->setColumnWidth(7,40);
    ui->bien_table->setColumnWidth(8,40);*/



     int index = 0;

    ui->bien_table->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);

         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString())); //6 not 5
         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
         ui->bien_table->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));
         ui->bien_table->setItem(index,8,new QTableWidgetItem(myquery2.value(9).toString()));

        index ++;
    }
    secondclientwindow::adjustTableSize2(ui->bien_table,1);
    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);
}


void secondclientwindow::on_radioMaison_clicked()
{
    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);



    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }
    ui->bien_table->setColumnCount(8);
    QStringList BienColumnName;
    BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nombre d'etage"<<"Nombre de chambre";
    ui->bien_table->setHorizontalHeaderLabels(BienColumnName);
    myquery2.exec();


    ui->bien_table->setColumnCount(8);

    ui->bien_table->setColumnWidth(3,80);
    ui->bien_table->setColumnWidth(7,80);


     int index = 0;

    ui->bien_table->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);

         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString())); //6 not 5
         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
         ui->bien_table->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));

        index ++;




    }
    secondclientwindow::adjustTableSize2(ui->bien_table,1);

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);


}

void secondclientwindow::on_radioTerrain_clicked()
{

    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);


    QSqlQuery myquery2;
    if ( Ventechecked==true && Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked==true ){

        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }

    myquery2.exec();

    ui->bien_table->setColumnCount(9);
    ui->bien_table->setColumnCount(9);

    QStringList BienColumnName;
    BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"nombre d'inscription"<<"nature"<<"etat" ;
    ui->bien_table->setHorizontalHeaderLabels( BienColumnName);

    ui->bien_table->setColumnWidth(0,80);
    ui->bien_table->setColumnWidth(1,80);
    ui->bien_table->setColumnWidth(2,80);
    ui->bien_table->setColumnWidth(3,40);
    ui->bien_table->setColumnWidth(4,120);
    ui->bien_table->setColumnWidth(5,90);
    ui->bien_table->setColumnWidth(6,120);
    ui->bien_table->setColumnWidth(7,80);
    ui->bien_table->setColumnWidth(8,80);



     int index = 0;

    ui->bien_table->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->bien_table->setRowCount(index+1);

         ui->bien_table->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->bien_table->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->bien_table->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->bien_table->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->bien_table->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->bien_table->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString())); //6 not 5

         ui->bien_table->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
         ui->bien_table->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));
         ui->bien_table->setItem(index,8,new QTableWidgetItem(myquery2.value(9).toString()));
        index ++;

    }

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);
    secondclientwindow::adjustTableSize2(ui->bien_table,1);


}


void secondclientwindow::adjustTableSize2(QTableWidget* wid,int t)
{
    if (t==1)
    {
    QRect rect = wid->geometry();
    int tableWidth = 18 + wid->verticalHeader()->width();
    for(int i = 0; i < wid->columnCount(); i++){
        tableWidth += wid->columnWidth(i);
    }
    rect.setWidth(tableWidth);
    int tableHeight = 160;
    rect.setHeight(tableHeight);

    wid->setGeometry(rect);

    }
    else
    {
        QRect rect = wid->geometry();
        int tableWidth = 18 + wid->verticalHeader()->width();
        for(int i = 0; i < wid->columnCount(); i++){
            tableWidth += wid->columnWidth(i);
        }
        rect.setWidth(tableWidth);
        int tableHeight = 5 + wid->horizontalHeader()->height();
        for(int i = 0; i < wid->rowCount(); i++){
            tableHeight += wid->rowHeight(i);
        }
        rect.setHeight(tableHeight);

        wid->setGeometry(rect);

    }

}



//*******************************Reserver un bien ****************************
void secondclientwindow::on_bien_table_cellDoubleClicked(int row, int column)
{
    qDebug()<<"item->text(----------------------------------------------";
    QTableWidgetItem *item = new QTableWidgetItem;

       if (Rien)
       {
            item = ui->bien_table->item(row,0);
            qDebug()<<item->text();
            Rien=false;
            Reservation R(this->ID,item->text().toInt());
            R.Afficher_Res();
            if(R.ADD_DB())
            {
                QMessageBox msgBox;
                msgBox.setText("Bien Reservé");
                msgBox.exec();
                secondclientwindow::on_pushButton_clicked();
            }

       }
}

void secondclientwindow::on_Reserver_Button_clicked()
{Rien=true ;}

void secondclientwindow::on_Location_button_clicked()//zeyeda ta nfas5ohom
{}

void secondclientwindow::on_Vente_button_clicked()//zeyeda ta nfas5ohom
{}




void secondclientwindow::on_checkBox_clicked(bool checked1)
{
    Locationchecked=checked1;
    qDebug()<<" Locationchecked : "<<Locationchecked<<"Ventechecked  "<<Ventechecked ;
    if (ui->radioEntrepot->isChecked())
    {
       secondclientwindow::on_radioEntrepot_clicked();
    }
    if (ui->radioMaison->isChecked())
    {
       secondclientwindow::on_radioMaison_clicked();
    }
    if (ui->radioTerrain->isChecked())
    {
       secondclientwindow::on_radioTerrain_clicked();
    }
    if (ui->radioAppartement->isChecked())
    {
       secondclientwindow::on_radioAppartement_clicked();
    }



}

void secondclientwindow::on_checkBox_2_clicked(bool checked2)
{
    Ventechecked=checked2;
    qDebug()<<" Locationchecked : "<<Locationchecked<<"Ventechecked  "<<Ventechecked ;
    if (ui->radioEntrepot->isChecked())
    {
       secondclientwindow::on_radioEntrepot_clicked();
    }
    if (ui->radioMaison->isChecked())
    {
       secondclientwindow::on_radioMaison_clicked();
    }
    if (ui->radioTerrain->isChecked())
    {
       secondclientwindow::on_radioTerrain_clicked();
    }
    if (ui->radioAppartement->isChecked())
    {
       secondclientwindow::on_radioAppartement_clicked();
    }

}
//------------------------------- fin catalogue + reserver un bien -----------------------

//**********************************Proposer un bien **********************
void secondclientwindow::on_Proposer_clicked()
{
    int superfice = ui->Bien_Superficie->text().toInt();
    int Valeur = ui->Bien_Valeur->text().toInt();
    int Adresse_Num =ui->Bien_Adresse1->text().toInt();
    string Quartier =ui->Bien_Adresse2->text().toStdString();
    string Ville =ui->Bien_Adresse3->text().toStdString();
    QString  Etat ="";
    if ( choix =="Maison")
    {
        if (RadioLocation == true)
            Etat ="Location";
        else if (RadioVente == true )
             Etat="Vente";

        int nb_etage = ui->M_Nb_Etage->text().toInt();
        int nb_chambre = ui->M_Nb_Chambre->text().toInt();
        if((Etat=="")||(superfice==0)||(Valeur==0)||(Adresse_Num==0)||(Quartier=="")||(Ville=="")||( nb_etage==0)||(nb_chambre==0))
        {

            QMessageBox msgBox;
            msgBox.setText("Il faut Remplir tous les champs !");
            msgBox.exec();
            secondclientwindow::on_pushButton_clicked();
        }
        else
        {
        Maison M1(9999,Etat.toStdString(),superfice,Valeur,Adresse_Num,Quartier,Ville,nb_etage,nb_chambre);
        M1.setDispobile("non disponible") ;
        M1.afficher_bien_immobilier("   ");
        M1.ADD_DB();
        Proposition P(ID,M1.getId());
        P.Afficher_Prop();
        qDebug()<<QString::fromStdString(P.get_Etat()) << M1.getId() ;
        if(P.ADD_DB())
        {

            QMessageBox msgBox;
            msgBox.setText("Proposition ajoutée !");
            msgBox.exec();
            secondclientwindow::on_pushButton_clicked();
            secondclientwindow::on_LoadProposition_clicked();

        }
        }
    }
    else if ( choix =="Appartement"){

        if (RadioLocation == true)
            Etat ="Location";
        else if (RadioVente == true )
             Etat="Vente";
        string immeuble =ui->A_Immeuble->text().toStdString();
        int nb_etage = ui->A_Etage->text().toInt();
        int nb_chambre = ui->A_Nb_Chamnre->text().toInt();
        if((Etat=="")||(superfice==0)||(Valeur==0)||(Adresse_Num==0)||(Quartier=="")||(Ville=="") ||( immeuble=="")||( nb_etage==0)||(nb_chambre==0))
        {

            QMessageBox msgBox;
            msgBox.setText("Il faut Remplir tous les champs !");
            msgBox.exec();
            secondclientwindow::on_pushButton_clicked();
        }
        else
        {
        Appartement A1(9999,Etat.toStdString(),superfice,Valeur,Adresse_Num,Quartier,Ville,immeuble,nb_etage,nb_chambre);
        A1.setDispobile("non disponible") ;
        A1.afficher_bien_immobilier("hiiiiiiiiiiiiiii");
        A1.ADD_DB();
        Proposition P(ID,A1.getId());
        P.Afficher_Prop();
        qDebug()<<QString::fromStdString(P.get_Etat()) << A1.getId() ;
        if(P.ADD_DB())
        {
            QMessageBox msgBox;
            msgBox.setText("Proposition ajoutée !");
            msgBox.exec();
            secondclientwindow::on_pushButton_clicked();
            secondclientwindow::on_LoadProposition_clicked();
       }
       }
    }
   else if ( choix=="Entrepot"){


        if (RadioLocation == true)
            Etat ="Location";
        else if (RadioVente == true )
             Etat="Vente";
        string utilisation =ui->E_Combo->currentText().toStdString();

        if((Etat=="")||(superfice==0)||(Valeur==0)||(Adresse_Num==0)||(Quartier=="")||(Ville=="") ||( utilisation==""))
        {

            QMessageBox msgBox;
            msgBox.setText("Il faut Remplir tous les champs !");
            msgBox.exec();
            secondclientwindow::on_pushButton_clicked();
        }
        else
        {
        Entrepot E1(9999,Etat.toStdString(),superfice,Valeur,Adresse_Num,Quartier,Ville,utilisation);
        E1.setDispobile("non disponible") ;
        E1.afficher_bien_immobilier("hiiiiiiiiiiiiiii");
        E1.ADD_DB();
        Proposition P(ID,E1.getId());
        P.Afficher_Prop();
        qDebug()<<QString::fromStdString(P.get_Etat()) << E1.getId() ;
        if(P.ADD_DB())
        {
            QMessageBox msgBox;
            msgBox.setText("Proposition ajoutée !");
            msgBox.exec();
            secondclientwindow::on_pushButton_clicked();
        }

        }

       }
    else
        if (choix =="Terrain"){
            if (RadioLocation == true)
                Etat ="Location";
            else if (RadioVente == true )
                 Etat="Vente";
            int num_inscription = ui->T_Num_Inscri->text().toInt();
            string nature =ui->T_Comb_Nature->currentText().toStdString();
            string etat_terr =ui->T_Combo_Etat->currentText().toStdString();

            if((Etat=="")||(superfice==0)||(Valeur==0)||(Adresse_Num==0)||(Quartier=="")||(Ville=="") ||(num_inscription==0)||( nature=="")||( etat_terr==""))
            {

                QMessageBox msgBox;
                msgBox.setText("Il faut Remplir tous les champs !");
                msgBox.exec();
                secondclientwindow::on_pushButton_clicked();
            }
            else
            {
            Terrain T1(9999,Etat.toStdString(),superfice,Valeur,Adresse_Num,Quartier,Ville,num_inscription,nature,etat_terr);
            T1.setDispobile("non disponible") ;
            T1.afficher_bien_immobilier("hiiiiiiiiiiiiiii");
            T1.ADD_DB();
            Proposition P(ID,T1.getId());
            P.Afficher_Prop();
            qDebug()<<QString::fromStdString(P.get_Etat()) << T1.getId() ;

            if(P.ADD_DB())
            {
                QMessageBox msgBox;
                msgBox.setText("Proposition ajoutée !");
                msgBox.exec();
                secondclientwindow::on_pushButton_clicked();
                secondclientwindow::on_LoadProposition_clicked();
            }



             }
        }
        else {
            ui->Proposer->hide() ;
            }
}



void secondclientwindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    choix = arg1 ;
    qDebug()<<"COMBOOO"<<arg1 ;


    if ( arg1 =="Maison"){
        ui->BienFrame->show();
        ui->MaisontFrame->show();
        ui->Entrepotframe->hide();
        ui->TerrainFrame->hide();
        ui->AppartemetFrame->hide();
    }
    else if ( arg1 =="Appartement"){
        ui->BienFrame->show();
        ui->MaisontFrame->hide();
        ui->Entrepotframe->hide();
        ui->TerrainFrame->hide();
        ui->AppartemetFrame->show();
    }
   else if ( arg1 =="Entrepot"){
        ui->BienFrame->show();
        ui->MaisontFrame->hide();
        ui->Entrepotframe->show();
        ui->TerrainFrame->hide();
        ui->AppartemetFrame->hide();
       }
    else
        if ( arg1 =="Terrain")
        {
            ui->BienFrame->show();
            ui->MaisontFrame->hide();
            ui->Entrepotframe->hide();
            ui->TerrainFrame->show();
            ui->AppartemetFrame->hide();
        }
        else  if ( arg1 =="Type")
        {
            ui->BienFrame->hide();
            ui->MaisontFrame->hide();
            ui->Entrepotframe->hide();
            ui->TerrainFrame->hide();
            ui->AppartemetFrame->hide();
            ui->Proposer->hide();
        }

}

void secondclientwindow::on_radioButton_clicked()//zeyeda ta nfas5ohom
{

}

void secondclientwindow::on_radioButton_clicked(bool checked)
{
  RadioLocation = checked ;
  if (RadioLocation==true)
        ui->Proposer->show();
  else ui->Proposer->hide();
}

void secondclientwindow::on_radioButton_2_clicked(bool checked)
{
 RadioVente= checked ;
 if (RadioVente==true)
     ui->Proposer->show();
else ui->Proposer->hide();
}
//--------------------------------------------------------------------------------------------

void secondclientwindow::showInfo()
{

    QSqlQuery ClientInfo;
    ClientInfo.prepare("select * from client where id_client=?");
    ClientInfo.bindValue(0,ID);
    ClientInfo.exec();
    ClientInfo.next();
    QString nom =ClientInfo.value(1).toString();
    QString prenom =ClientInfo.value(2).toString();
    QString adresses =ClientInfo.value(3).toString();
    ui->prenom_label->setText(prenom);
    ui->nom_label->setText(nom);
    ui->email_label->setText(adresses);


}

void secondclientwindow::on_pushButton_clicked()
{


    //********************************************
    ui->ReservationTable->clearContents();
    ui->ReservationTable->setColumnCount(4);
    QStringList PropositionColumnName;
    PropositionColumnName << "Identifiant" <<"Identifiant Client"<<"Identifiant bien"<<"Acceptation" ;
    ui->ReservationTable->setHorizontalHeaderLabels( PropositionColumnName);


    QSqlQuery myquery2;
    myquery2.prepare("select  * from reservation where id_client = ? " );
    myquery2.bindValue(0,ID);
    myquery2.exec();

  /*  ui->ReservationTable->setColumnWidth(0,40);
    ui->ReservationTable->setColumnWidth(1,40);
    ui->ReservationTable->setColumnWidth(2,40);
    ui->ReservationTable->setColumnWidth(3,150);*/

    int index = 0;

    ui->ReservationTable->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->ReservationTable->setRowCount(index+1);

         ui->ReservationTable->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->ReservationTable->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->ReservationTable->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->ReservationTable->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
        index ++;
    }
    ui->ReservationTable->setSortingEnabled(true);
    ui->ReservationTable->sortByColumn(0,Qt::AscendingOrder);
}

void secondclientwindow::on_ReservationTable_cellClicked(int row, int column)
{

     QTableWidgetItem *item = new QTableWidgetItem;
     item = ui->ReservationTable->item(row,2);
     int id_bien =item->text().toInt();
     qDebug()<<item->text();
     QSqlQuery myquery1 ;
     myquery1.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND b.id_imm=?") ;
     myquery1.bindValue(0,id_bien);
     myquery1.exec();
     if (myquery1.next())
     {
         ui->ClientMaison->hide();
         ui->ClientEntrepot->show();
         ui->ClientAppartemet->hide();
         ui->ClientTerrain->hide();


        qDebug()<<"raaaak hné entrepot" ;
        ui->ClientEntrepot->setColumnCount(7);
        this->adjustTableSize();
        int index = 0;
        ui->ClientEntrepot->setSortingEnabled(false);
        QStringList BienColumnName;
       BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Utilisation";
       ui->ClientEntrepot->setHorizontalHeaderLabels(BienColumnName);
       ui->ClientEntrepot->setColumnWidth(0,80);
       ui->ClientEntrepot->setColumnWidth(1,80);
       ui->ClientEntrepot->setColumnWidth(2,80);
       ui->ClientEntrepot->setColumnWidth(3,80);
       ui->ClientEntrepot->setColumnWidth(4,150);

            //  qDebug() << "de5el " << myquery2.next();
             ui->ClientEntrepot->setRowCount(index+1);
             ui->ClientEntrepot->setItem(index,0,new QTableWidgetItem(("0000"+myquery1.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientEntrepot->setItem(index,1,new QTableWidgetItem(myquery1.value(1).toString()));
             ui->ClientEntrepot->setItem(index,2,new QTableWidgetItem(myquery1.value(2).toString()));
             ui->ClientEntrepot->setItem(index,3,new QTableWidgetItem(myquery1.value(3).toString()));
             ui->ClientEntrepot->setItem(index,4,new QTableWidgetItem(myquery1.value(4).toString()));
             ui->ClientEntrepot->setItem(index,5,new QTableWidgetItem(myquery1.value(5).toString())); //6 not 5
             ui->ClientEntrepot->setItem(index,6,new QTableWidgetItem(myquery1.value(7).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientEntrepot);







     }
     QSqlQuery myquery2 ;
     myquery2.prepare("select  * from bien_immobilier b , Appartement a where b.id_imm=a.id_imm AND b.id_imm=?") ;
     myquery2.bindValue(0,id_bien);
     myquery2.exec();
     if (myquery2.next())
     {
        ui->ClientMaison->hide();
        ui->ClientEntrepot->hide();
        ui->ClientAppartemet->show();
        ui->ClientTerrain->hide();


        qDebug()<<"raaaak hné Appartement ";
        ui->ClientAppartemet->setColumnCount(9);

        QStringList BienColumnName;
            BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nom d'immeuble"<<"Nombre d'etage"<<"Nombre de chambre";
            ui->ClientAppartemet->setHorizontalHeaderLabels(BienColumnName);

        ui->ClientAppartemet->setColumnWidth(0,80);
        ui->ClientAppartemet->setColumnWidth(1,80);
        ui->ClientAppartemet->setColumnWidth(2,80);
        ui->ClientAppartemet->setColumnWidth(3,40);
        ui->ClientAppartemet->setColumnWidth(5,90);
        ui->ClientAppartemet->setColumnWidth(6,80);
        ui->ClientAppartemet->setColumnWidth(7,80);
        this->adjustTableSize();


         int index = 0;


        //qDebug() << "de5el " << myquery2.next();
             ui->ClientAppartemet->setRowCount(index+1);
             ui->ClientAppartemet->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientAppartemet->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
             ui->ClientAppartemet->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
             ui->ClientAppartemet->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
             ui->ClientAppartemet->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
             ui->ClientAppartemet->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString()));
             ui->ClientAppartemet->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
             ui->ClientAppartemet->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));
             ui->ClientAppartemet->setItem(index,8,new QTableWidgetItem(myquery2.value(9).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientAppartemet );




     }
     QSqlQuery myquery3 ;
     myquery3.prepare("select  * from bien_immobilier b , Terrain T where b.id_imm=T.id_imm AND b.id_imm=?") ;
     myquery3.bindValue(0,id_bien);
     myquery3.exec();
     if (myquery3.next())
     {
         qDebug()<<"raaaak hné Terrain " ;
         ui->ClientMaison->hide();
         ui->ClientEntrepot->hide();
         ui->ClientAppartemet->hide();
         ui->ClientTerrain->show();

         ui->ClientTerrain->setColumnCount(9);

         QStringList BienColumnName;
         BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"nombre d'inscription"<<"nature"<<"etat" ;
         ui->ClientTerrain->setHorizontalHeaderLabels( BienColumnName);

         ui->ClientTerrain->setColumnWidth(0,80);
         ui->ClientTerrain->setColumnWidth(1,80);
         ui->ClientTerrain->setColumnWidth(2,80);
         ui->ClientTerrain->setColumnWidth(3,80);
         ui->ClientTerrain->setColumnWidth(4,150);
         ui->ClientTerrain->setColumnWidth(5,90);
         ui->ClientTerrain->setColumnWidth(6,40);
         ui->ClientTerrain->setColumnWidth(7,80);
         ui->ClientTerrain->setColumnWidth(8,80);
        //this->adjustTableSize();


         int index = 0;


       // qDebug() << "de5el " << myquery2.value(4).toString();
             ui->ClientTerrain->setRowCount(index+1);
             ui->ClientTerrain->setItem(index,0,new QTableWidgetItem(("0000"+myquery3.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientTerrain->setItem(index,1,new QTableWidgetItem(myquery3.value(1).toString()));
             ui->ClientTerrain->setItem(index,2,new QTableWidgetItem(myquery3.value(2).toString()));
             ui->ClientTerrain->setItem(index,3,new QTableWidgetItem(myquery3.value(3).toString()));
             ui->ClientTerrain->setItem(index,4,new QTableWidgetItem(myquery3.value(4).toString()));
             ui->ClientTerrain->setItem(index,5,new QTableWidgetItem(myquery3.value(6).toString()));
             ui->ClientTerrain->setItem(index,6,new QTableWidgetItem(myquery3.value(7).toString()));
             ui->ClientTerrain->setItem(index,7,new QTableWidgetItem(myquery3.value(8).toString()));
             ui->ClientTerrain->setItem(index,8,new QTableWidgetItem(myquery3.value(9).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientTerrain);



























     }
     QSqlQuery myquery4 ;
     myquery4.prepare("select  * from bien_immobilier b , Maison m where b.id_imm=m.id_imm AND b.id_imm=?") ;
     myquery4.bindValue(0,id_bien);
     myquery4.exec();
     if (myquery4.next())
     {
         ui->ClientMaison->setColumnCount(8);

         QStringList BienColumnName;
        BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nombre d'etage"<<"Nombre de chambre";
        ui->ClientMaison->setHorizontalHeaderLabels(BienColumnName);

         ui->ClientMaison->setColumnWidth(0,80);
         ui->ClientMaison->setColumnWidth(1,80);
         ui->ClientMaison->setColumnWidth(2,80);
         ui->ClientMaison->setColumnWidth(3,80);
         qDebug()<<"raaaak hné Maison" ;
         ui->ClientMaison->show();
         ui->ClientEntrepot->hide();
         ui->ClientAppartemet->hide();
         ui->ClientTerrain->hide();

        int index = 0;
            ui->ClientMaison->setRowCount(index+1);
            ui->ClientMaison->setItem(index,0,new QTableWidgetItem(("0000"+myquery4.value(0).toString()).rightRef(5).toString()  ));
            ui->ClientMaison->setItem(index,1,new QTableWidgetItem(myquery4.value(1).toString()));
            ui->ClientMaison->setItem(index,2,new QTableWidgetItem(myquery4.value(2).toString()));
            ui->ClientMaison->setItem(index,3,new QTableWidgetItem(myquery4.value(3).toString()));
            ui->ClientMaison->setItem(index,4,new QTableWidgetItem(myquery4.value(4).toString()));
            ui->ClientMaison->setItem(index,5,new QTableWidgetItem(myquery4.value(5).toString()));
            ui->ClientMaison->setItem(index,6,new QTableWidgetItem(myquery4.value(7).toString())); //6 not 5
            ui->ClientMaison->setItem(index,7,new QTableWidgetItem(myquery4.value(8).toString()));
            secondclientwindow::adjustTableSize2(ui->ClientMaison );

       }






}

void secondclientwindow::on_pushButton_3_clicked()
{

}

void secondclientwindow::on_checkBox_clicked()
{

}

void secondclientwindow::on_PropositionTable_cellClicked(int row, int column)
{
    secondclientwindow::afficherbienprop( row);
    secondclientwindow::on_LoadProposition_clicked();
}


void secondclientwindow::afficherbienprop(int row)
{


    QTableWidgetItem *item = new QTableWidgetItem;
     item = ui->PropositionTable->item(row,2);
     int id_bien =item->text().toInt();
     qDebug()<<item->text();
     QSqlQuery myquery1 ;
     myquery1.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND b.id_imm=?") ;
     myquery1.bindValue(0,id_bien);
     myquery1.exec();
     if (myquery1.next())
     {
         ui->ClientMaison_2->hide();
         ui->ClientEntrepot_2->show();
         ui->ClientAppartemet_2->hide();
         ui->ClientTerrain_2->hide();

        qDebug()<<"raaaak hné entrepot" ;
        ui->ClientEntrepot_2->setColumnCount(7);

        QStringList BienColumnName;
       BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Utilisation";
        ui->ClientEntrepot_2->setHorizontalHeaderLabels(BienColumnName);
        ui->ClientEntrepot_2->setColumnWidth(0,80);
        ui->ClientEntrepot_2->setColumnWidth(1,80);
        ui->ClientEntrepot_2->setColumnWidth(2,80);
        ui->ClientEntrepot_2->setColumnWidth(3,80);
        ui->ClientEntrepot_2->setColumnWidth(4,150);

        //this->adjustTableSize();
        int index = 0;
        ui->ClientEntrepot_2->setSortingEnabled(false);

            //  qDebug() << "de5el " << myquery2.next();
             ui->ClientEntrepot_2->setRowCount(index+1);
             ui->ClientEntrepot_2->setItem(index,0,new QTableWidgetItem(("0000"+myquery1.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientEntrepot_2->setItem(index,1,new QTableWidgetItem(myquery1.value(1).toString()));
             ui->ClientEntrepot_2->setItem(index,2,new QTableWidgetItem(myquery1.value(2).toString()));
             ui->ClientEntrepot_2->setItem(index,3,new QTableWidgetItem(myquery1.value(3).toString()));
             ui->ClientEntrepot_2->setItem(index,4,new QTableWidgetItem(myquery1.value(4).toString()));
             ui->ClientEntrepot_2->setItem(index,5,new QTableWidgetItem(myquery1.value(5).toString())); //6 not 5
             ui->ClientEntrepot_2->setItem(index,6,new QTableWidgetItem(myquery1.value(7).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientEntrepot_2);








     }
     QSqlQuery myquery2 ;
     myquery2.prepare("select  * from bien_immobilier b , Appartement a where b.id_imm=a.id_imm AND b.id_imm=?") ;
     myquery2.bindValue(0,id_bien);
     myquery2.exec();
     if (myquery2.next())
     {
         ui->ClientMaison_2->hide();
         ui->ClientEntrepot_2->hide();
         ui->ClientAppartemet_2->show();
         ui->ClientTerrain_2->hide();

        qDebug()<<"raaaak hné Appartement ";
        ui->ClientAppartemet_2->setColumnCount(9);

        QStringList BienColumnName;
            BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nom d'immeuble"<<"Nombre d'etage"<<"Nombre de chambre";
            ui->ClientAppartemet_2->setHorizontalHeaderLabels(BienColumnName);

        ui->ClientAppartemet_2->setColumnWidth(0,80);
        ui->ClientAppartemet_2->setColumnWidth(1,80);
        ui->ClientAppartemet_2->setColumnWidth(2,80);
        ui->ClientAppartemet_2->setColumnWidth(3,40);
        ui->ClientAppartemet_2->setColumnWidth(5,90);
        ui->ClientAppartemet_2->setColumnWidth(6,80);
        ui->ClientAppartemet_2->setColumnWidth(7,80);
      //  this->adjustTableSize();


         int index = 0;


        //qDebug() << "de5el " << myquery2.next();
             ui->ClientAppartemet_2->setRowCount(index+1);
             ui->ClientAppartemet_2->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientAppartemet_2->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
             ui->ClientAppartemet_2->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
             ui->ClientAppartemet_2->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
             ui->ClientAppartemet_2->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
             ui->ClientAppartemet_2->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString()));
             ui->ClientAppartemet_2->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
             ui->ClientAppartemet_2->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));
             ui->ClientAppartemet_2->setItem(index,8,new QTableWidgetItem(myquery2.value(9).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientAppartemet_2);



     }
     QSqlQuery myquery3 ;
     myquery3.prepare("select  * from bien_immobilier b , Terrain T where b.id_imm=T.id_imm AND b.id_imm=?") ;
     myquery3.bindValue(0,id_bien);
     myquery3.exec();
     if (myquery3.next())
     {
        qDebug()<<"raaaak hné Terrain " ;
        ui->ClientMaison_2->hide();
        ui->ClientEntrepot_2->hide();
        ui->ClientAppartemet_2->hide();
        ui->ClientTerrain_2->show();

        ui->ClientTerrain_2->setColumnCount(9);

        QStringList BienColumnName;
        BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"nombre d'inscription"<<"nature"<<"etat" ;
        ui->ClientTerrain_2->setHorizontalHeaderLabels( BienColumnName);

        ui->ClientTerrain_2->setColumnWidth(0,80);
        ui->ClientTerrain_2->setColumnWidth(1,80);
        ui->ClientTerrain_2->setColumnWidth(2,80);
        ui->ClientTerrain_2->setColumnWidth(3,80);
        ui->ClientTerrain_2->setColumnWidth(4,150);
        ui->ClientTerrain_2->setColumnWidth(5,90);
        ui->ClientTerrain_2->setColumnWidth(6,40);
        ui->ClientTerrain_2->setColumnWidth(7,80);
        ui->ClientTerrain_2->setColumnWidth(8,80);
        //this->adjustTableSize();


         int index = 0;


       // qDebug() << "de5el " << myquery2.value(4).toString();
             ui->ClientTerrain_2->setRowCount(index+1);
             ui->ClientTerrain_2->setItem(index,0,new QTableWidgetItem(("0000"+myquery3.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientTerrain_2->setItem(index,1,new QTableWidgetItem(myquery3.value(1).toString()));
             ui->ClientTerrain_2->setItem(index,2,new QTableWidgetItem(myquery3.value(2).toString()));
             ui->ClientTerrain_2->setItem(index,3,new QTableWidgetItem(myquery3.value(3).toString()));
             ui->ClientTerrain_2->setItem(index,4,new QTableWidgetItem(myquery3.value(4).toString()));
             ui->ClientTerrain_2->setItem(index,5,new QTableWidgetItem(myquery3.value(6).toString()));
             ui->ClientTerrain_2->setItem(index,6,new QTableWidgetItem(myquery3.value(7).toString()));
             ui->ClientTerrain_2->setItem(index,7,new QTableWidgetItem(myquery3.value(8).toString()));
             ui->ClientTerrain_2->setItem(index,8,new QTableWidgetItem(myquery3.value(9).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientTerrain_2);













     }
     QSqlQuery myquery4 ;
     myquery4.prepare("select  * from bien_immobilier b , Maison m where b.id_imm=m.id_imm AND b.id_imm=?") ;
     myquery4.bindValue(0,id_bien);
     myquery4.exec();
     if (myquery4.next())
     {
        ui->ClientMaison_2->setColumnCount(8);

        QStringList BienColumnName;
       BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nombre d'etage"<<"Nombre de chambre";
       ui->ClientMaison_2->setHorizontalHeaderLabels(BienColumnName);

        ui->ClientMaison_2->setColumnWidth(0,80);
        ui->ClientMaison_2->setColumnWidth(1,80);
        ui->ClientMaison_2->setColumnWidth(2,80);
        ui->ClientMaison_2->setColumnWidth(3,80);
        qDebug()<<"raaaak hné Maison" ;
        ui->ClientMaison_2->show();
        ui->ClientEntrepot_2->hide();
        ui->ClientAppartemet_2->hide();
        ui->ClientTerrain_2->hide();

        int index = 0;
            ui->ClientMaison_2->setRowCount(index+1);
            ui->ClientMaison_2->setItem(index,0,new QTableWidgetItem(("0000"+myquery4.value(0).toString()).rightRef(5).toString()  ));
            ui->ClientMaison_2->setItem(index,1,new QTableWidgetItem(myquery4.value(1).toString()));
            ui->ClientMaison_2->setItem(index,2,new QTableWidgetItem(myquery4.value(2).toString()));
            ui->ClientMaison_2->setItem(index,3,new QTableWidgetItem(myquery4.value(3).toString()));
            ui->ClientMaison_2->setItem(index,4,new QTableWidgetItem(myquery4.value(4).toString()));
            ui->ClientMaison_2->setItem(index,5,new QTableWidgetItem(myquery4.value(5).toString()));
            ui->ClientMaison_2->setItem(index,6,new QTableWidgetItem(myquery4.value(7).toString())); //6 not 5
            ui->ClientMaison_2->setItem(index,7,new QTableWidgetItem(myquery4.value(8).toString()));
            secondclientwindow::adjustTableSize2(ui->ClientMaison_2);


       }


}

void secondclientwindow::on_LoadProposition_clicked()
{
    ui->PropositionTable->clearContents();
    ui->PropositionTable->setRowCount(0);
    ui->PropositionTable->setColumnCount(4);
    QStringList PropositionColumnName;
    PropositionColumnName << "Identifiant" <<"Identifiant Client"<<"Identifiant bien"<<"Acceptation" ;
    ui->PropositionTable->setHorizontalHeaderLabels( PropositionColumnName);

    QSqlQuery myquery;
       myquery.prepare("select  * from proposition where etat=? " );
       myquery.bindValue(0,"Non_Accepte");
       myquery.exec();


       ui->PropositionTable->clearContents();
      /* ui->PropositionTable->setColumnCount(4);
       ui->PropositionTable->setColumnWidth(0,40);
       ui->PropositionTable->setColumnWidth(1,40);
       ui->PropositionTable->setColumnWidth(2,40);
       ui->PropositionTable->setColumnWidth(3,150);*/



        int index = 0;

       ui->PropositionTable->setSortingEnabled(false);

       while(myquery.next())
        {   //  qDebug() << "de5el " << myquery2.next();
            ui->PropositionTable->setRowCount(index+1);

            ui->PropositionTable->setItem(index,0,new QTableWidgetItem(("0000"+myquery.value(0).toString()).rightRef(5).toString()  ));
            ui->PropositionTable->setItem(index,1,new QTableWidgetItem(myquery.value(1).toString()));
            ui->PropositionTable->setItem(index,2,new QTableWidgetItem(myquery.value(2).toString()));
            ui->PropositionTable->setItem(index,3,new QTableWidgetItem(myquery.value(3).toString()));
           index ++;
       }
       ui->PropositionTable->setSortingEnabled(true);
       ui->PropositionTable->sortByColumn(0,Qt::AscendingOrder);
       secondclientwindow::adjustTableSize2(ui->PropositionTable,1);
}
//**********************************************************************************

void secondclientwindow::on_loadContratLoc_clicked()
{

    QSqlQuery myquery2;
    myquery2.prepare("select * from contrat c , contratlocation l  where c.id_contrat=l.id_contrat AND c.id_client=? ;" );
    myquery2.bindValue(0,ID);
    myquery2.exec();

    ui->LocationTable->setRowCount(0);
    ui->LocationTable->clearContents();
    ui->LocationTable->setColumnCount(9);
  /*  ui->LocationTable->setColumnWidth(0,40);
    ui->LocationTable->setColumnWidth(1,40);
    ui->LocationTable->setColumnWidth(2,40);
    ui->LocationTable->setColumnWidth(3,150);
    ui->LocationTable->setColumnWidth(4,120);
    ui->LocationTable->setColumnWidth(5,80);
    ui->LocationTable->setColumnWidth(6,80);
    ui->LocationTable->setRowCount(0);*/




    int index2 = 0;



    while(myquery2.next())
     {
        //  qDebug() << "de5el " << myquery2.next();
         ui->LocationTable->setRowCount(index2+1);
         ui->LocationTable->setItem(index2,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->LocationTable->setItem(index2,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->LocationTable->setItem(index2,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->LocationTable->setItem(index2,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->LocationTable->setItem(index2,4,new QTableWidgetItem(myquery2.value(5).toString()));
         ui->LocationTable->setItem(index2,5,new QTableWidgetItem(myquery2.value(6).toString()));
         ui->LocationTable->setItem(index2,6,new QTableWidgetItem(myquery2.value(7).toString()));
         ui->LocationTable->setItem(index2,7,new QTableWidgetItem(myquery2.value(8).toString().leftRef(10).toString()));
         ui->LocationTable->setItem(index2,8,new QTableWidgetItem(myquery2.value(9).toString().leftRef(10).toString()));

        index2 ++;
    }
    ui->LocationTable->setSortingEnabled(true);
    ui->LocationTable->sortByColumn(0,Qt::AscendingOrder);
    secondclientwindow::adjustTableSize2(ui->LocationTable,1);









}
void secondclientwindow::on_LoadContratVente_clicked()
{



    ui->VenteTable->setRowCount(0);
    ui->VenteTable->clearContents();

    QSqlQuery myquery2;
    myquery2.prepare("select * from contrat c , contratachat a where c.id_contrat=a.id_contrat AND c.id_client=? ;" );
    myquery2.bindValue(0,ID);
    myquery2.exec();

    int index2 = 0;

    ui->VenteTable->setSortingEnabled(false);

    while(myquery2.next())
     {
        //  qDebug() << "de5el " << myquery2.next();
         ui->VenteTable->setRowCount(index2+1);
         ui->VenteTable->setItem(index2,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->VenteTable->setItem(index2,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->VenteTable->setItem(index2,2,new QTableWidgetItem(QString::number(myquery2.value(2).toFloat(),'f',2)));
         ui->VenteTable->setItem(index2,3,new QTableWidgetItem(myquery2.value(3).toString()));

                                      //QString::number( 2.5275862068965517, 'f', 2);
         ui->VenteTable->setItem(index2,4,new QTableWidgetItem(myquery2.value(5).toString()));
         ui->VenteTable->setItem(index2,5,new QTableWidgetItem(myquery2.value(6).toString()));
         ui->VenteTable->setItem(index2,6,new QTableWidgetItem(myquery2.value(7).toString().leftRef(10).toString()));
        index2 ++;
    }
    ui->VenteTable->setSortingEnabled(true);
    ui->VenteTable->sortByColumn(0,Qt::AscendingOrder);
    secondclientwindow::adjustTableSize2(ui->VenteTable,1);
}
void secondclientwindow::afficherBienContrat(int row,QTableWidget * t )
{



    QTableWidgetItem *item = new QTableWidgetItem;
     item = t->item(row,1);
     int id_bien =item->text().toInt();
     qDebug()<<item->text();
     QSqlQuery myquery1 ;
     myquery1.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND b.id_imm=?") ;
     myquery1.bindValue(0,id_bien);
     myquery1.exec();
     if (myquery1.next())
     {
         ui->ClientMaison_3->hide();
         ui->ClientEntrepot_3->show();
         ui->ClientAppartemet_3->hide();
         ui->ClientTerrain_3->hide();

        qDebug()<<"raaaak hné entrepot" ;
        ui->ClientEntrepot_3->setColumnCount(7);

        QStringList BienColumnName;
       BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Utilisation";
        ui->ClientEntrepot_3->setHorizontalHeaderLabels(BienColumnName);
        ui->ClientEntrepot_3->setColumnWidth(0,80);
        ui->ClientEntrepot_3->setColumnWidth(1,80);
        ui->ClientEntrepot_3->setColumnWidth(2,80);
        ui->ClientEntrepot_3->setColumnWidth(3,80);
        ui->ClientEntrepot_3->setColumnWidth(4,150);
        //this->adjustTableSize();
        int index = 0;
        ui->ClientEntrepot_3->setSortingEnabled(false);

            //  qDebug() << "de5el " << myquery2.next();
             ui->ClientEntrepot_3->setRowCount(index+1);
             ui->ClientEntrepot_3->setItem(index,0,new QTableWidgetItem(("0000"+myquery1.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientEntrepot_3->setItem(index,1,new QTableWidgetItem(myquery1.value(1).toString()));
             ui->ClientEntrepot_3->setItem(index,2,new QTableWidgetItem(myquery1.value(2).toString()));
             ui->ClientEntrepot_3->setItem(index,3,new QTableWidgetItem(myquery1.value(3).toString()));
             ui->ClientEntrepot_3->setItem(index,4,new QTableWidgetItem(myquery1.value(4).toString()));
             ui->ClientEntrepot_3->setItem(index,5,new QTableWidgetItem(myquery1.value(5).toString())); //6 not 5
             ui->ClientEntrepot_3->setItem(index,6,new QTableWidgetItem(myquery1.value(7).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientEntrepot_3);









     }
     QSqlQuery myquery2 ;
     myquery2.prepare("select  * from bien_immobilier b , Appartement a where b.id_imm=a.id_imm AND b.id_imm=?") ;
     myquery2.bindValue(0,id_bien);
     myquery2.exec();
     if (myquery2.next())
     {
         ui->ClientMaison_3->hide();
         ui->ClientEntrepot_3->hide();
         ui->ClientAppartemet_3->show();
         ui->ClientTerrain_3->hide();

        qDebug()<<"raaaak hné Appartement ";
        ui->ClientAppartemet_3->setColumnCount(9);
        QStringList BienColumnName;
            BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nom d'immeuble"<<"Nombre d'etage"<<"Nombre de chambre";
            ui->ClientAppartemet_3->setHorizontalHeaderLabels(BienColumnName);

        ui->ClientAppartemet_3->setColumnWidth(0,80);
        ui->ClientAppartemet_3->setColumnWidth(1,80);
        ui->ClientAppartemet_3->setColumnWidth(2,80);
        ui->ClientAppartemet_3->setColumnWidth(3,40);
        ui->ClientAppartemet_3->setColumnWidth(5,90);
        ui->ClientAppartemet_3->setColumnWidth(6,40);
        ui->ClientAppartemet_3->setColumnWidth(7,40);
      //  this->adjustTableSize();


         int index = 0;


        //qDebug() << "de5el " << myquery2.next();
             ui->ClientAppartemet_3->setRowCount(index+1);
             ui->ClientAppartemet_3->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientAppartemet_3->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
             ui->ClientAppartemet_3->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
             ui->ClientAppartemet_3->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
             ui->ClientAppartemet_3->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
             ui->ClientAppartemet_3->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString()));
             ui->ClientAppartemet_3->setItem(index,6,new QTableWidgetItem(myquery2.value(7).toString()));
             ui->ClientAppartemet_3->setItem(index,7,new QTableWidgetItem(myquery2.value(8).toString()));
             ui->ClientAppartemet_3->setItem(index,8,new QTableWidgetItem(myquery2.value(9).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientAppartemet_3);




     }
     QSqlQuery myquery3 ;
     myquery3.prepare("select  * from bien_immobilier b , Terrain T where b.id_imm=T.id_imm AND b.id_imm=?") ;
     myquery3.bindValue(0,id_bien);
     myquery3.exec();
     if (myquery3.next())
     {
        qDebug()<<"raaaak hné Terrain " ;
        ui->ClientMaison_3->hide();
        ui->ClientEntrepot_3->hide();
        ui->ClientAppartemet_3->hide();
        ui->ClientTerrain_3->show();

        ui->ClientTerrain_3->setColumnCount(9);
        QStringList BienColumnName;
        BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"nombre d'inscription"<<"nature"<<"etat" ;
        ui->ClientTerrain_3->setHorizontalHeaderLabels( BienColumnName);

        ui->ClientTerrain_3->setColumnWidth(0,80);
        ui->ClientTerrain_3->setColumnWidth(1,80);
        ui->ClientTerrain_3->setColumnWidth(2,80);
        ui->ClientTerrain_3->setColumnWidth(3,80);
        ui->ClientTerrain_3->setColumnWidth(4,150);
        ui->ClientTerrain_3->setColumnWidth(5,90);
        ui->ClientTerrain_3->setColumnWidth(6,40);
        ui->ClientTerrain_3->setColumnWidth(7,80);
        ui->ClientTerrain_3->setColumnWidth(8,80);
        //this->adjustTableSize();


         int index = 0;


       // qDebug() << "de5el " << myquery2.value(4).toString();
             ui->ClientTerrain_3->setRowCount(index+1);
             ui->ClientTerrain_3->setItem(index,0,new QTableWidgetItem(("0000"+myquery3.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientTerrain_3->setItem(index,1,new QTableWidgetItem(myquery3.value(1).toString()));
             ui->ClientTerrain_3->setItem(index,2,new QTableWidgetItem(myquery3.value(2).toString()));
             ui->ClientTerrain_3->setItem(index,3,new QTableWidgetItem(myquery3.value(3).toString()));
             ui->ClientTerrain_3->setItem(index,4,new QTableWidgetItem(myquery3.value(4).toString()));
             ui->ClientTerrain_3->setItem(index,5,new QTableWidgetItem(myquery3.value(5).toString()));
             ui->ClientTerrain_3->setItem(index,6,new QTableWidgetItem(myquery3.value(7).toString()));
             ui->ClientTerrain_3->setItem(index,7,new QTableWidgetItem(myquery3.value(8).toString()));
             ui->ClientTerrain_3->setItem(index,8,new QTableWidgetItem(myquery3.value(9).toString()));
             secondclientwindow::adjustTableSize2(ui->ClientTerrain_3);

     }
     QSqlQuery myquery4 ;
     myquery4.prepare("select  * from bien_immobilier b , Maison m where b.id_imm=m.id_imm AND b.id_imm=?") ;
     myquery4.bindValue(0,id_bien);
     myquery4.exec();
     if (myquery4.next())
     {
        ui->ClientMaison_3->setColumnCount(8);
        QStringList BienColumnName;
       BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nombre d'etage"<<"Nombre de chambre";
       ui->ClientMaison_3->setHorizontalHeaderLabels(BienColumnName);
       ui->ClientMaison_3->setColumnWidth(0,80);
       ui->ClientMaison_3->setColumnWidth(1,80);
       ui->ClientMaison_3->setColumnWidth(2,80);
       ui->ClientMaison_3->setColumnWidth(3,80);
        qDebug()<<"raaaak hné Maison" ;
        ui->ClientMaison_3->show();
        ui->ClientEntrepot_3->hide();
        ui->ClientAppartemet_3->hide();
        ui->ClientTerrain_3->hide();

        int index = 0;
            ui->ClientMaison_3->setRowCount(index+1);
            ui->ClientMaison_3->setItem(index,0,new QTableWidgetItem(("0000"+myquery4.value(0).toString()).rightRef(5).toString()  ));
            ui->ClientMaison_3->setItem(index,1,new QTableWidgetItem(myquery4.value(1).toString()));
            ui->ClientMaison_3->setItem(index,2,new QTableWidgetItem(myquery4.value(2).toString()));
            ui->ClientMaison_3->setItem(index,3,new QTableWidgetItem(myquery4.value(3).toString()));
            ui->ClientMaison_3->setItem(index,4,new QTableWidgetItem(myquery4.value(4).toString()));
            ui->ClientMaison_3->setItem(index,5,new QTableWidgetItem(myquery4.value(5).toString()));
            ui->ClientMaison_3->setItem(index,6,new QTableWidgetItem(myquery4.value(7).toString())); //6 not 5
            ui->ClientMaison_3->setItem(index,7,new QTableWidgetItem(myquery4.value(8).toString()));
            secondclientwindow::adjustTableSize2(ui->ClientMaison_3);


       }



}
void secondclientwindow::on_LocationTable_cellClicked(int row, int column)
{
     secondclientwindow::afficherBienContrat(row,ui->LocationTable);
}
void secondclientwindow::on_VenteTable_cellClicked(int row, int column)
{
    secondclientwindow::afficherBienContrat(row,ui->VenteTable);
}



//*****************************************************************************************

void secondclientwindow::on_pushButton_2_clicked()//zeyda
{
    this->hide();
}


void secondclientwindow::on_pushButton_4_clicked() //déconnexion
{
    ClientWindow * cl2 = new ClientWindow();
    cl2->show();
    this->hide();

}

void secondclientwindow::on_comboBox_activated(const QString &arg1)
{

}

void secondclientwindow::on_ReservationTable_itemEntered(QTableWidgetItem *item)
{

}
void secondclientwindow::on_ReservationTable_cellChanged(int row, int column)
{
   //QTableWidgetItem *it = new QTableWidgetItem();

   qDebug()<<ui->ReservationTable->item(row,column)->text();

}
