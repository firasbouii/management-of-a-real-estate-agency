#ifndef CLIENT_H
#define CLIENT_H

#include"date.h"
#include<iostream>
#include"adresse.h"
using namespace std;
class Client
{
protected:
    int Id_Client;
    string Nom;
    string Prenom;
    string Email;
    int Num_Tel;
    Adresse adresse;
    Date Date_Naissance;
public:                                                     //int strig string : mta3 l adresse

    Client(int=-3, string="", string="", string="", int=00, int=00 , string="" ,string="" , int=00, int=00, int=00);
    virtual ~Client();
    void virtual Afficher();
    void virtual Saisir();
    int get_Id_Client() { return Id_Client; }
    string get_Nom() { return Nom; }
    string get_Prenom() { return Prenom; }
    string get_Email() { return Email; }
    int get_Num_Tel() { return Num_Tel; }
   // string get_Adresse() { return Email; }
    Date get_Date_Naissance() { return Date_Naissance; }
    bool ADD_DB();


};



#endif // CLIENT_H
