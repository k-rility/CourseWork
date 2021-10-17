#ifndef AUTH_WINDOW_HPP
#define AUTH_WINDOW_HPP

#include <QWidget>
#include <QString>

namespace Ui {
    class auth_window;
}

class auth_window : public QWidget {

Q_OBJECT
public:
    explicit auth_window(QWidget *parent = nullptr);

    ~auth_window();

    void on_lineEdit_login(const QString &);

    void on_lineEdit_password(const QString &);

    QString& EditLine_login();

    QString& EditLine_password();

signals:


    void sign_in_clicked();

private slots:

    void on_sign_in_clicked();

private:
    Ui::auth_window *ui_auth;
    QString login;
    QString password;
};

#endif //AUTH_WINDOW_HPP
