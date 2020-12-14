/**
* @file main.cpp
* @brief entry point for final project
* @author Evan Patterson
* @assignment Final Project
* @date 12/13/2020
*/
#include<iostream>
#include"analytic_functions.h"
#include"read_csv.h"
#include<algorithm>

using namespace std;



/**
* @brief entry point for final project
* @date 12/13/2020
* @return success
* @param argv arguments
* @param number of arguments
*/
int main() {

	vector<pair<string,vector<double>>> data = csvLoadData("EventData.csv", 32);



	cout << endl;
	cin.get();
	return 0;
}