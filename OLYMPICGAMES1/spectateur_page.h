#ifndef SPECTATEUR_PAGE_H
#define SPECTATEUR_PAGE_H
#include "spectateur.h"
#include <QWidget>
#include "arduino.h"
#include "reservation.h"
#include <QSqlQuery>
namespace Ui {
class Spectateur_Page;
}

class Spectateur_Page : public QWidget
{
    Q_OBJECT

public:
    explicit Spectateur_Page(QWidget *parent = nullptr);
    ~Spectateur_Page();

private slots:
    void on_Actualiser_clicked();

    void on_Supprimer_clicked();

    void on_recherche_clicked();

    void on_tri_clicked();

    void on_convpdf_clicked();

 void update_label();


 void on_calendarWidget_A_activated(const QDate &date);

 void on_Ajouter_clicked();

 void on_Modifier_clicked();

 void on_Button_Ajouter_clicked();

 void on_ButtonSupprimer_clicked();

 void on_trier_clicked();

 void on_pushButton_3_clicked();

 void on_rechercher_2_textChanged(const QString &arg1);

 void on_pushButton_clicked();

 void on_pushButton_2_clicked();

private:
    Ui::Spectateur_Page *ui;
    Spectateur S;
    arduino a;
    QByteArray data;
     reservation R1;

};

#endif // SPECTATEUR_PAGE_H
