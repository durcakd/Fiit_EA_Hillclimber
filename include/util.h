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

    static double binToReal(double a, double b, unsigned int pow2tokm1, unsigned int bin) {
        return a + (b-a)*bin / pow2tokm1;
    }

    static double realToBin(double a, double b, unsigned int pow2tokm1, double real) {
        return ceilf( (real-a)*pow2tokm1/(b-a));
    }

    static double minDiff(double a, double b, unsigned int pow2tokm1) {
        return (b-a) / pow2tokm1;
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
