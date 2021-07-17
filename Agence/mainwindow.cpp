#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"clientwindow.h"
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ta->addTab(new QWidget, "tab1");
    QPixmap pix("C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/photos/FirstImage.png");
    ui->ClientImageLabel->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));


    QPixmap p("C:/Users/User/Documents/build-Agence-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/photos/client.png");
    ui->clientPhoto->setPixmap(p.scaled(80,80,Qt::KeepAspectRatio));


    //  ui->pushButton->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    cl->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
   LA->show();
   this->hide();
}
