#include<iostream>
#include<string>
#include<random>
#include<time.h>
#include"util.h"

using namespace std;

// printVector makes displaying std::vectors
// much easier
template<typename T>
void printVector(std::vector<T> vec, std::string seperator = std::string("\n")) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << seperator;
	}
}


int main() {
	srand(time(NULL));
	
	vector<string> myStrings = {"Bilbo", "Gandalf", "Pippin", "Sam", "Ring", "Wraith", "Balrog"};
	vector<double> myDoubles = {3.14, 5.56, 7.72, 9, -4, 99.99, 22, 30};
	string strMessage = "A little bird with a yellow bill";

	cout << "Dumping the vector of " << myStrings.size() << " elements: "; 
	printVector(myStrings, "  ");
	cout << '\n';
	cout << "calling randomElement\n";
	cout << randomElement(myStrings) << '\n';
	
	cout << "\nDumping the vector of doubles: ";
	printVector(myDoubles, "  ");
	cout << '\n';

	cout << "sum: " << sum(myDoubles) << '\n';
	cout << "average: " << avg(myDoubles) << '\n';
	cout << "lowest: " << lowest(myDoubles) << '\n';

	cout << "\nCalling camelCase with: " << strMessage << '\n';
	camelCase(strMessage);
	cout << "strMessage after camelCase: " << strMessage << endl;


	std::cout << std::endl;
	std::cin.get();
	
	return 0;
}
