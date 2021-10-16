#include "include/auth_window.hpp"
#include "../ui/ui_auth_window.h"

#include "include/main_window.hpp"

auth_window::auth_window(QWidget *parent) : QWidget(parent), ui_auth(new Ui::auth_window) {
    ui_auth->setupUi(this);
}

auth_window::~auth_window() {
    delete ui_auth;
}

QString auth_window::EditLine_login() {
    return ui_auth->lineEdit_login->text();
}

QString auth_window::EditLine_password() {
    return ui_auth->lineEdit_password->text();
}

QPushButton *auth_window::get_push_btn() {
    return ui_auth->pushButton_sign_in;
}

void auth_window::sign_in_clicked() {
    emit clicked();
}