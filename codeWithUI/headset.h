#ifndef HEADSET_H
#define HEADSET_H

#include "eegarray.h"

class Headset
{
  public:
    //Constructor/Destructor
    Headset();
    ~Headset();

    // get
    bool getHeadsetStatus() {return headsetStatus;};

    // set
    void setHeadsetStatus(bool status);

    // get average of each EEG
    void getEEGAverages();

    // apply the treatment to each EEG location
    void applyTreatment();

    //check EEG
    int getEEGBaseline();

  private:
  // store information (may have some problems, only can have one egg array)
    bool headsetStatus = false;
    EEGArray *eegs;

};

#endif
