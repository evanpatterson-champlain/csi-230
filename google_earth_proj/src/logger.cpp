/*
* @file logger.cpp
* @brief logger function implementations
* all logging functionality
* @author Evan Patterson
* @date 11/11/2020
*/

#include"logger.h"
#include<unistd.h>
#include<iostream>

using namespace std;



// this function creates a discrete syslog message
// date: 11/11/2020
// returns a boolean indicating the message was written
// param1: string containing syslog message
// param2: ofstream reference, validation of this filename is expected
bool log(std::string msg, std::ofstream& logFile, std::string programName){
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
    
    char hostName[1024];
    hostName[1023] = '\0';
    gethostname(hostName, 1023);

    if(logFile){
        logFile << strTime << hostName << ' ' << programName << '[' << pid << "]: " << msg << '\n';
        return true;
    }
    else{
        return false;
    }

}