#include "mainwindow.h"
#include"connexion.h"
#include <QApplication>
#include<QMessageBox>
#include<QtDebug>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
       MainWindow w;
       Connexion c;
       bool test=c.ouvrirConnexion();
       if(test)
       {w.show();
           qDebug()<<"DATABASE CONNECTED" ;

        }
   else
           QMessageBox::critical(0, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);






       return a.exec();











}
