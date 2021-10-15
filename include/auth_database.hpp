#ifndef AUTH_DATABASE_HPP
#define AUTH_DATABASE_HPP

#include <QObject>
#include <QSqlDatabase>
#include <QFile>
#include <QSqlQuery>
#include <QSql>
#include <QDebug>
#include <QSqlError>

#define DATABASE_NAME "password_DataBase"
#define DATABASE_HOSTNAME "kirik"

#define TABLE "Table Example"

#define TABLE_LOGIN "Login"
#define TABLE_PASSWORD "Password"

class password_DataBase:public QObject{

Q_OBJECT
public:
    explicit password_DataBase(QObject*parent);

    ~password_DataBase();

    void connect_to_DataBase();

private:

    bool open_DataBase();

    void close_DataBase();

private:
    QSqlDatabase db;
};


#endif // AUTH_DATABASE_HPP
