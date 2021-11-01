#ifndef MATCH_H
#define MATCH_H
#include <QString>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class Match
{public:
    Match(){};
   Match(int,int,QString,QString,int);
    int get_id();
    int get_idstade();
    QString get_dates();
    QString get_sport();
    int get_nbrp();


    bool ajouter();
    QSqlQueryModel * afficher();
     bool supprimer(QString);
     bool modifier(int,int,QString,QString,int);

    QSqlQueryModel * rechercher(QString);
        QSqlQueryModel * tri();

private:
        int id,idstade,nbrp;
    QString dates,sport;


};


#endif // MATCH_H
