#include "mainwindow.h"

#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleF(":/style/style.css");
    styleF.open(QFile::ReadOnly);
    a.setStyleSheet(styleF.readAll());

    MainWindow w;
    w.show();
    return a.exec();
}
