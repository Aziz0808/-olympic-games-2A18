#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QMessageBox>
class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool CreateConnection();
};

#endif // CONNECTION_H
