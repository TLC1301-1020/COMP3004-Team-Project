#include "mainwindow.h"
#include "headset.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    //Testing (not intended for final code)
    Headset headset = Headset();

    cout << headset.getEEGBaseline() << endl;
    headset.applyTreatment();
    cout << headset.getEEGBaseline() << endl;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
