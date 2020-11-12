/*
* @file logger.h
* @brief logger functions
* handles the decleration of 
* all logging functionality
* @author Evan Patterson
* @assignment 10.2
* @date 11/11/2020
*/

#ifndef LOGGER_H
#define LOGGER_H
#include<string>
#include<fstream>

// this function creates a discrete syslog message
// date: 11/11/2020
// returns a boolean indicating the message was written
// param1: string containing syslog message
// param2: ofstream reference, validation of this filename is expected
bool log(std::string msg, std::ofstream& logFile);

struct Logger{
    // global variable to store the program name
    static std::string globalProgramName;
    static std::string globalHostName;
};

#endif // !LOGGER_H