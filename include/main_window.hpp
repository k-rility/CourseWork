#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>

#include "include/auth_window.hpp"
#include "include/data_base.hpp"

namespace Ui {
    class main_window;
}

class main_window : public QMainWindow {
Q_OBJECT
public:

    explicit main_window(QWidget *parent = nullptr);

    ~main_window();

    void auth_show();

public slots:

    void sign_in();

private://ui

    Ui::main_window *ui_main;
    auth_window ui_auth;
private://db
    data_base __data_base;

};

#endif //MAIN_WINDOW_HPP
