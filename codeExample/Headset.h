#ifndef HEADSET_H
#define HEADSET_H

#include <string>
#include <ctime>

using namespace std;

class Headset
{
  public:
    // get
    bool getHeadsetStatu();

    // set
    void setHeadsetStatu();

  private:
  // store information (may have some problems, only can have one egg array)
    bool headsetStatu = false;
  
};

#endif
