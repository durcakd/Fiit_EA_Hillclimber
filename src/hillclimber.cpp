#include "hillclimber.h"

#include <math.h>
#include <vector>

#include <QDebug>
#include "util.h"

HillClimber::HillClimber()
{
}

void HillClimber::valuesTable(HCInput &in)
{

    Alpha::init(false, in.a, in.b, in.k, in.mutbits);
    uint ovalue, binValue;

    double pow2tokm1 = Util::pow2tokm1(in.k);
    if(in.useGray){
        ovalue = Util::binaryToGray(pow2tokm1);
    } else {
        ovalue = pow2tokm1;
    }
    for(uint u=0; u<pow2tokm1+1; u++ ) {
        if (in.useGray) {
            binValue = Util::binaryToGray(u);
        } else {
            binValue = u;
        }
        Alpha alp(binValue);

        QString diff = Util::bits( ovalue ^ alp.value(), in.k);

        qDebug() << u << "\t" << alp.value() \
                 << "\t" << Util::str(alp.realValue()) \
                 << "\t" << Util::str(alp.fitness()) \
                 << "\t" << diff << "   " << diff.count('1');
        ovalue = alp.value();
    }

}

HCOutput& HillClimber::optimaze(HCInput &in)
{
    int fitnessCount = 0;

    Alpha::init(false, in.a, in.b, in.k, in.mutbits);
    qDebug() << "------------";

    Alpha alfa(in.start);
    Alpha finalAlfa( alfa.value());
    double finalFitness = finalAlfa.fitness();

    qDebug() << "start optimize in alfa: " << alfa.toString();

    for (int i=0; i < in.tmax; i++) {

        qDebug();
        qDebug() << "alfa:  " << alfa.toString();

        // generate neighborhood from alfa
        // std::vector<Alpha*> &neighbors = *(alfa.getNeighborsAll());
        std::vector<Alpha*> &neighbors = *(alfa.getNeighborsRandom(in.cmax));
        std::vector<Alpha*>::const_iterator it = neighbors.begin();
        Alpha bestNeighbor( (*it)->value());
        double bestNeighborFitness = bestNeighbor.fitness();
        fitnessCount++;
        while (++it != neighbors.end()) {
            fitnessCount++;
            double itFitness = (*it)->fitness();
            if ( bestNeighborFitness > itFitness) {
                bestNeighbor.setValue((*it)->value());
                bestNeighborFitness = itFitness;
            }
        }
        qDebug() << "best:  " << bestNeighbor.toString();


        //qDebug() << "solution: "<< bestNeighbor.checkSolution(bestNeighborFitness);
        //qDebug() << "solution: "<< bestNeighbor.checkSolution();



        if( bestNeighborFitness < finalFitness ) {
            finalFitness = bestNeighborFitness;
            finalAlfa = bestNeighbor;
            qDebug() << "final: " << finalAlfa.toString() << endl << "-------";


            //qDebug() << "solution: "<< bestNeighbor.checkSolution(bestNeighborFitness);
            //qDebug() << "solution: "<< bestNeighbor.checkSolution();
            if(bestNeighbor.checkSolution()) {
                qDebug() << "solution " << i;

                HCOutput out(true, finalAlfa, i+1, fitnessCount);
                return out;
            }
        }

        alfa.setValue( bestNeighbor.value());

    }
    HCOutput out(false, finalAlfa, in.tmax, fitnessCount);
    return out;
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
