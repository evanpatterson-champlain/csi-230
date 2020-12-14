/**
* @file analytic_functions.h
* @brief functions for analyzing data, using stats
* @author Evan Patterson
* @assignment Final Project
* @date 12/13/2020
*/
#ifndef ANALYTIC_FUNCTIONS_H
#define ANALYTIC_FUNCTIONS_H
#include<vector>
#include<cmath>
#include<string>
#include<tuple>





/**
* @brief get the mean of the data
* @date 12/13/2020
* @return mean, sum of all entries divided by number of entries
* @param data
*/
double calcMean(std::vector<double> v);


/**
* @brief get the standard deviation from the mean
* @date 12/13/2020
* @return population standard deviation
* @param data
* @param mean of the data, calculating it if you already have would me redundant and inefficient
*/
double popStandardDeviation(std::vector<double> vec, double mean);


/**
* @brief get the standard deviation, this is the version that uses Bessel's correction
* @date 12/13/2020
* @return sample standard deviation
* @param data
* @param mean of the data
*/
double sampleStandardDeviation(std::vector<double> vec, double mean);


/**
* @brief get the correlation between two sets of data, assumes this is a population, not a sample
* @date 12/13/2020
* @return the correlation between the data sets
* @param first data set
* @param second data set
*/
double pearsonCorrelation(std::vector<double> x, std::vector<double> y);


/**
* @brief get the median value, averages the two middle values if the size is divisible by two
* @date 12/13/2020
* @return the median value
* @param data to get the median from
*/
double getMedian(std::vector<double> data);


/**
* @brief get the first quartile, averages the two in the lower middle if the size is divisible by 4
* @date 12/13/2020
* @return the first quartile
* @param the data to get it from
*/
double getQ1(std::vector<double> data);


/**
* @brief get the third quartile, averages the two in the upper middle if the size is divisible by 4
* @date 12/13/2020
* @return the third quartile
* @param the data to get it from
*/
double getQ3(std::vector<double> data);


/**
* @brief get the minimum and four quartiles that represent and summarize the data
* @date 12/13/2020
* @return a tuple with minimum, Q1, median, Q3, maximum
* @param the vector of data
*/
std::tuple<double, double, double, double, double> getFiveNumberSummary(std::vector<double> data);


/**
* @brief display 5 number summary to the console, useful for debugging
* @date 12/13/2020
* @return void
* @param the tuple with the 5 number summary
* @param a character to seperate the numbers, meant to be a \t or \n
*/
void displayFiveNumberSummary(std::tuple<double, double, double, double, double> data, char seperator);


/**
* @brief Uses a common technique of using IQR to detect potential outliers
* finds potential outliers on the high end of the data, returns the cut off index
* @date 12/13/2020
* @return a 64 bit unsigned int, an index in the array if there are outliers, the size if there aren't any
* @param the vector of data to use to detect outliers in
*/
size_t indexOfOutliersTop(std::vector<double> data);


/**
* @brief Uses a common technique of using IQR to detect potential outliers
* finds potential outliers on the low end of the data, returns the cut off index
* @date 12/13/2020
* @return a 64 bit signed int, so that it can be equal to -1 if there are no outliers
* returns an index in the array if there are outliers
* @param the vector of data to use to detect outliers in
*/
int64_t indexOfOutliersBottom(std::vector<double> data);


#endif