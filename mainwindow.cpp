#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_tickets.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QIntValidator>
#include <QtDebug>
#include<QObject>
#include <QSqlQueryModel>
#include <QRegExpValidator>
#include<QCheckBox>
#include<QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_tickets->setModel(G.afficher());
    ui->le_id->setValidator( new QIntValidator(0, 9999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_pushbotton_ajouter_clicked()
{

}


void MainWindow::on_pushButton_clicked()
{
    int ID=ui->le_id->text().toInt();
    int ID_EVENT =ui->le_nombre->text().toInt();
    QDate DATES_DES_TICKETS=ui->dateEdit->date();
    QString TYPE=ui->le_nombre_2->text();
    int PRIX=ui->le_nombre_3->text().toInt();
    Gestion_tickets G(ID,ID_EVENT,DATES_DES_TICKETS,TYPE,PRIX);
    bool test=G.ajouter();

    if(test)
      {          ui->tab_tickets->setModel(G.afficher())    ;

          QMessageBox::information(nullptr, QObject::tr("Ok"),
               QObject::tr("Ajout effectué.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);


      }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
               QObject::tr("Ajout non effectué.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{

}

void MainWindow::on_pushButton_2_clicked()


    {

       // Client C1;
      // C1.set_id(ui->Id_supp->text().toInt())    ;

    int ID=ui->lineEdit->text().toInt()  ;
       bool test =G.supprimer(ID)    ;
       if(test)
       {
           ui->tab_tickets->setModel(G.afficher())    ;

           QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("Suppression effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_tickets->setModel(G.afficher())    ;
       }
       else
       {
           QMessageBox::information(nullptr, QObject::tr("Not Ok"),
                QObject::tr("Suppression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


       }
       // }
       // else
       // {
       //     QMessageBox::warning(this, "Echec", "identifiant non existant !");


       // }

    }

void MainWindow::on_pushButton_3_clicked()
{

    int ID=ui->lineEdit_2->text().toInt();
    int  ID_EVENT=ui->lineEdit_3->text().toInt();
    QDate DATES_DES_TICKETS=ui->dateEdit_2->date();
    QString TYPE=ui->le_nombre_5->text();
    int PRIX=ui->le_nombre_4->text().toInt();
    Gestion_tickets G(ID,ID_EVENT,DATES_DES_TICKETS,TYPE,PRIX);


    bool test=G.modifier(ID,ID_EVENT,DATES_DES_TICKETS,TYPE,PRIX);
    if(test)
    {

        ui->tab_tickets->setModel(G.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               ui->lineEdit_2->clear();
               ui->lineEdit_3->clear();
               ui->dateEdit_2->clear();
               ui->le_nombre_5->clear();
               ui->le_nombre_4->clear();
   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->dateEdit_2->clear();
        ui->le_nombre_5->clear();
        ui->le_nombre_4->clear();

 }
    ui->tab_tickets->setModel(G.afficher());//refresh


}

void MainWindow::on_pushButton_4_clicked()

{
        if (ui->checkBox->isChecked())
        {
            ui->tab_tickets->setModel(G.trier("PRIX"));
            QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                        notifyIcon-> show ();
                        notifyIcon-> showMessage ( " GESTION TICKET" , " PRIX Trié " , QSystemTrayIcon :: Information, 15000 );

        }
    }


void MainWindow::on_pushButton_5_clicked()
{
    {

        int ID=ui->le_nombre_6->text().toInt();
           ui->tab_tickets->setModel(G.rechercher(ID));
    }
}
