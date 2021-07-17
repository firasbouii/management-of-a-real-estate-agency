#include "admin.h"
#include<QFloat16>
#include "ui_admin.h"
#include"NewQTABdesign.h"
#include"clientwindow.h"
#include"bien_immobilier.h"
#include"maison.h"
#include <QCursor>
#include"entrepot.h"
#include"terrain.h"
#include"appartement.h"
#include"qtablewidget.h"
#include <QWidget>
#include"reservation.h"
#include"proposition.h"
#include"contrat.h"
#include"contratlocation.h"
#include"contratachat.h"
#include"QProcess"
#include<QMessageBox>
#include <QLayout>
#include<QDateEdit>

bool accepter = false ;
bool accepterPro=false ;
//************** variable globale********************

bool  Ventechecked2=false  ;
bool  Locationchecked2=false ;
bool disponible=true ;

//-------------- fin variable globale*-----------------------

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    ui->ClientMaison->hide();
    ui->ClientEntrepot->hide();
    ui->ClientAppartemet->hide();
    ui->ClientTerrain->hide();

    ui->ClientMaison_3->hide();
    ui->ClientEntrepot_3->hide();
    ui->ClientAppartemet_3->hide();
    ui->ClientTerrain_3->hide();

    ui->ClientMaison_2->hide();
    ui->ClientEntrepot_2->hide();
    ui->ClientAppartemet_2->hide();
    ui->ClientTerrain_2->hide();

    QStringList ClientColumnName;
     ClientColumnName << "Identifiant" << "NOM" << "prenom"<<"EMAIL" << "NUM_TEL"<< "ADRESSE"<<"DATE_NAISSANCE";
    ui->tablew2->setHorizontalHeaderLabels( ClientColumnName);


    ui->LocationTable->setColumnCount(9);
    Admin::adjustTableSize(ui->LocationTable,1);
    QStringList ContratLoc;
    ContratLoc << "Identifiant "  <<"Identifiant"<<"Identifiant Client"<<"Comission"<<"Pourcentage loc"<<"Valeur du bien" <<"à payer (dt)"<< "Date Debut"<<"Date Fin";
    ui->LocationTable->setHorizontalHeaderLabels(ContratLoc);

    ui->VenteTable->setColumnCount(7);
    Admin::adjustTableSize(ui->VenteTable,1);
    QStringList ContratAchat;
    ContratAchat << "Identifiant "  <<"Identifiant"<<"Identifiant Client"<<"Comission"<<"Valeur du bien" <<"à payer (dt)"<< "Date  ";
    ui->VenteTable->setHorizontalHeaderLabels(ContratAchat);

    ui->PropositionTable_2->setColumnCount(4);
    QStringList PropositionColumnNam;
    PropositionColumnNam << "Identifiant" << "Identifiant Client"<<"Identifiant bien"<<"Acceptation" ;
    ui->PropositionTable_2->setHorizontalHeaderLabels( PropositionColumnNam);

    ui->ReservationTable_2->setColumnCount(4);
    PropositionColumnNam << "Identifiant" <<  "Identifiant Client"<<"Identifiant bien"<<"Acceptation" ;
    ui->ReservationTable_2->setHorizontalHeaderLabels( PropositionColumnNam);
    Admin::adjustTableSize(ui->ReservationTable_2,1);
    Admin::adjustTableSize(ui->PropositionTable_2,1);

    ui->tabWidget->setTabText(0, "Page d'acceuil");
    ui->tabWidget->setTabText(1, "Reservation et Proposition");
    ui->tabWidget->setTabText(2, "Les Biens");
    ui->tabWidget->setTabText(3, "Les Clients");
    ui->tabWidget->setTabText(4, "Contrat");





}

Admin::~Admin()
{
    delete ui;
}

//------------------Reservation-----------------
void Admin::on_LoadReservation_clicked()
{
    ui->ReservationTable->setRowCount(0);
    ui->ReservationTable->setColumnCount(4);
    QStringList PropositionColumnName;
    PropositionColumnName << "Identifiant" <<"Identifiant Client"<<"Identifiant bien"<<"Acceptation" ;
    ui->ReservationTable->setHorizontalHeaderLabels( PropositionColumnName);


    QSqlQuery myquery;
    myquery.prepare("select  * from reservation where etat=? OR etat=?" );
    myquery.bindValue(0,"Non_Accepte");
    myquery.bindValue(1,"NonAccepte");
    myquery.exec();
    ui->ReservationTable->clearContents();
   /* ui->ReservationTable->setColumnCount(4);
    ui->ReservationTable->setColumnWidth(0,40);
    ui->ReservationTable->setColumnWidth(1,40);
    ui->ReservationTable->setColumnWidth(2,40);
    ui->ReservationTable->setColumnWidth(3,150);*/
    ui->ReservationTable->setRowCount(0);



    int index = 0;

    ui->ReservationTable->setSortingEnabled(false);

    while(myquery.next())
     {
        //  qDebug() << "de5el " << myquery2.next();
         ui->ReservationTable->setRowCount(index+1);
         ui->ReservationTable->setItem(index,0,new QTableWidgetItem(("0000"+myquery.value(0).toString()).rightRef(5).toString()  ));
         ui->ReservationTable->setItem(index,1,new QTableWidgetItem(myquery.value(1).toString()));
         ui->ReservationTable->setItem(index,2,new QTableWidgetItem(myquery.value(2).toString()));
         ui->ReservationTable->setItem(index,3,new QTableWidgetItem(myquery.value(3).toString()));
        index ++;
    }
    ui->ReservationTable->setSortingEnabled(true);
    ui->ReservationTable->sortByColumn(0,Qt::AscendingOrder);
    Admin::adjustTableSize(ui->ReservationTable,1);




}
void Admin::afficherBien(int row)
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


        QStringList BienColumnName;
       BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Utilisation";
       ui->ClientEntrepot->setHorizontalHeaderLabels(BienColumnName);

        //this->adjustTableSize();
        int index = 0;
        ui->ClientEntrepot->setSortingEnabled(false);

            //  qDebug() << "de5el " << myquery2.next();
             ui->ClientEntrepot->setRowCount(index+1);
             ui->ClientEntrepot->setItem(index,0,new QTableWidgetItem(("0000"+myquery1.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientEntrepot->setItem(index,1,new QTableWidgetItem(myquery1.value(1).toString()));
             ui->ClientEntrepot->setItem(index,2,new QTableWidgetItem(myquery1.value(2).toString()));
             ui->ClientEntrepot->setItem(index,3,new QTableWidgetItem(myquery1.value(3).toString()));
             ui->ClientEntrepot->setItem(index,4,new QTableWidgetItem(myquery1.value(4).toString()));
             ui->ClientEntrepot->setItem(index,5,new QTableWidgetItem(myquery1.value(5).toString())); //6 not 5
             ui->ClientEntrepot->setItem(index,6,new QTableWidgetItem(myquery1.value(7).toString()));
             Admin::adjustTableSize(ui->ClientEntrepot);









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

        QStringList BienColumnName;
         ui->ClientAppartemet->setColumnCount(9);
        BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nom d'immeuble"<<"Nombre d'etage"<<"Nombre de chambre";
        ui->ClientAppartemet->setHorizontalHeaderLabels(BienColumnName);
        qDebug()<<"raaaak hné Appartement ";

        ui->ClientAppartemet->setColumnWidth(0,40);
        ui->ClientAppartemet->setColumnWidth(1,40);
        ui->ClientAppartemet->setColumnWidth(2,40);
        ui->ClientAppartemet->setColumnWidth(3,40);
        ui->ClientAppartemet->setColumnWidth(5,90);
        ui->ClientAppartemet->setColumnWidth(6,40);
        ui->ClientAppartemet->setColumnWidth(7,40);
      //  this->adjustTableSize();


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
             Admin::adjustTableSize(ui->ClientAppartemet);




     }
     QSqlQuery myquery3 ;
     myquery3.prepare("select  * from bien_immobilier b , Terrain T where b.id_imm=T.id_imm AND b.id_imm=?") ;
     myquery3.bindValue(0,id_bien);
     myquery3.exec();
     if (myquery3.next())
     {
        qDebug()<<"raaaak hné Terrain1 " ;
        ui->ClientMaison->hide();
        ui->ClientEntrepot->hide();
        ui->ClientAppartemet->hide();
        ui->ClientTerrain->show();


        ui->ClientTerrain->setColumnCount(9);
      /*  ui->ClientTerrain->setColumnWidth(0,40);
        ui->ClientTerrain->setColumnWidth(1,40);
        ui->ClientTerrain->setColumnWidth(2,40);
        ui->ClientTerrain->setColumnWidth(3,40);
        ui->ClientTerrain->setColumnWidth(4,150);
        ui->ClientTerrain->setColumnWidth(5,90);
        ui->ClientTerrain->setColumnWidth(6,40);
        ui->ClientTerrain->setColumnWidth(7,80);
        ui->ClientTerrain->setColumnWidth(8,80);*/
        //this->adjustTableSize();


        QStringList BienColumnName;
        BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"nombre d'inscription"<<"nature"<<"etat" ;
        ui->ClientTerrain->setHorizontalHeaderLabels( BienColumnName);

         int index = 0;


       // qDebug() << "de5el " << myquery2.value(4).toString();
             ui->ClientTerrain->setRowCount(index+1);
             ui->ClientTerrain->setItem(index,0,new QTableWidgetItem(("0000"+myquery3.value(0).toString()).rightRef(5).toString()  ));
             ui->ClientTerrain->setItem(index,1,new QTableWidgetItem(myquery3.value(1).toString()));
             ui->ClientTerrain->setItem(index,2,new QTableWidgetItem(myquery3.value(2).toString()));
             ui->ClientTerrain->setItem(index,3,new QTableWidgetItem(myquery3.value(3).toString()));
             ui->ClientTerrain->setItem(index,4,new QTableWidgetItem(myquery3.value(4).toString()));
             ui->ClientTerrain->setItem(index,5,new QTableWidgetItem(myquery3.value(5).toString()));
             ui->ClientTerrain->setItem(index,6,new QTableWidgetItem(myquery3.value(7).toString()));
             ui->ClientTerrain->setItem(index,7,new QTableWidgetItem(myquery3.value(8).toString()));
             ui->ClientTerrain->setItem(index,8,new QTableWidgetItem(myquery3.value(9).toString()));
             Admin::adjustTableSize(ui->ClientTerrain);

     }
     QSqlQuery myquery4 ;
     myquery4.prepare("select  * from bien_immobilier b , Maison m where b.id_imm=m.id_imm AND b.id_imm=?") ;
     myquery4.bindValue(0,id_bien);
     myquery4.exec();
     if (myquery4.next())
     {
        ui->ClientMaison->setColumnCount(8);
        qDebug()<<"raaaak hné Maison" ;
        ui->ClientMaison->show();
        ui->ClientEntrepot->hide();
        ui->ClientAppartemet->hide();
        ui->ClientTerrain->hide();
        QStringList BienColumnName;
       BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nombre d'etage"<<"Nombre de chambre";
       ui->ClientMaison->setHorizontalHeaderLabels(BienColumnName);


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
            Admin::adjustTableSize(ui->ClientMaison);


       }



}


void Admin::on_ReservationTable_cellClicked(int row, int column)
{
    if (accepter==false)
    {
        Admin::afficherBien(row);

    }
    else {
        QTableWidgetItem *itembien = new QTableWidgetItem;
        QTableWidgetItem *itemres = new QTableWidgetItem;
        itembien = ui->ReservationTable->item(row,2);
        itemres = ui->ReservationTable->item(row,0);        
        int id_client = ui->ReservationTable->item(row,1)->text().toInt();
        int id_bien =itembien->text().toInt();

        int id_res =itemres->text().toInt();

        qDebug()<<id_bien<<" "<<id_res ;





        QSqlQuery typecontrat;
        typecontrat.prepare("select etat , Valeur from bien_immobilier where id_imm=?");
        typecontrat.bindValue(0,id_bien);
        typecontrat.exec();
        typecontrat.next();
        QString typec = typecontrat.value(0).toString();
        int Valeur = typecontrat.value(1).toInt();
        if(typec=="Location")
        {    qDebug()<<"typec=Location";
            QSqlQuery q ;
            q.prepare("update bien_immobilier set etat=? where id_imm=? AND etat=?");
            q.bindValue(0,"Loue");
            q.bindValue(1,id_bien);
            q.bindValue(2,"Location");
            q.exec();
            QMessageBox mb;
            QLineEdit le;
            QLabel la;
            QLabel la2;
            QPushButton bt;
            QDateEdit d ;
            QDateEdit d2;
            la2.setText("Date Fin du Contrat");
            la.setText("Date Debut du Contrat");
            mb.layout()->addWidget(&la);
            mb.layout()->addWidget(&d);
            mb.layout()->addWidget(&la2);
            mb.layout()->addWidget(&d2);

            mb.exec();
            int year = d.date().year();
            int month = d.date().month();
            int day = d.date().day();
            int year2 = d2.date().year();
            int month2 = d2.date().month();
            int day2 = d2.date().day();
            ContratLocation c2(  id_bien , id_client , 0.02 ,  0.05,  day , month,  year,day2,month2,year2,Valeur);
            c2.setMont_a_payer();
            c2.afficher_contrat();
            c2.ADD_DB();


            QSqlQuery ARES;
            ARES.prepare("update reservation set etat= ? where id_reservation=? ");
            ARES.bindValue(0,"Accepte");
            ARES.bindValue(1,id_res);
            bool t = ARES.exec();
            QSqlQuery ABien;

            ABien.prepare("update bien_immobilier set disponible= ? where id_imm=? ");
            ABien.bindValue(0,"non disponible");
            ABien.bindValue(1,id_bien);
            ABien.exec();
            if ( t && ABien.exec())
            {
                QMessageBox msgBox;
                msgBox.setText("Reservation acceptée !");
                msgBox.exec();


            }

            QSqlQuery mail;
            mail.prepare("select EMAIL from client where id_client=?");
            mail.bindValue(0,id_client);
            mail.exec();
            if(mail.next())
            {

                QString email =mail.value(0).toString();
                QStringList arguments;
                qDebug()<<QCoreApplication::applicationDirPath();
                arguments<<"C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/debug/SendingResEmails.py"<<email;
                QProcess p;
                p.start("python", arguments);
                p.waitForFinished();
            }

        }

        else if (typec=="Vente") {
            qDebug()<<"typec=Vente";
            QSqlQuery q2;
            q2.prepare("update bien_immobilier set etat=? where id_imm=? AND etat=?");
            q2.bindValue(0,"Vendu");
            q2.bindValue(1,id_bien);
            q2.bindValue(2,"Vente");
            q2.exec();
            QMessageBox mb;
            QLineEdit le;
            QLabel la;
            QPushButton bt;
            QDateEdit d ;
            la.setText("Taper Date du Contrat");
            mb.layout()->addWidget(&la);
            mb.layout()->addWidget(&d);
            mb.exec();
            int year = d.date().year();
            int month = d.date().month();
            int day = d.date().day();



            ContratAchat c3( id_bien , id_client , 0.02  ,day ,month ,year ,0, Valeur );
            c3.setMont_a_payer();
            c3.afficher_contrat();
            c3.ADD_DB();

            QSqlQuery ARES;
            ARES.prepare("update reservation set etat= ? where id_reservation=? ");

            ARES.bindValue(0,"Accepte");
            ARES.bindValue(1,id_res);
            bool t = ARES.exec();
            QSqlQuery ABien;

            ABien.prepare("update bien_immobilier set disponible= ? where id_imm=? ");
            ABien.bindValue(0,"non disponible");
            ABien.bindValue(1,id_bien);


            if ( t && ABien.exec())
            {
                QMessageBox msgBox;
                msgBox.setText("Reservation acceptée !");
                msgBox.exec();


            }

            //*********************************************************ZEYED
            QSqlQuery mail;
            mail.prepare("select EMAIL from client where id_client=?");
            mail.bindValue(0,id_client);
            mail.exec();
            if(mail.next())
            {

                QString email =mail.value(0).toString();
                QStringList arguments;
                qDebug()<<QCoreApplication::applicationDirPath();
                arguments<<"C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/debug/SendingResEmails.py"<<email;
                QProcess p;
                p.start("python", arguments);
                p.waitForFinished();
            }

        }

        //nbadlou el disponible ->nondispo
        //nbadlou el etat loué vendu
        //nasn3ou el contrat mte3na w client ywali ynagm yra el contrat hetha fel interface mte3ou
        //goto



        Admin::afficherBien(row);

        accepter=false;
        Admin::on_LoadReservation_clicked();
    }
}

void Admin::on_AccepterRes_clicked(){accepter=true ;}


//--------------------Proposition----------------

void Admin::afficherbienprop(int row)
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
            Admin::adjustTableSize(ui->ClientEntrepot_2);








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
             Admin::adjustTableSize(ui->ClientAppartemet_2);



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
             Admin::adjustTableSize(ui->ClientTerrain_2);












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
            Admin::adjustTableSize(ui->ClientMaison_2);


       }


}
void Admin::on_PropositionTable_cellClicked(int row, int column)
{
    if (accepterPro==false)
        {
        afficherbienprop(row);

        }
        else {

             QTableWidgetItem *itembien = new QTableWidgetItem;
             QTableWidgetItem *itemres = new QTableWidgetItem;
             QTableWidgetItem *client = new QTableWidgetItem;

             itembien = ui->PropositionTable->item(row,2);
             itemres = ui->PropositionTable->item(row,0);

             int id_bien =itembien->text().toInt();

             int id_res =itemres->text().toInt();
             client= ui->PropositionTable->item(row,1);
             int id_client= client->text().toInt();

             qDebug()<<id_bien<<" "<<id_res ;

             QSqlQuery ARES;
             ARES.prepare("update Proposition set etat=? where id_proposition=? ");
             ARES.bindValue(0,"Accepte");
             ARES.bindValue(1,id_res);
             bool t = ARES.exec();

             QSqlQuery ABien;

             ABien.prepare("update bien_immobilier set disponible= ? where id_imm=? ");
             ABien.bindValue(0,"disponible"); //  mrigla **************************************
             ABien.bindValue(1,id_bien);
             ABien.exec();
             if ( t && ABien.exec())
             {
                 QMessageBox msgBox;
                 msgBox.setText("Proposition acceptée !");
                 msgBox.exec();

             }
             QSqlQuery mail;
             mail.prepare("select EMAIL from client where id_client=?");
             mail.bindValue(0,id_client);
             mail.exec();
             if(mail.next())
             {

                 QString email =mail.value(0).toString();
                 QStringList arguments;
                 qDebug()<<QCoreApplication::applicationDirPath();
                 arguments<<"C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/debug/SendingPropEmails.py"<<email;
                 QProcess p;
                 p.start("python", arguments);
                 p.waitForFinished();
             }



             //lahné normalement kamlna

             accepterPro=false;
             afficherbienprop(row);
             Admin::on_LoadProposition_clicked();
        }
}

void Admin::on_LoadProposition_clicked()
{   ui->PropositionTable->setRowCount(0);
    ui->PropositionTable->clearContents();
    ui->PropositionTable->setColumnCount(4);
    QStringList PropositionColumnName;
    PropositionColumnName << "Identifiant" << "Identifiant Client"<<"Identifiant bien"<<"Acceptation" ;
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
       Admin::adjustTableSize(ui->PropositionTable,1);

}

void Admin::on_AccepterPro_clicked()
{
 accepterPro=true;
}


//-------------------------adjustTableSize-------------------------
void Admin::adjustTableSize(QTableWidget* wid,int t)
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
//---------------------------------------WARNING**************************
//**********************************************catalogue + reserver un bien**********************************

void Admin::on_radioEntrepot_clicked()
{

    ui->bien_table->setRowCount(0);
    ui->bien_table->clearContents();
   /* ui->bien_table->setRowCount(0);
    ui->bien_table->setColumnWidth(1,40);
    ui->bien_table->setColumnWidth(2,40);
    ui->bien_table->setColumnWidth(3,40);
    ui->bien_table->setColumnWidth(5,100);
    ui->bien_table->setColumnWidth(6,100);*/
    QSqlQuery myquery2;

    if (disponible){

    if ( Ventechecked2==true && Locationchecked2==true ){
        qDebug()<<"radio button";
        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? and ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");


//aaaaaaaaaaaaaaaaa

    }
    }
    else
    {

        if ( Ventechecked2==true && Locationchecked2==true ){
            qDebug()<<"radio button";
            myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true)
        {
            myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? AND etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){

            myquery2.prepare("select  * from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"nondisponible");
            myquery2.bindValue(1,"Location");
        }
  }
    QStringList BienColumnName;
    BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Utilisation";
    ui->bien_table->setHorizontalHeaderLabels(BienColumnName);

    myquery2.exec();

    qDebug()<<"***************************"<<myquery2.size();
    ui->bien_table->setColumnCount(7);

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
    Admin::adjustTableSize(ui->bien_table,1);

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);

}
void Admin::on_radioAppartement_clicked()
{
    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);

    QSqlQuery myquery2;
    if (disponible)
    {
    if ( Ventechecked2==true && Locationchecked2==true ){

        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }
    }
    else {


        if ( Ventechecked2==true && Locationchecked2==true ){

            myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true)
        {
            myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){

            myquery2.prepare("select  * from bien_immobilier b , appartement a where b.id_imm=a.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");

        }






}
    QStringList BienColumnName;
    BienColumnName << "Identifiant" << "Catalogue" << "superficie"<<"Valeur"<<"adresse"<<"disponibilité"<<"Nom d'immeuble"<<"Nombre d'etage"<<"Nombre de chambre";
    ui->bien_table->setHorizontalHeaderLabels(BienColumnName);
    myquery2.exec();
    qDebug()<<"***************************"<<myquery2.size();
    //ui->tablew2->setColumnCount(7)
    ui->bien_table->setColumnCount(9);

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
    Admin::adjustTableSize(ui->bien_table,1);
    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);
}

void Admin::on_radioMaison_clicked()
{
    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);
    QSqlQuery myquery2;

    if (disponible){
    if ( Ventechecked2==true && Locationchecked2==true ){

        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }
    }
    else {
        if ( Ventechecked2==true && Locationchecked2==true ){
            myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true)
        {
            myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){
            myquery2.prepare("select  * from bien_immobilier b , maison m  where b.id_imm=m.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
        }







    }
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
    Admin::adjustTableSize(ui->bien_table,1);

    ui->bien_table->setSortingEnabled(true);
    ui->bien_table->sortByColumn(0,Qt::AscendingOrder);


}
void Admin::on_radioTerrain_clicked()
{
    ui->bien_table->clearContents();
    ui->bien_table->setRowCount(0);

    QSqlQuery myquery2;
    if (disponible){

    if ( Ventechecked2==true && Locationchecked2==true ){

        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");

    }


    }
    else {

        if ( Ventechecked2==true && Locationchecked2==true ){

            myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true){
            myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){
            myquery2.prepare("select  * from bien_immobilier b , Terrain t  where b.id_imm=t.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
        }



    }


    myquery2.exec();

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
     {    qDebug() << "de5el " ;
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
    Admin::adjustTableSize(ui->bien_table,1);


}
void Admin::on_pushButton_3_clicked()
{

}

void Admin::on_checkBox_clicked(bool checked1)
{
    Locationchecked2=checked1;
    qDebug()<<" Locationchecked : "<<Locationchecked2<<"Ventechecked  "<<Ventechecked2 ;
    if (ui->radioEntrepot->isChecked())
    {

       Admin::on_radioEntrepot_clicked();
    }
    if (ui->radioMaison->isChecked())
    {
       Admin::on_radioMaison_clicked();
    }
    if (ui->radioTerrain->isChecked())
    {
       Admin::on_radioTerrain_clicked();
    }
    if (ui->radioAppartement->isChecked())
    {
       Admin::on_radioAppartement_clicked();
    }

    Admin::calculEntrepot();
    Admin::calculTerrain();
    Admin::calculAppartement();
    Admin::calculMaison();


}
void Admin::on_checkBox_2_clicked(bool checked2)
{


        Ventechecked2=checked2;

         qDebug()<<" Locationchecked : "<<Locationchecked2<<"Ventechecked  "<<Ventechecked2 ;
        if (ui->radioEntrepot->isChecked())
        {

           Admin::on_radioEntrepot_clicked();
        }
        if (ui->radioMaison->isChecked())
        {
           Admin::on_radioMaison_clicked();
        }
        if (ui->radioTerrain->isChecked())
        {
           Admin::on_radioTerrain_clicked();
        }
        if (ui->radioAppartement->isChecked())
        {
           Admin::on_radioAppartement_clicked();
        }

        Admin::calculEntrepot();
        Admin::calculTerrain();
        Admin::calculAppartement();
        Admin::calculMaison();

}
void Admin::on_checkBox_3_clicked(bool checked)
{
    disponible=checked ;
    if (ui->radioEntrepot->isChecked())
    {

       Admin::on_radioEntrepot_clicked();
    }
    if (ui->radioMaison->isChecked())
    {
       Admin::on_radioMaison_clicked();
    }
    if (ui->radioTerrain->isChecked())
    {
       Admin::on_radioTerrain_clicked();
    }
    if (ui->radioAppartement->isChecked())
    {
       Admin::on_radioAppartement_clicked();
    }

    Admin::calculEntrepot();
    Admin::calculTerrain();
    Admin::calculAppartement();
    Admin::calculMaison();

}

//************************ (nombre de bien dispoible selon le filtre) ***********************
int Admin::calculEntrepot(){
    QSqlQuery myquery2;

    if (disponible){

    if ( Ventechecked2==true && Locationchecked2==true ){
        qDebug()<<"radio button";
        myquery2.prepare("select  count(*) from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? and ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  count(*) from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  count(*) from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");


//aaaaaaaaaaaaaaaaa

    }
    }
    else
    {

        if ( Ventechecked2==true && Locationchecked2==true ){
            qDebug()<<"radio button";
            myquery2.prepare("select  count(*) from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true)
        {
            myquery2.prepare("select  count(*) from bien_immobilier b , entrepot e where b.id_imm=e.id_imm  AND disponible=? AND etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){

            myquery2.prepare("select  count(*) from bien_immobilier b , entrepot e where b.id_imm=e.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"nondisponible");
            myquery2.bindValue(1,"Location");
        }
  }

    myquery2.exec();
    myquery2.next();
    ui->calculEntrepot->setText("("+myquery2.value(0).toString()+")");
    qDebug()<<"************"<<myquery2.value(0).toInt() ;
    return myquery2.value(0).toInt() ;


}
int Admin::calculTerrain(){
    QSqlQuery myquery2;

    if (disponible){

    if ( Ventechecked2==true && Locationchecked2==true ){
        qDebug()<<"radio button";
        myquery2.prepare("select  count(*) from bien_immobilier b , terrain e where b.id_imm=e.id_imm  AND disponible=? and ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  count(*) from bien_immobilier b ,terrain e where b.id_imm=e.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  count(*) from bien_immobilier b ,  terrain e where b.id_imm=e.id_imm AND disponible=? AND etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");


//aaaaaaaaaaaaaaaaa

    }
    }
    else
    {

        if ( Ventechecked2==true && Locationchecked2==true ){
            qDebug()<<"radio button";
            myquery2.prepare("select  count(*) from bien_immobilier b , terrain e where b.id_imm=e.id_imm  AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true)
        {
            myquery2.prepare("select  count(*) from bien_immobilier b , terrain e where b.id_imm=e.id_imm  AND disponible=? AND etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){

            myquery2.prepare("select  count(*) from bien_immobilier b , terrain e where b.id_imm=e.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"nondisponible");
            myquery2.bindValue(1,"Location");
        }
  }

    myquery2.exec();
    myquery2.next();
    ui->calculTerrain->setText("("+myquery2.value(0).toString()+")");
    qDebug()<<"************"<<myquery2.value(0).toInt() ;
    return myquery2.value(0).toInt() ;


}
int Admin::calculMaison(){

    QSqlQuery myquery2;

    if (disponible){

    if ( Ventechecked2==true && Locationchecked2==true ){
        qDebug()<<"radio button";
        myquery2.prepare("select  count(*) from bien_immobilier b , Maison e where b.id_imm=e.id_imm  AND disponible=? and ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  count(*) from bien_immobilier b , Maison e where b.id_imm=e.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  count(*) from bien_immobilier b , Maison e where b.id_imm=e.id_imm AND disponible=? AND etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");


//aaaaaaaaaaaaaaaaa

    }
    }
    else
    {

        if ( Ventechecked2==true && Locationchecked2==true ){
            qDebug()<<"radio button";
            myquery2.prepare("select  count(*) from bien_immobilier b , Maison e where b.id_imm=e.id_imm  AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true)
        {
            myquery2.prepare("select  count(*) from bien_immobilier b , Maison e where b.id_imm=e.id_imm  AND disponible=? AND etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){

            myquery2.prepare("select  count(*) from bien_immobilier b , Maison e where b.id_imm=e.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"nondisponible");
            myquery2.bindValue(1,"Location");
        }
  }

    myquery2.exec();
    myquery2.next();
    ui->calculMaison->setText("("+myquery2.value(0).toString()+")");
    qDebug()<<"************"<<myquery2.value(0).toInt() ;
    return myquery2.value(0).toInt() ;



}
int Admin::calculAppartement(){

    QSqlQuery myquery2;

    if (disponible){

    if ( Ventechecked2==true && Locationchecked2==true ){
        qDebug()<<"radio button";
        myquery2.prepare("select  count(*) from bien_immobilier b , Appartement e where b.id_imm=e.id_imm  AND disponible=? and ( etat=? or etat=?)" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");
        myquery2.bindValue(2,"Vente");
    }else if (Ventechecked2==true)
    {
        myquery2.prepare("select  count(*) from bien_immobilier b , Appartement e where b.id_imm=e.id_imm AND disponible=? AND  etat=?" );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Vente");


    }else if (Locationchecked2==true ){

        myquery2.prepare("select  count(*) from bien_immobilier b , Appartement e where b.id_imm=e.id_imm AND disponible=? AND etat=? " );
        myquery2.bindValue(0,"disponible");
        myquery2.bindValue(1,"Location");


//aaaaaaaaaaaaaaaaa

    }
    }
    else
    {

        if ( Ventechecked2==true && Locationchecked2==true ){
            qDebug()<<"radio button";
            myquery2.prepare("select  count(*) from bien_immobilier b , Appartement e where b.id_imm=e.id_imm  AND disponible=? AND ( etat=? or etat=?)" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Location");
            myquery2.bindValue(2,"Vente");
        }else if (Ventechecked2==true)
        {
            myquery2.prepare("select  count(*) from bien_immobilier b , Appartement e where b.id_imm=e.id_imm  AND disponible=? AND etat=?" );
            myquery2.bindValue(0,"non disponible");
            myquery2.bindValue(1,"Vente");


        }else if (Locationchecked2==true ){

            myquery2.prepare("select  count(*) from bien_immobilier b , Appartement e where b.id_imm=e.id_imm AND disponible=? AND  etat=? " );
            myquery2.bindValue(0,"nondisponible");
            myquery2.bindValue(1,"Location");
        }
  }

    myquery2.exec();
    myquery2.next();
    ui->calculAppartement->setText("("+myquery2.value(0).toString()+")");
    qDebug()<<"************"<<myquery2.value(0).toInt() ;
    return myquery2.value(0).toInt() ;



}
//---------------------------------------------------------------------------------




//-------------------------Partie ADMIN  Recherche + affichage d'un client---------------
void Admin::on_LoadClient_clicked()
{





    ui->tablew2->clearContents();
    QSqlQuery myquery2("select  * from Client");
    qDebug()<<"***************************"<<myquery2.numRowsAffected();
    //ui->tablew2->setColumnCount(7)

     int index = 0;
   // qDebug() << "lbara " << myquery2.next();
    ui->tablew2->setSortingEnabled(false);

    while(myquery2.next())
     {   //  qDebug() << "de5el " << myquery2.next();
         ui->tablew2->setRowCount(index+1);
         ui->tablew2->setRowHeight(index,5);
         ui->tablew2->setItem(index,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
         ui->tablew2->setItem(index,1,new QTableWidgetItem(myquery2.value(1).toString()));
         ui->tablew2->setItem(index,2,new QTableWidgetItem(myquery2.value(2).toString()));
         ui->tablew2->setItem(index,3,new QTableWidgetItem(myquery2.value(3).toString()));
         ui->tablew2->setItem(index,4,new QTableWidgetItem(myquery2.value(4).toString()));
         ui->tablew2->setItem(index,5,new QTableWidgetItem(myquery2.value(5).toString()));
         ui->tablew2->setItem(index,6,new QTableWidgetItem(  myquery2.value(6).toString().leftRef(10).toString()   ));




         index ++;

    }

    ui->tablew2->setSortingEnabled(true);
    ui->tablew2->sortByColumn(0,Qt::AscendingOrder);

}
void Admin::on_lineEdit_textChanged(const QString &arg1)
{
}

QString PrenomG="";

QString NomG="";

void Admin::on_ClientName_textChanged(const QString &arg1)
{
    PrenomG=arg1;
    ui->tablew2->clearContents();
    QSqlQuery RechercheClient;

    RechercheClient.prepare("select * from client where upper(prenom) Like ? AND upper(nom) Like ? ");
    QString rech = PrenomG+"%";
    QString rech2 = NomG+"%";
    RechercheClient.bindValue(1,rech2.toUpper());
    RechercheClient.bindValue(0,rech.toUpper());
    RechercheClient.exec();


     int index = 0;
   // qDebug() << "lbara " << myquery2.next();
    ui->tablew2->setSortingEnabled(false);

    while(RechercheClient.next())
     {   //  qDebug() << "de5el " << myquery2.next();
        ui->tablew2->setRowCount(index+1);
         ui->tablew2->setItem(index,0,new QTableWidgetItem(("0000"+RechercheClient.value(0).toString()).rightRef(5).toString()  ));
         ui->tablew2->setItem(index,1,new QTableWidgetItem(RechercheClient.value(1).toString()));
         ui->tablew2->setItem(index,2,new QTableWidgetItem(RechercheClient.value(2).toString()));
         ui->tablew2->setItem(index,3,new QTableWidgetItem(RechercheClient.value(3).toString()));
         ui->tablew2->setItem(index,4,new QTableWidgetItem(RechercheClient.value(4).toString()));
         ui->tablew2->setItem(index,5,new QTableWidgetItem(RechercheClient.value(5).toString()));
         ui->tablew2->setItem(index,6,new QTableWidgetItem(RechercheClient.value(6).toString().leftRef(10).toString()   ));
         index ++;

    }

    ui->tablew2->setSortingEnabled(true);
    ui->tablew2->sortByColumn(0,Qt::AscendingOrder);



}
void Admin::on_ClientNom_textChanged(const QString &arg1)
{
 NomG=arg1 ;
 ui->tablew2->clearContents();
 QSqlQuery RechercheClient;

 RechercheClient.prepare("select * from client where upper(prenom) Like ? AND upper(nom) Like ? ");
 QString rech = PrenomG+"%";
 QString rech2 = NomG+"%";
 RechercheClient.bindValue(1,rech2.toUpper());
 RechercheClient.bindValue(0,rech.toUpper());
 RechercheClient.exec();


  int index = 0;
// qDebug() << "lbara " << myquery2.next();
 ui->tablew2->setSortingEnabled(false);

 while(RechercheClient.next())
  {   //  qDebug() << "de5el " << myquery2.next();
      ui->tablew2->setRowCount(index+1);

      ui->tablew2->setItem(index,0,new QTableWidgetItem(("0000"+RechercheClient.value(0).toString()).rightRef(5).toString()  ));
      ui->tablew2->setItem(index,1,new QTableWidgetItem(RechercheClient.value(1).toString()));
      ui->tablew2->setItem(index,2,new QTableWidgetItem(RechercheClient.value(2).toString()));
      ui->tablew2->setItem(index,3,new QTableWidgetItem(RechercheClient.value(3).toString()));
      ui->tablew2->setItem(index,4,new QTableWidgetItem(RechercheClient.value(4).toString()));
      ui->tablew2->setItem(index,5,new QTableWidgetItem(RechercheClient.value(5).toString()));
      ui->tablew2->setItem(index,6,new QTableWidgetItem(RechercheClient.value(6).toString().leftRef(10).toString()   ));
      index ++;

 }

 ui->tablew2->setSortingEnabled(true);
 ui->tablew2->sortByColumn(0,Qt::AscendingOrder);




}

bool Supp=false ;
void Admin::on_tablew2_cellClicked(int row, int column)
{
   /* if (Supp==true)
    {

     QTableWidgetItem *item = new QTableWidgetItem;
     item = ui->tablew2->item(row,0);
     int id_client =item->text().toInt();
     qDebug()<<item->text();
     QSqlQuery rech;
     rech.prepare("");



    /* QSqlQuery suppr;
     suppr.prepare("delete from client where id=? ");
     suppr.bindValue(0,id_client);

    }
    Supp=false;*/
    ui->PropositionTable_2->setRowCount(0);
    ui->PropositionTable_2->clearContents();
    ui->ReservationTable_2->setRowCount(0);
    ui->ReservationTable_2->clearContents();
    QTableWidgetItem *item = new QTableWidgetItem;
    item = ui->tablew2->item(row,0);
    int id_client =item->text().toInt();




    QSqlQuery myquery;
       myquery.prepare("select  * from proposition where id_client=? " );
       myquery.bindValue(0,id_client);
       myquery.exec();
       /*ui->PropositionTable_2->clearContents();
       ui->PropositionTable_2->setColumnCount(4);
       ui->PropositionTable_2->setColumnWidth(0,40);
       ui->PropositionTable_2->setColumnWidth(1,40);
       ui->PropositionTable_2->setColumnWidth(2,40);
       ui->PropositionTable_2->setColumnWidth(3,150);*/



        int index = 0;
        ui->PropositionTable_2->setSortingEnabled(false);

       while(myquery.next())
        {   //  qDebug() << "de5el " << myquery2.next();
             ui->PropositionTable_2->setRowCount(index+1);
             ui->PropositionTable_2->setItem(index,0,new QTableWidgetItem(("0000"+myquery.value(0).toString()).rightRef(5).toString()  ));
             ui->PropositionTable_2->setItem(index,1,new QTableWidgetItem(myquery.value(1).toString()));
             ui->PropositionTable_2->setItem(index,2,new QTableWidgetItem(myquery.value(2).toString()));
             ui->PropositionTable_2->setItem(index,3,new QTableWidgetItem(myquery.value(3).toString()));
           index ++;
       }
        ui->PropositionTable_2->setSortingEnabled(true);
        ui->PropositionTable_2->sortByColumn(0,Qt::AscendingOrder);
        Admin::adjustTableSize( ui->PropositionTable_2,1);


        //*******************affichage reservation d'un client*************

        QSqlQuery myquery2;
        myquery2.prepare("select  * from reservation where id_client=?" );
        myquery2.bindValue(0,id_client);
        myquery2.exec();

       /* ui->ReservationTable_2->setRowCount(0);
        ui->ReservationTable_2->clearContents();
        ui->ReservationTable_2->setColumnCount(4);
        ui->ReservationTable_2->setColumnWidth(0,40);
        ui->ReservationTable_2->setColumnWidth(1,40);
        ui->ReservationTable_2->setColumnWidth(2,40);
        ui->ReservationTable_2->setColumnWidth(3,150);
        ui->ReservationTable_2->setRowCount(0);*/



        int index2 = 0;

        ui->ReservationTable_2->setSortingEnabled(false);

        while(myquery2.next())
         {
            //  qDebug() << "de5el " << myquery2.next();
             ui->ReservationTable_2->setRowCount(index2+1);
             ui->ReservationTable_2->setItem(index2,0,new QTableWidgetItem(("0000"+myquery2.value(0).toString()).rightRef(5).toString()  ));
             ui->ReservationTable_2->setItem(index2,1,new QTableWidgetItem(myquery2.value(1).toString()));
             ui->ReservationTable_2->setItem(index2,2,new QTableWidgetItem(myquery2.value(2).toString()));
             ui->ReservationTable_2->setItem(index2,3,new QTableWidgetItem(myquery2.value(3).toString()));
            index2 ++;
        }
        ui->ReservationTable_2->setSortingEnabled(true);
        ui->ReservationTable_2->sortByColumn(0,Qt::AscendingOrder);
        Admin::adjustTableSize(ui->ReservationTable_2,1);
}
void Admin::on_pushButton_clicked()
{
    Supp=true ;
}
//------------------------------Partie ADMIN  Recherche + affichage d'un client---------------

void Admin::on_loadContratLoc_clicked()
{

    QSqlQuery myquery2;
    myquery2.prepare("select * from contrat c , contratlocation l  where c.id_contrat=l.id_contrat ;" );
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

    ui->ReservationTable_2->setSortingEnabled(false);

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
    Admin::adjustTableSize(ui->LocationTable,1);









}


void Admin::on_LoadContratVente_clicked()
{

    ui->VenteTable->setRowCount(0);
    ui->VenteTable->clearContents();


    QSqlQuery myquery2;
    myquery2.prepare("select * from contrat c , contratachat a where c.id_contrat=a.id_contrat ;" );
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
    Admin::adjustTableSize(ui->VenteTable,1);
}
void Admin::afficherBienContrat(int row,QTableWidget * t )
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
             Admin::adjustTableSize(ui->ClientEntrepot_3);









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
             Admin::adjustTableSize(ui->ClientAppartemet_3);




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
             Admin::adjustTableSize(ui->ClientTerrain_3);

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
            Admin::adjustTableSize(ui->ClientMaison_3);


       }



}
void Admin::on_LocationTable_cellClicked(int row, int column)
{
     Admin::afficherBienContrat(row,ui->LocationTable);
}


void Admin::on_VenteTable_cellClicked(int row, int column)
{
    Admin::afficherBienContrat(row,ui->VenteTable);
}

void Admin::on_pushButton_2_clicked()
{
    this->hide();
}

void Admin::on_testing_clicked()
{
           QMessageBox mb;
           QLineEdit le;
           QLabel la;
           QLabel la2;
           QPushButton bt;
           QDateEdit d ;
           QDateEdit d2;
           la2.setText("Date Fin du Contrat");
           la.setText("Date Debut du Contrat");
           mb.layout()->addWidget(&la);
           mb.layout()->addWidget(&d);
           mb.layout()->addWidget(&la2);
           mb.layout()->addWidget(&d2);

           mb.exec();
           int year = d.date().year();
           int month = d.date().month();
           int day = d.date().day();
           int year2 = d2.date().year();
           int month2 = d2.date().month();
           int day2 = d2.date().day();
           qDebug()<<year<<month<<day<<year2<<month2<<day2;
}
