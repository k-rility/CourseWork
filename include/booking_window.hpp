#ifndef BOOKING_WINDOW_HPP
#define BOOKING_WINDOW_HPP

#include <QWidget>
#include <QSqlTableModel>


namespace Ui { class booking_window; }

class booking_window : public QWidget {
Q_OBJECT

public:
    explicit booking_window(QWidget *parent = nullptr);

    ~booking_window();

    void setupModel(const QString &, const QStringList &);

    void createUi();

signals:

    void back_clicked();

private slots:

    void back();

private:
    Ui::booking_window *ui;
    QSqlTableModel *model;
};


#endif //WORK_BOOKING_WINDOW_HPP
