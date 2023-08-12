#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpart.h"
#include "qpartslistsqlmodel.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateText();

private slots:
    void on_BuyButton_clicked();

    void getSelectedItem(const QString& partName);

    void on_listView_clicked(const QModelIndex &index);

    void on_SearchLineEdit_textEdited(const QString &arg1);

signals:
    void selectedItem(const QString& partName);

private:
    Ui::MainWindow *ui;
    QPartsListModel qPartsListModel_;
    QPartsSqlModel Parts_;
};
#endif // MAINWINDOW_H
