#ifndef PROPOSITION_H
#define PROPOSITION_H
#include<iostream>
using namespace std;
class Proposition
{
    int ID_Proposition;
    int ID_Client;
    int ID_Bien_Imobbilier;
    string Etat;  //Accepte ou NonAccepte
public:
    Proposition( int, int);
    virtual ~Proposition();
    int get_ID_Proposition() { return ID_Proposition; }
    int get_ID_Client() { return ID_Client; }
    int get_ID_Bien_Imobbilier() { return ID_Bien_Imobbilier; }
    string get_Etat() { return Etat; }
    //void saisir();
    void Afficher_Prop();
    void Set_Etat_Accepte() { Etat = "Accepte";  }
    bool ADD_DB();
};



#endif // PROPOSITION_H
