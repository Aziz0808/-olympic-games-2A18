#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stade.h"

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
    void on_Button_Ajouter_clicked();

    void on_ButtonSupprimer_clicked();

    void on_Button_Modification_clicked();

   /* void on_tabWidget_currentChanged(int index);

    void on_groupBox_clicked();

    void on_le_id_cursorPositionChanged(int arg1, int arg2);

    void on_label_linkActivated(const QString &link);*/

    void on_Excel_clicked();

    void on_Imprimer_clicked();

    void on_Rechercher_textChanged(const QString &arg1);

    void on_TriID_clicked();

    void on_TriNom_clicked();

    void on_tricapacite_clicked();

    void on_Stat_clicked();



private:
    Ui::MainWindow *ui;
    Stade S1;
};

#endif // MAINWINDOW_H
