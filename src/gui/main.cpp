/**
 * @file main.cpp
 * @author Petr Hanzlík (xhanzlp00)
 * @note Project: Calculator - JuHaBeGl
*/

#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <clocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/app_icon.png"));

    QTranslator translator;
    QString systemLanguage = QLocale::system().name();
    std::setlocale(LC_NUMERIC, "C");

    if (systemLanguage.startsWith("cs")) {
        if (translator.load("kalkulacka_cs.qm", a.applicationDirPath())) {
            a.installTranslator(&translator);
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}
