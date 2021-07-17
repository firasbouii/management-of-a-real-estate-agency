#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "NewQTABdesign.h"
#include"client.h"
#include <QRegExpValidator>
#import <string>
#include <tr1/functional>
#include"QMessageBox"
bool digit=false ;
bool letter=false ;
bool Pswsize =false ;
ClientWindow::ClientWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWindow)
{
    //ui->tabWidgetPage1->tabBar()->setStyle(new CustomTabStyle);

    //ui->Client_Adresse_Num->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->Client_Adresse_Num ));
    //ui->Client_Tel_Num->setValidator(new QRegExpValidator(QRegExp("[0-9]{8,8}") , ui->Client_Tel_Num ));

    //https://stackoverflow.com/questions/13422995/set-qlineedit-to-accept-only-numbers



    ui->setupUi(this);
    ui->pswsize->setText("Password size >=8");
    ui->Digit->setText("Au moins un chiffre ");
    ui->letter->setText("Au moins un  caractère ");


}

ClientWindow::~ClientWindow()
{
    delete ui;
}

//*************Partie authentification client ****************************

void ClientWindow::on_pushButton_clicked()
{
    std::tr1::hash <std::string> hash;
    string LoginMail =ui->LoginAds->text().toStdString();
    string LoginPwd =ui->LoginPW->text().toStdString();
    QSqlQuery LoginQuery ;
    LoginQuery.prepare("select ID_client , Email from Client where Email=? ");
    LoginQuery.bindValue(0,QString::fromStdString(LoginMail));
    LoginQuery.exec();
    if (LoginQuery.next())
    {
        int LoginID = LoginQuery.value(0).toInt();
        QString LoginEmail = LoginQuery.value(1).toString() ;
        qDebug()<<"--- "<<LoginID <<"--- "<<LoginEmail ;
        QSqlQuery PSWQuery ;
        PSWQuery.prepare("select mot_de_passe from clientlogin where id_client =?");
        PSWQuery.bindValue(0,QString::number(LoginID));
        PSWQuery.exec();
        PSWQuery.next();
        qDebug()<<"password---- "<<PSWQuery.value(0).toString();
        qDebug()<<"login hashed password : hash(LoginPwd) ---- "<<hash(LoginPwd);

        if (PSWQuery.value(0).toInt() ==   hash(LoginPwd) )
              {

              qDebug()<<"password---- correct ";
              scl->setID(LoginID);
              scl->showInfo();
              scl->show() ;
              this->hide();
              }

        else
            {

            qDebug()<<"password---- false ";
            QMessageBox msgBox;
            msgBox.setText("Email ou mot de passe incorrect !");
            msgBox.exec();

            }


    }


    else
    {
        QMessageBox msgBox;
        msgBox.setText("Email ou Mot de pas incorrect ! ");
        msgBox.exec();
    }





}




//*************Partie Login client ****************************

void ClientWindow::on_Client_ADD_Button_clicked()
{


    string Name =ui->Client_Name->text().toStdString();
    string Last_Name =ui->Client_Last_Name->text().toStdString();
    string Email =ui->Client_Email->text().toStdString();
    int Tel_Num =ui->Client_Tel_Num->text().toInt();
    int Adresse_Num =ui->Client_Adresse_Num->text().toInt();
    string Quartier =ui->Client_Adresse_Quartier->text().toStdString();
    string Ville =ui->Client_Adresse_Ville->text().toStdString();
    int year = ui->Client_Date_Edit->date().year();
    int month = ui->Client_Date_Edit->date().month();
    int day = ui->Client_Date_Edit->date().day();
    string mdp1 = ui->password1->text().toStdString();
    string mdp2 = ui->password2->text().toStdString();

if (digit==false || letter==false || Pswsize==false )
{ QMessageBox msgBox2;
     msgBox2.setText(" Votre mot de passe doit contenir un minimum de 8 caractères dont au moins 1 chiffre   ");
     msgBox2.exec();
}

else
{


 if (mdp2!=mdp1)
            {
       ui->PasswordLabel->setText("<font color='red'>Vos mots de passe ne sont identiques</font>");
       QMessageBox msgBox;
       msgBox.setText("Vous devez saisir deux fois le même mot de passe pour le confirmer.    ");
       msgBox.exec();
}
    else
          {
        QSqlQuery query1;
        query1.prepare("select * from client where email='"+ui->Client_Email->text()+"' ");

        query1.exec();
        if ( query1.next() )
        {   QString Em = query1.value(3).toString(); //
            QMessageBox msgBox;
            msgBox.setText("Cette Adresse E-mail existe ");
            msgBox.exec();

        }
        else
        {
            if ((Name=="")||(Last_Name=="")||(Email=="")||(Tel_Num==0)||(Adresse_Num==0)||(Quartier=="")||(Ville==""))
            {
                QMessageBox msgBox;
                msgBox.setText("Remplir tous les champs");
                msgBox.exec();
            }
            else
            {
            Client C(9999,Name,Last_Name,Email,Tel_Num,Adresse_Num,Quartier,Ville,day,month,year) ;
            C.ADD_DB();
            int IDCL =C.get_Id_Client();
            std::tr1::hash <std::string> hash;
            QSqlQuery insertMPD;
            insertMPD.prepare("insert into CLIENTLOGIN(ID_CLIENT,MOT_DE_PASSE) values(?,?) ");
            insertMPD.bindValue(0,IDCL);
            insertMPD.bindValue(1,QString::number(hash(mdp1)));
            insertMPD.exec();
            QMessageBox msgBox;
            msgBox.setText("votre compte est créé.");
            msgBox.exec();
            }
       }
    }
}
}



void ClientWindow::on_password1_textChanged(const QString &arg1)
{   ui->pswsize->setText("Password size >=8");
    ui->Digit->setText("Au moins un chiffre ");
    ui->letter->setText("Au moins un  caractère ");

    digit=false ;
    letter=false ;
    qDebug()<<"------------------------- -  "<<arg1 ;
    for (int i =0;i<arg1.size();i++)
    {
        if (arg1[i].isDigit())
            digit=true;

        else if (arg1[i].isLetter())
            letter=true ;
    }
    qDebug()<<"diiiiigiiit  "<<digit<<"  letterr  "<<letter ;

    if (digit)
        ui->Digit->setText("    ");

    if (letter)
        ui->letter->setText("    ");

    if ( arg1.size() >= 8 )
        Pswsize = true ;
    else
        Pswsize = false ;

    if (Pswsize)
        ui->pswsize->setText("  ");
    qDebug()<<"Pswsize "<<Pswsize ;

}

void ClientWindow::on_password2_textChanged(const QString &arg1)
{

    QString FirstPassword = ui->password1->text();
    if (FirstPassword !=arg1)
        ui->PasswordLabel->setText("Vos mots de passe ne sont identiques");
    else
        ui->PasswordLabel->setText("  ");

}



void ClientWindow::on_pushButton_2_clicked()
{
    md->show();

}
