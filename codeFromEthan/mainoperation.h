#ifndef MAINOPERATE_H
#define MAINOPERATE_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include <QThread>

#include "headset.h"
#include "logs.h"

class MainOperation
{
  public:
        //Constructor/Destructor
        MainOperation();
        ~MainOperation();

      // turn off
      void turnOff();

      // turn on
      void turnOn();

      //new session
      void newSession();

      // session log
      void sessionLog();

      //Time and date
      void timeAndDate();

      //Run EEG treatment
      void EEGTreatment(int i);

    void startTimer();

    int singleTreatment(int index);

    //Get the EEG Baseline
    int EEGBaseline();

    //Get the average of one EEG location
    int EEGAverage(int index);

    //Get the logs
    string getLogs();

    //Add to logs
    void addToLogs(string entry);

  private:
    Headset* headset;
    Logs* log;
    int seconds;
    int battery;


};

#endif
