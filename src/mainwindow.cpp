#include "mainwindow.h"

#include <QTextEdit>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

#include <QFileInfo>
#include <QFile>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QVector>

#include "statistictest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle( tr("EA") );

    QGridLayout *paramLA = createParamLayout();

    QVBoxLayout *buttonLA = new QVBoxLayout();
    QHBoxLayout *mainLA = new QHBoxLayout();

    runBasicTestPB = new QPushButton(tr("run test"));
    buttonLA->addLayout(paramLA);
    buttonLA->addWidget(runBasicTestPB);


    plotView = new QCustomPlot();
    plotView->setMinimumWidth(500);


    mainLA->addLayout(buttonLA);
    mainLA->addWidget(plotView);


    QWidget *widget = new QWidget;
    widget->setLayout(mainLA);
    setCentralWidget(widget);

    QObject::connect( runBasicTestPB, SIGNAL(clicked()),
                      this, SLOT(runBasicTest()));

    plotBasic();
    tested = false;

}

void MainWindow::runBasicTest() {
    qDebug() << "SLOT run basic test";
    StatisticTest statisticTest;
    input = getParams();
    output = statisticTest.simpleTest(input);
    tested = true;
    //plot1Run();
    //plotMultiFitnes();
    plotMultiFitnessCalls();
}


void MainWindow::plotBasic() {
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
        x[i] = i/50.0 - 1; // x goes from -1 to 1
        y[i] = (x[i]+0.01)*(x[i]+0.01); // let's plot a quadratic function
    }
    // create graph and assign data to it:
    plotView->addGraph();
    plotView->graph(0)->setData(x,y);
    // give the axes some labels:
    plotView->xAxis->setLabel("x");
    plotView->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    plotView->yAxis->setRange(0, 1);
    plotView->xAxis->setRange(-1, 1);
    plotView->replot();
}

void MainWindow::plot1Run() {
    if (tested) {
        qDebug() << "SLOT plot1Run";
        plotView->raise();

        int tmax = input.tmax+1;
        QVector<double> x(tmax);
        for(int i=0; i<tmax; i++) { x[i]=i;}

        plotView->addGraph();
        plotView->graph(0)->setData(x,output.vfinalAlphaF);
        plotView->graph(0)->setPen(QPen(Qt::red)); // line color blue for first graph
        plotView->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 80))); // first graph will be filled with translucent blue

        plotView->addGraph();
        plotView->graph(1)->setData(x,output.vAlphaF);
        plotView->graph(1)->setPen(QPen(Qt::blue));

        plotView->xAxis->setLabel("x");
        plotView->yAxis->setLabel("y");

        plotView->xAxis->setRange(0, tmax+2);
        plotView->yAxis->setRange(-0.1, 1.0);
        plotView->replot();

    }
}

void MainWindow::plotMultiFitnes() {
    if (tested) {
        qDebug() << "SLOT plotMultiFitness";
        plotView->raise();

        QVector<double> vfitness = output.testFitness;
        if(sortCB->isChecked()) {qSort(vfitness);}

        int tmax = input.testmax;
        QVector<double> x(tmax);
        for(int i=0; i<tmax; i++) { x[i]=i;}

        plotView->addGraph();
        plotView->graph(0)->setData(x,vfitness);

        plotView->xAxis->setLabel("x");
        plotView->yAxis->setLabel("y");
        plotView->yAxis->setScaleType(QCPAxis::stLogarithmic);

        plotView->xAxis->setRange(0, tmax);
        plotView->yAxis->setRange(-0.000001, 0.015);
        plotView->replot();
    }
}

void MainWindow::plotMultiFitnessCalls() {
    if (tested) {
        qDebug() << "SLOT plot multi fitness calls";
        plotView->raise();

        QVector<double> vfitness = output.testFitnessCalls;
        if(sortCB->isChecked()) {qSort(vfitness);}

        int tmax = input.testmax;
        QVector<double> x(tmax);
        for(int i=0; i<tmax; i++) { x[i]=i;}

        plotView->addGraph();
        plotView->graph(0)->setData(x,vfitness);

        plotView->xAxis->setLabel("x");
        plotView->yAxis->setLabel("y");

        plotView->xAxis->setRange(0, tmax);
        plotView->yAxis->setRange(-0.0, input.k*input.tmax);
        plotView->replot();
    }

}



QGridLayout *MainWindow::createParamLayout() {
    useGrayCB    = new QCheckBox();
    useGrayCB->setChecked(C_USEGRAY);
    tmaxLE       = new QLineEdit(QString::number( C_TMAX ));
    cmaxLE       = new QLineEdit(QString::number( C_CMAX ));
    mutbitsLE    = new QLineEdit(QString::number( C_MUTBITS ));
    kLE          = new QLineEdit(QString::number( C_K ));
    startLE      = new QLineEdit(QString::number( C_START ));
    aLE          = new QLineEdit(QString::number( C_A ));
    bLE          = new QLineEdit(QString::number( C_B ));
    testMaxLE    = new QLineEdit(QString::number( C_TESTMAX ));
    sortCB          = new QCheckBox();
    allNeighborsCB  = new QCheckBox();
    QLabel *useGrayL = new QLabel(tr("Gray code"));
    QLabel *tmaxL = new QLabel(tr("t max"));
    QLabel *cmaxL = new QLabel(tr("c max"));
    QLabel *mutbitsL = new QLabel(tr("mutbits"));
    QLabel *kL = new QLabel(tr("k"));
    QLabel *startL = new QLabel(tr("start"));
    QLabel *aL = new QLabel(tr("a"));
    QLabel *bL = new QLabel(tr("b"));
    QLabel *testMaxL = new QLabel(tr("test max"));
    QLabel *sortL = new QLabel(tr("sort"));
    QLabel *allNeighborsL = new QLabel(tr("all neighbors"));

    QGridLayout *paramLayout = new QGridLayout();

    paramLayout->addWidget( useGrayL,  0,0 );
    paramLayout->addWidget( tmaxL,     1,0 );
    paramLayout->addWidget( cmaxL,     2,0 );
    paramLayout->addWidget( mutbitsL,  3,0 );
    paramLayout->addWidget( kL,        4,0 );
    paramLayout->addWidget( startL,    5,0 );
    paramLayout->addWidget( aL,        6,0 );
    paramLayout->addWidget( bL,        7,0 );
    paramLayout->addWidget( testMaxL,  8,0 );
    paramLayout->addWidget( sortL,  9,0 );
    paramLayout->addWidget( allNeighborsL,  10,0 );
    paramLayout->addWidget( useGrayCB,   0,1 );
    paramLayout->addWidget( tmaxLE,      1,1 );
    paramLayout->addWidget( cmaxLE,      2,1 );
    paramLayout->addWidget( mutbitsLE,   3,1 );
    paramLayout->addWidget( kLE,         4,1 );
    paramLayout->addWidget( startLE,     5,1 );
    paramLayout->addWidget( aLE,         6,1 );
    paramLayout->addWidget( bLE,         7,1 );
    paramLayout->addWidget( testMaxLE,   8,1 );
    paramLayout->addWidget( sortCB,      9,1 );
    paramLayout->addWidget( allNeighborsCB,  10,1 );


    QIntValidator *validatorInt     = new QIntValidator(1, 1000000, this);
    QDoubleValidator *validatorDouble = new QDoubleValidator(-1000000.0, 1000000.1, 2);

    tmaxLE->setValidator(validatorInt);
    cmaxLE->setValidator(validatorInt);
    mutbitsLE->setValidator(validatorInt);
    kLE->setValidator(validatorInt);
    startLE->setValidator(validatorDouble);
    aLE->setValidator(validatorDouble);
    bLE->setValidator(validatorDouble);
    testMaxLE->setValidator(validatorInt);


    return paramLayout;
}

HCInput MainWindow::getParams() {
    if ( tmaxLE->hasAcceptableInput() &&
         cmaxLE->hasAcceptableInput() &&
         mutbitsLE->hasAcceptableInput() &&
         kLE->hasAcceptableInput() &&
         startLE->hasAcceptableInput() &&
         aLE->hasAcceptableInput() &&
         bLE->hasAcceptableInput() &&
         testMaxLE->hasAcceptableInput()) {

        return HCInput(tmaxLE->text().toInt(),
                       cmaxLE->text().toInt(),
                       useGrayCB->isChecked(),
                       mutbitsLE->text().toInt(),
                       kLE->text().toInt(),
                       startLE->text().toDouble(),
                       aLE->text().toDouble(),
                       bLE->text().toDouble(),
                       testMaxLE->text().toInt(),
                       allNeighborsCB->isChecked());

    }
    qDebug() << "WARNING: not valid input parameter, who knows which one :)";
    return HCInput();
}
