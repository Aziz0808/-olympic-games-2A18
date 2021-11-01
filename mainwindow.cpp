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

