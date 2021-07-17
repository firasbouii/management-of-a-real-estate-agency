#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"loginadmin.h"
#include"clientwindow.h"
#include"admin.h"
#include <QMainWindow>
#include"Qtabnewstyle.h"
#include"loginadminwindow.h"
#include <QApplication>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    ClientWindow *cl = new ClientWindow();
    QTabWidget * tab_3 = new QTabWidget();
    TabWidget * ta = new TabWidget(tab_3);
    Admin  * A = new Admin();
    LoginAdmin * LA = new LoginAdmin();



};
#endif // MAINWINDOW_H
