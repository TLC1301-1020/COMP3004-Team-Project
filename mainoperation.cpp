#include <iostream>
#include <iomanip>
#include <sstream>
#include <unistd.h>

#include "mainoperation.h"

MainOperation::MainOperation() {
    headset = new Headset();
    log = new Logs();
    battery = new Battery(1, 79);

}

MainOperation::~MainOperation() {
    delete log;
    delete headset;
    delete battery;
}


double MainOperation::EEGBaseline() {
    double total = 0;
    double average;
    for(int i = 0; i < 21; i++) {
        total += headset->getEEGFrequency(i);
    }
    average = total / 21;
//    usleep(100);
    stringstream newLog;
    newLog << "EEG Baseline: " << average << "\n";
    log->addToLogs(newLog.str());
    return average;
}

double MainOperation::EEGAverage(int index) {
    double total = 0.0;
    double average;
    for(int i = 0; i < 60; i++) {
        total += headset->getEEGFrequency(index);
//        usleep(100);
    }
    average = total / 60;
    stringstream newLog;
    newLog << "EEG: " << index << " average: " << average << "\n";
    log->addToLogs(newLog.str());
    return average;
}

void MainOperation::EEGTreatment(int index) {
    for(int i = 0; i < 16; i++) {
        headset->applyTreatment(index);
//        usleep(62 * 1000);

    }
    stringstream newLog;
    newLog << "Treatment applied to EEG " << index << "\n";
    log->addToLogs(newLog.str());

}


void MainOperation::getLogs() {
    log->showAllInfoLogs();
}


void MainOperation::addToLogs(string entry) {
    log->addToLogs(entry);
}

double MainOperation::getBattery() {
    return battery->getBLvl();
}

void MainOperation::setBattery(double bLevel) {
    battery->setBLvl(bLevel);
}

// power get and set
bool MainOperation::getPowerStatu(){
    return powerStatu;
}

void MainOperation::setPowerStatu(bool powerSingal) {
    powerStatu = powerSingal;
}

// time get and set
int MainOperation::getTime(){
    return time;
}

void MainOperation::setTime(int timer) {
    time = timer;
}



