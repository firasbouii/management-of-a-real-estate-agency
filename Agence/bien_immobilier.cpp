#include "bien_immobilier.h"
#include<iostream>
using namespace std;
//int id_Counter=-1;
Bien_immobilier::Bien_immobilier(int id , string e, float s, float v, int num, string quar, string  vi) : lieu(num,quar,vi)

{

    QSqlQuery myquery("select  max(id_imm) from BIEN_IMMOBILIER");


    myquery.next();
    id_imm = myquery.value(0).toInt()+1;
    etat = e;
    superficie = s;
    valeur = v;

}
Bien_immobilier::~Bien_immobilier()
{
}
int Bien_immobilier::getId()
{
    return id_imm;
}
string Bien_immobilier::geetEtat()
{
    return etat;
}
float Bien_immobilier::getSuperficie()
{
    return superficie;
}
float Bien_immobilier::getValeur()
{
    return valeur;
}
Adresse Bien_immobilier::getAdresse()
{
    return lieu;
}
void Bien_immobilier::setId(int id)
{
    id_imm = id;
}
void Bien_immobilier::setEtat(string e)
{
    etat = e;
}
void Bien_immobilier::setSuperficie(float s)
{
    superficie = s;
}
void Bien_immobilier::setValeur(float v)
{
    valeur = v;
}
void Bien_immobilier::setAdresse(Adresse a)
{
    lieu = a;
}
void Bien_immobilier::afficher_bien_immobilier(string msg)
{
    cout<<msg<< endl;

    cout << "ID du bien : " << id_imm << endl;
    cout << "ETAT  : "<<etat << endl;
    cout << "SUPERFICIE : "<<superficie << endl;
    cout<<"VALEUR : "<<valeur<<endl;
    lieu.afficher(" Adresse Du Bien :");
    cout<<"DISPONIBLE : "<<disponible<<endl;
}


void Bien_immobilier::Saisir() {


    cout << "ETAT  : ";
    cin >> etat ;
    cout << "SUPERFICIE : ";
    cin >> superficie ;
    cout << "VALEUR : ";
    cin >> valeur;
    lieu.saisir();

}

bool Bien_immobilier::ADD_DB(){
    QSqlQuery Bien;
    Bien.prepare("insert into bien_immobilier(id_imm,etat,superficie,valeur,lieu,disponible) VALUES(?,?,?,?,?,?)");
    Bien.bindValue(0,id_imm);
    Bien.bindValue(1,QString::fromStdString(etat));
    Bien.bindValue(2,(int)superficie);
    Bien.bindValue(3,(int)valeur);
    Bien.bindValue(4,QString::number(lieu.getNumero())+" "+QString::fromStdString(lieu.getQuartier())+" "+QString::fromStdString(lieu.getVille()));
    Bien.bindValue(5,QString::fromStdString(disponible));
    Bien.exec();
}

void Bien_immobilier::setDispobile(string d ){

    disponible = d ;

}
