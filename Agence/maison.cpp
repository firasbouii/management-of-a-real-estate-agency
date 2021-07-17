#include "maison.h"
#include<iostream>
using namespace std;
Maison::Maison(int id, string e, float s, float v, int num, string quar, string  vi, int ee, int c ) : Bien_immobilier(id, e, s, v, num, quar, vi)
{
    nb_etage = ee;
    nb_chambre = c;
}
Maison::~Maison()
{
}
int Maison::getNb_etage()
{
    return nb_etage;
}
int Maison::getNb_chambre()
{
    return nb_chambre;
}
void Maison::setNb_etage(int e)
{
    nb_etage = e;
}
void Maison::setNb_chambre(int c)
{
    nb_chambre = c;
}
void Maison::afficher_bien_immobilier(string msg)
{
    cout << msg << endl;
    Bien_immobilier::afficher_bien_immobilier("Maison");
    cout << "NB ETAGES : " << nb_etage << endl;
    cout<< "NB CHAMBRE : "<<nb_chambre << endl;
}

void Maison::Saisir() {
    Bien_immobilier::Saisir();
    cout << "NB Etage       : "; cin >> nb_etage;
    cout << "NB Chambre: "; cin >> nb_chambre;
}


bool Maison::ADD_DB(){

    Bien_immobilier::ADD_DB();
    QSqlQuery M;
    M.prepare("insert into maison(id_imm,nb_etage,nb_chambre) VALUES(?,?,?)");
    M.bindValue(0,id_imm);
    M.bindValue(1,nb_etage);
    M.bindValue(2,nb_chambre);
    return M.exec();

}


void Maison::setDispobile(string d){

    disponible = d ;




}
