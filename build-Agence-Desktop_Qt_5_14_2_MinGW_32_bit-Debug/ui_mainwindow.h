/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *frame;
    QLabel *ClientImageLabel;
    QLabel *clientPhoto;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(854, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 260, 191, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 370, 191, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 30, 401, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font.setPointSize(26);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 90, 271, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS PGothic"));
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 200, 241, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Tw Cen MT"));
        font2.setPointSize(16);
        label_3->setFont(font2);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 200, 371, 251));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	\n"
"border: 1px solid black\n"
"}\n"
"\n"
"QLabel{\n"
"\n"
"border-style: none;\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ClientImageLabel = new QLabel(frame);
        ClientImageLabel->setObjectName(QString::fromUtf8("ClientImageLabel"));
        ClientImageLabel->setGeometry(QRect(10, 120, 181, 151));
        clientPhoto = new QLabel(centralwidget);
        clientPhoto->setObjectName(QString::fromUtf8("clientPhoto"));
        clientPhoto->setGeometry(QRect(240, 240, 101, 91));
        MainWindow->setCentralWidget(centralwidget);
        frame->raise();
        pushButton->raise();
        pushButton_2->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        clientPhoto->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 854, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Agent", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Agence Immobiliere", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Bienvenue", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Menu Principale", nullptr));
        ClientImageLabel->setText(QString());
        clientPhoto->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
