#include "include/main_window.hpp"
#include "../ui/ui_main_window.h"

main_window::main_window(QWidget *parent) : QMainWindow(parent), ui_main(new Ui::main_window) {
    ui_main->setupUi(this);
}

main_window::~main_window() {
    delete ui_main;
}

void main_window::regular_customers() {

}
