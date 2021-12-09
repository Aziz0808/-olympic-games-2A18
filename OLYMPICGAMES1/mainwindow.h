#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spectateur.h"
#include "spectateur_page.h"

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
    void on_Spectateur_clicked();

private:
    Ui::MainWindow *ui;
    Spectateur_Page Sp_P;
    Spectateur S;
     reservation R1;

};
#endif // MAINWINDOW_H
