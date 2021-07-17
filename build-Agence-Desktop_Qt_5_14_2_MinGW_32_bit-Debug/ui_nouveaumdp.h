/********************************************************************************
** Form generated from reading UI file 'nouveaumdp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOUVEAUMDP_H
#define UI_NOUVEAUMDP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nouveauMDP
{
public:
    QLabel *Digit;
    QLabel *pswsize;
    QLabel *PasswordLabel;
    QLineEdit *password2;
    QLabel *letter;
    QLineEdit *password1;
    QPushButton *ChangePSDButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *nouveauMDP)
    {
        if (nouveauMDP->objectName().isEmpty())
            nouveauMDP->setObjectName(QString::fromUtf8("nouveauMDP"));
        nouveauMDP->resize(371, 277);
        Digit = new QLabel(nouveauMDP);
        Digit->setObjectName(QString::fromUtf8("Digit"));
        Digit->setGeometry(QRect(260, 90, 101, 31));
        pswsize = new QLabel(nouveauMDP);
        pswsize->setObjectName(QString::fromUtf8("pswsize"));
        pswsize->setGeometry(QRect(240, 150, 121, 16));
        PasswordLabel = new QLabel(nouveauMDP);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(130, 130, 111, 16));
        password2 = new QLineEdit(nouveauMDP);
        password2->setObjectName(QString::fromUtf8("password2"));
        password2->setGeometry(QRect(70, 150, 151, 20));
        password2->setEchoMode(QLineEdit::Password);
        letter = new QLabel(nouveauMDP);
        letter->setObjectName(QString::fromUtf8("letter"));
        letter->setGeometry(QRect(230, 120, 131, 41));
        password1 = new QLineEdit(nouveauMDP);
        password1->setObjectName(QString::fromUtf8("password1"));
        password1->setGeometry(QRect(70, 100, 151, 20));
        password1->setEchoMode(QLineEdit::Password);
        ChangePSDButton = new QPushButton(nouveauMDP);
        ChangePSDButton->setObjectName(QString::fromUtf8("ChangePSDButton"));
        ChangePSDButton->setGeometry(QRect(180, 200, 75, 23));
        label = new QLabel(nouveauMDP);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 70, 131, 31));
        label_2 = new QLabel(nouveauMDP);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 130, 111, 21));

        retranslateUi(nouveauMDP);

        QMetaObject::connectSlotsByName(nouveauMDP);
    } // setupUi

    void retranslateUi(QWidget *nouveauMDP)
    {
        nouveauMDP->setWindowTitle(QCoreApplication::translate("nouveauMDP", "Form", nullptr));
        Digit->setText(QString());
        pswsize->setText(QString());
        PasswordLabel->setText(QString());
        letter->setText(QString());
        ChangePSDButton->setText(QCoreApplication::translate("nouveauMDP", "Valider", nullptr));
        label->setText(QCoreApplication::translate("nouveauMDP", "Nouveau mot de passe", nullptr));
        label_2->setText(QCoreApplication::translate("nouveauMDP", "Verification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nouveauMDP: public Ui_nouveauMDP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOUVEAUMDP_H
