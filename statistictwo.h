#ifndef STATISTICTWO_H
#define STATISTICTWO_H

#include "qcustomplot.h"
#include <QMainWindow>

namespace Ui {
class statistictwo;
}

class statistictwo : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistictwo(QWidget *parent = nullptr);
    ~statistictwo();
    void updateGraph(double motorSpeed, double timestamp);

public slots:

    void receiveMotorSpeed(int motorSpeed);
    void receiveProgressbars(int progressValue);
    void receiveProgressbars2(int progressValue2);
private:
    Ui::statistictwo *ui;
    QCustomPlot *customPlot;  // объект для графика
    QCustomPlot *customPlot2;
    QCustomPlot *customPlot3;
    QCustomPlot *customPlot4;
    QCPBars *bars1;   // Указатель на столбцы для первого графика
    QCPBars *bars2;   // Указатель на столбцы для второго графика

    // Переменные для хранения данных графиков
    QVector<double> xData1, yData1;  // Данные для первого графика
    QVector<double> xData2, yData2;  // Данные для второго графика

    QVector<double> timestamps; // Временные метки
    QVector<double> motorSpeeds; // Скорости мотора

    void setupGraph();
};

#endif // STATISTICTWO_H
