/**
* @file main.cpp
* @brief google earth lab code
* @author Evan Patterson
* @assignment 10.2
* @date 11/11/2020
*/
#include<iostream>
#include<pwd.h>
#include<unistd.h>
#include<libgen.h>
#include"logger.h"
#include"earth_utils.h"

using namespace std;


// code for deliverable 1
// displays args for count and logFile
// saving it just in case I need to
// returns whether there was an error
// param1: number of arguments
// param2: list of arguments as cstrings
int deliverable1Code(int argc, char* argv[]){
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

        // this if is redundant, but shown in the video
        if (logFile != "" && count != 0){
            optErr = false;
            cout << "count: " << count << endl;
            cout << "log: " << logFile << endl;
        }
        cout << "optErr: " << optErr << endl;

    }
    else{
        optErr = true;
        cout << "flags not set" << endl;
    }
    return optErr;
}








// main function
// returns whether there was an error
// param1: number of arguments
// param2: list of arguments as cstrings
int main(int argc, char* argv[]) {
    //return deliverable1Code(argc, argv);
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
        if (logFileName != "" && kmlFile != ""){
            optErr = false;
            string message = "the kml file is: " + kmlFile + 
            " and the log file is: " + logFileName + '\n';
            ofstream logFile;
            logFile.open(logFileName);
            cout << message;
            log(message, logFile, string(basename(argv[0])));
            logFile.close();
            ifstream fin;
            fin.open(kmlFile);
            if(fin.is_open()){
                int recordCount = parseCSV(fin, kmlFile);
                if(recordCount){
                    cout << recordCount << " records processed\n";
                }
                else{
                    optErr = true;
                }
            }
            else{
                cout << "file did not open\n";
                optErr = true;
            }
        }
        cout << "optErr: " << optErr << endl;
    }
    else{
        cout << "flags not set" << endl;
        return 1;
    }
    


    return 0;
}