#ifndef EEG_H
#define EEG_H

#include <string>
#include <ctime>

using namespace std;

class EEG
{
  public:
    //Constructor/Destructor
    EEG();
    ~EEG() {};

    // calculate HZ for treatment
    void createTreatmentHZ();

    // create log
    string createEEGLog();

    //start
    void startLog();

    //pause
    void pauseLog();

    //stop
    void pauseStop();

  private:
    // input value
    int inputHz;

    // result value
    int resultHZ;

    // start time
    time_t startTime;

    // start time
    time_t endTime;

};

#endif
