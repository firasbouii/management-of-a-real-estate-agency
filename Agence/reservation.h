#ifndef RESERVATION_H
#define RESERVATION_H

#include<iostream>
using namespace std;
//#include"ALL_Contrats.h"
//#include"ALLClients.h"
class Reservation
{
    int ID_Reservation;
    int ID_Client;
    int ID_Bien_Imobbilier;
    string Etat;  //Accepte ou Non_Accepte
public:
    Reservation( int, int);
    virtual ~Reservation();
    int get_ID_Reservation() { return ID_Reservation; }
    int get_ID_Client() { return ID_Client; }
    int get_ID_Bien_Imobbilier() { return ID_Bien_Imobbilier; }
    string get_Etat() { return Etat; }
    //void saisir();
    void Afficher_Res();
    void Set_Etat_Accepte() { Etat = "Accepte";  }
    bool ADD_DB();
};
#endif // RESERVATION_H
