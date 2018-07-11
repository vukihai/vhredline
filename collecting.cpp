#include "collecting.h"
#include "ui_collecting.h"

Collecting::Collecting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Collecting)
{
    ui->setupUi(this);
}

Collecting::~Collecting()
{
    delete ui;
}

void Collecting::collect() {

}
