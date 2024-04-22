#ifndef BATTERY_H
#define BATTERY_H

#include <string>
#include <ctime>

using namespace std;

class Battery
{
  public:
    Battery(int, double);

    int getId();
    double getBLvl();
    void setBLvl(double);

  private:
    int id;
    double batteryLvl;

};

#endif
