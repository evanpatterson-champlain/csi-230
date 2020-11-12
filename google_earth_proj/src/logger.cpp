/*
* @file logger.cpp
* @brief logger function implementations
* all logging functionality
* @author Evan Patterson
* @date 11/11/2020
*/

#include"logger.h"
#include<unistd.h>

using namespace std;

// this function creates a discrete syslog message
// date: 11/11/2020
// returns a boolean indicating the message was written
// param1: string containing syslog message
// param2: ofstream reference, validation of this filename is expected
bool log(std::string msg, std::ofstream& logFile){
    string strTime;

    //get the time
    time_t logTime = time(NULL);
    strTime = ctime(&logTime);

    // time off the newLine
    int timeSize = strTime.size();

    if(timeSize){
        strTime[timeSize-1] = ' ';
    }

    pid_t pid = getpid();

    if(logFile){
        logFile << strTime << "" << "[" << pid << "]: " << msg << endl;
        return true;
    }
    else{
        return false;
    }

}