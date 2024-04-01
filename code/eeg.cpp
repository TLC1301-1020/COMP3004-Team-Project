#include <iostream>
#include <iomanip>

#include "eeg.h"

EEG::EEG() {
    //Start the random seed, and set the minimum and maximum
    srand(time(0));
    frequencyMax = 200;
    frequencyMin = 20;
}

int EEG::getFrequency() {
    //Generate a random number between the range of the frequency maximum and minimum and output it to the terminal
    int brainFrequency = frequencyMin + (rand() % (frequencyMax - frequencyMin));
    return brainFrequency;
}

void EEG::createTreatmentHZ() {
    frequencyMax += 5;
    frequencyMin += 5;
}

