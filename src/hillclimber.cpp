#include "hillclimber.h"

#include <math.h>
#include <vector>

#include <QDebug>
#include "util.h"

HillClimber::HillClimber()
{

}


void HillClimber::optimaze()
{
    uint tmax = 10;
    uint cmax = 8;
    Alpha::init(false, 3.0, 5.0, 3);

    double _rtbCoef = Util::rtbCoef(3.0, 5.0, 3);
    double _btrCoef = Util::btrCoef(3.0, 5.0, 3);

    //uint bv =  Util::realToBin(3.0, _rtbCoef, 4.5);
    //qDebug() << "bin valu  " << bv;
/*    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 3.0);
    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 3.25);
    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 3.5);
    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 3.75);
    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 4.0);
    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 4.25);
    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 4.5);
    qDebug() << "  " << Util::realToBin(3.0, _rtbCoef, 4.75);
*/
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 3.0);
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 3.25);
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 3.5);
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 3.75);
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 4.0);
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 4.25);
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 4.5);
    qDebug() << "  " << Util::realToBin(3.0, 5.0, 7, 4.75);


   /* qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 0);
    qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 1);
    qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 2);
    qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 3);
    qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 4);
    qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 5);
    qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 6);
    qDebug() << "   " << Util::binToReal( 3.0, _btrCoef, 7);*/


    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 0);
    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 1);
    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 2);
    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 3);
    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 4);
    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 5);
    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 6);
    qDebug() << "       " << Util::binToReal( 3.0,5.0, 7, 7);



    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 0));
    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 1));
    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 2));
    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 3));
    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 4));
    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 5));
    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 6));
    qDebug() << " <> " << Util::realToBin(3.0, 5.0, 7, Util::binToReal( 3.0,5.0, 7, 7));



    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 0));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 1));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 2));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 3));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 4));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 5));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 6));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 7));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 8));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 50));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 100));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 150));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 200));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 250));
    qDebug() << "    <**> " << Util::realToBin(-1.0, 1.0, 255, Util::binToReal( -1.0,1.0, 255, 255));

   /* double rv = Util::binToReal( 3.0, _btrCoef, bv);
    qDebug() << "rea valu  " << rv;

/*
    qDebug() << "------------";
    Alpha alfa(3.5);
    Alpha finalAlfa(alfa.value());
    double finalFitness = finalAlfa.fitness();

    qDebug() << "start optimize in alfa: " << alfa.value() <<  "   " << alfa.realValue();


    for (int i=0; i < tmax; i++) {

        // generate neighborhood from alfa
        std::vector<Alpha*> &neighbors = *(alfa.generateNeighbors(cmax));
        std::vector<Alpha*>::const_iterator it = neighbors.begin();
        Alpha bestNeighbor( (*it)->value());
        double bestNeighborFitness = bestNeighbor.fitness();

        while (++it != neighbors.end()) {
            double itFitness = (*it)->fitness();
            if ( bestNeighborFitness < itFitness) {
                bestNeighbor.setValue((*it)->value());
                bestNeighborFitness = itFitness;
            }
        }

        if( bestNeighborFitness > finalFitness ) {
            finalFitness = bestNeighborFitness;
            finalAlfa = bestNeighbor;
        }
        alfa.setValue( bestNeighbor.value());

    }
    */
}

