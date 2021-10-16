#include "include/auth_window.hpp"
#include "../ui/ui_auth_window.h"

auth_window::auth_window(QWidget *parent) : QWidget(parent), ui(new Ui::auth_window) {
    if (!connect_auth_DataBase()) {
        qDebug() << "Failed to connect DataBase";
    }
    ui->setupUi(this);
}

auth_window::~auth_window() {
    delete ui;
}

bool auth_window::connect_auth_DataBase() {
    auth_db = QSqlDatabase::addDatabase("QSQLITE");
    QString database_path = "/home/kirill/Рабочий стол/database/sound_recording_studio.db";
    if (!QFile(database_path).exists()) {
        qDebug() << "Cannot open DataBase: " << auth_db.lastError();
        return false;
    }
    auth_db.setDatabaseName(database_path);
    if (!auth_db.open()) {
        qDebug() << "Cannot open DataBase: " << auth_db.lastError();
        return false;
    }
    return true;
}

void auth_window::sign_in() {
    QSqlQuery query;
    QString login = ui->lofin_edit_line->text();
    QString password = ui->password_edit_line->text();
    QString str_t = " SELECT * FROM passwords WHERE LOGIN = '%1' ";
    if (!query.exec(str_t.arg(login))) {
        qDebug() << "Error";
    }
    QSqlRecord rec = query.record();
    query.next();

    if (login != query.value(rec.indexOf("LOGIN")).toString() ||
        password != query.value(rec.indexOf("PASSWORD")).toString()) {
        QMessageBox::warning(this, "Authorize", "Nosuccessful authorize");
    } else if (login == "" || password == "") {
        QMessageBox::warning(this, "Authorize", "Nouccessful authorize");
    } else {
        QMessageBox::about(this, "Authorize", "Successful authorize");
    }
}