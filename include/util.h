#ifndef UTIL_H
#define UTIL_H

#include <math.h>

class Util
{

public:
    inline Util(){}

    static double rtbCoef(double a, double b, int k) {
        return (b-a)/(pow(k,2)-1);
    }

    static double binToReal(double a, double rtbCoef, int x) {
        return a + rtbCoef*x;
    }

    static double btrCoef(double a, double b, int k) {
        return (pow(k,2)-1)/(b-a);
    }

    static double realToBin(double a, double btrCoef, int x) {
        return ceil( (x-a) * btrCoef );   //ceil(7.0/2*0.0)
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
