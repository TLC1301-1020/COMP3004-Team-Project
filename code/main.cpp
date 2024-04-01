#include "mainwindow.h"
#include "eegarray.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    //Testing (not intended for final code)
    EEG testEeg = EEG();
    EEG testEeg2 = EEG();
    int freq = testEeg.getFrequency();
    cout << freq << endl;
    cout << testEeg2.getFrequency() << endl;
    EEGArray test;
    testEeg.createTreatmentHZ();
    cout << testEeg.getFrequency() << endl;
    cout << testEeg2.getFrequency() << endl;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
