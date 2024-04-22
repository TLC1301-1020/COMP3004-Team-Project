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
    double getFrequency();
    double getTimer();

    //

  private:
    //Frequency range
    double amplitudeMax;
    double amplitudeMin;
    double xMax;
    double xMin;
    double offset;



    // start time
    time_t startTime;
    int timer = 500;

};

#endif
