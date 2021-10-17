#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>

#include "include/auth_window.hpp"
#include "include/reg_customers_window.hpp"
#include "include/booking_window.hpp"
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

    void reg_customers_clicked();

    void booking_clicked();

    void sign_in();

    void back_main_window_from_reg_customers();

    void back_main_window_from_booking();

private:
    //user interface
    Ui::main_window *ui_main;
    auth_window ui_auth;
    reg_customers_window ui_reg_customers;
    booking_window ui_book;
private:
    //database
    data_base __data_base;
};

#endif //MAIN_WINDOW_HPP
