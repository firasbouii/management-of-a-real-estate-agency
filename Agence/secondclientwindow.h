#ifndef SECONDCLIENTWINDOW_H
#define SECONDCLIENTWINDOW_H

#include <QWidget>
#include"qtablewidget.h"

namespace Ui {
class secondclientwindow;
}

class secondclientwindow : public QWidget
{
    Q_OBJECT

public:
    explicit secondclientwindow(QWidget *parent = nullptr);
    ~secondclientwindow();
    void setID(int);
    void showInfo();

private slots:
    //void on_pushButton_clicked();



  //  void on_pushButton_3_clicked();

   // void on_radioButton_clicked(bool checked);

    void adjustTableSize() ;


    void on_radioEntrepot_clicked();

    void on_radioAppartement_clicked();

    void on_radioMaison_clicked();

    void on_radioTerrain_clicked();

    void on_bien_table_cellDoubleClicked(int row, int column);

    void on_Reserver_Button_clicked();



    void on_Location_button_clicked();

    void on_Vente_button_clicked();

    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_Proposer_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_pushButton_clicked();

    void on_ReservationTable_cellClicked(int row, int column);

    void on_pushButton_3_clicked();

    void on_checkBox_clicked();

    void adjustTableSize2(QTableWidget* ,int=2 );



    void on_PropositionTable_cellClicked(int row, int column);

    void on_LoadProposition_clicked();
    void afficherbienprop(int );

    void on_VenteTable_cellClicked(int row, int column);

    void on_LocationTable_cellClicked(int row, int column);

    void on_LoadContratVente_clicked();

    void on_loadContratLoc_clicked();
    void afficherBienContrat(int ,QTableWidget * );

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_ReservationTable_itemEntered(QTableWidgetItem *item);

    void on_ReservationTable_cellChanged(int row, int column);

private:
    Ui::secondclientwindow *ui;
    int ID ; //id_client
};

#endif // SECONDCLIENTWINDOW_H
