/**
 * @file main.cpp
 * @author Petr Hanzlík (xhanzlp00)
 * @note Project: Calculator - JuHaBeGl
*/

#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;

    QString systemLanguage = QLocale::system().name();

    if (systemLanguage.startsWith("cs")) {
        if (translator.load("kalkulacka_cs.qm", a.applicationDirPath())) {
            a.installTranslator(&translator);
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}
