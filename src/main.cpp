#include <QDebug>


#include "mainwindow.h"
#include <QApplication>

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

    qDebug() << "hello beautiful world!" << endl;

    test();

    return 0;




}



// real(x)  = a + (b-a)/(2^k - 1)*x
double rtbCoef(double a, double b, int k) {
    return (b-a)/(pow(k,2)-1);
}

double binToReal(double a, double rtbCoef, int x) {
    return a + rtbCoef*x;
}

double btrCoef(double a, double b, int k) {
    return (pow(k,2)-1)/(b-a);
}

double realToBin(double a, double btrCoef, int x) {
    return ceil( (x-a) * btrCoef );   //ceil(7.0/2*0.0)
}


// initial binary ( binaryToGray(0.5))
// fitness(grayToBinary(x))

unsigned int binaryToGray(unsigned int num) {
        return (num >> 1) ^ num;
}

unsigned int grayToBinary(unsigned int num) {
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1) {
        num = num ^ mask;
    }
    return num;
}

void test() {


    double coef = computeKoef(3,5,3);


    qDebug() << ceil(7.0/2*0.0);
    qDebug() << ceil(7.0/2*0.25);
    qDebug() << ceil(7.0/2*0.5);
    qDebug() << ceil(7.0/2*0.75);
    qDebug() << ceil(7.0/2*1.0);
    qDebug() << ceil(7.0/2*1.25);
    qDebug() << ceil(7.0/2*1.5);
    qDebug() << ceil(7.0/2*1.75);
}
