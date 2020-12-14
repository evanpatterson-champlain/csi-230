/**
* @file analytic_functions.cpp
* @brief implementations of the functions for analyzing data
* @author Evan Patterson
* @assignment Final Project
* @date 12/13/2020
*/
#include"analytic_functions.h"
#include<iostream>
#include<algorithm>



using namespace std;



/**
* @brief function for displaying error when asserting
* @date 12/13/2020
* @return always false, so the assert fails
* @param the message to print to the console when the assert fails
*/
bool displayAssertError(const string& s) {
	cout << s;
	return false;
}


/**
* @brief get the mean of the data
* @date 12/13/2020
* @return mean, sum of all entries divided by number of entries
* @param data
*/
double calcMean(vector<double> v) {
	double ave = 0.0;
	for (vector<double>::iterator it = v.begin(); it != v.end(); ++it) {
		ave += *it;
	}
	return ave / v.size();
}


/**
* @brief get the standard deviation from the mean
* @date 12/13/2020
* @return population standard deviation
* @param data
* @param mean of the data, calculating it if you already have would me redundant and inefficient
*/
double popStandardDeviation(vector<double> vec, double mean) {
	double sum = 0.0;
	for (size_t i = 0; i < vec.size(); i++) {
		double entry = vec[i] - mean;
		sum += entry * entry;
	}
	sum /= vec.size();
	return sqrt(sum);
}


/**
* @brief get the standard deviation, this is the version that uses Bessel's correction
* @date 12/13/2020
* @return sample standard deviation
* @param data
* @param mean of the data
*/
double sampleStandardDeviation(vector<double> vec, double mean) {
	_ASSERT(vec.size() > 1 || displayAssertError("Size can't be 1 or 0"));
	double sum = 0.0;
	for (size_t i = 0; i < vec.size(); i++) {
		double entry = vec[i] - mean;
		sum += entry * entry;
	}
	sum /= (vec.size()-1);
	return sqrt(sum);
}


/**
* @brief get the correlation between two sets of data, assumes this is a population, not a sample
* @date 12/13/2020
* @return the correlation between the data sets
* @param first data set
* @param second data set
*/
double pearsonCorrelation(vector<double> x, vector<double> y) {
	_ASSERT(x.size() == y.size() || displayAssertError("Sizes must match"));
	_ASSERT(x.size() > 1 || displayAssertError("Sizes can't be 1 or 0"));

	double aveX = calcMean(x);
	double aveY = calcMean(y);

	cout << "ave x: " << aveX << endl;
	cout << "ave y: " << aveY << endl;

	double stdDevX = popStandardDeviation(x, aveX);
	double stdDevY = popStandardDeviation(y, aveY);

	double sum = 0.0;
	for (size_t i = 0; i < x.size(); i++) {
		double xi = (x[i] - aveX) / stdDevX;
		double yi = (y[i] - aveY) / stdDevY;
		sum += xi * yi;
	}

	sum /= x.size();
	return sum;
}


/**
* @brief get the median value, averages the two middle values if the size is divisible by two
* this version assumes that the data is already sorted so is only used by other functions
* @date 12/13/2020
* @return the median value
* @param data to get the median from
*/
double getMedianSorted(const vector<double>& data) {
	size_t size = data.size();
	if (size == 0) {
		return 0.0;
	}

	if (size % 2 == 0) {
		size_t half = size / 2;
		double median = data[half];
		median += data[half - 1];
		return median / 2.0;
	}
	else {
		return data[size / 2];
	}
}


/**
* @brief get the first quartile, averages the two in the lower middle if the size is divisible by 4
* this version assumes that the data is already sorted so is only used by other functions
* @date 12/13/2020
* @return the first quartile
* @param the data to get it from
*/
double getQ1Sorted(const vector<double>& data) {
	size_t size = data.size();
	if (size == 0) {
		return 0.0;
	}

	if (size % 4 == 0) {
		size_t midpoint = size / 4;
		double median = data[midpoint];
		median += data[midpoint - 1];

		cout << "ave1: " << data[midpoint] << endl;
		cout << "ave2: " << data[midpoint-1] << endl;

		return median / 2.0;
	}
	else {
		return data[size / 4];
	}
}


/**
* @brief get the third quartile, averages the two in the upper middle if the size is divisible by 4
* this version assumes that the data is already sorted so is only used by other functions
* @date 12/13/2020
* @return the third quartile
* @param the data to get it from
*/
double getQ3Sorted(const vector<double>& data) {
	size_t size = data.size();
	if (size == 0) {
		return 0.0;
	}

	if (size % 4 == 0) {
		size_t midpoint = (size * 3) / 4;
		double median = data[midpoint];
		median += data[midpoint - 1];
		return median / 2.0;
	}
	else {
		return data[(size * 3) / 4];
	}
}


/**
* @brief get the median value, averages the two middle values if the size is divisible by two
* @date 12/13/2020
* @return the median value
* @param data to get the median from
*/
double getMedian(vector<double> data) {
	sort(data.begin(), data.end());
	return getMedianSorted(data);
}


/**
* @brief get the first quartile, averages the two in the lower middle if the size is divisible by 4
* @date 12/13/2020
* @return the first quartile
* @param the data to get it from
*/
double getQ1(vector<double> data) {
	sort(data.begin(), data.end());
	return getQ1Sorted(data);
}


/**
* @brief get the third quartile, averages the two in the upper middle if the size is divisible by 4
* @date 12/13/2020
* @return the third quartile
* @param the data to get it from
*/
double getQ3(vector<double> data) {
	sort(data.begin(), data.end());
	return getQ3Sorted(data);
}


/**
* @brief get the minimum and four quartiles that represent and summarize the data
* @date 12/13/2020
* @return a tuple with minimum, Q1, median, Q3, maximum
* @param the vector of data
*/
tuple<double, double, double, double, double> getFiveNumberSummary(vector<double> data) {
	sort(data.begin(), data.end());
	double min = data[0];
	double Q1 = getQ1Sorted(data);
	double median = getMedianSorted(data);
	double Q3 = getQ3Sorted(data);
	double maximum = data[data.size() - 1];
	return make_tuple(min, Q1, median, Q3, maximum);
}


/**
* @brief display 5 number summary to the console, useful for debugging
* @date 12/13/2020
* @return void
* @param the tuple with the 5 number summary
* @param a character to seperate the numbers, meant to be a \t or \n
*/
void displayFiveNumberSummary(tuple<double, double, double, double, double> data, char seperator) {
	cout << "Min: " <<					get<0>(data) 
		<< seperator << "Q1: " <<		get<1>(data)
		<< seperator << "Median: " <<	get<2>(data)
		<< seperator << "Q3: " <<		get<3>(data)
		<< seperator << "Maximum: " <<	get<4>(data);
}


/**
* @brief Uses a common technique of using IQR to detect potential outliers
* finds potential outliers on the high end of the data, returns the cut off index
* @date 12/13/2020
* @return a 64 bit unsigned int, an index in the array if there are outliers, the size if there aren't any
* @param the vector of data to use to detect outliers in
*/
size_t indexOfOutliersTop(std::vector<double> data) {
	sort(data.begin(), data.end());

	double q1 = getQ1Sorted(data);
	double q3 = getQ3Sorted(data);

	double iqr = q3 - q1;
	iqr *= 1.5;

	double outlierThreshold = q3 + iqr;

	for (size_t i = (data.size()*3)/4; i < data.size(); i++) {
		if (data[i] > outlierThreshold) {
			return i;
		}
	}

	return data.size();
}


/**
* @brief Uses a common technique of using IQR to detect potential outliers
* finds potential outliers on the low end of the data, returns the cut off index
* @date 12/13/2020
* @return a 64 bit signed int, so that it can be equal to -1 if there are no outliers
* returns an index in the array if there are outliers
* @param the vector of data to use to detect outliers in
*/
int64_t indexOfOutliersBottom(std::vector<double> data) {
	sort(data.begin(), data.end());

	double q1 = getQ1Sorted(data);
	double q3 = getQ3Sorted(data);

	double iqr = q3 - q1;
	iqr *= 1.5;

	double outlierThreshold = q1 - iqr;

	for (int64_t i = data.size() / 4; i >= 0; i--) {
		if (data[i] < outlierThreshold) {
			return i;
		}
	}

	return -1;
}