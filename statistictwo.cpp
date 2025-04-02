#include "statistictwo.h"
#include "ui_statistictwo.h"
#include <QDateTime>
#include <QDebug>
#include "qcustomplot.h"
#include <QAxObject>
#include <QDir>
#include <QTemporaryFile>
#include <QBuffer>
#include <QFileDialog>
#include <QMessageBox>

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

    // Настройка customPlot4 для отображения прогресса
    customPlot4->addGraph();
    customPlot4->setInteraction(QCP::iRangeDrag, true);
    customPlot4->setInteraction(QCP::iRangeZoom, true);
    customPlot4->axisRect()->setRangeDrag(Qt::Horizontal);
    customPlot4->axisRect()->setRangeZoom(Qt::Horizontal);
    customPlot4->graph(0)->setLineStyle(QCPGraph::lsNone);
    customPlot4->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, 8));
    customPlot4->xAxis->setLabel("Время");
    customPlot4->yAxis->setLabel("Температура");

    // Установим светлый фон для графиков
    customPlot2->setBackground(QBrush(QColor(245, 245, 245)));
    customPlot3->setBackground(QBrush(QColor(245, 245, 245)));
    customPlot4->setBackground(QBrush(QColor(245, 245, 245)));

    // Добавление столбцов с использованием QCPBars
    bars1 = new QCPBars(customPlot2->xAxis, customPlot2->yAxis);
    bars1->setAntialiased(false);
    bars1->setPen(QPen(QColor(100, 255, 255, 255)));
    bars1->setBrush(QColor(100, 255, 100, 80));

    bars2 = new QCPBars(customPlot3->xAxis, customPlot3->yAxis);
    bars2->setAntialiased(false);
    bars2->setPen(QPen(QColor(255, 100, 100, 255)));
    bars2->setBrush(QColor(255, 100, 100, 80));

    bars4 = new QCPBars(customPlot4->xAxis, customPlot4->yAxis);
    bars4->setAntialiased(false);
    bars4->setPen(QPen(QColor(255, 100, 100, 255)));
    bars4->setBrush(QColor(255, 100, 100, 80));


    // Начальная настройка осей
    customPlot2->yAxis->setRange(0, 100);
    customPlot3->yAxis->setRange(0, 100);
    customPlot4->yAxis->setRange(0, 100);

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

void statistictwo::receiveProgressbars4(int progressValue4)
{
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    qDebug() << "Получено значение прогресса 2:" << progressValue4 << "время:" << currentTime;

    if (progressValue4 < 0 || progressValue4 > 100) {
        qDebug() << "Некорректное значение прогресса 2:" << progressValue4;
        return;
    }

    xData4.append(currentTime);
    yData4.append(progressValue4);

    if (xData4.size() > 60) {
        xData4.removeFirst();
        yData4.removeFirst();
    }

    bars4->setData(xData4, yData4);

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss");
    customPlot4->xAxis->setTicker(dateTicker);

    customPlot4->xAxis->setRange(currentTime - 30, currentTime + 1);
    customPlot4->replot();
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
/*QString widget_to_base64(QWidget *w) {
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
*/

// Добавьте новый метод для расчета средней температуры
double statistictwo::calculateAverageTemperature()
{
    if (yData4.isEmpty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (const double& value : yData4) {
        sum += value;
    }

    return sum / yData4.size();
}

// Добавьте новый метод для создания отчета Word
void statistictwo::createWordReport(const QString& templatePath, const QString& outputPath)
{
    // Создаем экземпляр Word
    QAxObject* word = new QAxObject("Word.Application", this);

    if (word->isNull()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось запустить Microsoft Word. Убедитесь, что Word установлен.");
        return;
    }

    word->setProperty("Visible", false);

    // Получаем коллекцию документов
    QAxObject* documents = word->querySubObject("Documents");

    // Открываем шаблон
    QAxObject* document = documents->querySubObject("Open(const QString&)", QDir::toNativeSeparators(templatePath));

    if (!document) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть шаблон документа.");
        word->dynamicCall("Quit()");
        delete word;
        return;
    }

    // Ищем закладки в документе
    QAxObject* bookmarks = document->querySubObject("Bookmarks");

    // Делаем скриншот всего окна статистики
    QPixmap screenshot = this->grab();

    // Сохраняем скриншот во временный файл
    QTemporaryFile tempFile;
    tempFile.setAutoRemove(false); // Не удалять файл автоматически
    if (tempFile.open()) {
        screenshot.save(&tempFile, "PNG");
        QString screenshotPath = QDir::toNativeSeparators(tempFile.fileName());
        tempFile.close();

        // Проверяем, существует ли закладка для вставки изображения
        if (bookmarks->dynamicCall("Exists(const QString&)", "GraphImage").toBool()) {
            // Получаем диапазон текста по закладке
            QAxObject* bookmark = bookmarks->querySubObject("Item(const QString&)", "GraphImage");
            QAxObject* range = bookmark->querySubObject("Range");
            range->dynamicCall("Text", QString(""));

            // Вставляем изображение в место закладки
            QAxObject* inlineShapes = range->querySubObject("InlineShapes");
            inlineShapes->dynamicCall("AddPicture(const QString&)", screenshotPath);

            delete inlineShapes;
            delete range;
            delete bookmark;
        }

        // Удаляем временный файл
        QFile::remove(screenshotPath);
    }

    // Вставляем данные по средней температуре
    if (bookmarks->dynamicCall("Exists(const QString&)", "AvgTemperature").toBool()) {
        QAxObject* bookmark = bookmarks->querySubObject("Item(const QString&)", "AvgTemperature");
        QAxObject* range = bookmark->querySubObject("Range");

        // Форматируем значение средней температуры
        QString avgTemp = QString::number(calculateAverageTemperature(), 'f', 2);
        range->dynamicCall("Text", avgTemp);

        delete range;
        delete bookmark;
    }

    // Получаем текущую дату и время для отчета
    QDateTime now = QDateTime::currentDateTime();
    QString dateTimeStr = now.toString("dd.MM.yyyy HH:mm:ss");

    // Сохраняем как новый документ
    document->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(outputPath));

    // Закрываем документ и Word
    document->dynamicCall("Close()");
    word->dynamicCall("Quit()");

    // Очищаем память
    delete bookmarks;
    delete document;
    delete documents;
    delete word;

    QMessageBox::information(this, "Готово", "Отчет успешно создан и сохранен в:\n" + outputPath);
}

// Обновляем обработчик кнопки "Создать отчет"
void statistictwo::on_pushButton_2_clicked()
{
    // Путь к шаблону по умолчанию
    QString defaultTemplatePath = "C:/Qt/Raboti/vfd/templates/otchet.docx";
    QString templatePath;

    // Проверяем, существует ли шаблон по умолчанию
    if (QFile::exists(defaultTemplatePath)) {
        // Спрашиваем пользователя, хочет ли он использовать шаблон по умолчанию
        QMessageBox::StandardButton reply = QMessageBox::question(
            this,
            "Выбор шаблона",
            "Использовать шаблон по умолчанию?\nНет - выбрать другой шаблон",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            templatePath = defaultTemplatePath;
        } else {
            // Если пользователь выбрал "Нет", открываем диалог выбора файла
            templatePath = QFileDialog::getOpenFileName(
                this,
                "Выберите шаблон отчета",
                QFileInfo(defaultTemplatePath).path(), // Открываем диалог в папке с шаблоном
                "Word Documents (*.docx)"
                );
        }
    } else {
        // Если шаблона по умолчанию нет, просто показываем диалог выбора файла
        templatePath = QFileDialog::getOpenFileName(
        this,
        "Выберите шаблон отчета",
        "",
        "Word Documents (*.docx)"
        );
    }
    if (templatePath.isEmpty()) return;
    // Создаем имя для выходного файла на основе текущей даты и времени
    QString defaultOutputPath = QString("C:/Qt/Raboti/vfd/reports/Отчет_%1.docx")
                                    .arg(QDateTime::currentDateTime().toString("dd_MM_yyyy_hh_mm"));

    // Убедимся, что директория существует
    QDir().mkpath(QFileInfo(defaultOutputPath).path());
    // Запрашиваем путь для сохранения отчета
    QString outputPath = QFileDialog::getSaveFileName(
        this,
        "Сохранить отчет как",
        defaultOutputPath,
        "Word Documents (*.docx)"
        );

    if (outputPath.isEmpty()) return;

    // Создаем отчет
    createWordReport(templatePath, outputPath);
}
