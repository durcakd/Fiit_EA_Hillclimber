#ifndef UTIL_H
#define UTIL_H


#include <math.h>
#include <QDebug>

class Util
{

public:
    inline Util(){}

    static unsigned int pow2tokm1(unsigned int k) {
        return pow(2,k)-1;
    }

    static double rtbCoef(double a, double b, unsigned int k) {
        return (pow(2,k)-1)/(b-a);
    }

    static double btrCoef(double a, double b, unsigned int k) {
        return (b-a)/(pow(2,k)-1);
    }


    static double realToBin(double a, double rtbCoef, double x) {
        return ceil( (x-a) * rtbCoef );
    }
    static double realToBin(double a, double b, unsigned int pow2tokm1, double x) {
        qDebug() << "              "  << (x-a)*pow2tokm1/(b-a) << "     ceil " <<  ceil((x-a)*pow2tokm1/(b-a));
        return ceil( (x-a)*pow2tokm1/(b-a));
    }



    static double binToReal(double a, double btrCoef, unsigned int x) {
        return a + btrCoef*x;
    }
    static double binToReal(double a, double b, unsigned int pow2tokm1, unsigned int x) {
        return a + (b-a)*x/pow2tokm1;
    }


    // initial binary ( binaryToGray(0.5))
    // fitness(grayToBinary(x))

    static unsigned int binaryToGray(unsigned int num) {
            return (num >> 1) ^ num;
    }

    static unsigned int grayToBinary(unsigned int num) {
        unsigned int mask;
        for (mask = num >> 1; mask != 0; mask = mask >> 1) {
            num = num ^ mask;
        }
        return num;
    }

};

#endif
