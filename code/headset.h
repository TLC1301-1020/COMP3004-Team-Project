#ifndef HEADSET_H
#define HEADSET_H

#include "eegarray.h"

class Headset
{
  public:
    //Constructor/Destructor
    Headset();
    ~Headset() {};

    // get
    bool getHeadsetStatus();

    // set
    void setHeadsetStatus(bool status);

    //check EEG
    int getEEGBaseline();

  private:
  // store information (may have some problems, only can have one egg array)
    bool headsetStatus = false;
    EEGArray eegs;

};

#endif
