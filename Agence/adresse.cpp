#include "adresse.h"

#include<iostream>
using namespace std;

Adresse::Adresse(int num, string quar, string v)
{
    numero = num;
    quartier = quar;
    ville = v;
}
Adresse::~Adresse(){}
int Adresse::getNumero()
{
    return numero;
}
string Adresse::getQuartier()
{
    return quartier;
}
string Adresse::getVille()
{
    return ville;
}
void Adresse::setNumero(int num)
{
    numero = num;
}
void Adresse::setQuartier(string q)
{
    quartier = q;
}
void Adresse::setVille(string v)
{
    ville = v;
}
void Adresse::afficher(string msg)
{
    cout<<msg<< endl;
    cout << "Numero Du Bien: " << numero << endl;
    cout << "Quartier: " << quartier << endl;
    cout <<"Ville : "<<ville<<endl;
}


void Adresse::saisir()
{
    cout << "ADRESSE : " << endl;
    cout << "Num : "  ;
    cin >> numero;
    cout << "Quartier : " ;
    cin >> quartier ;
    cout << "Ville : " ;
    cin  >>ville ;


}
