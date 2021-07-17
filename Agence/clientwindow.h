#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include"secondclientwindow.h"
#include"mpdoublie.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QtDebug>

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_pushButton_clicked();

    void on_Client_ADD_Button_clicked();

    void on_password1_textChanged(const QString &arg1);

    void on_password2_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::ClientWindow *ui;
    secondclientwindow * scl = new secondclientwindow();
    mpdoublie * md = new mpdoublie();

};

#endif // CLIENTWINDOW_H
