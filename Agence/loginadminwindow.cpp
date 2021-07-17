#include "loginadminwindow.h"
#include "ui_loginadminwindow.h"
LoginAdminWindow::LoginAdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginAdminWindow)
{
    ui->setupUi(this);
}

LoginAdminWindow::~LoginAdminWindow()
{
    delete ui;
}

void LoginAdminWindow::on_AdminLoginButton_clicked()
{



}
