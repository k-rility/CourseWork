#include "include/main_window.hpp"
#include "../ui/ui_main_window.h"

main_window::main_window(QWidget *parent) : QMainWindow(parent), ui_main(new Ui::main_window) {
    if (!__data_base.connect_to_data_base()) {
        qDebug() << "Could not connecting to DataBase";
    }
    QObject::connect(&ui_auth, &auth_window::sign_in_clicked, this, &main_window::sign_in);
    ui_main->setupUi(this);
}

main_window::~main_window() {
    delete ui_main;
}

void main_window::auth_show() {
    ui_auth.show();
}

void main_window::sign_in() {
    QSqlQuery query;
    QString login = ui_auth.EditLine_login();
    QString password = ui_auth.EditLine_password();

    QString str_t = "SELECT * FROM passwords WHERE LOGIN = '%1'";
    if (!query.exec(str_t.arg(login))) {
        qDebug() << "Unable to execute query - exiting" << query.lastError() << " : " << query.lastQuery();
    }

    QSqlRecord rec = query.record();
    query.next();

    if (login != query.value(rec.indexOf("LOGIN")).toString() ||
        password != query.value(rec.indexOf("PASSWORD")).toString()) {
        qDebug() << "111";
        QMessageBox::warning(this, "Authorize", "NOsuccessful authorize");
    } else if (login == "" || password == "") {
        qDebug() << "222";
        QMessageBox::warning(this, "Authorize", "NOsuccessful authorize");
    } else {
        QMessageBox::about(this, "Authorize", "successful authorize");
        ui_auth.hide();
        this->show();
    }
}
