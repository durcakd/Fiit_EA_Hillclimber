#include "statistictest.h"


#include <QDebug>

StatisticTest::StatisticTest()
{

}


void StatisticTest::simpleTest()
{
    int tmax = 100;
    int cmax = 4;
    int mutbits = 1;
    bool useGray = true;
    HCInput input(tmax, cmax, mutbits, useGray);
    HillClimber hillClimber;
    hillClimber.optimaze(input);

}
