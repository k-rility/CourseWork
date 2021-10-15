#include "include/auth_window.hpp"
#include "ui_auth_window.h"
#include <QMessageBox>
#include <QString>

AuthorizeWindow::AuthorizeWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AuthorizeWindow) {
    ui->setupUi(this);
//        db=new password_DataBase(this);
//        db->connect_to_DataBase();
}

AuthorizeWindow::~AuthorizeWindow() {
    delete ui;
}


void AuthorizeWindow::sign_in() {
    QSqlQuery query;
    QString login = ui->login_line->text();
    QString password = ui->password_line->text();
    db = new password_DataBase(this);
    db->connect_to_DataBase();
    if (query.exec("SELECT * FROM passwords WHERE PASSWORD=""+arg+") == login && "qwerty1234" == password) {
        QMessageBox::about(this, "Authorize", "successful authorize");
    } else {
        QMessageBox::warning(this, "Authorize", "nosuccessful authorize");
    }
}
