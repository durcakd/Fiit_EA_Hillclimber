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


    mainLA->addLayout(buttonLA);
    mainLA->addWidget(plotView);


    QWidget *widget = new QWidget;
    widget->setLayout(mainLA);
    setCentralWidget(widget);

    QObject::connect( runBasicTestPB, SIGNAL(clicked()),
                      this, SLOT(runBasicTest()));

}

void MainWindow::runBasicTest() {
    qDebug() << "SLOT run basic test";
    //runBasicTestPB->setEnabled(false);
    //startB->setText(tr("Running"));

    StatisticTest statisticTest;
    statisticTest.simpleTest(getParams());
    //runBasicTestPB->setEnabled(true);


}

//void  SudokuDialog::threadDone(){
//    runBasicTestPB->setEnabled( true );
//    startB->setText(tr("Run test"));
//}


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
                       testMaxLE->text().toInt());

    }
    qDebug() << "WARNING: not valid input parameter, who knows which one :)";
    return HCInput();
}
