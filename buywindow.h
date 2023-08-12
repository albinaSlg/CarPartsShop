#ifndef BUYWINDOW_H
#define BUYWINDOW_H

#include <QDialog>

namespace Ui {
class BuyWindow;
}

class BuyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BuyWindow(QWidget *parent = nullptr);
    ~BuyWindow();

private:
    Ui::BuyWindow *ui;
};

#endif // BUYWINDOW_H
