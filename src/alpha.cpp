#include "alpha.h"
#include "util.h"

// define static fields and methods
bool   Alpha::_isgray;
double Alpha::_a;
double Alpha::_b;
unsigned int Alpha::_k;
unsigned int Alpha::_pow2tokm1;
double Alpha::_mindiff;
double Alpha::_mindiffFitness;

QString str2(double val) {
    return QString::number(val,'f',8);
}

void Alpha::init(bool isgray, double a, double b, unsigned int k)
{
    _isgray = isgray;
    _a = a;
    _b = b;
    _k = k;
    _pow2tokm1 = Util::pow2tokm1(k);
    _mindiff = Util::minDiff(a, b, _pow2tokm1)/2;
    _mindiffFitness = _mindiff * _mindiff;

    qDebug() << "=======================";
    qDebug() << "  isgray = " << _isgray;
    qDebug() << "       a = " << _a;
    qDebug() << "       b = " << _b;
    qDebug() << "       k = " << _k;
    qDebug() << " pow2km1 = " << _pow2tokm1;
    qDebug() << "    diff = " <<  QString::number(_mindiff,'f',15);
    qDebug() << " mindiff = " << QString::number(_mindiffFitness,'f',15);
    qDebug() << "=======================";

}


// constructor
Alpha::Alpha(uint value) {
  _value = value;
}

Alpha::Alpha(double realValue) {
  _value = Util::realToBin(_a, _b, _pow2tokm1, realValue);
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
    return Util::binToReal( _a, _b, _pow2tokm1, value);
}

double Alpha::fitness() {
//    const double x = realValue() + C;
//    return x*x;

    return (realValue()+C)*(realValue()+C);
}


std::vector<Alpha *>* Alpha::generateNeighbors(int count) {
    std::vector<Alpha *>* neighbors  = new std::vector<Alpha *>();
    double real = realValue();
    //qDebug() << "neighbors: " << value() << /*"   " << printBin() <<  */"    fitness=" << str2(fitness());

    for (int i=0; i<count; i++ ) {
        Alpha* mut;

        neighbors->push_back( mut = new Alpha(negateBit(i)));
        //qDebug() << "           " << mut->value() << /*"   " << mut->printBin() <<*/  "    fitness=" << str2(mut->fitness());

    }

    return neighbors;

}


uint Alpha::negateBit(uint i) {
    return _value ^ (1u << i) ;
}


QString Alpha::printBin() {
    return QString::number( value(), 2 );
}

bool Alpha::checkSolution(double fitness) {
    if( fitness <= _mindiffFitness){
        return true;
    }
    return false;
}

bool Alpha::checkSolution() {
    double real = realValue();
    if( -C-_mindiff < real  &&  real < -C+_mindiff){
        return true;
    }
    return false;
}
