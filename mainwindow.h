#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_tickets.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //void on_pb_ajouter_clicked();

    void on_pushbotton_ajouter_clicked();


    void on_pushButton_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_le_nombre_6_editingFinished();

    void on_pushButton_5_clicked();



private:
    Ui::MainWindow *ui;
    Gestion_tickets G;
};

#endif // MAINWINDOW_H






