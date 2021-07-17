#include "entrepot.h"
#include<iostream>
using namespace std;
Entrepot::Entrepot(int id, string e, float s, float v, int num, string quar, string  vi,string u) : Bien_immobilier(id,e,s,v,num,quar,vi)
{
    utilisation = u;
}
Entrepot::~Entrepot()
{
}
string Entrepot::getUtilisation_entrepot()
{
    return utilisation;
}
void Entrepot::setUtilisation_entrepot(string u)
{
    utilisation = u;
}
void Entrepot::afficher_bien_immobilier(string msg)
{
    cout << msg << endl;
    Bien_immobilier::afficher_bien_immobilier("Entrepot");
    cout << "Utilsation : " << utilisation << endl;

}

void Entrepot::Saisir() {
    Bien_immobilier::Saisir();
    cout << "Utilisation: "; cin >> utilisation ;

}


bool Entrepot::ADD_DB(){
    Bien_immobilier::ADD_DB();
    QSqlQuery Entrepot;
    Entrepot.prepare("insert into Entrepot(id_imm,utilisation) VALUES(?,?)");
    Entrepot.bindValue(0,id_imm);
    Entrepot.bindValue(1,QString::fromStdString(utilisation));
    return Entrepot.exec();





}

void Entrepot::setDispobile(string d )
{
    disponible = d ;


}
