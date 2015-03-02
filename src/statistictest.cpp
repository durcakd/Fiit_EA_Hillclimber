#include "statistictest.h"


#include <QDebug>

StatisticTest::StatisticTest()
{

}


void StatisticTest::simpleTest(const HCInput &in)
{
    srand(time(NULL));
    for (int i=0; i<in.testmax; i++) {

        HillClimber hillClimber;
        HCOutput out = hillClimber.optimaze(in);
        qDebug() << i << "\t" << out.isSolution \
                 << "\t" << out.fitnessCount \
                 << "\t" << out.tCount;

    }

}
