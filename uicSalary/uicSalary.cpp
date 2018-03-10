#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
using namespace std;

// 3/7/18, reads the pdf data for 2014 UIC salaries and sums it all up.
// >>copied and pasted all data from pdf to a txt<<, then I ran through every
// entry and parsed it only if it was a salary, deturmined by numerous 
// characteristics, put the values into a vector in order to sort 
// it by salary and find the largest individual payment.

class Salary{
	public:
		string name;
		double salary;
	
	Salary(double Salary, string Name)
	: salary(Salary), name(Name)
		{}
	
	Salary(double Salary)
	: salary(Salary)
		{}
};

// checks if it's a number I WANT to parse
int isDigits(string str){
	if(!str.length()) // if null string
		return 0;
	if(!isdigit(str[0])) // if it is something like 0.434343
		return 0;
	if(str.length() > 1 && str[1] == '.') // if it has a decimal, 1.0 or 0.4
		return 0;
	
	return 1;
}


int main(int argc, char** argv) {
	vector<Salary> salaries;
	
  	ifstream FileS("Salaries.txt");
  	cout << std::fixed;
  	cout << std::setprecision(2);
	
	if (!FileS.good()){
    	cout << "**ERROR: cannot open customers file: '" << "Salaries" << "'" << endl;
    	return -1;
  	}
	string tmp, line, name;
	double TOTAL = 0;
	int count = 0;
	
	// read in salaries into vector.
	name = "TMP";
    while(FileS >> tmp){
    	if(isDigits(tmp)){
    		tmp.erase(remove(tmp.begin(), tmp.end(), ','), tmp.end()); // erase comma before pushing
    		TOTAL += stod(tmp);
    		salaries.push_back(Salary(stod(tmp), name)); // used to sort and find largest
    		count++; // used for average)
		}
	}
	
	//now sort vector based on salary
	sort(salaries.begin(), salaries.end(),
		[=](Salary one, Salary two){
			return one.salary > two.salary; // notice the symbol LOOKs like descending order
		}	
	);
	
	cout << "UIC 2014 Salary Statistics..." << endl;
	cout << "Highest Salary: $" << salaries[0].salary << endl; // << " given to: " << salaries[1].name << endl; // [1] because [0] is total
	cout << "Total combined Salaries: $" << TOTAL << endl;
	cout << "Rough average Salary payment: $" << (TOTAL / (double)(count)) << endl;
	cout << "There were " + to_string(count) + " total payments in 2014." << endl;
	
	FileS.close();
	return 0;
}



