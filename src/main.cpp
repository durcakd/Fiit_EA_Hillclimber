#include <QDebug>


// #include "mainwindow.h"
// #include <QApplication>

#include <statistictest.h>
#include <math.h>


void test();

int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);
//    MainWindow window;
//    window.setGeometry(100, 100, 800, 500);
//    window.show();
//    return app.exec();

    // =================

    qDebug() << "Program start" << endl;

    StatisticTest statisticTest;
    statisticTest.simpleTest();

    qDebug() << "Program end" << endl;
    return 0;
}

