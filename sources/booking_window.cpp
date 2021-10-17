
#include "include/booking_window.hpp"
#include "../ui/ui_booking_window.h"


booking_window::booking_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::booking_window) {
    ui->setupUi(this);
}

booking_window::~booking_window() {
    delete ui;
}

void booking_window::back() {
    emit back_clicked();
}

void booking_window::setupModel(const QString &table_name, const QStringList &headers) {

    model = new QSqlTableModel(this);
    model->setTable(table_name);
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    model->setSort(0, Qt::AscendingOrder);
}

void booking_window::createUi() {
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select();
}


