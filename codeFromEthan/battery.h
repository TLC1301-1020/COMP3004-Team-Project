#ifndef BATTERY_H
#define BATTERY_H

#include <string>
#include <ctime>

using namespace std;

class Battery
{
  public:
    Battery(int, double);

    // 10% battery warning
    void batteryWarning();

    // run out warning
    void batteryRunOutWarning();

    // full battery prompts
    void batteryFullPrompts();

    int getId();
    double getBLvl();
    void setBLvl(double);

  private:
    // battery max time
    time_t batteryMaxContinueTime = 10;

    // battery current time
    time_t batteryCurrentTime;

    int id;
    double batteryLvl;
};

#endif
