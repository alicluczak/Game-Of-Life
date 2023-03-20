#include "mainwindow.h"
#include "testy.h"
#include "Game.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    test_sasiadow();
    test_zasad();
    return a.exec();
}
