#ifndef MAINOPERATE_H
#define MAINOPERATE_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include <QThread>

#include "headset.h"
#include "logs.h"
#include "battery.h"

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
    double EEGBaseline();

    //Get the average of one EEG location
    double EEGAverage(int index);

    //Get the logs
    void getLogs();

    //Add to logs
    void addToLogs(string entry);

    //Get battery level
    double getBattery();

    //Set battery level
    void setBattery(double bLevel);



    // light info
    // get
    bool getContactLight();
    bool getTreatmentSignalLight ();
    bool getContactLostLight();

    //set
    void setContactLight(bool contactLightStatu);
    void setTreatmentSignalLight(bool treatmentSignalStatu);
    void setContactLostLight(bool contactLostLightStatu);


    // set power statu
    bool getPowerStatu();
    void setPowerStatu(bool powerSingal);


    // timer
    // get and set
    int getTime();
    void setTime(int timer);

  private:
    // power
    bool powerStatu = false;

    Headset* headset;
    Logs* log;
    Battery* battery;
    int seconds;

    bool contactLight = false;
    bool treatmentSignalLight = false;
    bool contactLostLight = false;

   int time = 1000;


};

#endif
