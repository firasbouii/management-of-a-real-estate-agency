#ifndef AGENT_H
#define AGENT_H
#include<map>
#include<string>
using namespace std;
#include<iostream>
#include<fstream>
#include<QMap>

class Agent
{
    private:
        map<string,string> admin ;

    public:
        Agent();
        virtual ~Agent();
        void ajouter(string,string);//conditon
        string rechercher(string) ;
        void afficher();
        void friend creer(Agent *);
        void friend creer2(Agent *);
        void friend EcrireFichier(Agent *);
        void friend LireFichier(Agent * );



    };

#endif // AGENT_H
