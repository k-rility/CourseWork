#include "include/data_base.hpp"

data_base::data_base(QObject *parent) : QObject(parent) {}

data_base::~data_base() {}

bool data_base::connect_to_data_base() {
    __data_base = QSqlDatabase::addDatabase("QSQLITE");
    if (!QFile(data_base_path).exists()) {
        qDebug() << "Could not open DataBase" << __data_base.lastError();
        return false;
    }

    __data_base.setDatabaseName(data_base_path);

    if (!__data_base.open()) {
        qDebug() << "Could not open DataBase" << __data_base.lastError();
        return false;
    }
    return true;
}

bool data_base::add_to_reg_customers_table() {
    //добавить ограничение, чтобы нельзя было добавлять еще одну ячейку в базу данных пока предыдущая не заполнена

    QSqlQuery query;
    query.prepare("INSERT INTO regular_customers DEFAULT VALUES;");
    if (!query.exec()) {
        qDebug() << "Failed to add regular customers to the DataBase";
    }
}