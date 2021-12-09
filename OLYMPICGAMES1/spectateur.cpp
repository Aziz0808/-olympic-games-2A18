#include "spectateur.h"
#include<QSqlQuery>
Spectateur::Spectateur()
{
    this->CIN = 0;
    this->NOMPRENOM = "_";
    this->AGE = 0;
    this->TELES = 0;
    this->TYPE = "_";
    this->FIDALITE = "_";
    this->NB_PLACE =0;

}
Spectateur::Spectateur(int CIN,QString NOMPRENOM,int AGE,int TEL,QString TYPE,int NB_PLACE,QString DATE,QString FIDALITE)
{
    this->CIN = CIN;
    this->NOMPRENOM = NOMPRENOM;
    this->AGE = AGE;
    this->TELES = TEL;
    this->TYPE = TYPE;
    this->DATE = DATE;
    this->FIDALITE = FIDALITE;
    this->NB_PLACE = NB_PLACE;


}

//////////////////////////////////////////////////////////////////////////////
/// Cruds
//////////////////////////////////////////////////////////////////////////////
/////////afficher//////////
QSqlQueryModel * Spectateur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from SPECTATEUR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPRENOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_H"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NB_PLACE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("FIDALITE"));

    return model;
}
bool Spectateur::rech(int cin)
{
    QString c=QString::number(cin);
    QSqlQuery q("select * from spectateur where cin="+c);
    while (q.next()) {
        return true;
    }
    return false;
}
////////ajouter///////////
bool Spectateur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SPECTATEUR(CIN,NOMPRENOM,AGE,TELES,TYPE,NB_PLACE,FIDALITE,DATE_H)"
                  "VALUES (:cin,:nomprenom,:age, :tel,:type,:nbplace,:fidalite,:date)");

                        query.bindValue(":cin",CIN);
                        query.bindValue(":nomprenom", NOMPRENOM );
                        query.bindValue(":age",AGE);
                        query.bindValue(":tel", TELES);
                        query.bindValue(":type", TYPE);
                        query.bindValue(":nbplace",NB_PLACE);
                        query.bindValue(":fidalite", FIDALITE);
                        query.bindValue(":date", DATE);



    return query.exec();
}
///////supprimer/////////
bool Spectateur::supprimer(int Cin)
{
    QSqlQuery query;
    query.prepare("delete from SPECTATEUR where (CIN=:cin)");
    query.bindValue(":cin",Cin);

    return query.exec();
}
//////modifier//////////
bool Spectateur::modifier(int CIN)
{
    QSqlQuery query;
    query.prepare("UPDATE SPECTATEUR SET NOMPRENOM=:nomprenom,AGE=:age,TELES=:tel ,TYPE=:type,NB_PLACE=:nbplace, FIDALITE=:fidalite ,DATE_H=:date WHERE CIN=:cin");
    query.bindValue(":cin",CIN);
    query.bindValue(":nomprenom", NOMPRENOM );
    query.bindValue(":age",AGE);
    query.bindValue(":tel", TELES);
    query.bindValue(":type", TYPE);
    query.bindValue(":fidalite", FIDALITE);
    query.bindValue(":date", DATE);
    query.bindValue(":nbplace",NB_PLACE);


    return query.exec();

}


bool Spectateur::verifage(int age)
{
    bool test = true;
    if (age < 8 ){
        test = false;
    }
    return test;
}
bool Spectateur::verifnom(QString ch_nom){
    bool test=true;
        int i;
        if(true)
        {
            for(i=0;i<ch_nom.length();i++){
                if(!(ch_nom[i]=='A')&&!(ch_nom[i]=='B')&&!(ch_nom[i]=='C')&&!(ch_nom[i]=='D')&&!(ch_nom[i]=='E')&&!(ch_nom[i]=='F')&&!(ch_nom[i]=='G')&&!(ch_nom[i]=='H')&&!(ch_nom[i]=='I')&&!(ch_nom[i]=='J')&&!(ch_nom[i]=='K')&&!(ch_nom[i]=='L')&&!(ch_nom[i]=='M')&&!(ch_nom[i]=='N')&&!(ch_nom[i]=='O')&&!(ch_nom[i]=='P')&&!(ch_nom[i]=='Q')&&!(ch_nom[i]=='R')&&!(ch_nom[i]=='S')&&!(ch_nom[i]=='T')&&!(ch_nom[i]=='U')&&!(ch_nom[i]=='V')&&!(ch_nom[i]=='W')&&!(ch_nom[i]=='Y')&&!(ch_nom[i]=='Z')&&!(ch_nom[i]=='a')&&!(ch_nom[i]=='b')&&!(ch_nom[i]=='c')&&!(ch_nom[i]=='d')&&!(ch_nom[i]=='e')&&!(ch_nom[i]=='f')&&!(ch_nom[i]=='g')&&!(ch_nom[i]=='h')&&!(ch_nom[i]=='i')&&!(ch_nom[i]=='j')&&!(ch_nom[i]=='k')&&!(ch_nom[i]=='l')&&!(ch_nom[i]=='m')&&!(ch_nom[i]=='n')&&!(ch_nom[i]=='o')&&!(ch_nom[i]=='p')&&!(ch_nom[i]=='q')&&!(ch_nom[i]=='r')&&!(ch_nom[i]=='s')&&!(ch_nom[i]=='t')&&!(ch_nom[i]=='u')&&!(ch_nom[i]=='v')&&!(ch_nom[i]=='w')&&!(ch_nom[i]=='y')&&!(ch_nom[i]=='z')){
                    test=false;
                    return  test;
            }
        }
        }
        return  test;
    }
/////metier//////
QSqlQueryModel * Spectateur::Rech(QString choix,QString ch)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    if (choix == "cin"){
    model->setQuery("select * from SPECTATEUR where CIN like '"+ch+"%'");
    }
    else if (choix =="age")
    {
        model->setQuery("select * from SPECTATEUR where AGE like '"+ch+"%'");
    }
    else if (choix =="telephone")
    {
        model->setQuery("select * from SPECTATEUR where TELE like '"+ch+"%'");
    }
    if (choix == "nomprenom"){
    model->setQuery("select * from SPECTATEUR where NOMPRENOM like '"+ch+"%'");
    }
    else if (choix == "date"){
        model->setQuery("select * from SPECTATEUR where DATE_H like '"+ch+"%'");
    }
    else if  (choix =="type" ){
        model->setQuery("select * from SPECTATEUR where TYPE like '"+ch+"%'");
    }
    else if  (choix =="place" ){
        model->setQuery("select * from SPECTATEUR where NB_PLACE like '"+ch+"%'");
    }
    return model;
}
QSqlQueryModel * Spectateur::triCIN()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from SPECTATEUR order by CIN");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * Spectateur::triAGE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from SPECTATEUR order by AGE");
    return model;
}
QSqlQueryModel * Spectateur::triPLACE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from SPECTATEUR order by NB_PLACE");
    return model;
}
QSqlQueryModel * Spectateur::triDate()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from SPECTATEUR order by DATE_E");
    return model;
}

void Spectateur::fidele(int cin)
{
    QSqlQuery q;
    q.prepare("update spectateur set FIDALITE='OUI' where cin=:cin");
    q.bindValue(":cin",cin);
    q.exec();
}
////////////////////////////////
void Spectateur::convPDF (){
    QString str;
               str.append("<!DOCTYPE html><html lang='en'><head><style>#ipi-table > thead > tr, #ipi-table > thead > tr > td {font-size: .9em;font-weight: 400;background: #51596a;text-transform: uppercase;color: #ffffff;}#ipi-table > tbody > tr > td {max-height: 200px;vertical-align: middle!important;}</style></head><body><div class='container'><div class='row'><div class='col-md-12'><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; TABLEAU GESTION SPECTATEUR  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p></div></div></div><div class='container'><div class='card' id='TableSorterCard'><div class='row'><div class='col-12'><div><table class='table table tablesorter' id='ipi-table'><thead class='thead-dark'><tr><th>CIN &nbsp; &nbsp;</th><th class='filter-false'>NOMPRENOM &nbsp; &nbsp;</th><th class='filter-false'>AGE &nbsp; &nbsp;</th><th class='filter-false sorter-false'>TELE &nbsp; &nbsp;</th><th class='filter-false sorter-false'>DATE &nbsp; &nbsp;</th><th class='filter-false sorter-false'>TYPE &nbsp; &nbsp;</th><th class='filter-false sorter-false'>NOMBRE PLACE &nbsp; &nbsp;</th><th class='filter-false sorter-false'>FIDALITE &nbsp; &nbsp;</th></tr></thead><tbody>");




               QSqlQuery* query=new QSqlQuery();
               query->exec("SELECT * FROM SPECTATEUR");

               while(query->next())
               {
               str.append("<tr><td>");
               str.append(query->value(0).toString()) ;
               str.append("</td><td>") ;
               str.append(query->value(1).toString());
               str.append("</td><td>") ;
               str.append(query->value(2).toString());
               str.append("</td><td>") ;
               str.append(query->value(3).toString());
               str.append("</td><td>") ;
               str.append(query->value(4).toString());
               str.append("</td><td>") ;
               str.append(query->value(5).toString());
               str.append("</td><td>") ;
               str.append(query->value(6).toString());
               str.append("</td><td>") ;
               str.append(query->value(7).toString());
               str.append("</td><td>") ;






               }
            str.append("</tbody></table></div></div></div></div></body></html>") ;

            QPrinter printer ;
            printer.setOrientation(QPrinter::Portrait);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4) ;

            QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","..","PDF(*.pdf)");

            if (path.isEmpty()) return ;
            printer.setOutputFileName(path) ;

            QTextDocument doc;
            doc.setHtml(str) ;
            doc.print(&printer);
}
