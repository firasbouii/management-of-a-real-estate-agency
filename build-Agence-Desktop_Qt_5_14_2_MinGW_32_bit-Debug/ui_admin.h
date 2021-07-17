/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QCalendarWidget *calendarWidget;
    QPushButton *testing;
    QWidget *tab;
    QTableWidget *ReservationTable;
    QPushButton *LoadReservation;
    QTableWidget *ClientTerrain;
    QTableWidget *ClientEntrepot;
    QTableWidget *ClientAppartemet;
    QTableWidget *ClientMaison;
    QPushButton *AccepterRes;
    QTableWidget *ClientMaison_2;
    QTableWidget *ClientAppartemet_2;
    QPushButton *LoadProposition;
    QPushButton *AccepterPro;
    QTableWidget *ClientEntrepot_2;
    QTableWidget *PropositionTable;
    QTableWidget *ClientTerrain_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QWidget *tab_5;
    QTableWidget *bien_table;
    QPushButton *pushButton_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QRadioButton *radioEntrepot;
    QLabel *calculEntrepot;
    QRadioButton *radioAppartement;
    QLabel *calculAppartement;
    QRadioButton *radioMaison;
    QLabel *calculMaison;
    QRadioButton *radioTerrain;
    QLabel *calculTerrain;
    QWidget *tab_6;
    QTableWidget *tablew2;
    QPushButton *LoadClient;
    QFrame *frame;
    QLabel *label_3;
    QLineEdit *ClientName;
    QLineEdit *ClientNom;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QTableWidget *PropositionTable_2;
    QTableWidget *ReservationTable_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tab_3;
    QTableWidget *LocationTable;
    QTableWidget *VenteTable;
    QPushButton *loadContratLoc;
    QPushButton *LoadContratVente;
    QTableWidget *ClientTerrain_3;
    QTableWidget *ClientMaison_3;
    QTableWidget *ClientAppartemet_3;
    QTableWidget *ClientEntrepot_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(1061, 683);
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 0, 1041, 651));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"    position: absolute;\n"
"    top: -0.5em;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 "
                        "#fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"QTabBar::tab { height: 50px; width: 100px; }"));
        tabWidget->setTabPosition(QTabWidget::North);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        calendarWidget = new QCalendarWidget(tab_2);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(20, 40, 256, 183));
        testing = new QPushButton(tab_2);
        testing->setObjectName(QString::fromUtf8("testing"));
        testing->setGeometry(QRect(250, 230, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        ReservationTable = new QTableWidget(tab);
        ReservationTable->setObjectName(QString::fromUtf8("ReservationTable"));
        ReservationTable->setGeometry(QRect(10, 30, 421, 151));
        ReservationTable->setStyleSheet(QString::fromUtf8(" QTableView {\n"
"     selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                 stop: 0 #FF92BB, stop: 1 white);\n"
" }"));
        LoadReservation = new QPushButton(tab);
        LoadReservation->setObjectName(QString::fromUtf8("LoadReservation"));
        LoadReservation->setGeometry(QRect(440, 40, 75, 23));
        ClientTerrain = new QTableWidget(tab);
        ClientTerrain->setObjectName(QString::fromUtf8("ClientTerrain"));
        ClientTerrain->setGeometry(QRect(10, 240, 771, 61));
        ClientEntrepot = new QTableWidget(tab);
        ClientEntrepot->setObjectName(QString::fromUtf8("ClientEntrepot"));
        ClientEntrepot->setGeometry(QRect(10, 240, 771, 61));
        ClientAppartemet = new QTableWidget(tab);
        ClientAppartemet->setObjectName(QString::fromUtf8("ClientAppartemet"));
        ClientAppartemet->setGeometry(QRect(10, 240, 771, 61));
        ClientMaison = new QTableWidget(tab);
        ClientMaison->setObjectName(QString::fromUtf8("ClientMaison"));
        ClientMaison->setGeometry(QRect(10, 240, 771, 61));
        AccepterRes = new QPushButton(tab);
        AccepterRes->setObjectName(QString::fromUtf8("AccepterRes"));
        AccepterRes->setGeometry(QRect(440, 70, 75, 23));
        ClientMaison_2 = new QTableWidget(tab);
        ClientMaison_2->setObjectName(QString::fromUtf8("ClientMaison_2"));
        ClientMaison_2->setGeometry(QRect(0, 440, 791, 61));
        ClientAppartemet_2 = new QTableWidget(tab);
        ClientAppartemet_2->setObjectName(QString::fromUtf8("ClientAppartemet_2"));
        ClientAppartemet_2->setGeometry(QRect(0, 440, 791, 61));
        LoadProposition = new QPushButton(tab);
        LoadProposition->setObjectName(QString::fromUtf8("LoadProposition"));
        LoadProposition->setGeometry(QRect(520, 120, 75, 23));
        AccepterPro = new QPushButton(tab);
        AccepterPro->setObjectName(QString::fromUtf8("AccepterPro"));
        AccepterPro->setGeometry(QRect(520, 150, 75, 23));
        ClientEntrepot_2 = new QTableWidget(tab);
        ClientEntrepot_2->setObjectName(QString::fromUtf8("ClientEntrepot_2"));
        ClientEntrepot_2->setGeometry(QRect(0, 440, 791, 61));
        PropositionTable = new QTableWidget(tab);
        PropositionTable->setObjectName(QString::fromUtf8("PropositionTable"));
        PropositionTable->setGeometry(QRect(600, 30, 401, 151));
        ClientTerrain_2 = new QTableWidget(tab);
        ClientTerrain_2->setObjectName(QString::fromUtf8("ClientTerrain_2"));
        ClientTerrain_2->setGeometry(QRect(0, 440, 791, 61));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 10, 131, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 101, 21));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 180, 391, 41));
        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        bien_table = new QTableWidget(tab_5);
        bien_table->setObjectName(QString::fromUtf8("bien_table"));
        bien_table->setEnabled(true);
        bien_table->setGeometry(QRect(150, 110, 611, 151));
        bien_table->verticalHeader()->setDefaultSectionSize(23);
        pushButton_3 = new QPushButton(tab_5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 20, 75, 23));
        checkBox_2 = new QCheckBox(tab_5);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 200, 70, 17));
        checkBox = new QCheckBox(tab_5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 170, 70, 17));
        checkBox_3 = new QCheckBox(tab_5);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 260, 70, 17));
        radioEntrepot = new QRadioButton(tab_5);
        radioEntrepot->setObjectName(QString::fromUtf8("radioEntrepot"));
        radioEntrepot->setGeometry(QRect(20, 21, 65, 17));
        calculEntrepot = new QLabel(tab_5);
        calculEntrepot->setObjectName(QString::fromUtf8("calculEntrepot"));
        calculEntrepot->setGeometry(QRect(82, 21, 16, 16));
        radioAppartement = new QRadioButton(tab_5);
        radioAppartement->setObjectName(QString::fromUtf8("radioAppartement"));
        radioAppartement->setGeometry(QRect(20, 51, 86, 17));
        calculAppartement = new QLabel(tab_5);
        calculAppartement->setObjectName(QString::fromUtf8("calculAppartement"));
        calculAppartement->setGeometry(QRect(103, 51, 16, 16));
        radioMaison = new QRadioButton(tab_5);
        radioMaison->setObjectName(QString::fromUtf8("radioMaison"));
        radioMaison->setGeometry(QRect(20, 81, 56, 17));
        calculMaison = new QLabel(tab_5);
        calculMaison->setObjectName(QString::fromUtf8("calculMaison"));
        calculMaison->setGeometry(QRect(73, 81, 16, 16));
        radioTerrain = new QRadioButton(tab_5);
        radioTerrain->setObjectName(QString::fromUtf8("radioTerrain"));
        radioTerrain->setGeometry(QRect(20, 111, 57, 17));
        calculTerrain = new QLabel(tab_5);
        calculTerrain->setObjectName(QString::fromUtf8("calculTerrain"));
        calculTerrain->setGeometry(QRect(74, 111, 16, 16));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tablew2 = new QTableWidget(tab_6);
        if (tablew2->columnCount() < 7)
            tablew2->setColumnCount(7);
        tablew2->setObjectName(QString::fromUtf8("tablew2"));
        tablew2->setGeometry(QRect(210, 60, 671, 181));
        tablew2->setRowCount(0);
        tablew2->setColumnCount(7);
        tablew2->horizontalHeader()->setMinimumSectionSize(25);
        tablew2->horizontalHeader()->setDefaultSectionSize(90);
        tablew2->horizontalHeader()->setStretchLastSection(true);
        tablew2->verticalHeader()->setCascadingSectionResizes(true);
        tablew2->verticalHeader()->setDefaultSectionSize(23);
        tablew2->verticalHeader()->setStretchLastSection(true);
        LoadClient = new QPushButton(tab_6);
        LoadClient->setObjectName(QString::fromUtf8("LoadClient"));
        LoadClient->setGeometry(QRect(210, 250, 75, 23));
        frame = new QFrame(tab_6);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 60, 171, 181));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 71, 21));
        ClientName = new QLineEdit(frame);
        ClientName->setObjectName(QString::fromUtf8("ClientName"));
        ClientName->setGeometry(QRect(80, 40, 81, 20));
        ClientNom = new QLineEdit(frame);
        ClientNom->setObjectName(QString::fromUtf8("ClientNom"));
        ClientNom->setGeometry(QRect(80, 80, 81, 21));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 51, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 80, 47, 13));
        pushButton = new QPushButton(tab_6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 250, 75, 23));
        PropositionTable_2 = new QTableWidget(tab_6);
        PropositionTable_2->setObjectName(QString::fromUtf8("PropositionTable_2"));
        PropositionTable_2->setGeometry(QRect(580, 330, 291, 151));
        ReservationTable_2 = new QTableWidget(tab_6);
        ReservationTable_2->setObjectName(QString::fromUtf8("ReservationTable_2"));
        ReservationTable_2->setGeometry(QRect(80, 330, 291, 151));
        ReservationTable_2->setStyleSheet(QString::fromUtf8(" QTableView {\n"
"     selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                 stop: 0 #FF92BB, stop: 1 white);\n"
" }"));
        label_7 = new QLabel(tab_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(210, 40, 321, 16));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(80, 310, 111, 16));
        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(580, 310, 161, 16));
        tabWidget->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        LocationTable = new QTableWidget(tab_3);
        LocationTable->setObjectName(QString::fromUtf8("LocationTable"));
        LocationTable->setGeometry(QRect(0, 40, 881, 192));
        VenteTable = new QTableWidget(tab_3);
        VenteTable->setObjectName(QString::fromUtf8("VenteTable"));
        VenteTable->setGeometry(QRect(0, 270, 881, 192));
        loadContratLoc = new QPushButton(tab_3);
        loadContratLoc->setObjectName(QString::fromUtf8("loadContratLoc"));
        loadContratLoc->setGeometry(QRect(950, 30, 75, 23));
        LoadContratVente = new QPushButton(tab_3);
        LoadContratVente->setObjectName(QString::fromUtf8("LoadContratVente"));
        LoadContratVente->setGeometry(QRect(960, 290, 75, 23));
        ClientTerrain_3 = new QTableWidget(tab_3);
        ClientTerrain_3->setObjectName(QString::fromUtf8("ClientTerrain_3"));
        ClientTerrain_3->setGeometry(QRect(20, 520, 771, 61));
        ClientMaison_3 = new QTableWidget(tab_3);
        ClientMaison_3->setObjectName(QString::fromUtf8("ClientMaison_3"));
        ClientMaison_3->setGeometry(QRect(20, 520, 771, 61));
        ClientAppartemet_3 = new QTableWidget(tab_3);
        ClientAppartemet_3->setObjectName(QString::fromUtf8("ClientAppartemet_3"));
        ClientAppartemet_3->setGeometry(QRect(20, 520, 771, 61));
        ClientEntrepot_3 = new QTableWidget(tab_3);
        ClientEntrepot_3->setObjectName(QString::fromUtf8("ClientEntrepot_3"));
        ClientEntrepot_3->setGeometry(QRect(20, 520, 771, 61));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 20, 111, 16));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 250, 111, 16));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 500, 151, 16));
        tabWidget->addTab(tab_3, QString());
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(950, 10, 75, 23));
        Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Admin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1061, 21));
        Admin->setMenuBar(menubar);
        statusbar = new QStatusBar(Admin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Admin->setStatusBar(statusbar);

        retranslateUi(Admin);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "MainWindow", nullptr));
        testing->setText(QCoreApplication::translate("Admin", "Testing", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Admin", "Tab 2", nullptr));
        LoadReservation->setText(QCoreApplication::translate("Admin", "Afficher", nullptr));
        AccepterRes->setText(QCoreApplication::translate("Admin", "Accepter", nullptr));
        LoadProposition->setText(QCoreApplication::translate("Admin", "Afficher", nullptr));
        AccepterPro->setText(QCoreApplication::translate("Admin", "Accepter", nullptr));
        label->setText(QCoreApplication::translate("Admin", "Proposition", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "Reservation", nullptr));
        label_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Admin", "Tab 1", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Admin", "PushButton", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Admin", "Vente", nullptr));
        checkBox->setText(QCoreApplication::translate("Admin", "Location", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Admin", "Disponible", nullptr));
        radioEntrepot->setText(QCoreApplication::translate("Admin", "Entrepot", nullptr));
        calculEntrepot->setText(QCoreApplication::translate("Admin", "(0)", nullptr));
        radioAppartement->setText(QCoreApplication::translate("Admin", "Appartement", nullptr));
        calculAppartement->setText(QCoreApplication::translate("Admin", "(0)", nullptr));
        radioMaison->setText(QCoreApplication::translate("Admin", "Maison", nullptr));
        calculMaison->setText(QCoreApplication::translate("Admin", "(0)", nullptr));
        radioTerrain->setText(QCoreApplication::translate("Admin", "Terrain", nullptr));
        calculTerrain->setText(QCoreApplication::translate("Admin", "(0)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Admin", "Page", nullptr));
        LoadClient->setText(QCoreApplication::translate("Admin", "Afficher", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "Recherche", nullptr));
        label_4->setText(QCoreApplication::translate("Admin", "Prenom", nullptr));
        label_5->setText(QCoreApplication::translate("Admin", "Nom", nullptr));
        pushButton->setText(QCoreApplication::translate("Admin", "Supprimer", nullptr));
        label_7->setText(QCoreApplication::translate("Admin", "Nos Clients", nullptr));
        label_8->setText(QCoreApplication::translate("Admin", "Les RESERVATIONS", nullptr));
        label_9->setText(QCoreApplication::translate("Admin", "Les PROPOSITIONS", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Admin", "Page", nullptr));
        loadContratLoc->setText(QCoreApplication::translate("Admin", "Afficher", nullptr));
        LoadContratVente->setText(QCoreApplication::translate("Admin", "Afficher", nullptr));
        label_10->setText(QCoreApplication::translate("Admin", "Contrat Location", nullptr));
        label_11->setText(QCoreApplication::translate("Admin", "Contrat Vente", nullptr));
        label_12->setText(QCoreApplication::translate("Admin", "Details sur le bien concern\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Admin", "Page", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Admin", "d\303\251connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
