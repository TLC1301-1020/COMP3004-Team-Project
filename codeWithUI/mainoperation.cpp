#include <iostream>
#include <iomanip>
#include <sstream>
#include <unistd.h>

#include "mainoperation.h"

MainOperation::MainOperation() {
    headset = new Headset();
    log = new Logs();

}

MainOperation::~MainOperation() {
    delete timer;
    delete thread;
    delete log;
    delete headset;
}


int MainOperation::EEGBaseline() {
    int total = 0;
    int average;
    for(int i = 0; i < 21; i++) {
        total += headset->getEEGFrequency(i);
    }
    average = total / 21;
    usleep(1000000);
    return average;
}

int MainOperation::EEGAverage(int index) {
    int total = 0;
    int average;
    for(int i = 0; i < 60; i++) {
        total += headset->getEEGFrequency(index);
        usleep(100000);
    }
    average = total / 60;
    stringstream newLog;
    newLog << "EEG: " << index << " average: " << average << endl;
    log->addToLogs(newLog.str());
    return average;
}

void MainOperation::EEGTreatment(int i) {
    for(int i = 0; i < 16; i++) {
        headset->applyTreatment(i);
        cout << headset->getEEGFrequency(i) << endl;
        usleep(62 * 1000);

    }
    stringstream newLog;
    newLog << "Treatment applied to EEG " << i << endl;
    log->addToLogs(newLog.str());

}


string MainOperation::getLogs() {
    return log->showAllInfoLogs();
}


void MainOperation::addToLogs(string entry) {
    log->addToLogs(entry);
}


