/********************************************************************************
** Form generated from reading UI file 'loginadminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINADMINWINDOW_H
#define UI_LOGINADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAdminWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AdminLoginButton;
    QLabel *label_3;
    QLineEdit *AdminLoginPW;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *AdminLoginAds;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginAdminWindow)
    {
        if (LoginAdminWindow->objectName().isEmpty())
            LoginAdminWindow->setObjectName(QString::fromUtf8("LoginAdminWindow"));
        LoginAdminWindow->resize(398, 299);
        centralwidget = new QWidget(LoginAdminWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AdminLoginButton = new QPushButton(centralwidget);
        AdminLoginButton->setObjectName(QString::fromUtf8("AdminLoginButton"));
        AdminLoginButton->setGeometry(QRect(250, 210, 75, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 0, 47, 13));
        AdminLoginPW = new QLineEdit(centralwidget);
        AdminLoginPW->setObjectName(QString::fromUtf8("AdminLoginPW"));
        AdminLoginPW->setGeometry(QRect(130, 130, 161, 31));
        AdminLoginPW->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 111, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 140, 81, 16));
        AdminLoginAds = new QLineEdit(centralwidget);
        AdminLoginAds->setObjectName(QString::fromUtf8("AdminLoginAds"));
        AdminLoginAds->setGeometry(QRect(130, 40, 161, 31));
        LoginAdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginAdminWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 398, 21));
        LoginAdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginAdminWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginAdminWindow->setStatusBar(statusbar);

        retranslateUi(LoginAdminWindow);

        QMetaObject::connectSlotsByName(LoginAdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginAdminWindow)
    {
        LoginAdminWindow->setWindowTitle(QCoreApplication::translate("LoginAdminWindow", "MainWindow", nullptr));
        AdminLoginButton->setText(QCoreApplication::translate("LoginAdminWindow", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("LoginAdminWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("LoginAdminWindow", "Adresse Email", nullptr));
        label_2->setText(QCoreApplication::translate("LoginAdminWindow", "Mot de Passe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginAdminWindow: public Ui_LoginAdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMINWINDOW_H
