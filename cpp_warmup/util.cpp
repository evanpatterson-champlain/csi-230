#include"util.h"
#include<limits>


// returns the sum of all elements
double sum(std::vector<double> vec) {
	double x = 0; // set initial value to zero
	for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it) {
		x += *it; // sum all elements
	}
	return x;
}

// returns the average element value
double avg(std::vector<double> vec) {
	double x = 0; // set initial value to zero
	for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it) {
		x += *it; // sum all elements
	}
	x /= double(vec.size()); // divide by number of elements
	return x;
}

// returns the lowest
double lowest(std::vector<double> vec) {
	// x tracks the current lowest number
	double x = std::numeric_limits<double>::max(); // set initial value to highest possible value for float64
	for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it) { // iterate through vector
		double tmp = *it;
		if (tmp < x) { // if you find a number lower than x, then set x to that value
			x = tmp;
		}
	}
	return x;
}


// turn string into camelCase
void camelCase(std::string& str) {
	size_t wsp = 0; // tracks the index of the last non-space character
	bool updating = false;
	for (size_t i = 0; i < str.size(); i++) {
		if (updating) { // if changing the string (after finding empty space)
			if (str[i] != ' ') { // if you are changing the string and you find something that is not empty space

				// change the current character in the string to uppercase
				str[i] = toupper(str[i]);

				// remove the part of the string that is empty, and move backwards to the last non-space character
				str.erase(str.begin() + wsp, str.begin() + i);

				updating = false;
				i = wsp;
			}
		}
		else if (str[i] == ' ') { // if you find an empty space, start changing the string
			updating = true;
			wsp = i;
		}
	}

	// make sure the first character is lowercase
	if (str.size() > 0) {
		str[0] = tolower(str[0]);
	}
}
