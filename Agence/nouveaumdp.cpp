#include "nouveaumdp.h"
#include "ui_nouveaumdp.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>
#include <QDebug>
#include <QRegularExpression>
#include <QUuid>
#include<QProcess>
#include<string>
#include"string.h"
#include <tr1/functional>
#include<QMessageBox>

nouveauMDP::nouveauMDP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nouveauMDP)
{
    ui->setupUi(this);
}

nouveauMDP::~nouveauMDP()
{
    delete ui;
}
bool digit1=false;
bool letter1=false;
bool Pswsize1=false;
void nouveauMDP::on_password1_textChanged(const QString &arg1)
{
  ui->pswsize->setText("Password size >=8");
  ui->Digit->setText("Au moins un chiffre ");
  ui->letter->setText("Au moins un  caractère ");

  digit1=false ;
  letter1=false ;
  qDebug()<<"------------------------- -  "<<arg1 ;
  for (int i =0;i<arg1.size();i++)
  {
      if (arg1[i].isDigit())
          digit1=true;

      else if (arg1[i].isLetter())
          letter1=true ;
  }
  qDebug()<<"diiiiigiiit  "<<digit1<<"  letterr  "<<letter1 ;

  if (digit1)
      ui->Digit->setText("    ");

  if (letter1)
      ui->letter->setText("    ");

  if ( arg1.size() >= 8 )
      Pswsize1 = true ;
  else
      Pswsize1 = false ;

  if (Pswsize1)
      ui->pswsize->setText("  ");
  qDebug()<<"Pswsize "<<Pswsize1 ;



}

void nouveauMDP::on_password2_textChanged(const QString &arg1)
{

    QString FirstPassword = ui->password1->text();
    if (FirstPassword !=arg1)
        ui->PasswordLabel->setText("Vos mots de passe ne sont identiques");
    else
        ui->PasswordLabel->setText("  ");

}

void nouveauMDP::on_ChangePSDButton_clicked()
{
    QString mdp1 = ui->password1->text();
    QString mdp2 = ui->password2->text();

    if (digit1==false || letter1==false || Pswsize1==false )
    {
        QMessageBox msgBox2;
        msgBox2.setText(" Votre mot de passe doit contenir un minimum de 8 caractères dont au moins 1 chiffre   ");
        msgBox2.exec();
    }

    else
    {


    if (mdp2!=mdp1)

        {
        ui->PasswordLabel->setText("<font color='red'>Vos mots de passe ne sont identiques</font>");
        QMessageBox msgBox;
        msgBox.setText("Vous devez saisir deux fois le même mot de passe pour le confirmer.     ");
        msgBox.exec();
        }

    else
          {
            QSqlQuery query1;
            query1.prepare("select ID_client from client where email='"+LoginEmail+"' ");
            query1.exec();
        if ( query1.next() )
        {   int Id = query1.value(0).toInt();
            qDebug()<<"Ce Id  Existe : "<< Id ;
            QSqlQuery query2;
            std::tr1::hash <std::string> hash;
            query2.prepare("update clientlogin set mot_de_passe=? where id_client=?");
            query2.bindValue(0,QString::number(hash(mdp1.toStdString())));
            query2.bindValue(1,Id);
            if(query2.exec())
            {
                this->hide();
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Probleme : Mise à jour  ");
                msgBox.exec();
             }


        }

    }
    }
}
