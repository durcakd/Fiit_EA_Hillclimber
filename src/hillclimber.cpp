#include "hillclimber.h"

#include <math.h>
#include <vector>

#include <QDebug>
#include "util.h"

QString str(double val) {
    return QString::number(val,'f',15);
}

HillClimber::HillClimber()
{

}


void HillClimber::optimaze()
{
    uint tmax = 20;

    uint k = 15;
     uint cmax = k;
    double a = -1.0;
    double b = 1.0;
    Alpha::init(true, a, b, k);
    qDebug() << "------------";


/*
        double pow2tokm1 = Util::pow2tokm1(k);
        uint ovalue = Util::binaryToGray(pow2tokm1);
        //uint ovalue = pow2tokm1;

        for(uint u=0; u<pow2tokm1+1; u++ ) {
            Alpha alp(Util::binaryToGray((uint)u));
            //Alpha alp((uint)u);

            QString diff = QString::number( ovalue ^ alp.value(), 2).rightJustified(k, '0');

            qDebug() << u << "\t" << alp.value() \
                     << "\t" << QString::number(alp.realValue(),'f',8) \
                     << "\t" << QString::number(alp.fitness(), 'f', 8) \
                     << "\t" << diff << "   " << diff.count('1');
            ovalue = alp.value();
        }

*/




    Alpha alfa(-0.5);
    Alpha finalAlfa( alfa.value());

    double finalFitness = finalAlfa.fitness();

    qDebug() << "start optimize in alfa: " << alfa.value() <<  "   " << str(alfa.realValue()) << "    fitness=" << str(alfa.fitness());




    for (int i=0; i < tmax; i++) {

        qDebug();
        qDebug() << "alfa: " << alfa.value() << "    fitness=" << str(alfa.fitness())  <<  "   " << str(alfa.realValue());

        // generate neighborhood from alfa
        std::vector<Alpha*> &neighbors = *(alfa.generateNeighbors(cmax));
        std::vector<Alpha*>::const_iterator it = neighbors.begin();
        Alpha bestNeighbor( (*it)->value());
        double bestNeighborFitness = bestNeighbor.fitness();

        while (++it != neighbors.end()) {
            double itFitness = (*it)->fitness();
            if ( bestNeighborFitness > itFitness) {
                bestNeighbor.setValue((*it)->value());
                bestNeighborFitness = itFitness;
            }
        }
        qDebug() << "best: " << bestNeighbor.value() << "    fitness=" << str(bestNeighborFitness)  <<  "   " << str(bestNeighbor.realValue());

        qDebug() << "solution: "<< finalAlfa.checkSolution(bestNeighborFitness);
        qDebug() << "solution: "<< finalAlfa.checkSolution();

        if( bestNeighborFitness < finalFitness ) {
            finalFitness = bestNeighborFitness;
            finalAlfa = bestNeighbor;
            qDebug() << "---final: " << finalAlfa.value() << "    fitness=" << str(finalFitness)  <<  "   " << str(finalAlfa.realValue());
        }

        alfa.setValue( bestNeighbor.value());

    }
}

/*
void test() {

    //double pow2tokm1 = pow(2,8)-1;
    double pow2tokm1 = Util::pow2tokm1(8);
    double real, oreal = 0.0;
    uint bin;
    uint errc = 0;

    for(uint u=0; u<256; u++ ) {

    QString myStringOfBits( QString::number( value(), 2 ) );

        real = Util::binToReal(a, b, pow2tokm1, u);
        bin = Util::realToBin(a, b, pow2tokm1, real);

        qDebug() << qSetRealNumberPrecision(8) <<" "<< bin-u <<"  "<< u <<"  "<< bin <<"         "<< real <<"     "<< real-oreal;
        if(bin != u) {errc++;}
        oreal = real;
    }
    qDebug() << "Error count= "<< errc;


}*/
/*
void test2() {

    for(uint u=0; u<256; u++ ) {
       QString myStringOfBits( QString::number( Util::binaryToGray(u), 2 ) );
        qDebug() << u << "   " << myStringOfBits;

    }

}*/
