#ifndef AUTH_WINDOW_HPP
#define AUTH_WINDOW_HPP

#include <QWidget>
#include <QString>
#include <QPushButton>

#include "include/data_base.hpp"

namespace Ui {
    class auth_window;
}

class auth_window : public QWidget {

Q_OBJECT
public:
    explicit auth_window(QWidget *parent = nullptr);

    ~auth_window();

    QString EditLine_login();

    QString EditLine_password();

    QPushButton *get_push_btn();


signals:

    void clicked();

private slots:

    void sign_in_clicked();

private:
    Ui::auth_window *ui_auth;
};

#endif //AUTH_WINDOW_HPP
