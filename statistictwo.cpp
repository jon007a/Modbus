#include "statistictwo.h"
#include "ui_statistictwo.h"
#include <QDateTime>
#include <QDebug>
#include "qcustomplot.h"

// Конструктор StatisticTwo
statistictwo::statistictwo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistictwo)
{
    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/icon2.png"));
    ui->setupUi(this);
    customPlot2 = ui->customPlot2;
    customPlot3 = ui->customPlot3;
    customPlot4 = ui->customPlot4;

    // Настройка customPlot2 для отображения прогресса
    customPlot2->addGraph();
    customPlot2->setInteraction(QCP::iRangeDrag, true);   // Перетаскивание осей
    customPlot2->setInteraction(QCP::iRangeZoom, true);  // Масштабирование колесиком
    customPlot2->axisRect()->setRangeDrag(Qt::Horizontal); // Перетаскивание только по оси X
    customPlot2->axisRect()->setRangeZoom(Qt::Horizontal); // Масштабирование только по оси X
    customPlot2->graph(0)->setLineStyle(QCPGraph::lsNone);  // Без линии
    customPlot2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, 8));  // Стиль столбцов
    customPlot2->xAxis->setLabel("Время");
    customPlot2->yAxis->setLabel("Progress1");


    // Настройка customPlot3 для отображения прогресса
    customPlot3->addGraph();
    customPlot3->setInteraction(QCP::iRangeDrag, true);   // Перетаскивание осей
    customPlot3->setInteraction(QCP::iRangeZoom, true);  // Масштабирование колесиком
    customPlot3->axisRect()->setRangeDrag(Qt::Horizontal); // Перетаскивание только по оси X
    customPlot3->axisRect()->setRangeZoom(Qt::Horizontal); // Масштабирование только по оси X
    customPlot3->graph(0)->setLineStyle(QCPGraph::lsNone);  // Без линии
    customPlot3->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, 8));  // Стиль столбцов
    customPlot3->xAxis->setLabel("Время");
    customPlot3->yAxis->setLabel("Progress2");

    // Установим светлый фон для графиков
    customPlot2->setBackground(QBrush(QColor(245, 245, 245)));
    customPlot3->setBackground(QBrush(QColor(245, 245, 245)));

    // Добавление столбцов с использованием QCPBars
    bars1 = new QCPBars(customPlot2->xAxis, customPlot2->yAxis);  // Столбцы для первого прогресс-бара
    bars1->setAntialiased(false);  // Выключаем сглаживание
    bars1->setPen(QPen(QColor(100, 255, 255, 255)));  // Цвет обводки
    bars1->setBrush(QColor(100, 255, 100, 80));  // Цвет заливки столбцов

    bars2 = new QCPBars(customPlot3->xAxis, customPlot3->yAxis);  // Столбцы для второго прогресс-бара
    bars2->setAntialiased(false);  // Выключаем сглаживание
    bars2->setPen(QPen(QColor(255, 100, 100, 255)));  // Цвет обводки
    bars2->setBrush(QColor(255, 100, 100, 80));  // Цвет заливки столбцов
    // Начальная настройка осей
    customPlot2->xAxis->setRange(0, 10);  // Начальный диапазон оси X
    customPlot2->yAxis->setRange(0, 100);  // Диапазон оси Y для прогресса 1

    customPlot3->xAxis->setRange(0, 10);  // Начальный диапазон оси X
    customPlot3->yAxis->setRange(0, 100);  // Диапазон оси Y для прогресса 2

    // Настройка графика
    ui->customPlot->addGraph(); // Добавляем график
    ui->customPlot->setInteraction(QCP::iRangeDrag, true);   // Перетаскивание осей
    ui->customPlot->setInteraction(QCP::iRangeZoom, true);  // Масштабирование колесиком
    ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal); // Перетаскивание только по оси X
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal); // Масштабирование только по оси X

    // Настройка цвета и стиля линии
    QPen pen;
    pen.setColor(QColor(186, 85, 211)); // Нежно фиолетовый цвет
    pen.setWidth(3); // Толщина линии
    pen.setCapStyle(Qt::RoundCap); // Круглые концы линии
    pen.setJoinStyle(Qt::RoundJoin); // Круглые углы линии
    ui->customPlot->graph(0)->setPen(pen);

    // Стиль точек на графике
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7)); // Стиль точек - большие круги

    // Настроим оси
    ui->customPlot->xAxis->setLabel("Время");
    ui->customPlot->yAxis->setLabel("Скорость (об/мин)");

    // Добавляем сетку
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(220, 220, 220), 1, Qt::DotLine)); // Сетку по оси X
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(220, 220, 220), 1, Qt::DotLine)); // Сетку по оси Y
    ui->customPlot->xAxis->grid()->setSubGridVisible(true); // Подсетка
    ui->customPlot->yAxis->grid()->setSubGridVisible(true); // Подсетка

    // Установим светлый фон для графика
    ui->customPlot->setBackground(QBrush(QColor(245, 245, 245))); // Светлый фон графика

    // Сделаем фон области графика светло-серым
    ui->customPlot->axisRect()->setBackground(QBrush(QColor(240, 240, 240))); // Легкий серый фон области

    // Добавим тени для объема
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(186, 85, 211, 50))); // Легкая полупрозрачность фиолетового для графика

    // Настроим оси для улучшенного отображения
    ui->customPlot->xAxis->setTickLabelColor(QColor(80, 80, 80));  // Цвет меток оси X
    ui->customPlot->yAxis->setTickLabelColor(QColor(80, 80, 80));  // Цвет меток оси Y
    ui->customPlot->xAxis->setTickLength(5); // Длина делений на оси X
    ui->customPlot->yAxis->setTickLength(5); // Длина делений на оси Y

    // Задаём формат отображения времени
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeFormat("hh:mm:ss"); // Формат времени
    ui->customPlot->xAxis->setTicker(dateTimeTicker);

    // Диапазон Y
    ui->customPlot->yAxis->setRange(0, 12000); // Диапазон скоростей
    timestamps.clear();
    motorSpeeds.clear();

    // Установим начальный диапазон для оси X, например с 3:00:00 до текущего времени
    qint64 initialTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 500;
    ui->customPlot->xAxis->setRange(initialTime - 3600, initialTime);  // 1 час назад и текущий момент
}

// Деструктор StatisticTwo
statistictwo::~statistictwo()
{
    delete ui;
}

// Метод для обновления графика
void statistictwo::receiveMotorSpeed(int motorSpeed)
{
    // Получение текущего времени
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 500; // Время в секундах
    qDebug() << "Получена скорость мотора:" << motorSpeed << "время:" << currentTime;

    // Проверка значений
    if (motorSpeed < 0 || motorSpeed > 12000) {
        qDebug() << "Некорректное значение скорости мотора:" << motorSpeed;
        return;  // Прерываем обработку, если данные некорректны
    }

    // Добавляем данные
    timestamps.append(currentTime);   // Добавляем временную метку
    motorSpeeds.append(motorSpeed);   // Добавляем значение скорости

    // Ограничиваем размер данных до 60 точек
    if (timestamps.size() > 60) {
        timestamps.removeFirst();
        motorSpeeds.removeFirst();
    }

    qDebug() << "Количество точек на графике:" << timestamps.size();

    // Сохраняем диапазон оси X (чтобы он не сбрасывался)
    double currentXMin = ui->customPlot->xAxis->range().lower;
    double currentXMax = ui->customPlot->xAxis->range().upper;
    qDebug() << "Диапазон оси X:" << currentXMin << "до" << currentXMax;

    // Обновляем данные графика
    ui->customPlot->graph(0)->setData(timestamps, motorSpeeds);

    // Обновляем диапазоны оси X с сохранением предыдущего диапазона
    ui->customPlot->xAxis->setRange(currentXMin, currentXMax); // Оставляем тот же диапазон по оси X

    // Перерисовываем график
    ui->customPlot->replot();
}

// Слот для обновления графика прогресс-баров
void statistictwo::receiveProgressbars(int progressValue)
{
    // Получаем текущее время
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 500; // Время в секундах
    qDebug() << "Получено значение прогресса 1:" << progressValue << "время:" << currentTime;

    // Проверяем значение прогресса
    if (progressValue < 0 || progressValue > 100) {
        qDebug() << "Некорректное значение прогресса 1:" << progressValue;
        return;
    }

    // Добавляем новые данные в контейнеры
    xData1.append(currentTime);  // Время
    yData1.append(progressValue);  // Значение прогресса

    // Устанавливаем данные в bars1
    bars1->setData(xData1, yData1);

    // Устанавливаем диапазон оси X с шагом
    customPlot2->xAxis->setRange(currentTime - 10, currentTime);

    // Перерисовываем график
    customPlot2->replot();
}

void statistictwo::receiveProgressbars2(int progressValue2)
{
    // Получаем текущее время
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 500; // Время в секундах
    qDebug() << "Получено значение прогресса 2:" << progressValue2 << "время:" << currentTime;

    // Проверяем значение прогресса
    if (progressValue2 < 0 || progressValue2 > 100) {
        qDebug() << "Некорректное значение прогресса 2:" << progressValue2;
        return;
    }

    // Добавляем новые данные в контейнеры
    xData2.append(currentTime);  // Время
    yData2.append(progressValue2);  // Значение прогресса

    // Устанавливаем данные в bars2
    bars2->setData(xData2, yData2);

    // Устанавливаем диапазон оси X с шагом
    customPlot3->xAxis->setRange(currentTime - 10, currentTime);

    // Перерисовываем график
    customPlot3->replot();
}
