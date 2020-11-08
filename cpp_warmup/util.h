#ifndef UTIL_H
#define UTIL_H
#include<vector>
#include<random>
#include<string>
#include<iostream>

template<typename T>
T randomElement(std::vector<T> vec);

// returns the sum of all elements
double sum(std::vector<double> vec);

// returns the average element value
double avg(std::vector<double> vec);

// returns the lowest
double lowest(std::vector<double> vec);

void camelCase(std::string& str);




#endif
