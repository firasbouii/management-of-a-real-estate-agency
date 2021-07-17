/********************************************************************************
** Form generated from reading UI file 'mpdoublie.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPDOUBLIE_H
#define UI_MPDOUBLIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mpdoublie
{
public:
    QPushButton *EnvoyerMail;
    QLineEdit *randomNum;
    QLabel *label_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label8;
    QLabel *label9;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *MyEmail;

    void setupUi(QWidget *mpdoublie)
    {
        if (mpdoublie->objectName().isEmpty())
            mpdoublie->setObjectName(QString::fromUtf8("mpdoublie"));
        mpdoublie->resize(400, 300);
        EnvoyerMail = new QPushButton(mpdoublie);
        EnvoyerMail->setObjectName(QString::fromUtf8("EnvoyerMail"));
        EnvoyerMail->setGeometry(QRect(270, 50, 75, 23));
        randomNum = new QLineEdit(mpdoublie);
        randomNum->setObjectName(QString::fromUtf8("randomNum"));
        randomNum->setGeometry(QRect(100, 140, 171, 31));
        label_2 = new QLabel(mpdoublie);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 150, 71, 16));
        widget = new QWidget(mpdoublie);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 80, 211, 53));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label5 = new QLabel(widget);
        label5->setObjectName(QString::fromUtf8("label5"));

        verticalLayout->addWidget(label5);

        label6 = new QLabel(widget);
        label6->setObjectName(QString::fromUtf8("label6"));

        verticalLayout->addWidget(label6);

        label7 = new QLabel(widget);
        label7->setObjectName(QString::fromUtf8("label7"));
        QFont font;
        font.setPointSize(7);
        label7->setFont(font);

        verticalLayout->addWidget(label7);

        widget1 = new QWidget(mpdoublie);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(100, 180, 211, 34));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label8 = new QLabel(widget1);
        label8->setObjectName(QString::fromUtf8("label8"));

        verticalLayout_2->addWidget(label8);

        label9 = new QLabel(widget1);
        label9->setObjectName(QString::fromUtf8("label9"));

        verticalLayout_2->addWidget(label9);

        widget2 = new QWidget(mpdoublie);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(100, 30, 135, 41));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        MyEmail = new QLineEdit(widget2);
        MyEmail->setObjectName(QString::fromUtf8("MyEmail"));

        verticalLayout_3->addWidget(MyEmail);


        retranslateUi(mpdoublie);

        QMetaObject::connectSlotsByName(mpdoublie);
    } // setupUi

    void retranslateUi(QWidget *mpdoublie)
    {
        mpdoublie->setWindowTitle(QCoreApplication::translate("mpdoublie", "Form", nullptr));
        EnvoyerMail->setText(QCoreApplication::translate("mpdoublie", "Envoyer", nullptr));
        label_2->setText(QCoreApplication::translate("mpdoublie", "Taper Le code", nullptr));
        label5->setText(QCoreApplication::translate("mpdoublie", "TextLabel", nullptr));
        label6->setText(QCoreApplication::translate("mpdoublie", "TextLabel", nullptr));
        label7->setText(QCoreApplication::translate("mpdoublie", "TextLabel", nullptr));
        label8->setText(QCoreApplication::translate("mpdoublie", "TextLabel", nullptr));
        label9->setText(QCoreApplication::translate("mpdoublie", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("mpdoublie", "Votre Adresse Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mpdoublie: public Ui_mpdoublie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPDOUBLIE_H
