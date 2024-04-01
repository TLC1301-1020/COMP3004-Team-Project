#ifndef LOGS_H
#define LOGS_H

#include <string>
#include <ctime>

#include "EEGArray.h"

using namespace std;

class Logs
{
  public:
    // create new eeg array (may be use new to create a new array)
    void createNewEEGArray();

    // show all information in logs
    void showAllInfoLogs();

  private:
  // store information (may have some problems, only can have one egg array)
    EEGArray eegs;
};

#endif
