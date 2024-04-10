#include "mainwindow.h"
#include "mainoperation.h"
#include "logs.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    MainOperation* mOp = new MainOperation();

    mOp->addToLogs("\n\nNew Test\n");

    mOp->EEGAverage(1);
    mOp->EEGTreatment(1);
    mOp->EEGAverage(1);

    cout << mOp->getLogs() << endl;

    delete mOp;




    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
