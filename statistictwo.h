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

private slots:
    void toggleAutoFollow();  // Слот для переключения автоследования

    void on_pushButton_2_clicked();

public slots:

    void receiveMotorSpeed(int motorSpeed);
    void receiveProgressbars(int progressValue);
    void receiveProgressbars2(int progressValue2);
    void receiveProgressbars4(int progressValue4);
    void onXAxisRangeChanged(const QCPRange &range);
private:
    Ui::statistictwo *ui;
    QCustomPlot *customPlot;  // объект для графика
    QCustomPlot *customPlot2;
    QCustomPlot *customPlot3;
    QCustomPlot *customPlot4;
    QCPBars *bars1;   // Указатель на столбцы для второго графика
    QCPBars *bars2;   // Указатель на столбцы для третьего графика
    QCPBars *bars4;   // Указатель на столбцы для четвертого графика


    QPushButton *autoFollowButton;

    QCPRange lastXRange;  // Для хранения последнего диапазона оси X

    bool autoFollow;  // Флаг автоследования

    // Переменные для хранения данных графиков
    QVector<double> xData1, yData1;  // Данные для первого графика
    QVector<double> xData2, yData2;  // Данные для второго графика
    QVector<double> xData4, yData4;  // Данные для второго графика

    QVector<double> timestamps; // Временные метки
    QVector<double> motorSpeeds; // Скорости мотора

    void setupGraph();
    double calculateAverageTemperature(); // Новый метод для расчета средней температуры
    void createWordReport(const QString& templatePath, const QString& outputPath); // Новый метод для создания отчета
    QDateTime startTime;
};

#endif // STATISTICTWO_H
