#ifndef STATISTIC_H
#define STATISTIC_H

#include <QMainWindow>


namespace Ui {
class Statistic;
}

class Statistic : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statistic(QWidget *parent = nullptr);
    ~Statistic();

private:
    Ui::Statistic *ui;
};

#endif // STATISTIC_H
