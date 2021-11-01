#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "match.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int idstade= ui->lineEdit_idstade->text().toInt();
    QString dates= ui->lineEdit_date->text();
    QString sport= ui->lineEdit_sport->text();
    int nbrp= ui->lineEdit_nbrp->text().toInt();



  Match m(id,idstade,dates,sport,nbrp);

  bool test=m.ajouter();
  if(test)
{

      ui->tableView->setModel(tmpmatchs.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un match"),
                  QObject::tr("match ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un match"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supprimer_2_clicked()
{
 QString id = ui->lineEdit_ids->text();
    bool test=tmpmatchs.supprimer(id);
    if(test)
    {



        ui->tableView->setModel(tmpmatchs.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un match"),
                    QObject::tr("match supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un match"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_idm->text().toInt();
    int idstade = ui->lineEdit_idstadem->text().toInt();
    QString date= ui->lineEdit_datem->text();
    QString sport= ui->lineEdit_sportm->text();

    int nbrp = ui->lineEdit_nbrpm->text().toInt();


    Match m;
    bool test=m.modifier(id,idstade,date,sport,nbrp);

    if(test)
    {




        QMessageBox::information(nullptr, QObject::tr("modifie un match"),
                          QObject::tr("match modifiée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tmpmatchs.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tmpmatchs.afficher());

}
