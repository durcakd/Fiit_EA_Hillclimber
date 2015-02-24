#include "alpha.h"
#include "util.h"

// define static fields and methods
bool   Alpha::_isgray;
double Alpha::_a;
double Alpha::_b;
double Alpha::_k;
double Alpha::_btrCoef;
double Alpha::_rtbCoef;

void Alpha::init(bool isgray, double a, double b, double k)
{
    _isgray = isgray;
    _a = a;
    _b = b;
    _k = k;
    _btrCoef = Util::btrCoef(a, b, k);
    _rtbCoef = Util::rtbCoef(a, b, k);
}


// constructor
Alpha::Alpha(uint value)
{
  _value = value;
}

Alpha::Alpha(double realValue)
{
  _value = Util::realToBin(_a, _btrCoef, realValue);
  if (_isgray) {
     _value = Util::binaryToGray(_value);
  }
}


double Alpha::fitness()
{
    const double x = realValue() + C;
    return x*x;
}

// initial binary ( binaryToGray(0.5))
// fitness(grayToBinary(x))

uint Alpha::value()
{
    if (_isgray) {
        return Util::grayToBinary(_value);
    }
    return _value;
}

double Alpha::realValue()
{
    return Util::binToReal( _a, _rtbCoef, value());
}

std::vector<Alpha *>* Alpha::generateNeighbors(int count)
{
    std::vector<Alpha *>* neighbors  = new std::vector<Alpha *>();

    for (int i=0; i<count; i++ ) {
        neighbors->push_back( new Alpha((uint)5));
    }

    return neighbors;

}


