#ifndef HILLCLIMBER_H
#define HILLCLIMBER_H


#include "hcinput.h"
#include "hcoutput.h"
#include "alpha.h"

//typedef unsigned int uint;

class HillClimber
{

public:
    HillClimber();

    HCOutput optimaze(const HCInput &in);
    void valuesTable(HCInput &in);

};

#endif


