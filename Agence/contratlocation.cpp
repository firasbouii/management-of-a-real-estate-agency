#include "contratlocation.h"
#include<iostream>
using namespace std;
ContratLocation::ContratLocation(  int idb , int idc  , float comission , float const pourcentage_loc,  int j1, int m1, int a1, int j2, int m2, int a2 ,double m): Contrat(  idb, idc ,comission ), Date_Debut(j1, m1, a1), Date_Fin(j2,m2,a2),Valeur_Contrat(m)
{

}
void ContratLocation::creer()
{
    Contrat::creer();
    cout << "Date du Creation du Contrat:";
    Date_Debut.saisir();
    cout << "Date fin du Contrat:";
    Date_Fin.saisir();
}
void ContratLocation::afficher_contrat()
{
    Contrat::afficher_contrat();

    cout << "Date de creation du contrat	:";
    Date_Debut.afficher();
    cout << "La date fin du contrat			:";
    Date_Fin.afficher();
    cout <<"Montant a payer : " << Mont_a_payer << endl;
    cout << "valeur du contrat  :" << Valeur_Contrat << endl;

}


ContratLocation::~ContratLocation(void)
{
}
void ContratLocation::setMont_a_payer()
{
     Mont_a_payer = Valeur_Contrat + Valeur_Contrat* this->getComission() ;
}
Date ContratLocation::getDate_deb()
{
    return Date_Debut;
}
Date ContratLocation::getDate_fin()
{
    return Date_Fin;
}
void ContratLocation::setDate_deb(Date d)
{
    Date_Debut.setDate(d);
}
void ContratLocation::setDate_fin(Date d)
{
    Date_Fin.setDate(d);
}

bool ContratLocation::ADD_DB(){
    QSqlQuery  query;
    query.prepare("INSERT INTO contratlocation(id_contrat,POURCENTAGE_LOC,VALEUR_CONTRAT,mont_a_payer,date_debut,date_fin)  "
                        "VALUES(?,?,?,?,to_date(?,'DD/MM/YYYY'),to_date(?,'DD/MM/YYYY')) ");

    qDebug()<<"ADD DB CONTRAT";


    query.bindValue(0,this->getId_contrat());
    query.bindValue(1,(double)pourcentage_loc);
    query.bindValue(2,(double)Valeur_Contrat);
    query.bindValue(3,(double)Mont_a_payer);
    QString ch=QString::number(Date_Debut.getJour())+'/'+QString::number(Date_Debut.getMois())+'/'+QString::number(Date_Debut.getANNEE());
    qDebug()<<"testing  : "<<ch;
    query.bindValue(4,ch);
    QString ch2=QString::number(Date_Fin.getJour())+'/'+QString::number(Date_Fin.getMois())+'/'+QString::number(Date_Fin.getANNEE());
    qDebug()<<"testing  : "<<ch2;
    query.bindValue(5,ch2);


    QSqlQuery  query2;
    query2.prepare("INSERT INTO contrat(id_contrat,id_bien,ID_CLIENT,comission)  "
                        "VALUES(?,?,?,?) ");
    qDebug()<<"ADD DB CONTRAT";

    query2.bindValue(0,this->getId_contrat());
    query2.bindValue(1,this->getID_Bien());
    query2.bindValue(2,this->getID_Client());
    query2.bindValue(3,(double)this->getComission());





       return ( query2.exec() && query.exec() ) ;




}
