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

    void sign_in();

private slots:

private:
    Ui::main_window *ui_main;
    auth_window ui_auth;
private:
    data_base __data_base;
};

#endif //MAIN_WINDOW_HPP
