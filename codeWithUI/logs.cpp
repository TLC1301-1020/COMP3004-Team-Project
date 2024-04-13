#include <cstdio>
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

string Logs::showAllInfoLogs() {
    stringstream logOutput;
    string temp;
    out.close();
    in.open("neuraset_logs.txt", istream::in);
    if(in.is_open()) {
        while(in.good()) {
            getline(in, temp);
            logOutput << temp << '\n';
        }
    }
    in.close();
    out.open("neuraset_logs.txt", ios::app);
    return logOutput.str();
}
