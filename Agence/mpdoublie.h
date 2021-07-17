#ifndef MPDOUBLIE_H
#define MPDOUBLIE_H

#include <QWidget>

namespace Ui {
class mpdoublie;
}

class mpdoublie : public QWidget
{
    Q_OBJECT

public:
    explicit mpdoublie(QWidget *parent = nullptr);
    ~mpdoublie();


private slots:
    void on_EnvoyerMail_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_randomNum_textChanged(const QString &arg1);

private:
    Ui::mpdoublie *ui;


};

#endif // MPDOUBLIE_H
