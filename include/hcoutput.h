#ifndef HCOUTPUT_H
#define HCOUTPUT_H

#include "alpha.h"

class HCOutput
{

public:
    HCOutput(bool isSolution, Alpha &alpha,
    //Alpha &result,
    int tCount,
    int fitnessCount);

    bool isSolution;
    Alpha result;
    int tCount;
    int fitnessCount;

};

#endif
