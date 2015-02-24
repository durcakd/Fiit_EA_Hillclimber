#ifndef ALPHA_H
#define ALPHA_H


#include "util.h"
#include "math.h"

#include <vector>
#include <QDebug>

const double C = 0.01;

class Alpha
{

public:
    Alpha(uint value);
    Alpha(double realValue);

    static void init(bool isgray, double a, double b, double k);

 double fitness();

    uint value();
    double realValue();

    std::vector<Alpha*>* generateNeighbors(int count);

private:

    //  mutation();


    static bool   _isgray;
    static double _a;
    static double _b;
    static double _k;
    static double _btrCoef;
    static double _rtbCoef;


    uint _value;

};

#endif


