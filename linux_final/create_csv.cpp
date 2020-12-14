/**
* @file create_csv.cpp
* @brief functions for creating a csv file that has data with certain characteristics
* @author Evan Patterson
* @assignment Final Project
* @date 12/13/2020
*/
#include"create_csv.h"
#include<fstream>
//also include boost

using namespace std;


/**
* @brief function that creates a column of data with certain qualities
* @date 12/13/2020
* @return a vector of string that is: name, number 1, number 2, etc.
* @param the name of the data
* @param the mean of the data
* @param the standard devation of the data
*/
std::vector<std::string> createColumn(std::string name, double mean, double standardDeviation) {
	// put boost code here
	return std::vector<std::string>();
}


/**
* @brief function that writes to a csv file whatever series of columns you provide it
* @date 12/13/2020
* @return whether the file creation was seccessful
* @param the name of the file you want to create
* @param the data to write
*/
bool createCSV(std::string fName, std::vector<std::vector<std::string>> columns) {
	ofstream fout;
	fout.open(fName);

	if (fout.is_open()) {

		size_t shortestColumnSize = 0xFFFFFFFFFFFFFFFF; // max unsigned int value
		for (size_t i = 0; i < columns.size(); i++) {
			if (columns[i].size() < shortestColumnSize) {
				shortestColumnSize = columns[i].size();
			}
		}

		for (size_t i = 0; i < shortestColumnSize; i++) {
			for (size_t j = 0; j < columns.size(); j++) {
				fout << columns[j][i] << ',';
			}
			fout << '\n';
		}

		return true;
	}
	else {
		return false;
	}
}


/**
* @brief a function that combines the previous functions into an easier to use version
* creates the data, and then writes to a file
* @date 12/13/2020
* @return whether file creation was successful
* @param file name to write to
* @param the information to base the data on, the tuple is the <label, mean, standard deviation>
*/
bool createCsvFromInfo(std::string fName, std::vector<std::tuple<std::string, double, double>> info) {
	vector<vector<string>> data;
	data.reserve(info.size());
	for (size_t i = 0; i < info.size(); i++) {
		data.push_back(createColumn(get<0>(info[i]), get<1>(info[i]), get<2>(info[i])));
	}
	return createCSV(fName, data);
}

