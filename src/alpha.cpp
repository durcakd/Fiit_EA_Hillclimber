#include "alpha.h"
#include "util.h"

// define static fields and methods
bool   Alpha::_isgray;
double Alpha::_a;
double Alpha::_b;
unsigned int Alpha::_k;
double Alpha::_btrCoef;
double Alpha::_rtbCoef;

void Alpha::init(bool isgray, double a, double b, unsigned int k)
{
    _isgray = isgray;
    _a = a;
    _b = b;
    _k = k;
    _rtbCoef = Util::rtbCoef(a, b, k);
    _btrCoef = Util::btrCoef(a, b, k);

    qDebug() << "=======================";
    qDebug() << " isgray = " << _isgray;
    qDebug() << "      a = " << _a;
    qDebug() << "      b = " << _b;
    qDebug() << "      k = " << _k;
    qDebug() << "    r>b = " << _rtbCoef;
    qDebug() << "    b>r = " << _btrCoef;
    qDebug() << "=======================";

}


// constructor
Alpha::Alpha(uint value) {
  _value = value;
}

Alpha::Alpha(double realValue) {
  _value = Util::realToBin(_a, _rtbCoef, realValue);
  if (_isgray) {
     _value = Util::binaryToGray(_value);
  }
}



// initial binary ( binaryToGray(0.5))
// fitness(grayToBinary(x))

uint Alpha::value() {
    return _value;
}

void Alpha::setValue(uint value) {
    _value = value;
}

double Alpha::realValue() {
    uint value = _value;
    if (_isgray) {
        value = Util::grayToBinary(_value);
    }

    return Util::binToReal( _a, _btrCoef, value);
}

double Alpha::fitness() {
    const double x = realValue() + C;
    return x*x;
}


std::vector<Alpha *>* Alpha::generateNeighbors(int count) {
    std::vector<Alpha *>* neighbors  = new std::vector<Alpha *>();

    for (int i=0; i<count; i++ ) {
        neighbors->push_back( new Alpha((uint)5));
    }

    return neighbors;

}


