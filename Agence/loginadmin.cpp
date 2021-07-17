#include "loginadmin.h"
#include "ui_loginadmin.h"
#include"agent.h"
#include "string.h"
#include"bien_immobilier.h"
#include"maison.h"
#include"entrepot.h"
#include"terrain.h"
#include"appartement.h"
#include"qtablewidget.h"
#include <QWidget>
#include"reservation.h"
#include"proposition.h"
#include <tr1/functional>
#include"QMessageBox"
#include <QLayout>

LoginAdmin::LoginAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
   // A->show();
  //  this->hide();

}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

void LoginAdmin::on_AdminLoginButton_clicked()
{

    string Pseudo =ui->AdminLoginAds->text().toStdString();
    string LoginPwd =ui->AdminLoginPW->text().toStdString();
    std::tr1::hash <std::string> hash;




    Agent b ;
    creer2(&b);
    LireFichier(&b);


    qDebug()<<"here"<<QString::fromStdString(b.rechercher("Yacine"));
    b.afficher();

    if ( b.rechercher(Pseudo)== QString::number(hash(LoginPwd)).toStdString() )
    {
        A->show();
        this->hide();


    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Mot de passe incorrect !");
        msgBox.exec();

    }




    cout<<"*****************";







}

void LoginAdmin::on_pushButton_clicked()
{


    QMessageBox mb2;
    QLabel le1;
    QLabel le2;
    QLineEdit l1;
    QLineEdit l2;

    le1.setText("ID SYSTEM");
    le2.setText("Mot de Passe");
    mb2.layout()->addWidget(&le1);
    mb2.layout()->addWidget(&le2);
    mb2.layout()->addWidget(&l1);
    mb2.layout()->addWidget(&l2);


    mb2.setStandardButtons(QMessageBox::Ok);
    mb2.setDefaultButton(QMessageBox::Ok);
    int ret = mb2.exec();

    if (ret==QMessageBox::Ok)
        qDebug()<<'hiii';

    else
        qDebug()<<'byeee';


    if( (l1.text()=="admin") && (l2.text()=="admin"))
    {

        QMessageBox mb;
        QLineEdit le;
        QLineEdit le2;
        QLabel la;
        QLabel la2;
        la2.setText("Pseudo");
        la.setText("Mot de Passe");
        mb.layout()->addWidget(&le2);
        mb.layout()->addWidget(&la2);
        mb.layout()->addWidget(&la);
        mb.layout()->addWidget(&le);


        mb.exec();
        qDebug()<<le2.text()<<le.text();


         Agent a ;
         creer2(&a);
         LireFichier(&a);
         EcrireFichier(&a);
         a.afficher();

         std::tr1::hash <std::string> hash;
         string pseudo=le2.text().toStdString();
         string psw=le.text().toStdString();
         a.ajouter(pseudo,QString::number(hash(psw)).toStdString());
         creer(&a);
         EcrireFichier(&a);






    }
    else
    {

        QMessageBox mb3;
        QLabel l;
        l.setText("Mot de passe ou ID incorrect ");
        mb3.layout()->addWidget(&l);
        mb3.exec();

    }





}
