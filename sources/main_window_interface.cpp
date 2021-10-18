#include "include/main_window_interface.hpp"
#include "../ui/ui_main_window_interface.h"

main_window_interface::main_window_interface(QWidget *parent) : QWidget(parent), ui(new Ui::main_window_interface) {
    ui->setupUi(this);
}

main_window_interface::~main_window_interface() noexcept {
    delete ui;
}


void main_window_interface::back() {
    emit back_clicked();
    model->select();
}

void main_window_interface::setupModel(const QString &table_name, const QStringList &headers) {

    model = new QSqlTableModel(this);
    model->setTable(table_name);
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    model->setSort(0, Qt::AscendingOrder);
}

void main_window_interface::createUi() {
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select();
}

reg_customers_window::reg_customers_window(main_window_interface *parent) : main_window_interface(parent) {
    QPushButton *add_btn = new QPushButton("Add", this);
    QObject::connect(add_btn, &QPushButton::clicked, this, &reg_customers_window::add);
    add_btn->setGeometry(330, 610, 461, 41);
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setStyleSheet("QPushButton{"
                           "color: rgb(211, 215, 207);"
                           "border: 2px solid rgb(211, 215, 207);"
                           "border-radius:20px;"
                           "background-color: rgb(63, 67, 68)"
                           "}"
                           "QPushButton::hover{"
                           "border: 2px solid rgb(85, 87, 83);"
                           "background-color: rgb(45, 47, 48)"
                           "}");
}

void reg_customers_window::add() {
    emit add_clicked();
    model->select();
}
