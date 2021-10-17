#ifndef REG_CUSTOMERS_WINDOW_HPP
#define REG_CUSTOMERS_WINDOW_HPP

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QString>
#include "include/data_base.hpp"

namespace Ui {
    class reg_customers_window;
}

class reg_customers_window : public QWidget {

Q_OBJECT
public:

    explicit reg_customers_window(QWidget *parent = nullptr);

    ~reg_customers_window();

    void setupModel(const QString &, const QStringList &);

    void createUi();

//private slots:

//    void back();

private:

    Ui::reg_customers_window *ui;
    QSqlTableModel *model;
};


#endif //REG_CUSTOMERS_WINDOW_HPP
