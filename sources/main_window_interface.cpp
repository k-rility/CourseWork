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
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select();
}
