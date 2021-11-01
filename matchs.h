#ifndef MATCHS_H
#define MATCHS_H


#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class matchs
{public:
    matchs(){};
   matchs(int,int,QString,QString,int);
    int get_id();
    int get_idstade();
    QString get_dates();
    QString get_sport();
    int get_nbrp();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
     bool modifier(QString);
    QSqlQueryModel * rechercher(QString);
        QSqlQueryModel * tri();

private:
        int id,idstade,nbrp;
    QString dates,sport;


};
