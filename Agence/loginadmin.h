#ifndef LOGINADMIN_H
#define LOGINADMIN_H
#include"admin.h"

#include <QWidget>

namespace Ui {
class LoginAdmin;
}

class LoginAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit LoginAdmin(QWidget *parent = nullptr);
    ~LoginAdmin();

private slots:
    void on_AdminLoginButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::LoginAdmin *ui;
     Admin * A = new Admin();
};

#endif // LOGINADMIN_H
