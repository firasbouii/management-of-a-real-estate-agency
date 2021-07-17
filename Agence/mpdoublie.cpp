#include "mpdoublie.h"
#include "ui_mpdoublie.h"
#include"secondclientwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>
#include <QDebug>
#include <QRegularExpression>
#include <QUuid>
#include<QProcess>
#include"nouveaumdp.h"
#include<QMessageBox>

mpdoublie::mpdoublie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mpdoublie)
{
    ui->setupUi(this);
    ui->label5->hide();
    ui->label6->hide();
    ui->label7->hide();
    ui->label8->hide();
    ui->label9->hide();
}

mpdoublie::~mpdoublie()
{
    delete ui;
}


bool text_changed=false;
QString str="";


void mpdoublie::on_EnvoyerMail_clicked()
{
    QString adresse=ui->MyEmail->text();
    QSqlQuery LoginQuery ;
    LoginQuery.prepare("select ID_client , Email from Client where Email=? ");
    LoginQuery.bindValue(0,adresse);
    LoginQuery.exec();
    if (LoginQuery.next())
    {
        int LoginID = LoginQuery.value(0).toInt();
        QString LoginEmail = LoginQuery.value(1).toString() ;
        str = QUuid::createUuid().toString();
        str.remove(QRegularExpression("{|}|-")); // if you want only hex numbers

        QStringList arguments;
      //  qDebug()<<QCoreApplication::applicationDirPath();
        arguments<<"C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/debug/mdpoublie.py"<<adresse<<str ;
        QProcess p;
        p.start("python", arguments);
        p.waitForFinished();
        ui->label5->show();
        ui->label6->show();
        ui->label7->show();
        ui->label8->show();
        ui->label9->show();
        ui->label5->setText("Veuillez vérifier votre e-mail pour un message avec votre code");
        ui->label6->setText("Votre code comporte 15 chiffres");
        ui->label7->setText("Code à 15 chiffres");
        ui->label8->setText("Nous avons envoyé votre code à:");
        ui->label9->setText(adresse);



    }
     else {

            this->hide();
            QMessageBox msgBox;
            msgBox.setText("Adresse Email inexistante  ");
            msgBox.exec();
        }



}

void mpdoublie::on_lineEdit_textChanged(const QString &arg1)
{

}

void mpdoublie::on_randomNum_textChanged(const QString &arg1)
{
    qDebug()<<"str : "<<str ;
    qDebug()<<"arg1 : "<<arg1;

    if(arg1==str){

        nouveauMDP * nv = new nouveauMDP;
        nv->setLOGINEMAIL(ui->MyEmail->text());
        nv->show();
        this->hide();
    }
    else
    {
        this->hide();
        QMessageBox msgBox;
        msgBox.setText("Code invalide ");
        msgBox.exec();
    }

}
//-/////////////////////////////////////////////////////////////////////////////////

