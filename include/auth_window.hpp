#ifndef AUTH_WINDOW_HPP
#define AUTH_WINDOW_HPP

#include <QMessageBox>
#include <QWidget>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QFile>

namespace Ui {
    class auth_window;
}

class auth_window : public QWidget {
Q_OBJECT
public:
    explicit auth_window(QWidget *parent = nullptr);

    ~auth_window();

    bool connect_auth_DataBase();

private slots:

    void sign_in();

private:
    Ui::auth_window *ui;
    QSqlDatabase auth_db;
};

#endif //AUTH_WINDOW_HPP