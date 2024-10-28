#include "mainwindow.h"
#include <QApplication>
#include <QtQml>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Используем только QApplication, так как работаем с виджетами



    // Создаем и показываем главное окно
    MainWindow w;
    w.show();

    return a.exec(); // Запускаем главный цикл приложения
}
