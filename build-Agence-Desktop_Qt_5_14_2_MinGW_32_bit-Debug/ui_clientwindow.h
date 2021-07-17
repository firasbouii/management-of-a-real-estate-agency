/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QLineEdit *LoginAds;
    QLineEdit *LoginPW;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label_4;
    QLabel *label_10;
    QLineEdit *Client_Name;
    QLineEdit *Client_Email;
    QPushButton *Client_ADD_Button;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_12;
    QLineEdit *Client_Last_Name;
    QLineEdit *Client_Adresse_Ville;
    QLabel *label_11;
    QLineEdit *Client_Tel_Num;
    QLineEdit *Client_Adresse_Num;
    QLineEdit *Client_Adresse_Quartier;
    QLabel *label_7;
    QDateEdit *Client_Date_Edit;
    QLineEdit *password1;
    QLineEdit *password2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *PasswordLabel;
    QLabel *Digit;
    QLabel *letter;
    QLabel *pswsize;
    QLabel *label_14;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(905, 579);
        LoginAds = new QLineEdit(ClientWindow);
        LoginAds->setObjectName(QString::fromUtf8("LoginAds"));
        LoginAds->setGeometry(QRect(170, 170, 161, 31));
        LoginPW = new QLineEdit(ClientWindow);
        LoginPW->setObjectName(QString::fromUtf8("LoginPW"));
        LoginPW->setGeometry(QRect(170, 260, 161, 31));
        LoginPW->setEchoMode(QLineEdit::Password);
        label = new QLabel(ClientWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 180, 111, 16));
        label_2 = new QLabel(ClientWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 270, 81, 16));
        label_3 = new QLabel(ClientWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 130, 61, 21));
        pushButton = new QPushButton(ClientWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 340, 75, 23));
        line = new QFrame(ClientWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(430, 70, 20, 511));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(ClientWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(610, 90, 121, 41));
        label_10 = new QLabel(ClientWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(500, 310, 47, 13));
        Client_Name = new QLineEdit(ClientWindow);
        Client_Name->setObjectName(QString::fromUtf8("Client_Name"));
        Client_Name->setGeometry(QRect(610, 160, 151, 20));
        Client_Email = new QLineEdit(ClientWindow);
        Client_Email->setObjectName(QString::fromUtf8("Client_Email"));
        Client_Email->setGeometry(QRect(610, 230, 151, 20));
        Client_ADD_Button = new QPushButton(ClientWindow);
        Client_ADD_Button->setObjectName(QString::fromUtf8("Client_ADD_Button"));
        Client_ADD_Button->setGeometry(QRect(750, 510, 121, 31));
        label_8 = new QLabel(ClientWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(500, 190, 47, 13));
        label_9 = new QLabel(ClientWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(500, 230, 51, 21));
        label_12 = new QLabel(ClientWindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(500, 270, 51, 21));
        Client_Last_Name = new QLineEdit(ClientWindow);
        Client_Last_Name->setObjectName(QString::fromUtf8("Client_Last_Name"));
        Client_Last_Name->setGeometry(QRect(610, 190, 151, 20));
        Client_Adresse_Ville = new QLineEdit(ClientWindow);
        Client_Adresse_Ville->setObjectName(QString::fromUtf8("Client_Adresse_Ville"));
        Client_Adresse_Ville->setGeometry(QRect(760, 310, 111, 21));
        label_11 = new QLabel(ClientWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(500, 350, 111, 21));
        Client_Tel_Num = new QLineEdit(ClientWindow);
        Client_Tel_Num->setObjectName(QString::fromUtf8("Client_Tel_Num"));
        Client_Tel_Num->setGeometry(QRect(610, 270, 151, 20));
        Client_Tel_Num->setEchoMode(QLineEdit::Normal);
        Client_Adresse_Num = new QLineEdit(ClientWindow);
        Client_Adresse_Num->setObjectName(QString::fromUtf8("Client_Adresse_Num"));
        Client_Adresse_Num->setGeometry(QRect(610, 310, 41, 21));
        Client_Adresse_Quartier = new QLineEdit(ClientWindow);
        Client_Adresse_Quartier->setObjectName(QString::fromUtf8("Client_Adresse_Quartier"));
        Client_Adresse_Quartier->setGeometry(QRect(660, 310, 91, 21));
        label_7 = new QLabel(ClientWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 160, 47, 17));
        Client_Date_Edit = new QDateEdit(ClientWindow);
        Client_Date_Edit->setObjectName(QString::fromUtf8("Client_Date_Edit"));
        Client_Date_Edit->setGeometry(QRect(610, 350, 141, 21));
        password1 = new QLineEdit(ClientWindow);
        password1->setObjectName(QString::fromUtf8("password1"));
        password1->setGeometry(QRect(610, 390, 113, 20));
        password1->setEchoMode(QLineEdit::Password);
        password2 = new QLineEdit(ClientWindow);
        password2->setObjectName(QString::fromUtf8("password2"));
        password2->setGeometry(QRect(610, 430, 113, 20));
        password2->setEchoMode(QLineEdit::Password);
        label_5 = new QLabel(ClientWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(500, 390, 71, 16));
        label_6 = new QLabel(ClientWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 430, 91, 16));
        label_13 = new QLabel(ClientWindow);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(610, 410, 47, 13));
        PasswordLabel = new QLabel(ClientWindow);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(610, 370, 111, 16));
        Digit = new QLabel(ClientWindow);
        Digit->setObjectName(QString::fromUtf8("Digit"));
        Digit->setGeometry(QRect(760, 375, 101, 31));
        letter = new QLabel(ClientWindow);
        letter->setObjectName(QString::fromUtf8("letter"));
        letter->setGeometry(QRect(760, 390, 101, 41));
        pswsize = new QLabel(ClientWindow);
        pswsize->setObjectName(QString::fromUtf8("pswsize"));
        pswsize->setGeometry(QRect(760, 420, 121, 16));
        label_14 = new QLabel(ClientWindow);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(290, 20, 311, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font.setPointSize(20);
        label_14->setFont(font);
        pushButton_2 = new QPushButton(ClientWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 340, 121, 23));

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QWidget *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("ClientWindow", "ADRESSE Email", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWindow", "Mot de Passe", nullptr));
        label_3->setText(QCoreApplication::translate("ClientWindow", "Login", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientWindow", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("ClientWindow", "INSCRIPTION", nullptr));
        label_10->setText(QCoreApplication::translate("ClientWindow", "Adresse", nullptr));
        Client_ADD_Button->setText(QCoreApplication::translate("ClientWindow", "S'INSCRIRE", nullptr));
        label_8->setText(QCoreApplication::translate("ClientWindow", "Prenom", nullptr));
        label_9->setText(QCoreApplication::translate("ClientWindow", "Email", nullptr));
        label_12->setText(QCoreApplication::translate("ClientWindow", "Numero Tel", nullptr));
        label_11->setText(QCoreApplication::translate("ClientWindow", "Date_Naissance", nullptr));
        label_7->setText(QCoreApplication::translate("ClientWindow", "Nom", nullptr));
        label_5->setText(QCoreApplication::translate("ClientWindow", "Mot de Passe", nullptr));
        label_6->setText(QCoreApplication::translate("ClientWindow", "Mot de Passe", nullptr));
        label_13->setText(QString());
        PasswordLabel->setText(QString());
        Digit->setText(QString());
        letter->setText(QString());
        pswsize->setText(QString());
        label_14->setText(QCoreApplication::translate("ClientWindow", "Page d'Authentification", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ClientWindow", "Mot de passe oubli\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
