#include "include/main_window.hpp"
#include "../ui/ui_main_window.h"

main_window::main_window(QWidget *parent) : QMainWindow(parent), ui_main(new Ui::main_window) {

    if (!__data_base.connect_to_data_base()) {
        qDebug() << "Could not connecting to DataBase";
    }

    QObject::connect(&ui_auth, &auth_window::sign_in_clicked, this, &main_window::sign_in);
    QObject::connect(&ui_reg_customers, &reg_customers_window::back_clicked, this,
                     &main_window::back_main_window_from_reg_customers);
    QObject::connect(&ui_book, &booking_window::back_clicked, this, &main_window::back_main_window_from_booking);
    QObject::connect(&ui_reg_customers, &reg_customers_window::add_clicked, this, &main_window::add_reg_customer);

    ui_reg_customers.setupModel("regular_customers", QStringList() << trUtf8("ID") << trUtf8("Regular customers"));
    ui_reg_customers.createUi();

    ui_book.setupModel("studios",
                       QStringList()
                               << trUtf8("ID")
                               << trUtf8("user_id")
                               << trUtf8("Date")
                               << trUtf8("Time")
                               << trUtf8("Status"));
    ui_book.createUi();

    ui_main->setupUi(this);
}

main_window::~main_window() {
    delete ui_main;
}

void main_window::auth_show() {
    ui_auth.show();
}

void main_window::add_reg_customer() {
    __data_base.add_to_reg_customers_table();
}

void main_window::reg_customers_clicked() {
    this->hide();
    ui_reg_customers.show();
}

void main_window::booking_clicked() {
    this->hide();
    ui_book.show();
}

void main_window::back_main_window_from_reg_customers() {
    ui_reg_customers.close();
    this->show();
}

void main_window::back_main_window_from_booking() {
    ui_book.close();
    this->show();
}

void main_window::sign_in() {
    QSqlQuery query;
    QString login = ui_auth.EditLine_login();
    QString password = ui_auth.EditLine_password();

    QString str_t = "SELECT * FROM admin_pass WHERE login = '%1'";
    if (!query.exec(str_t.arg(login))) {
        qDebug() << "Unable to execute query - exiting" << query.lastError() << " : " << query.lastQuery();
    }

    QSqlRecord rec = query.record();
    query.next();

    if (login != query.value(rec.indexOf("login")).toString() ||
        password != query.value(rec.indexOf("password")).toString()) {
        QMessageBox::warning(this, "Authorize", "NOsuccessful authorize");
    } else if (login == "" || password == "") {
        QMessageBox::warning(this, "Authorize", "NOsuccessful authorize");
    } else {
        ui_auth.close();
        this->show();
    }
}
