#ifndef MAIN_WINDOW_INTERFACE_HPP
#define MAIN_WINDOW_INTERFACE_HPP

#include <QWidget>
#include <QSqlTableModel>
#include <QTableWidget>

#include <QPushButton>

namespace Ui { class main_window_interface; }


class main_window_interface : public QWidget {
Q_OBJECT
public:

    explicit main_window_interface(QWidget *parent = nullptr);

    ~main_window_interface() override;

    virtual void setupModel(const QString &, const QStringList &);

    virtual void createUi();

signals:

    void back_clicked();

private slots:

    void back();

protected:
    Ui::main_window_interface *ui;
    QSqlTableModel *model;
};

class reg_customers_window : public main_window_interface {

Q_OBJECT

public:

    reg_customers_window(main_window_interface *parent = nullptr);

signals:

    void add_clicked();

    void win_up();

private slots:

    void add();
};

class booking_window : public main_window_interface {
};


#endif //MAIN_WINDOW_INTERFACE_HPP
