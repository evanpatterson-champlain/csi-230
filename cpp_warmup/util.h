#ifndef UTIL_H
#define UTIL_H
#include<vector>
#include<random>
#include<string>
#include<iostream>

/*
* templated functions can not be
* defined in .h files and have
* implementations in .cpp files, 
* so the randomElement function
* belongs in this file and not util.cpp
*/

// returns a random element from a vector
template<typename T>
T randomElement(std::vector<T> vec) {
	size_t ind = rand() % vec.size();
	return vec[ind];
}

// returns the sum of all elements
double sum(std::vector<double> vec);

// returns the average element value
double avg(std::vector<double> vec);

// returns the lowest
double lowest(std::vector<double> vec);

void camelCase(std::string& str);




#endif