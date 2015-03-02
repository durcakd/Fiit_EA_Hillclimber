#include "hcoutput.h"


HCOutput::HCOutput(bool isSolution,
                   Alpha &alpha,
                    int tCount,

                    int fitnessCount)
    : result(alpha.value())
{

    this->isSolution = isSolution;
    //this->result.setValue( result.value());
    this->tCount = tCount;
    this->fitnessCount = fitnessCount;
}
