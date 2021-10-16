#ifndef COURSE_WORK_MAIN_WINDOW_HPP
#define COURSE_WORK_MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QWidget>

namespace Ui {
    class main_window;
}

class main_window : public QMainWindow {
Q_OBJECT
public:

    explicit main_window(QWidget *parent = nullptr);

    ~main_window();

private slots:

    void regular_customers();

private:
    Ui::main_window *ui_main;
};

#endif //COURSE_WORK_MAIN_WINDOW_HPP
