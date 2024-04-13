#include <iostream>
#include <iomanip>

#include "battery.h"

Battery::Battery(int id, double batteryLvl) {
    this->id = id;
    this->batteryLvl = batteryLvl;
}


// getters
int Battery::getId() { return id; }
double Battery::getBLvl() { return batteryLvl; }


// setters
void Battery::setBLvl(double newLvl) { batteryLvl = newLvl; }
