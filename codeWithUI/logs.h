#ifndef LOGS_H
#define LOGS_H



#include "headset.h"

class Logs
{
  public:
    //Constructor/Destructor
    Logs();
    ~Logs() {};

    // show all information in logs
    void showAllInfoLogs();

    //Add info to a log
    void addToLogs(string entry);

  private:
  // store information (may have some problems, only can have one egg array)
    string logFileName;
};

#endif
