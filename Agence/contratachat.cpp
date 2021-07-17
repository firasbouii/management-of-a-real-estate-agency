#include "contratachat.h"
#include<iostream>
#include"date.h"
using namespace std;
ContratAchat::ContratAchat( int idb , int idc  , float comission,int j ,int m ,int a , double mont_a_payer, double valeur_contart) : Contrat(idb,idc, comission) , Date_Vente(j,m,a)
{

    Mont_a_payer = mont_a_payer;
    Valeur_Contrat = valeur_contart;
}
void ContratAchat::creer()
{
    Contrat::creer();
    cout << "Date de vente:" ;
    Date_Vente.saisir();      //a revoir
    cout << "Montant a Payer:";
    cin >> Mont_a_payer;
    cout << "Valeur du Contrat:" ;
    cin >> Valeur_Contrat;

}
void ContratAchat::afficher_contrat()
{
    Contrat::afficher_contrat();
    cout << "Date de vente : ";
    Date_Vente.afficher();
    cout <<"Montant a payer : " << Mont_a_payer << endl;
    cout << "valeur du contrat  :" << Valeur_Contrat << endl;
}

ContratAchat::~ContratAchat(void)
{
}

double ContratAchat::getMont_a_payer()
{
    return Mont_a_payer;
}
double ContratAchat::getValeur_contrat()
{
    return Valeur_Contrat;
}
void ContratAchat::setMont_a_payer()
{
    Mont_a_payer = Valeur_Contrat + Valeur_Contrat* this->getComission() ;
}
void ContratAchat::setValeur_contrat(double v)
{
    Valeur_Contrat = v;
}


bool ContratAchat::ADD_DB()
{
    QSqlQuery  query;
    query.prepare("INSERT INTO contratachat(id_contrat,valeur_contrat,mont_a_payer,date_vente)  "
                        "VALUES(?,?,?,to_date(?,'DD/MM/YYYY')) ");

    qDebug()<<"ADD DB CONTRAT";


    query.bindValue(0,this->getId_contrat());
    query.bindValue(1,(double)Valeur_Contrat);
    query.bindValue(2,(double)Mont_a_payer);
    QString ch=QString::number(Date_Vente.getJour())+'/'+QString::number(Date_Vente.getMois())+'/'+QString::number(Date_Vente.getANNEE());
    qDebug()<<"testing  : "<<ch;
    query.bindValue(3,ch);


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


