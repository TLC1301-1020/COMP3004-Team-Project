#ifndef EEG_H
#define EEG_H

#include <string>
#include <ctime>
#include <random>

using namespace std;

class EEG
{
  public:
    //Constructor/Destructor
    EEG();
    ~EEG() {};

    // calculate HZ for treatment
    void createTreatmentHZ();

    //get brainwave frequency
    int getFrequency();

    //

  private:
    //Frequency range
    int frequencyMax;
    int frequencyMin;

    // start time
    time_t startTime;

    // start time
    time_t endTime;

};

#endif
