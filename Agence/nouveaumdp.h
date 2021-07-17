#ifndef NOUVEAUMDP_H
#define NOUVEAUMDP_H

#include <QWidget>

namespace Ui {
class nouveauMDP;
}

class nouveauMDP : public QWidget
{
    Q_OBJECT

public:
    explicit nouveauMDP(QWidget *parent = nullptr);
    ~nouveauMDP();
    void setLOGINEMAIL(QString l ){LoginEmail= l ;}

private slots:
    void on_password1_textChanged(const QString &arg1);

    void on_password2_textChanged(const QString &arg1);

    void on_ChangePSDButton_clicked();



private:
    Ui::nouveauMDP *ui;
    QString LoginEmail ;
};

#endif // NOUVEAUMDP_H
