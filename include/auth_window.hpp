#ifndef AUTHORIZEWINDOW_H
#define AUTHORIZEWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QSqlTableModel>

#include "auth_database.hpp"

namespace Ui {
    class AuthorizeWindow;
}

class AuthorizeWindow:public QMainWindow{

Q_OBJECT
public:

    explicit AuthorizeWindow(QWidget*parent=nullptr);

    ~AuthorizeWindow();

private slots:

    void sign_in();
private:

    void setupModel(const QString&,const QStringList&);
private:

    Ui::AuthorizeWindow*ui;
    password_DataBase*db;
    QSqlTableModel*model;
};

#endif // AUTHORIZEWINDOW_H
