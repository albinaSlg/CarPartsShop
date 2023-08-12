#include "buywindow.h"
#include "ui_buywindow.h"

BuyWindow::BuyWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyWindow)
{
    ui->setupUi(this);
}

BuyWindow::~BuyWindow()
{
    delete ui;
}
