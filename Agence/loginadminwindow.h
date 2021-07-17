#ifndef LOGINADMINWINDOW_H
#define LOGINADMINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginAdminWindow;
}

class LoginAdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginAdminWindow(QWidget *parent = nullptr);
    ~LoginAdminWindow();

private slots:
    void on_AdminLoginButton_clicked();

private:
    Ui::LoginAdminWindow *ui;
   // Admin * A = new Admin();
};

#endif // LOGINADMINWINDOW_H
