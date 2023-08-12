#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buywindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listView->setModel(&qPartsListModel_);


    Parts_.Add(QPart{"Right shock absorber", "SFGxbn%671", 100, {50, 50, 30}, "Ukraine", "Cool Part", "Part.jpg"});

    //QVector<QPart> parts_ = Parts_.Select();
    //QVector<QPart> parts_ = Parts_.Select("*", "Name = 'None'");
    //qInfo() << parts_[0].name();
    //qInfo() << parts_[0].height();
    //qInfo() << Parts_.Count();
    QPartsListSqlModel::getAllQPartsModelFromDb(qPartsListModel_, Parts_);

    connect(this, &MainWindow::selectedItem, this, &MainWindow::getSelectedItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateText()
{

}


void MainWindow::on_BuyButton_clicked()
{
    auto buyDialog = new BuyWindow();
    buyDialog->show();
    if(!buyDialog->isVisible())
        delete(buyDialog);
}

void MainWindow::getSelectedItem(const QString& partName)
{
     QPart part = Parts_.Select("*", "Name = '" + partName + "'").at(0);
    ui->NameLabel->setText(part.name());
    ui->CodeLabel->setText("Code: " + part.code());
    ui->WeightLabel->setText("Weight: " + QString::number(part.weight()) + " kg");
    ui->SizesLabel->setText("Sizes: " + QString("%1x%2x%3").arg(QString::number(part.sizes().x()), QString::number(part.sizes().y()), QString::number(part.sizes().z())) + " mm");
    ui->CountryLabel->setText("Country: " + part.country());
    ui->DescriptionLabel->setText("Description: " + part.description());
    QPixmap pix;
    if(pix.load(":/resources/images/" + part.imagePath()))
        ui->ItemImage->setPixmap(pix);
}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    emit selectedItem(qPartsListModel_.data(index).toString());
}


void MainWindow::on_SearchLineEdit_textEdited(const QString &arg1)
{
    qPartsListModel_.clear();

    for (const auto& row : QPartsListSqlModel::getListOfSuitableRows(arg1))
        qPartsListModel_.addPart(row);
}

