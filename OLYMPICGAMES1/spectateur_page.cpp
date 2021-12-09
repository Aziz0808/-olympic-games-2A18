#include "spectateur_page.h"
#include "ui_spectateur_page.h"
#include <QDebug>
#include <QIntValidator>
#include <QPdfWriter>
#include <QTextStream>
#include <QTextDocument>
#include <QSqlQuery>
#include <QtDebug>
#include <QVariant>
#include <QPainter>
#include <QtCharts>
#include <QPieSeries>

Spectateur_Page::Spectateur_Page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Spectateur_Page)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();
        QSqlQuery q("select type,count(*) from reservation group by type");


         while(q.next())
         {series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques");
        chart->setBackgroundBrush(Qt::transparent);
        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->horizontalFrame);
        chartview->resize(400,300);

        chart->setAnimationOptions(QChart::AllAnimations);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        series->setLabelsVisible(true);

      ui->tableView->setModel(S.afficher());
      QIntValidator *val=new QIntValidator(10000000,99999999,this);
      ui->Cin_A->setValidator(val);
    int ret=a.connect_arduino();
          switch (ret) {
          case(0):qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
              break;
          case(1):qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
              break;
          case(-1):qDebug()<<"arduino is not available";
          }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    ui->tab_Reservation->setModel(R1.afficher());
    ui->comboBox->addItems(R1.lister());

    ui->le_id ->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_Reservation->setModel(R1.afficher());

}

Spectateur_Page::~Spectateur_Page()
{
    delete ui;
}

void Spectateur_Page::on_Actualiser_clicked()
{
    ui->tableView->setModel(S.afficher());
}
void Spectateur_Page::update_label()
{
data.append(a.read_from_arduino());
qDebug()<<data;
if(data.length()==8)
{
    if(S.rech(data.toInt())){
        S.fidele(data.toInt());
        a.write_to_arduino("l");
        QMessageBox::information(nullptr,QObject::tr("Spectateur existe"),
                                 QObject::tr("successfull \n"
                                             "click ok to exist "),QMessageBox::Ok);
         a.write_to_arduino("m");
         data.clear();
    }else
    {
         a.write_to_arduino("b");
         QMessageBox::critical(nullptr,QObject::tr("Spectateur n'existe pas"),
                                  QObject::tr("Spectateur n'existe pas \n"
                                              "click ok to exist "),QMessageBox::Ok);
          a.write_to_arduino("x");
           data.clear();
    }
}
}

void Spectateur_Page::on_Supprimer_clicked()
{
    int cin=ui->Supp->text().toInt();
    S.supprimer(cin);
    ui->tableView->setModel(S.afficher());
}


void Spectateur_Page::on_recherche_clicked()
{
    QString choix = ui->comboBox->currentText();
            QString ch = ui->rech->text();
            ui->tableView->setModel(S.Rech(choix,ch));
}


void Spectateur_Page::on_tri_clicked()
{
    QString choix = ui->comboBox_2->currentText();
        if (choix =="cin" ){
            ui->tableView->setModel(S.triCIN());
        }else if (choix =="age") {
            ui->tableView->setModel(S.triAGE());
        }else if  (choix == "date"){
            ui->tableView->setModel(S.triDate());
        }else {
            ui->tableView->setModel(S.triPLACE());
        }

}


void Spectateur_Page::on_convpdf_clicked()
{
    S.convPDF();
}



void Spectateur_Page::on_Ajouter_clicked()
{

    QString FIDALITE="";
    int CIN=ui->Cin_A->text().toInt();
    QString NOMPRENOM=ui->NomPrenom_A->text();
    int AGE=ui->Age_A->text().toInt();
    int TEL=ui->Tel_A->text().toInt();
    QString TYPE=ui->Type_A->currentText();
    int NB_PLACE=ui->Nb_Place_A->text().toInt();
    QString DATE=ui->calendarWidget_A->selectedDate().toString();
    if(ui->Oui_A->isChecked())
    FIDALITE="OUI";
    if(ui->Non_A->isChecked())
    FIDALITE="NON";
    Spectateur s(CIN,NOMPRENOM,AGE,TEL,TYPE,NB_PLACE,DATE,FIDALITE);
    bool test=s.ajouter();
    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("Ajout effectué"),
                                 QObject::tr("successfull \n"
                                             "click ok to exist "),QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Ajout erroné"),
                                 QObject::tr("error \n"
                                             "click ok to exist "),QMessageBox::Ok);
    }
}


void Spectateur_Page::on_Modifier_clicked()
{
    QString FIDALITE="";
    int CIN=ui->Cin_A->text().toInt();
    QString NOMPRENOM=ui->NomPrenom_A->text();
    int AGE=ui->Age_A->text().toInt();
    int TEL=ui->Tel_A->text().toInt();
    QString TYPE=ui->Type_A->currentText();
    int NB_PLACE=ui->Nb_Place_A->text().toInt();
    QString DATE=ui->calendarWidget_A->selectedDate().toString();
    if(ui->Oui_A->isChecked())
    FIDALITE="OUI";
    if(ui->Non_A->isChecked())
    FIDALITE="NON";
    Spectateur s(CIN,NOMPRENOM,AGE,TEL,TYPE,NB_PLACE,DATE,FIDALITE);
    bool test=s.modifier(CIN);
    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("Modification effectué"),
                                 QObject::tr("successfull \n"
                                             "click ok to exist "),QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Modification erroné"),
                                 QObject::tr("error \n"
                                             "click ok to exist "),QMessageBox::Ok);
    }
}


void Spectateur_Page::on_Button_Ajouter_clicked()
{
    int id =ui->le_id->text().toInt();
    int time=ui->le_time->text().toInt();
    QString dat=ui->le_dat->text();
    QString type =ui->le_type->currentText();
    float prix =ui->le_pr->text().toFloat();


    reservation R(id,dat,time,type,prix);
    bool test=R.ajouter();


    if(test)
    {
        ui->tab_Reservation->setModel(R1.afficher());
R.notification_ajoutReservation();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("ajout effectue\n"
                               "click cancel te exit."), QMessageBox::Cancel);

       ui->le_id->clear();
       ui->le_time->clear();
       ui->le_pr->clear();
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                   QObject::tr("ajout non effectue\n"
                               "click cancel te exit."), QMessageBox::Cancel);
    ui->le_id->clear();
    ui->le_time->clear();
    ui->le_pr->clear();
}


void Spectateur_Page::on_ButtonSupprimer_clicked()
{
    reservation R2;
    R2.set_id(ui->comboBox->currentText().toInt());
    bool test=R2.supprimer(R2.get_id());
    QMessageBox msgBox;

   R2.notification_supprimerReservation();

    if(test)
    {
        ui->comboBox->addItems(R1.lister());
        ui->tab_Reservation->setModel(R2.afficher());

        ui->tab_Reservation->setModel(R1.afficher())    ;
        msgBox.setText("suppression avec succes");
ui->comboBox->clear();

    }
    else

    msgBox.setText("echec de suppression");
    msgBox.exec();
}


void Spectateur_Page::on_trier_clicked()
{
     ui->tab_Reservation->setModel(R1.trier_type());
}


void Spectateur_Page::on_pushButton_3_clicked()
{
    int i = 4000;


    QPdfWriter pdf("C:/Users/HP/Desktop/olympic-games.pdf");
    QPainter painter(&pdf);

    QSqlQuery query;
    query.prepare("select * from RESERVATION");
    painter.setPen(QPen(Qt::red));

    painter.drawText(100,3000,"id");
     painter.drawText(1300,3000,"time");
    painter.drawText(2100,3000,"date");
    painter.drawText(3200,3000,"type");
    painter.drawText(4300,3000,"prix");
    if (query.exec()){
    while (query.next())
     {
        painter.setPen(QPen(Qt::black));

     /*   QString quantite_mat=query.value(0).toString();
  painter.drawText(100,i,quantite_mat);
  QString  fournisseur=query.value(1).toString();
  painter.drawText(3200,i,);


    QString  code_mat=query.value(3).toString();
    painter.drawText(2100,i,code_mat);

    QString id_fournisseur=query.value(4).toString();
    painter.drawText(1300,i,id_fournisseur);
*/

    i = i +500;
    }
    }
  painter.end();

  QMessageBox::information(nullptr, QObject::tr("PDF "),
                                  QObject::tr("PDF Enregistré avec succes.\n" ), QMessageBox::AcceptRole);






}


void Spectateur_Page::on_rechercher_2_textChanged(const QString &arg1)
{
    reservation R;
    ui->tab_Reservation->setModel(R.recherche(ui->rechercher_2->text()));

}


void Spectateur_Page::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Spectateur_Page::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

