/**
* @file read_csv.cpp
* @brief functions used for reading data stored in a csv file
* @author Evan Patterson
* @assignment Final Project
* @date 12/13/2020
*/
#include"read_csv.h"
#include<fstream>
#include<iostream>



using namespace std;



/**
* @brief function for retrieving data from a csv file in the format: <column label, vector of data>
* @date 12/13/2020
* @return a series of columns
* @param the name of the file to get data from
* @param the expected number of rows of the data, detirmined ahead of time to reduce memory allocation time
*/
std::vector<std::pair<std::string, std::vector<double>>> csvLoadData(std::string fName, uint64_t expectedSize) {
    std::fstream fin;
    fin.open(fName);
    std::vector<std::pair<std::string, std::vector<double>>> data;
    
    uint64_t count = 0;
    if (fin.is_open()) {
        std::string line = "";

        // get first line
        if (getline(fin, line)) {

            string name = "";
            size_t curEntryIndex = 0;

            // loop through lines and get column names
            for (uint64_t i = 0; i < line.size(); i++) {
                char c = line[i];
                if (c == ',') {
                    data.push_back(make_pair(name, vector<double>()));
                    data[curEntryIndex].second.reserve(expectedSize);
                    curEntryIndex++;
                    name = "";
                }
                else {
                    name += c;
                }
            }

            // if that was not the last entry
            if (name != "") {
                data.push_back(make_pair(name, vector<double>()));
                data[curEntryIndex].second.reserve(expectedSize);
            }

            // loop through each line
            while (getline(fin, line)) {
                string curEntry = "";
                curEntryIndex = 0;
                for (uint64_t i = 0; i < line.size() && curEntryIndex < data.size(); i++) {
                    char c = line[i];
                    if (c == ',') {
                        data[curEntryIndex].second.push_back(stod(curEntry));
                        curEntryIndex++;
                        curEntry = "";
                    }
                    else {
                        curEntry += c;
                    }
                }

                // if there is another entry still, add it in
                if (curEntry != "" && curEntryIndex < data.size()) {
                    data[curEntryIndex].second.push_back(stod(curEntry));
                    curEntry = "";
                }

            }
        }
    }
    else {
        std::cout << "File didn't open, maybe the file name is wrong?\n";
        std::cin.get();
        exit(0);
    }
    return data;
}


/**
* @brief function for displaying data read from csv
* @date 12/13/2020
* @return void
* @param the data to display, names/labels and their corresponding columns
*/
void csvDisplayData(std::vector<std::pair<std::string, std::vector<double>>> data) {

    // loop through names
    for (size_t j = 0; j < data.size(); j++) {
        cout << data[j].first << '\t';
    }
    cout << '\n';

    // loop through data
    for (size_t i = 0; i < data[0].second.size(); i++) {
        for (size_t j = 0; j < data.size(); j++) {
            cout << data[j].second[i] << '\t';
        }
        cout << '\n';
    }
}


