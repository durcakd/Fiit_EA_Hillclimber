#include "hillclimber.h"

#include <math.h>
#include <vector>

#include <QDebug>

HillClimber::HillClimber()
{

}


void HillClimber::optimaze()
{
    uint alfa = 5;
    uint tmax = 10;
    uint cmax = 5;

    double finalAlfa = alfa;
    double finalFitness = 80000; //alfa.fitness();


    qDebug() << "start optimize in alfa: " << alfa;

    for (int i=0; i < tmax; i++) {

        // generate neighborhood from alfa
        std::vector<double> neighbors; // = new std::vector<double>(); // alfa.getNeighbors(cmax);
        std::vector<double>::const_iterator it = neighbors.begin();
        double bestNeighbor = *it;
        double bestNeighborFitness = 5; //bestNeighbor.fitness();

        while (++it != neighbors.end()) {
            double itFitness = 5; //it->fitness();
            if ( bestNeighborFitness < itFitness) {
                alfa = *it;
                bestNeighborFitness = itFitness;
            }
        }

        double neighborFitness = 15; //bestNeighbor.fitnes();
        if( neighborFitness > finalFitness ) {
            finalFitness = neighborFitness;
            finalAlfa = bestNeighbor;
        }
        alfa = bestNeighbor;
    }
}

