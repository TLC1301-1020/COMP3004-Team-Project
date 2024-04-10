#include "logs.h"

Logs::Logs() {
    ofstream LogFile(logFileName);
    logFileName = "neuraset_logs.txt";
    out.open(logFileName, ios::app);
    in.open(logFileName, ifstream::in);

}

Logs::~Logs() {
    out.close();
    in.close();
}

void Logs::addToLogs(string entry) {
    //Open text file

    //Write new entry to the log file
    out << entry;

}

string Logs::showAllInfoLogs() {
    string logContents;
    string temp;

    in >> logContents;

    return logContents;
}
