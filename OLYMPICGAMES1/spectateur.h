#ifndef SPECTATEUR_H
#define SPECTATEUR_H
#include <QString>
#include <QDate>
#include <QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

class Spectateur
{
public:
    Spectateur();
    Spectateur(int CIN,QString NOMPRENOM,int AGE,int TEL,QString TYPE,int NB_PLACE,QString DATE,QString FIDALITE);
    //////////////////////////////////////////////////////////////////////////////
        /// getter
        //////////////////////////////////////////////////////////////////////////////
    int getCin(){return CIN;}
    int getAge(){return AGE;}
    int getTel(){return TELES;}
    int getNbPlace(){return NB_PLACE;}
    QString getNomPrenom(){return NOMPRENOM;}
    QString getType(){return TYPE;}
    QString getFidalite(){return FIDALITE;}

        //////////////////////////////////////////////////////////////////////////////
        /// setter
        //////////////////////////////////////////////////////////////////////////////
    void setCin(int Cin){this->CIN= Cin;}
    void setAge(int Age){this->AGE=Age;}
    void setTel(int Tel){this->TELES=Tel;}
    void setNbPlace(int nb_place){this->NB_PLACE=nb_place;}
    void setNomPrenom(QString NomPrenom){this->NOMPRENOM=NomPrenom;}
    void setType(QString Type){this->TYPE= Type;}
    void setFidalite(QString Fidalite){this->FIDALITE= Fidalite;}
        //////////////////////////////////////////////////////////////////////////////
        /// Cruds
        //////////////////////////////////////////////////////////////////////////////
        ////////////afficher//////////
        QSqlQueryModel * afficher();
        ////////ajouter///////////
        bool ajouter();
        ///////supprimer/////////
        bool supprimer(int);
        //////modifier//////////
        bool modifier(int CIN);
        //////////////////////////////////////////////////////////////////////////////
        bool verifage(int age);
        bool verifnom(QString ch_nom);
        void fidele(int);

        QSqlQueryModel * Rech(QString choix,QString ch);
        QSqlQueryModel * triCIN();
        QSqlQueryModel * triAGE();
        QSqlQueryModel * triPLACE();
        QSqlQueryModel * triDate();
        void convPDF ();
        bool rech(int);
    int A;
private:
        int CIN,AGE,TELES,NB_PLACE;
        QString NOMPRENOM,TYPE,FIDALITE;
        QString DATE;

};


#endif // SPECTATEUR_H
