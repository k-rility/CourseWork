#ifndef MAIN_WINDOW_INTERFACE_HPP
#define MAIN_WINDOW_INTERFACE_HPP

#include <QWidget>
#include <QSqlTableModel>

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

private:
    Ui::main_window_interface *ui;
    QSqlTableModel *model;
};


#endif //COURSE_WORK_MAIN_WINDOW_INTERFACE_HPP
