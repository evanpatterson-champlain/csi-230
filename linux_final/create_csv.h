/**
* @file create_csv.h
* @brief functions for creating a csv file that has data with certain characteristics
* @author Evan Patterson
* @assignment Final Project
* @date 12/13/2020
*/
#ifndef CREATE_CSV_H
#include<vector>
#include<string>
#include<tuple>


/**
* @brief function that creates a column of data with certain qualities
* @date 12/13/2020
* @return a vector of string that is: name, number 1, number 2, etc.
* @param the name of the data
* @param the mean of the data
* @param the standard devation of the data
*/
std::vector<std::string> createColumn(std::string name, double mean, double standardDeviation);


/**
* @brief function that writes to a csv file whatever series of columns you provide it
* @date 12/13/2020
* @return whether the file creation was seccessful
* @param the name of the file you want to create
* @param the data to write
*/
bool createCSV(std::string fName, std::vector<std::string> columns);


/**
* @brief a function that combines the previous functions into an easier to use version
* creates the data, and then writes to a file
* @date 12/13/2020
* @return whether file creation was successful
* @param file name to write to
* @param the information to base the data on, the tuple is the <label, mean, standard deviation>
*/
bool createCsvFromInfo(std::string fName, std::vector<std::tuple<std::string, double, double>> info);


#endif // !CREATE_CSV_H