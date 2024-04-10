#include <iostream>
#include <iomanip>

#include "headset.h"

Headset::Headset() {
    eegs = new EEGArray();
    headsetStatus = true;
}

Headset::~Headset() {
    delete eegs;
}

int Headset::getEEGFrequency(int index) {
    EEG* temp = eegs->get(index);
    return temp->getFrequency();
}

int Headset::getEEGBaseline() {
    int average = 0;
    int total = 0;
    EEG* temp;

    for(int i = 0; i < 21; i++) {
        temp = eegs->get(i);
        total += temp->getFrequency();
    }

    average = total / 21;


    return average;
}

void Headset::getEEGAverages() {
    int average = 0;
    int total = 0;
    EEG* temp;
    string averageLog;

    for(int i = 0; i < 21; i++) {
        temp = eegs->get(i);
        for(int j = 0; j < 20; j++) {
            total += temp->getFrequency();
        }
        average = total / 20;
        averageLog += "EEG " + to_string(i+1) + " Average Frequency: " + to_string(average) + "\n";
        total = 0;
    }
    cout << averageLog << endl;
}


void Headset::applyTreatment(int index) {
    EEG* temp;
    temp = eegs->get(index);
    temp->createTreatmentHZ();
}


