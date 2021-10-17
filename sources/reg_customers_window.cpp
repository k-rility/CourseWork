#include "include/reg_customers_window.hpp"
#include "../ui/ui_reg_customers_window.h"

reg_customers_window::reg_customers_window(QWidget *parent) : QWidget(parent), ui(new Ui::reg_customers_window) {
    ui->setupUi(this);
}

reg_customers_window::~reg_customers_window() noexcept {
    delete ui;
}

void reg_customers_window::setupModel(const QString &table_name, const QStringList &headers) {

    model = new QSqlTableModel(this);
    model->setTable(table_name);
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    model->setSort(0, Qt::AscendingOrder);
}

void reg_customers_window::createUi() {
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select();
}