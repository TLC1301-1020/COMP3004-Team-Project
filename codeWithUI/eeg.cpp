#include <iostream>
#include <iomanip>

#include "eeg.h"

EEG::EEG() {
    //Start the random seed, and set the minimum and maximum
    srandom(time(0));
    amplitudeMax = 20.0;
    amplitudeMin = 1.0;
    xMax = 10.0;
    xMin = -10.0;


    offset = 1;
}

double EEG::getFrequency() {
    //Generate a random number between the range of the frequency maximum and minimum and output it to the terminal
    uniform_real_distribution<double> unifAmp(amplitudeMin, amplitudeMax);
    uniform_real_distribution<double> unifX(xMin, xMax);
    default_random_engine re;

    double amplitude = unifAmp(re);
    double x = unifX(re);
    double brainFrequency = amplitude * sin(x * offset);
    return brainFrequency;
}

void EEG::createTreatmentHZ() {
    offset += 5;
}

