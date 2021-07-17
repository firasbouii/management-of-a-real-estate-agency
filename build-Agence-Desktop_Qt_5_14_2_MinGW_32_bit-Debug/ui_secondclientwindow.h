/********************************************************************************
** Form generated from reading UI file 'secondclientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDCLIENTWINDOW_H
#define UI_SECONDCLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondclientwindow
{
public:
    QTabWidget *ClientTab;
    QWidget *tab;
    QTableWidget *ReservationTable;
    QLabel *testlabel;
    QPushButton *pushButton;
    QTableWidget *ClientEntrepot;
    QTableWidget *ClientAppartemet;
    QTableWidget *ClientTerrain;
    QTableWidget *ClientMaison;
    QWidget *tab_3;
    QTableWidget *bien_table;
    QPushButton *pushButton_3;
    QRadioButton *radioEntrepot;
    QRadioButton *radioAppartement;
    QRadioButton *radioMaison;
    QRadioButton *radioTerrain;
    QPushButton *Reserver_Button;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_13;
    QWidget *tab_2;
    QPushButton *Proposer;
    QComboBox *comboBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QFrame *BienFrame;
    QLineEdit *Bien_Superficie;
    QLineEdit *Bien_Valeur;
    QLineEdit *Bien_Adresse3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Bien_Adresse1;
    QLineEdit *Bien_Adresse2;
    QFrame *MaisontFrame;
    QLabel *label_6;
    QLineEdit *M_Nb_Chambre;
    QLineEdit *M_Nb_Etage;
    QLabel *label_5;
    QFrame *AppartemetFrame;
    QLineEdit *A_Etage;
    QLineEdit *A_Immeuble;
    QLabel *label_10;
    QLineEdit *A_Nb_Chamnre;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *Entrepotframe;
    QLabel *label;
    QComboBox *E_Combo;
    QTableWidget *PropositionTable;
    QFrame *TerrainFrame;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *T_Num_Inscri;
    QLabel *label_9;
    QComboBox *T_Comb_Nature;
    QComboBox *T_Combo_Etat;
    QTableWidget *ClientTerrain_2;
    QTableWidget *ClientEntrepot_2;
    QTableWidget *ClientMaison_2;
    QTableWidget *ClientAppartemet_2;
    QPushButton *LoadProposition;
    QPushButton *pushButton_2;
    QWidget *tab_4;
    QTableWidget *ClientTerrain_3;
    QTableWidget *ClientAppartemet_3;
    QPushButton *loadContratLoc;
    QTableWidget *LocationTable;
    QTableWidget *VenteTable;
    QTableWidget *ClientMaison_3;
    QPushButton *LoadContratVente;
    QTableWidget *ClientEntrepot_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QFrame *line_4;
    QPushButton *pushButton_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *nom_label;
    QLabel *prenom_label;
    QLabel *email_label;

    void setupUi(QWidget *secondclientwindow)
    {
        if (secondclientwindow->objectName().isEmpty())
            secondclientwindow->setObjectName(QString::fromUtf8("secondclientwindow"));
        secondclientwindow->resize(1052, 652);
        ClientTab = new QTabWidget(secondclientwindow);
        ClientTab->setObjectName(QString::fromUtf8("ClientTab"));
        ClientTab->setGeometry(QRect(0, 20, 1051, 631));
        ClientTab->setLayoutDirection(Qt::LeftToRight);
        ClientTab->setStyleSheet(QString::fromUtf8("QTabWidget::pane { /* The tab widget frame */\n"
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
        ClientTab->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        ReservationTable = new QTableWidget(tab);
        ReservationTable->setObjectName(QString::fromUtf8("ReservationTable"));
        ReservationTable->setGeometry(QRect(20, 30, 291, 151));
        testlabel = new QLabel(tab);
        testlabel->setObjectName(QString::fromUtf8("testlabel"));
        testlabel->setGeometry(QRect(750, 520, 131, 51));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 190, 111, 23));
        ClientEntrepot = new QTableWidget(tab);
        ClientEntrepot->setObjectName(QString::fromUtf8("ClientEntrepot"));
        ClientEntrepot->setGeometry(QRect(20, 250, 771, 61));
        ClientAppartemet = new QTableWidget(tab);
        ClientAppartemet->setObjectName(QString::fromUtf8("ClientAppartemet"));
        ClientAppartemet->setGeometry(QRect(20, 250, 771, 51));
        ClientTerrain = new QTableWidget(tab);
        ClientTerrain->setObjectName(QString::fromUtf8("ClientTerrain"));
        ClientTerrain->setGeometry(QRect(20, 250, 771, 51));
        ClientMaison = new QTableWidget(tab);
        ClientMaison->setObjectName(QString::fromUtf8("ClientMaison"));
        ClientMaison->setGeometry(QRect(20, 250, 771, 61));
        ClientTab->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        bien_table = new QTableWidget(tab_3);
        bien_table->setObjectName(QString::fromUtf8("bien_table"));
        bien_table->setEnabled(true);
        bien_table->setGeometry(QRect(200, 170, 721, 192));
        bien_table->verticalHeader()->setDefaultSectionSize(23);
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 350, 75, 23));
        radioEntrepot = new QRadioButton(tab_3);
        radioEntrepot->setObjectName(QString::fromUtf8("radioEntrepot"));
        radioEntrepot->setGeometry(QRect(50, 120, 82, 17));
        radioAppartement = new QRadioButton(tab_3);
        radioAppartement->setObjectName(QString::fromUtf8("radioAppartement"));
        radioAppartement->setGeometry(QRect(50, 150, 82, 17));
        radioMaison = new QRadioButton(tab_3);
        radioMaison->setObjectName(QString::fromUtf8("radioMaison"));
        radioMaison->setGeometry(QRect(50, 180, 82, 17));
        radioTerrain = new QRadioButton(tab_3);
        radioTerrain->setObjectName(QString::fromUtf8("radioTerrain"));
        radioTerrain->setGeometry(QRect(50, 210, 82, 17));
        Reserver_Button = new QPushButton(tab_3);
        Reserver_Button->setObjectName(QString::fromUtf8("Reserver_Button"));
        Reserver_Button->setGeometry(QRect(240, 110, 75, 23));
        checkBox = new QCheckBox(tab_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(50, 250, 70, 17));
        checkBox_2 = new QCheckBox(tab_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(50, 280, 70, 17));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(260, 120, 521, 71));
        ClientTab->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        Proposer = new QPushButton(tab_2);
        Proposer->setObjectName(QString::fromUtf8("Proposer"));
        Proposer->setGeometry(QRect(580, 310, 75, 23));
        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 60, 69, 22));
        radioButton = new QRadioButton(tab_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 130, 82, 17));
        radioButton_2 = new QRadioButton(tab_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(40, 160, 82, 17));
        BienFrame = new QFrame(tab_2);
        BienFrame->setObjectName(QString::fromUtf8("BienFrame"));
        BienFrame->setGeometry(QRect(150, 30, 211, 201));
        BienFrame->setFrameShape(QFrame::StyledPanel);
        BienFrame->setFrameShadow(QFrame::Raised);
        Bien_Superficie = new QLineEdit(BienFrame);
        Bien_Superficie->setObjectName(QString::fromUtf8("Bien_Superficie"));
        Bien_Superficie->setGeometry(QRect(70, 20, 113, 20));
        Bien_Valeur = new QLineEdit(BienFrame);
        Bien_Valeur->setObjectName(QString::fromUtf8("Bien_Valeur"));
        Bien_Valeur->setGeometry(QRect(70, 60, 113, 20));
        Bien_Adresse3 = new QLineEdit(BienFrame);
        Bien_Adresse3->setObjectName(QString::fromUtf8("Bien_Adresse3"));
        Bien_Adresse3->setGeometry(QRect(70, 160, 101, 20));
        label_2 = new QLabel(BienFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 47, 13));
        label_3 = new QLabel(BienFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 47, 13));
        label_4 = new QLabel(BienFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 100, 47, 13));
        Bien_Adresse1 = new QLineEdit(BienFrame);
        Bien_Adresse1->setObjectName(QString::fromUtf8("Bien_Adresse1"));
        Bien_Adresse1->setGeometry(QRect(70, 100, 41, 20));
        Bien_Adresse2 = new QLineEdit(BienFrame);
        Bien_Adresse2->setObjectName(QString::fromUtf8("Bien_Adresse2"));
        Bien_Adresse2->setGeometry(QRect(70, 130, 71, 20));
        MaisontFrame = new QFrame(tab_2);
        MaisontFrame->setObjectName(QString::fromUtf8("MaisontFrame"));
        MaisontFrame->setGeometry(QRect(150, 240, 201, 71));
        MaisontFrame->setFrameShape(QFrame::StyledPanel);
        MaisontFrame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(MaisontFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 40, 61, 20));
        M_Nb_Chambre = new QLineEdit(MaisontFrame);
        M_Nb_Chambre->setObjectName(QString::fromUtf8("M_Nb_Chambre"));
        M_Nb_Chambre->setGeometry(QRect(60, 40, 111, 20));
        M_Nb_Etage = new QLineEdit(MaisontFrame);
        M_Nb_Etage->setObjectName(QString::fromUtf8("M_Nb_Etage"));
        M_Nb_Etage->setGeometry(QRect(60, 10, 113, 20));
        label_5 = new QLabel(MaisontFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 10, 47, 13));
        AppartemetFrame = new QFrame(tab_2);
        AppartemetFrame->setObjectName(QString::fromUtf8("AppartemetFrame"));
        AppartemetFrame->setGeometry(QRect(370, 10, 211, 171));
        AppartemetFrame->setFrameShape(QFrame::StyledPanel);
        AppartemetFrame->setFrameShadow(QFrame::Raised);
        A_Etage = new QLineEdit(AppartemetFrame);
        A_Etage->setObjectName(QString::fromUtf8("A_Etage"));
        A_Etage->setGeometry(QRect(70, 70, 120, 20));
        A_Immeuble = new QLineEdit(AppartemetFrame);
        A_Immeuble->setObjectName(QString::fromUtf8("A_Immeuble"));
        A_Immeuble->setGeometry(QRect(70, 40, 120, 20));
        label_10 = new QLabel(AppartemetFrame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 40, 47, 13));
        A_Nb_Chamnre = new QLineEdit(AppartemetFrame);
        A_Nb_Chamnre->setObjectName(QString::fromUtf8("A_Nb_Chamnre"));
        A_Nb_Chamnre->setGeometry(QRect(70, 110, 121, 20));
        label_11 = new QLabel(AppartemetFrame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 63, 47, 20));
        label_12 = new QLabel(AppartemetFrame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 110, 61, 20));
        Entrepotframe = new QFrame(tab_2);
        Entrepotframe->setObjectName(QString::fromUtf8("Entrepotframe"));
        Entrepotframe->setGeometry(QRect(370, 170, 191, 61));
        Entrepotframe->setFrameShape(QFrame::StyledPanel);
        Entrepotframe->setFrameShadow(QFrame::Raised);
        label = new QLabel(Entrepotframe);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 47, 13));
        E_Combo = new QComboBox(Entrepotframe);
        E_Combo->addItem(QString());
        E_Combo->addItem(QString());
        E_Combo->setObjectName(QString::fromUtf8("E_Combo"));
        E_Combo->setGeometry(QRect(70, 10, 121, 22));
        PropositionTable = new QTableWidget(tab_2);
        PropositionTable->setObjectName(QString::fromUtf8("PropositionTable"));
        PropositionTable->setGeometry(QRect(600, 110, 401, 151));
        TerrainFrame = new QFrame(tab_2);
        TerrainFrame->setObjectName(QString::fromUtf8("TerrainFrame"));
        TerrainFrame->setGeometry(QRect(360, 260, 231, 91));
        TerrainFrame->setFrameShape(QFrame::StyledPanel);
        TerrainFrame->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(TerrainFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 47, 13));
        label_8 = new QLabel(TerrainFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 60, 61, 20));
        T_Num_Inscri = new QLineEdit(TerrainFrame);
        T_Num_Inscri->setObjectName(QString::fromUtf8("T_Num_Inscri"));
        T_Num_Inscri->setGeometry(QRect(70, 0, 111, 20));
        label_9 = new QLabel(TerrainFrame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 0, 47, 13));
        T_Comb_Nature = new QComboBox(TerrainFrame);
        T_Comb_Nature->addItem(QString());
        T_Comb_Nature->addItem(QString());
        T_Comb_Nature->setObjectName(QString::fromUtf8("T_Comb_Nature"));
        T_Comb_Nature->setGeometry(QRect(70, 30, 111, 22));
        T_Combo_Etat = new QComboBox(TerrainFrame);
        T_Combo_Etat->addItem(QString());
        T_Combo_Etat->addItem(QString());
        T_Combo_Etat->setObjectName(QString::fromUtf8("T_Combo_Etat"));
        T_Combo_Etat->setGeometry(QRect(70, 60, 111, 22));
        ClientTerrain_2 = new QTableWidget(tab_2);
        ClientTerrain_2->setObjectName(QString::fromUtf8("ClientTerrain_2"));
        ClientTerrain_2->setGeometry(QRect(140, 350, 771, 61));
        ClientEntrepot_2 = new QTableWidget(tab_2);
        ClientEntrepot_2->setObjectName(QString::fromUtf8("ClientEntrepot_2"));
        ClientEntrepot_2->setGeometry(QRect(140, 350, 771, 61));
        ClientMaison_2 = new QTableWidget(tab_2);
        ClientMaison_2->setObjectName(QString::fromUtf8("ClientMaison_2"));
        ClientMaison_2->setGeometry(QRect(140, 350, 771, 61));
        ClientAppartemet_2 = new QTableWidget(tab_2);
        ClientAppartemet_2->setObjectName(QString::fromUtf8("ClientAppartemet_2"));
        ClientAppartemet_2->setGeometry(QRect(140, 350, 771, 61));
        LoadProposition = new QPushButton(tab_2);
        LoadProposition->setObjectName(QString::fromUtf8("LoadProposition"));
        LoadProposition->setGeometry(QRect(810, 290, 111, 23));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(940, -40, 75, 23));
        ClientTab->addTab(tab_2, QString());
        MaisontFrame->raise();
        Proposer->raise();
        comboBox->raise();
        radioButton->raise();
        radioButton_2->raise();
        BienFrame->raise();
        AppartemetFrame->raise();
        Entrepotframe->raise();
        PropositionTable->raise();
        TerrainFrame->raise();
        ClientTerrain_2->raise();
        ClientEntrepot_2->raise();
        ClientMaison_2->raise();
        ClientAppartemet_2->raise();
        LoadProposition->raise();
        pushButton_2->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        ClientTerrain_3 = new QTableWidget(tab_4);
        ClientTerrain_3->setObjectName(QString::fromUtf8("ClientTerrain_3"));
        ClientTerrain_3->setGeometry(QRect(70, 460, 771, 61));
        ClientAppartemet_3 = new QTableWidget(tab_4);
        ClientAppartemet_3->setObjectName(QString::fromUtf8("ClientAppartemet_3"));
        ClientAppartemet_3->setGeometry(QRect(70, 460, 771, 61));
        loadContratLoc = new QPushButton(tab_4);
        loadContratLoc->setObjectName(QString::fromUtf8("loadContratLoc"));
        loadContratLoc->setGeometry(QRect(970, 60, 75, 23));
        LocationTable = new QTableWidget(tab_4);
        LocationTable->setObjectName(QString::fromUtf8("LocationTable"));
        LocationTable->setGeometry(QRect(40, 40, 831, 121));
        VenteTable = new QTableWidget(tab_4);
        VenteTable->setObjectName(QString::fromUtf8("VenteTable"));
        VenteTable->setGeometry(QRect(40, 250, 831, 111));
        ClientMaison_3 = new QTableWidget(tab_4);
        ClientMaison_3->setObjectName(QString::fromUtf8("ClientMaison_3"));
        ClientMaison_3->setGeometry(QRect(70, 460, 771, 61));
        LoadContratVente = new QPushButton(tab_4);
        LoadContratVente->setObjectName(QString::fromUtf8("LoadContratVente"));
        LoadContratVente->setGeometry(QRect(970, 250, 75, 23));
        ClientEntrepot_3 = new QTableWidget(tab_4);
        ClientEntrepot_3->setObjectName(QString::fromUtf8("ClientEntrepot_3"));
        ClientEntrepot_3->setGeometry(QRect(70, 460, 771, 61));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(40, 230, 351, 16));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 20, 251, 16));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(70, 440, 151, 16));
        ClientTab->addTab(tab_4, QString());
        line_4 = new QFrame(secondclientwindow);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(750, -10, 161, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        pushButton_4 = new QPushButton(secondclientwindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(960, 20, 75, 23));
        layoutWidget = new QWidget(secondclientwindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 171, 68));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nom_label = new QLabel(layoutWidget);
        nom_label->setObjectName(QString::fromUtf8("nom_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        nom_label->setFont(font);

        verticalLayout->addWidget(nom_label);

        prenom_label = new QLabel(layoutWidget);
        prenom_label->setObjectName(QString::fromUtf8("prenom_label"));
        prenom_label->setFont(font);

        verticalLayout->addWidget(prenom_label);

        email_label = new QLabel(layoutWidget);
        email_label->setObjectName(QString::fromUtf8("email_label"));
        email_label->setFont(font);

        verticalLayout->addWidget(email_label);


        retranslateUi(secondclientwindow);

        ClientTab->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(secondclientwindow);
    } // setupUi

    void retranslateUi(QWidget *secondclientwindow)
    {
        secondclientwindow->setWindowTitle(QCoreApplication::translate("secondclientwindow", "Form", nullptr));
        testlabel->setText(QCoreApplication::translate("secondclientwindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("secondclientwindow", "Load Reservation", nullptr));
        ClientTab->setTabText(ClientTab->indexOf(tab), QCoreApplication::translate("secondclientwindow", "Tab 1", nullptr));
        pushButton_3->setText(QCoreApplication::translate("secondclientwindow", "PushButton", nullptr));
        radioEntrepot->setText(QCoreApplication::translate("secondclientwindow", "Entrepot", nullptr));
        radioAppartement->setText(QCoreApplication::translate("secondclientwindow", "Appartement", nullptr));
        radioMaison->setText(QCoreApplication::translate("secondclientwindow", "Maison", nullptr));
        radioTerrain->setText(QCoreApplication::translate("secondclientwindow", "Terrain", nullptr));
        Reserver_Button->setText(QCoreApplication::translate("secondclientwindow", "Reserver", nullptr));
        checkBox->setText(QCoreApplication::translate("secondclientwindow", "Location", nullptr));
        checkBox_2->setText(QCoreApplication::translate("secondclientwindow", "Vente", nullptr));
        label_13->setText(QCoreApplication::translate("secondclientwindow", "Pour passer votre reservation veuillez selectionner votre bien souhai\303\251 puis cliquez sur le bouton\"RESERVER\"", nullptr));
        ClientTab->setTabText(ClientTab->indexOf(tab_3), QCoreApplication::translate("secondclientwindow", "Page", nullptr));
        Proposer->setText(QCoreApplication::translate("secondclientwindow", "Proposer", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("secondclientwindow", "Type", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("secondclientwindow", "Maison", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("secondclientwindow", "Appartement", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("secondclientwindow", "Entrepot", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("secondclientwindow", "Terrain", nullptr));

        radioButton->setText(QCoreApplication::translate("secondclientwindow", "Location", nullptr));
        radioButton_2->setText(QCoreApplication::translate("secondclientwindow", "Vente", nullptr));
        label_2->setText(QCoreApplication::translate("secondclientwindow", "Superficie", nullptr));
        label_3->setText(QCoreApplication::translate("secondclientwindow", "Valeur", nullptr));
        label_4->setText(QCoreApplication::translate("secondclientwindow", "Adresse", nullptr));
        label_6->setText(QCoreApplication::translate("secondclientwindow", "nb chambre", nullptr));
        label_5->setText(QCoreApplication::translate("secondclientwindow", "nb etage", nullptr));
        label_10->setText(QCoreApplication::translate("secondclientwindow", "Immeuble", nullptr));
        label_11->setText(QCoreApplication::translate("secondclientwindow", "Etage", nullptr));
        label_12->setText(QCoreApplication::translate("secondclientwindow", "NB  chambre", nullptr));
        label->setText(QCoreApplication::translate("secondclientwindow", "Utilisation", nullptr));
        E_Combo->setItemText(0, QCoreApplication::translate("secondclientwindow", "frigorifique", nullptr));
        E_Combo->setItemText(1, QCoreApplication::translate("secondclientwindow", "logistique", nullptr));

        label_7->setText(QCoreApplication::translate("secondclientwindow", "Nature", nullptr));
        label_8->setText(QCoreApplication::translate("secondclientwindow", "Etat_terr", nullptr));
        label_9->setText(QCoreApplication::translate("secondclientwindow", "Num isncri", nullptr));
        T_Comb_Nature->setItemText(0, QCoreApplication::translate("secondclientwindow", "constructible", nullptr));
        T_Comb_Nature->setItemText(1, QCoreApplication::translate("secondclientwindow", "agricole", nullptr));

        T_Combo_Etat->setItemText(0, QCoreApplication::translate("secondclientwindow", "titr\303\251", nullptr));
        T_Combo_Etat->setItemText(1, QCoreApplication::translate("secondclientwindow", "non titr\303\251", nullptr));

        LoadProposition->setText(QCoreApplication::translate("secondclientwindow", "Mes propositions", nullptr));
        pushButton_2->setText(QCoreApplication::translate("secondclientwindow", "d\303\251connexion", nullptr));
        ClientTab->setTabText(ClientTab->indexOf(tab_2), QCoreApplication::translate("secondclientwindow", "Tab 2", nullptr));
        loadContratLoc->setText(QCoreApplication::translate("secondclientwindow", "Afficher", nullptr));
        LoadContratVente->setText(QCoreApplication::translate("secondclientwindow", "Afficher", nullptr));
        label_14->setText(QCoreApplication::translate("secondclientwindow", "Mes contrats de Vente", nullptr));
        label_15->setText(QCoreApplication::translate("secondclientwindow", "Mes contrats de Location", nullptr));
        label_16->setText(QCoreApplication::translate("secondclientwindow", "Details  du bien selectionn\303\251", nullptr));
        ClientTab->setTabText(ClientTab->indexOf(tab_4), QCoreApplication::translate("secondclientwindow", "Page", nullptr));
        pushButton_4->setText(QCoreApplication::translate("secondclientwindow", "d\303\251connexion", nullptr));
        nom_label->setText(QCoreApplication::translate("secondclientwindow", "TextLabel", nullptr));
        prenom_label->setText(QCoreApplication::translate("secondclientwindow", "TextLabel", nullptr));
        email_label->setText(QCoreApplication::translate("secondclientwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondclientwindow: public Ui_secondclientwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDCLIENTWINDOW_H
