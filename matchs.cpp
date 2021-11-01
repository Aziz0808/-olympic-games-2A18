#include "matchs.h"
#include <QDebug>
#include<QDate>
/*matchs::matchs()
{
id=0;
idstade=0;
dates=" ";
sport=" ";
nbrp=0;

}*/
matchs::matchs(int id,int idstade, QString dates ,QString sport ,int nbrp)
{
  this->id=id;
  this->idstade=idstade;
  this->dates=dates;
  this->sport=sport;
    this->nbrp=nbrp;



}
int matchs::get_id(){return  id;}
int matchs::get_idstade(){return idstade;}
QString matchs::get_dates(){return dates;}
QString matchs::get_sport(){return sport;}
int matchs::get_nbrp(){return nbrp;}



bool matchs::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO match (id, idstade, dates, sport ,nbrp) "
                    "VALUES (:id, :idstade, :dates, :sport , :nbrp)");
query.bindValue(":id", id);
query.bindValue(":idstade", idstade);
query.bindValue(":dates", dates);
query.bindValue(":sport", sport);
query.bindValue("nbrp", nbrp);



return    query.exec();
}

QSqlQueryModel * matchs::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from match");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDSTADE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATES"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("SPORT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRP"));


    return model;
}

bool matchs::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from match where ID = :id ");
query.bindValue(":id", id);
return    query.exec();
}
QSqlQueryModel *matchs::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from match where id LIKE '"+rech+"%' or idstade LIKE '"+rech+"%'");
    return model;
}
/*bool matchs::modifier(QString id)
{
    QSqlQuery query;

  query.prepare("UPDATE match set idstade='"+idstade+"',dates='"+dates+"',sport='"+sport+"' WHERE id LIKE '"+id+"' ");
   return query.exec();
    }*/
QSqlQueryModel * matchs::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from match ORDER BY id ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDSTADE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SPORT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRP"));





        return model;
}
