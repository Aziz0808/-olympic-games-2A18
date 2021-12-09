#include "connection.h"
#include "QSqlDatabase"

Connection::Connection()
{

}
bool Connection::CreateConnection(){
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("base");
db.setUserName("Amine");
db.setPassword("Amine");

if (db.open()){
    test=true;
    return test;
}
return test;
}
