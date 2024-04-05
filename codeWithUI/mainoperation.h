#ifndef MAINOPERATE_H
#define MAINOPERATE_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>

#include "headset.h"
#include "logs.h"

class MainOperation
{
  public:
    //Constructor/Destructor
    MainOperation();
    ~MainOperation() {};

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

  //Run EEG function


  private:
    QTimer timer;

    int seconds;

};

#endif
