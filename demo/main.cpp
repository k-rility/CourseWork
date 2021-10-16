#include "include/auth_window.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auth_window w;
//    w.resize(400,400);
    w.show();
    return a.exec();
}
