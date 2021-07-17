#include "date.h"
#include<iostream>
using namespace std;
Date::Date(int jour, int mois, int annee) : j(jour), m(mois), a(annee)
{
}
Date::~Date(void)
{
}
void Date::saisir()
{
    cout << " Date jj/mm/aaaa : ";
    cin >> j >> m >> a;
}
void Date::afficher(string msg)
{

    cout << j << "/" << m << "/" << a << endl;
}
void Date::setDate_Jour(int jo)
{
    j = jo;
}
void Date::setDate_Mois(int mo)
{
    m = mo;
}
void Date::setDate_Annee(int an)
{
    a = an;
}

void Date::setDate(Date d )
{
    j = d.getJour() ;
    m = d.getMois() ;
    a = d.getANNEE() ;
}


/*

int main()
{

    Date d ;
    d.setDate_Annee(1998);
    d.setDate_Jour(23);
    d.setDate_Mois(12);
    d.afficher();
    return 0 ;
}
*/

