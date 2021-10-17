#include "include/auth_window.hpp"
#include "../ui/ui_auth_window.h"

#include "include/main_window.hpp"


auth_window::auth_window(QWidget *parent) : QWidget(parent), ui_auth(new Ui::auth_window) {
    ui_auth->setupUi(this);
}

auth_window::~auth_window() noexcept {
    delete ui_auth;
}

void auth_window::on_lineEdit_login(const QString &in_edit_line_login) {
    login = in_edit_line_login;
}

void auth_window::on_lineEdit_password(const QString &in_edit_line_password) {
    password = in_edit_line_password;
}

QString &auth_window::EditLine_login() {
    return login;
}

QString &auth_window::EditLine_password() {
    return password;
}

void auth_window::_sign_in_clicked() {
    on_lineEdit_login(ui_auth->lineEdit_login->text());
    on_lineEdit_password(ui_auth->lineEdit_password->text());
    emit sign_in_clicked();
}

