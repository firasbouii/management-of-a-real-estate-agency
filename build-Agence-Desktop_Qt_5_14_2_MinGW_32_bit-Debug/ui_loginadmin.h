/********************************************************************************
** Form generated from reading UI file 'loginadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINADMIN_H
#define UI_LOGINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAdmin
{
public:
    QPushButton *AdminLoginButton;
    QLabel *label_3;
    QLineEdit *AdminLoginPW;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *AdminLoginAds;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QWidget *LoginAdmin)
    {
        if (LoginAdmin->objectName().isEmpty())
            LoginAdmin->setObjectName(QString::fromUtf8("LoginAdmin"));
        LoginAdmin->resize(400, 300);
        AdminLoginButton = new QPushButton(LoginAdmin);
        AdminLoginButton->setObjectName(QString::fromUtf8("AdminLoginButton"));
        AdminLoginButton->setGeometry(QRect(290, 230, 75, 23));
        label_3 = new QLabel(LoginAdmin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 20, 47, 13));
        AdminLoginPW = new QLineEdit(LoginAdmin);
        AdminLoginPW->setObjectName(QString::fromUtf8("AdminLoginPW"));
        AdminLoginPW->setGeometry(QRect(170, 150, 161, 31));
        AdminLoginPW->setEchoMode(QLineEdit::Password);
        label = new QLabel(LoginAdmin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 70, 71, 21));
        label_2 = new QLabel(LoginAdmin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 160, 81, 16));
        AdminLoginAds = new QLineEdit(LoginAdmin);
        AdminLoginAds->setObjectName(QString::fromUtf8("AdminLoginAds"));
        AdminLoginAds->setGeometry(QRect(170, 60, 161, 31));
        label_4 = new QLabel(LoginAdmin);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 240, 71, 21));
        pushButton = new QPushButton(LoginAdmin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 260, 75, 23));

        retranslateUi(LoginAdmin);

        QMetaObject::connectSlotsByName(LoginAdmin);
    } // setupUi

    void retranslateUi(QWidget *LoginAdmin)
    {
        LoginAdmin->setWindowTitle(QCoreApplication::translate("LoginAdmin", "Form", nullptr));
        AdminLoginButton->setText(QCoreApplication::translate("LoginAdmin", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("LoginAdmin", "Login", nullptr));
        label->setText(QCoreApplication::translate("LoginAdmin", "Pseudo", nullptr));
        label_2->setText(QCoreApplication::translate("LoginAdmin", "Mot de Passe", nullptr));
        label_4->setText(QCoreApplication::translate("LoginAdmin", "Ajout Agent", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginAdmin", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginAdmin: public Ui_LoginAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
