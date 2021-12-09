#include "mainwindow.h"
#include "spectateur_page.h"
#include "spectateur.h"
#include <QApplication>
#include "connection.h"
#include <QDebug>


int main(int argc, char *argv[])
{



    QApplication a(argc, argv);

    Connection c;

    bool test= c.CreateConnection();
    if (test){

        QMessageBox::information(nullptr,QObject::tr("Database is open"),
                                 QObject::tr("connection successfull \n"
                                             "click ok to exist "),QMessageBox::Ok);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("error Database"),
                                 QObject::tr("connection failed \n"
                                             "click ok to exist "),QMessageBox::Cancel);

    }
    MainWindow w;
    w.show();
    return a.exec();
}
