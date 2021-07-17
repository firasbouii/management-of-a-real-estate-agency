#ifndef ADRESSE_H
#define ADRESSE_H
#include<iostream>
using namespace std;
class Adresse
{
    int numero;
    string quartier;
    string ville;
public:
    Adresse(int=00, string ="", string="");
    ~Adresse();
    int getNumero();
    string getQuartier();
    string getVille();
    void setNumero(int);
    void setQuartier(string);
    void setVille(string);
    void afficher(string);
    void saisir();
};



#endif // ADRESSE_H
