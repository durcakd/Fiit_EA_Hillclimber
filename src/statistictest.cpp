#include "statistictest.h"


#include <QDebug>

StatisticTest::StatisticTest()
{

}


void StatisticTest::simpleTest()
{
    srand(time(NULL));
    int testmax = 50;

    int tmax = 100;
    int cmax = 4;
    int mutbits = 1;
    bool useGray = true;
    HCInput input(tmax, cmax, mutbits, useGray);


    for (int i=0; i<testmax; i++) {

        HillClimber hillClimber;
        HCOutput out = hillClimber.optimaze(input);
        qDebug() << i << "\t" << out.isSolution \
                 << "\t" << out.fitnessCount \
                 << "\t" << out.tCount;

    }

}
