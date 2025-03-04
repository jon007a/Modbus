#include "statistictwo.h"
#include "ui_statistictwo.h"
#include <QDateTime>
#include <QDebug>
#include "qcustomplot.h"

statistictwo::statistictwo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistictwo),
    autoFollow(true) //Автоматическое включение автоследования при запуске
{


    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/icon2.png"));
    ui->setupUi(this);

    // ПОСЛЕ setupUi настраиваем кнопку
    autoFollowButton = ui->autoFollowButton;
    if (autoFollowButton) {  // Проверяем, что кнопка существует
        autoFollowButton->setCheckable(true);
        autoFollowButton->setChecked(true);
        autoFollowButton->setText("Автоследование: Вкл");
        connect(autoFollowButton, &QPushButton::clicked, this, &statistictwo::toggleAutoFollow);
    } else {
        qDebug() << "Warning: autoFollowButton not found in UI";
    }


    customPlot2 = ui->customPlot2;
    customPlot3 = ui->customPlot3;
    customPlot4 = ui->customPlot4;
    // Инициализируем lastXRange пустым диапазоном
    lastXRange = QCPRange();

    // Настройка customPlot2 для отображения прогресса
    customPlot2->addGraph();
    customPlot2->setInteraction(QCP::iRangeDrag, true);
    customPlot2->setInteraction(QCP::iRangeZoom, true);
    customPlot2->axisRect()->setRangeDrag(Qt::Horizontal);
    customPlot2->axisRect()->setRangeZoom(Qt::Horizontal);
    customPlot2->graph(0)->setLineStyle(QCPGraph::lsNone);
    customPlot2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, 8));
    customPlot2->xAxis->setLabel("Время");
    customPlot2->yAxis->setLabel("Ампераж");

    // Настройка customPlot3 для отображения прогресса
    customPlot3->addGraph();
    customPlot3->setInteraction(QCP::iRangeDrag, true);
    customPlot3->setInteraction(QCP::iRangeZoom, true);
    customPlot3->axisRect()->setRangeDrag(Qt::Horizontal);
    customPlot3->axisRect()->setRangeZoom(Qt::Horizontal);
    customPlot3->graph(0)->setLineStyle(QCPGraph::lsNone);
    customPlot3->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, 8));
    customPlot3->xAxis->setLabel("Время");
    customPlot3->yAxis->setLabel("Вольтаж");

    // Установим светлый фон для графиков
    customPlot2->setBackground(QBrush(QColor(245, 245, 245)));
    customPlot3->setBackground(QBrush(QColor(245, 245, 245)));

    // Добавление столбцов с использованием QCPBars
    bars1 = new QCPBars(customPlot2->xAxis, customPlot2->yAxis);
    bars1->setAntialiased(false);
    bars1->setPen(QPen(QColor(100, 255, 255, 255)));
    bars1->setBrush(QColor(100, 255, 100, 80));

    bars2 = new QCPBars(customPlot3->xAxis, customPlot3->yAxis);
    bars2->setAntialiased(false);
    bars2->setPen(QPen(QColor(255, 100, 100, 255)));
    bars2->setBrush(QColor(255, 100, 100, 80));

    // Начальная настройка осей
    customPlot2->yAxis->setRange(0, 100);
    customPlot3->yAxis->setRange(0, 100);

    // Настройка основного графика скорости
    ui->customPlot->addGraph();
    ui->customPlot->setInteraction(QCP::iRangeDrag, true);
    ui->customPlot->setInteraction(QCP::iRangeZoom, true);
    ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal);
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);

    // Добавляем обработчики изменения диапазона
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),
            this, SLOT(onXAxisRangeChanged(QCPRange)));

    // Настройка стиля линии
    QPen pen;
    pen.setColor(QColor(186, 85, 211));
    pen.setWidth(3);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    ui->customPlot->graph(0)->setPen(pen);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));

    // Настройка осей и сетки
    ui->customPlot->xAxis->setLabel("Время");
    ui->customPlot->yAxis->setLabel("Скорость (об/мин)");
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(220, 220, 220), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(220, 220, 220), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);

    // Настройка внешнего вида
    ui->customPlot->setBackground(QBrush(QColor(245, 245, 245)));
    ui->customPlot->axisRect()->setBackground(QBrush(QColor(240, 240, 240)));
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(186, 85, 211, 50)));

    ui->customPlot->xAxis->setTickLabelColor(QColor(80, 80, 80));
    ui->customPlot->yAxis->setTickLabelColor(QColor(80, 80, 80));
    ui->customPlot->xAxis->setTickLength(5);
    ui->customPlot->yAxis->setTickLength(5);

    // Настройка диапазонов
    ui->customPlot->yAxis->setRange(0, 3500);
    timestamps.clear();
    motorSpeeds.clear();
}

statistictwo::~statistictwo()
{
    delete ui;
}

void statistictwo::receiveMotorSpeed(int motorSpeed)
{
    // Получаем текущее время
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    qDebug() << "Получена скорость мотора:" << motorSpeed << "время:" << currentTime;

    // Проверка значений
    if (motorSpeed < 0 || motorSpeed > 3500) {
        qDebug() << "Некорректное значение скорости мотора:" << motorSpeed;
        return;
    }

    // Добавляем данные
    timestamps.append(currentTime);
    motorSpeeds.append(motorSpeed);

    // Ограничиваем размер данных до 60 точек
    if (timestamps.size() > 600) {
        timestamps.removeFirst();
        motorSpeeds.removeFirst();
    }

    // Обновляем данные графика
    ui->customPlot->graph(0)->setData(timestamps, motorSpeeds);

    // Настраиваем форматирование оси X
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss");
    ui->customPlot->xAxis->setTicker(dateTicker);

    // Обновляем диапазон в зависимости от режима автоследования
    if (autoFollow) {
        // Если включено автоследование, всегда показываем последние 30 секунд
        ui->customPlot->xAxis->setRange(currentTime - 30, currentTime + 1);
    } else {
        // Если автоследование выключено
        if (lastXRange.size() > 0) {
            // Используем сохраненный диапазон
            ui->customPlot->xAxis->setRange(lastXRange);
        } else {
            // Только при первом запуске
            ui->customPlot->xAxis->setRange(currentTime - 30, currentTime + 1);
            lastXRange = ui->customPlot->xAxis->range();
        }
    }




    // Устанавливаем фиксированный диапазон для оси Y
    ui->customPlot->yAxis->setRange(0, 3500);

    // Перерисовываем график
    ui->customPlot->replot();
}

void statistictwo::receiveProgressbars(int progressValue)
{
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    qDebug() << "Получено значение прогресса 1:" << progressValue << "время:" << currentTime;

    if (progressValue < 0 || progressValue > 100) {
        qDebug() << "Некорректное значение прогресса 1:" << progressValue;
        return;
    }

    xData1.append(currentTime);
    yData1.append(progressValue);

    if (xData1.size() > 60) {
        xData1.removeFirst();
        yData1.removeFirst();
    }

    bars1->setData(xData1, yData1);

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss");
    customPlot2->xAxis->setTicker(dateTicker);

    customPlot2->xAxis->setRange(currentTime - 30, currentTime + 1);
    customPlot2->replot();
}

void statistictwo::receiveProgressbars2(int progressValue2)
{
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    qDebug() << "Получено значение прогресса 2:" << progressValue2 << "время:" << currentTime;

    if (progressValue2 < 0 || progressValue2 > 100) {
        qDebug() << "Некорректное значение прогресса 2:" << progressValue2;
        return;
    }

    xData2.append(currentTime);
    yData2.append(progressValue2);

    if (xData2.size() > 60) {
        xData2.removeFirst();
        yData2.removeFirst();
    }

    bars2->setData(xData2, yData2);

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss");
    customPlot3->xAxis->setTicker(dateTicker);

    customPlot3->xAxis->setRange(currentTime - 30, currentTime + 1);
    customPlot3->replot();
}
void statistictwo::onXAxisRangeChanged(const QCPRange &range)
{
    // Сохраняем текущий диапазон
    lastXRange = range;
}
void statistictwo::toggleAutoFollow()
{
    autoFollow = !autoFollow;
    autoFollowButton->setText(autoFollow ? "Автоследование: Вкл" : "Автоследование: Выкл");
}



//Отчеты
QString widget_to_base64(QWidget *w) {
    QPixmap pixmap = w->grab();
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "JPG");
    return bytes.toBase64();
}

void doc_to_pdf(QTextDocument& doc) {

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    //printer.set.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("C:\\gf\\one2.pdf");
    // doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

QString read_res(const QString& s) {
    QString r=qApp->applicationDirPath();
    QFile f(r+s);
    if(!f.exists())f.setFileName(":/"+s);
    f.open(QIODevice::ReadOnly);
    return f.readAll();
}

void statistictwo::on_pushButton_2_clicked()
{
    QString s=read_res("1.html");
    s.replace("$777$","888888");
    s.replace("$111$",widget_to_base64(this));
    QTextDocument doc;
    doc.setHtml(s);
    doc_to_pdf(doc);

    QTextDocumentWriter odfWritter("c://gf//8.odt");
    odfWritter.write(&doc);

      QTextDocumentWriter od("c://gf//81.pdf");
        od.setFormat("PDF");
    od.write(&doc);

}
