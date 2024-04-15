#include <cstdio>
#include <QString>
#include "logs.h"

Logs::Logs() {
    char logFileName[] = "neuraset_logs.txt";
    out.open(logFileName, ios::app);
}

Logs::~Logs() {
    out.close();
    in.close();
}

void Logs::addToLogs(string entry) {

    //Write new entry to the log file
    out << entry;

}

void Logs::showAllInfoLogs() {
    out.close();
    out.open("neuraset_logs.txt", ios::app);
}
