#include "hcinput.h"


HCInput::HCInput(uint tmax,
        uint cmax,
        bool useGray,
        uint mutbits,
        uint k,
        double start,
        double a,
        double b) {

    this->tmax = tmax;
    this->cmax = cmax;
    this->useGray = useGray;
    this->mutbits = mutbits;
    this->k = k;
    this->start = start;
    this->a = a;
    this->b = b;
}
