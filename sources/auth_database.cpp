#include "include/auth_database.hpp"

password_DataBase::password_DataBase(QObject*parent):QObject(parent){}

password_DataBase::~password_DataBase(){}

void password_DataBase::connect_to_DataBase(){
    if(!QFile("/home/kirill/Рабочий стол" DATABASE_NAME).exists()){
        this->open_DataBase();
    }
}

bool password_DataBase::open_DataBase(){
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("/home/kirill/Рабочий стол/database/" DATABASE_NAME);
    if(db.open())
        return true;
    else
        return false;
}

void password_DataBase::close_DataBase(){
    db.close();
}
