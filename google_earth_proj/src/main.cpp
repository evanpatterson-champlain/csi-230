/*
* @file main.cpp
* @breif google earth lab code
* @author Evan Patterson
* @assignment 10.2
* @date 11/11/2020
*/


#include<iostream>
#include<pwd.h>
#include<unistd.h>
#include<libgen.h>
#include"logger.h"

using namespace std;


// code for deliverable 1
// displays args for count and logFile
void deliverable1Code(int argc, char* argv[]){
    int opt{};
    bool countFlag{false};
    bool logFlag{false};
    int count;
    string logFile;
    bool optErr = true;
    while((opt = getopt(argc, argv, "k:l:")) != EOF){
        switch(opt)
        {
            case 'k':
            {
                countFlag = true;
                count = atoi(optarg);
                break;
            }
            case 'l':
            {
                logFlag = true;
                logFile = optarg;
                break;
            }
            default:
            {
                optErr = true;
                break;
            }
        }
    }

    cout << "log flag is " << logFlag << endl;
    cout << "kml flag is " << countFlag << endl;

    if(logFlag && countFlag){
        cout << "flags set\n";

        // redundant, but shown in the video
        if (logFile != "" && count != 0){
            optErr = false;
            cout << "count: " << count << endl;
            cout << "log: " << logFile << endl;
        }
        cout << "optErr: " << optErr << endl;

    }
    else{
        cout << "flags not set" << endl;
    }
}









int main(int argc, char* argv[]) {
    //Logger::globalProgramName = basename(argv[0]);
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string kmlFile;
    string logFileName;
    bool optErr = true;
    while((opt = getopt(argc, argv, "k:l:")) != EOF){
        switch(opt)
        {
            case 'k':
            {
                kmlFlag = true;
                kmlFile = optarg;
                break;
            }
            case 'l':
            {
                logFlag = true;
                logFileName = optarg;
                break;
            }
            default:
            {
                optErr = true;
                break;
            }
        }
    }

    cout << "log flag is " << logFlag << endl;
    cout << "kml flag is " << kmlFlag << endl;

    if(logFlag && kmlFlag){
        cout << "flags set\n";

        // redundant, but shown in the video
        if (logFileName != "" && kmlFile != ""){
            optErr = false;
            string message = "the kml file is: " + kmlFile + 
            "and the log file is" + logFileName + '\n';
            ofstream logFile;
            cout << message;
            log(message, logFile);
            logFile.close();
        }
        cout << "optErr: " << optErr << endl;
    }
    else{
        cout << "flags not set" << endl;
    }
    


    return 0;
}