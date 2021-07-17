#include "appartement.h"

#include<iostream>
using namespace std;
Appartement::Appartement(int id, string e, float s, float v, int num, string quar, string  vi,string im, int numm, int n): Bien_immobilier(id, e, s, v, num, quar, vi)
{
    immeuble = im;
    num_etage = numm;
    nb_chambre = n;
}
Appartement::~Appartement()
{
}
string Appartement::getImmeuble()
{
    return immeuble;
}
int Appartement::getNum_etage()
{
    return num_etage;
}
int Appartement::getNb_chbre()
{
    return nb_chambre;
}
void Appartement::setImmeuble(string im)
{
    immeuble = im;
}
void Appartement::setNum_etage(int num)
{
    num_etage = num;
}
void Appartement::setNb_chbre(int n)
{
    nb_chambre = n;
}
void Appartement::afficher_bien_immobilier(string msg)
{
    cout << msg << endl;
    Bien_immobilier::afficher_bien_immobilier("Appartement");
    cout << "Immeuble :  " << immeuble << endl;
    cout << "N° ETAGE : " << num_etage << endl;
    cout<< "NB CHAMBRE :  "<<nb_chambre << endl;
}

void Appartement::Saisir() {
    Bien_immobilier::Saisir();
    cout << "Nom Immeuble	 : "; cin >> immeuble;
    cout << "Num Etage       : "; cin >> num_etage;
    cout << "NB Chambre: "; cin >> nb_chambre;
}

bool Appartement::ADD_DB(){
    Bien_immobilier::ADD_DB();
    QSqlQuery Appartement;
    Appartement.prepare("insert into appartement(id_imm,immeuble,num_etage,nb_chambre) VALUES(?,?,?,?)");
    Appartement.bindValue(0,id_imm);
    Appartement.bindValue(1,QString::fromStdString(immeuble));
    Appartement.bindValue(2,num_etage);
    Appartement.bindValue(3,nb_chambre);
    return Appartement.exec();




}

void Appartement::setDispobile(string d){

    disponible = d ;
}
