#include "include/auth_window.hpp"
#include "include/main_window.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    main_window w;
    w.auth_show();
    return a.exec();
}
