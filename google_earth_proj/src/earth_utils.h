/**
* @file earth_utils.h
* @brief handles parsing a lat/long csv file
* and conversion of that file to kml
* @author Evan Patterson
* @assignment 10.2
* @date 11/11/2020
*/

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include<string>
#include<fstream>

/**
 * @brief process a country csv file
 * @date 11/11/2020
 * @return number of records
 * @param inFile ifstream to an opened and validated csv file
 * @param kmlFileName name of kml file
*/
int parseCSV(std::ifstream& inFile, const std::string& kmlFileName);



#endif // !EARTH_UTILS_H