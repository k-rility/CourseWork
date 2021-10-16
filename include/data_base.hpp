#ifndef DATA_BASE_HPP
#define DATA_BASE_HPP

#include <QSql>
#include <QSqlDatabase>
#include <QObject>
#include <QFile>
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

const QString data_base_path = "/home/kirill/Рабочий стол/database/sound_recording_studio.db";

class data_base : QObject {
public:

    explicit data_base(QObject *parent = nullptr);

    ~data_base();

    bool connect_to_data_base();

private:
    QSqlDatabase __data_base;
};

#endif //DATA_BASE_HPP