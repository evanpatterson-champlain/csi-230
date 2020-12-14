/**
* @file read_csv.h
* @brief functions used for reading data stored in a csv file
* @author Evan Patterson
* @assignment Final Project
* @date 12/13/2020
*/
#ifndef READ_CSV_H
#define READ_CSV_H
#include<vector>
#include<string>
#include<utility>
#include<cstdint>


/**
* @brief function for retrieving data from a csv file in the format: <column label, vector of data>
* @date 12/13/2020
* @return a series of columns
* @param the name of the file to get data from
* @param the expected number of rows of the data, detirmined ahead of time to reduce memory allocation time
*/
std::vector<std::pair<std::string, std::vector<double>>> csvLoadData(std::string fName, uint64_t expectedSize);


/**
* @brief function for displaying data read from csv
* @date 12/13/2020
* @return void
* @param the data to display, names/labels and their corresponding columns
*/
void csvDisplayData(std::vector<std::pair<std::string, std::vector<double>>> data);



#endif // !READ_CSV_H