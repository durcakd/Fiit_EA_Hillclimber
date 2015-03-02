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

#include "statistictest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle( tr("EA") );

    QGridLayout *paramLA = createParamLayout();

    QVBoxLayout *buttonLA = new QVBoxLayout();
    QHBoxLayout *mainLA = new QHBoxLayout();

    QPushButton *runBasicTestPB = new QPushButton(tr("run test"));
    buttonLA->addWidget(runBasicTestPB);

    //mainLA->addItem(paramLA);
    mainLA->addLayout(buttonLA);


    mainLA->addLayout(paramLA);


    QWidget *widget = new QWidget;
    widget->setLayout(mainLA);
    setCentralWidget(widget);

    QObject::connect( runBasicTestPB, SIGNAL(clicked()),
                      this, SLOT(runBasicTest()));

}

void MainWindow::runBasicTest() {
    qDebug() << "SLOT run basic test";
    StatisticTest statisticTest;
    statisticTest.simpleTest();
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
    QLabel *useGrayL = new QLabel(tr("Gray code"));
    QLabel *tmaxL = new QLabel(tr("t max"));
    QLabel *cmaxL = new QLabel(tr("c max"));
    QLabel *mutbitsL = new QLabel(tr("mutbits"));
    QLabel *kL = new QLabel(tr("k"));
    QLabel *startL = new QLabel(tr("start"));
    QLabel *aL = new QLabel(tr("a"));
    QLabel *bL = new QLabel(tr("b"));
    QLabel *testMaxL = new QLabel(tr("test max"));

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
    paramLayout->addWidget( useGrayCB,   0,1 );
    paramLayout->addWidget( tmaxLE,      1,1 );
    paramLayout->addWidget( cmaxLE,      2,1 );
    paramLayout->addWidget( mutbitsLE,   3,1 );
    paramLayout->addWidget( kLE,         4,1 );
    paramLayout->addWidget( startLE,     5,1 );
    paramLayout->addWidget( aLE,         6,1 );
    paramLayout->addWidget( bLE,         7,1 );
    paramLayout->addWidget( testMaxLE,   8,1 );

    return paramLayout;
}


