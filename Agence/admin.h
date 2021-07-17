#ifndef ADMIN_H
#define ADMIN_H

#include <QTableWidget>
#include <QMainWindow>

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();


private slots:
    void on_LoadReservation_clicked();

    void on_ReservationTable_cellClicked(int row, int column);

    void on_AccepterRes_clicked();
    void afficherBien(int);
    void afficherbienprop(int );

//    void on_ReservationTable_2_cellClicked(int row, int column);

   // void on_LoadReservation_3_clicked();

   //void on_AccepterRes_3_clicked();

    void on_PropositionTable_cellClicked(int row, int column);

    void on_LoadProposition_clicked();

    void on_AccepterPro_clicked();
    void adjustTableSize(QTableWidget *,int =2);


    void on_radioEntrepot_clicked();
    void on_radioAppartement_clicked();

    void on_radioMaison_clicked();

    void on_radioTerrain_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_clicked(bool);
    void on_checkBox_2_clicked(bool);


    void on_checkBox_3_clicked(bool checked);
    int calculEntrepot();
    int calculTerrain();
    int calculMaison();
    int calculAppartement();
    void on_LoadClient_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_ClientName_textChanged(const QString &arg1);

    void on_ClientNom_textChanged(const QString &arg1);

    void on_tablew2_cellClicked(int row, int column);

    void on_pushButton_clicked();

    void on_loadContratLoc_clicked();

    void on_LoadContratVente_clicked();

    void on_LocationTable_cellClicked(int row, int column);

    void afficherBienContrat(int,QTableWidget *);


    void on_VenteTable_cellClicked(int row, int column);

    void on_pushButton_2_clicked();

    void on_testing_clicked();

private:
    Ui::Admin *ui;
    QString ID ;
};


#endif // ADMIN_H
