#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    int j;
    int m;
    int a;

public:

    Date(int=11, int=11, int=11111);
    ~Date(void);
    void saisir();
    void afficher(string = "");
    int getANNEE() { return a; }
    int getMois() { return m; }
    int getJour() { return j; }
    void setDate_Jour(int);
    void setDate_Annee(int);
    void setDate_Mois(int);
    void setDate(Date);
};


#endif // DATE_H

