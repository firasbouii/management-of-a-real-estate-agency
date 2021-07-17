#include "agent.h"
#include "ui_agent.h"
#include <iomanip>
#include<QtDebug>
#include<QFile>

fstream f1;

Agent::Agent()
{
    //ctor
}

Agent::~Agent()
{
    //dtor
}

void Agent::afficher()
{

    map<string,string>::iterator it;
    cout<<"affichage admin"<<endl;
    for(it = admin.begin(); it!=admin.end(); it++)
    {
    cout<<"---------------------"<<endl;
    cout<<"Pseudi :      "<<it->first<<endl;
    cout<<"Mot de Passe: "<<it->second<<endl;

    }
}


void Agent::ajouter(string pseudo,string password){

    admin[pseudo]=password;
}
string Agent::rechercher(string pseudo){

        map<string,string>::iterator it;
        for ( it = admin.begin(); it!=admin.end(); it++)
            if(it->first ==pseudo )
              return it->second;
        return "" ;

}

//-----------------------------

void EcrireFichier(Agent * A){
    f1.seekg(0);
    map<string,string>::iterator it;
    for ( it = A->admin.begin(); it!=A->admin.end(); it++)
        f1<<setw(25)<<it->first<<" "<<setw(25)<<it->second<<endl;
    f1.close();

}

void LireFichier(Agent * A){
    string choix,choix2;
    f1.seekg(0);
    A->admin.clear();
    while(1)
    {
        f1>>choix;
        if (f1.eof()) break  ;
        f1>>choix2;
        A->admin[choix]=choix2;



    }
    f1.close();
}



void creer(Agent * A){

    f1.open("C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/debug/Agence8.txt", ios::in | ios::out | ios::trunc) ;
}

void creer2(Agent * A){

    f1.open("C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/debug/Agence8.txt",  ios::in ) ;
}





