#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QDesktopServices>
#include <QDebug>
#include <QMultimedia>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1,&Sp_P);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Spectateur_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

