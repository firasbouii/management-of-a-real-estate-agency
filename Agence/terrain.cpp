#include "terrain.h"
#include<iostream>
using namespace std;

Terrain::Terrain(int id, string e, float s, float v, int num, string quar, string  vi,int nu, string n, string et) : Bien_immobilier(id,e,s,v,num,quar,vi)
{
    num_inscription = nu;
    nature = n;
    etat_terr = et;
}
Terrain::~Terrain(){}
string Terrain::getNature()
{
    return nature;
}
int Terrain::getNum_inscri()
{
    return num_inscription;
}

void Terrain::setNature(string n)
{
    nature = n;
}
void Terrain::setNum_inscr(int num)
{
    num_inscription = num;
}
void Terrain::afficher_bien_immobilier(string msg)
{
    cout << msg << endl;
    Bien_immobilier::afficher_bien_immobilier("Terrain");

    cout << "Num d'inscription : " << num_inscription << endl;
    cout << "Nature  :" << nature << endl;
    cout<<" ETAT :" << etat_terr << endl;
}

void Terrain::Saisir() {
    Bien_immobilier::Saisir();
    cout << "Num d'inscription : "; cin >> num_inscription ;
    cout << "Nature            : "; cin >> nature;
    cout << "Etat du Terrain: "; cin >>etat_terr;
}

bool Terrain::ADD_DB(){
    Bien_immobilier::ADD_DB();
    QSqlQuery terrain;
    terrain.prepare("insert into terrain(id_imm,num_inscription,nature,etat_terr) VALUES(?,?,?,?)");
    terrain.bindValue(0,id_imm);
    terrain.bindValue(1,num_inscription);
    terrain.bindValue(2,QString::fromStdString(nature));
    terrain.bindValue(3,QString::fromStdString(etat_terr));
    return terrain.exec();



}
void Terrain::setDispobile(string d){

    disponible = d ;


}
