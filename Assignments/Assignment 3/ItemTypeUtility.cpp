#include "ItemType.h"
#include "ItemTypeUtility.h"
#include <string>

void runMenu() {
	fstream fileIn;
	fstream fileOut;
	string inFile;
	string outFile;
	string test;
	
	cout << "Enter name of input command file; press return." << endl;
	cin >> inFile;

	cout << "Enter name of output file; press return." << endl;
	cin >> outFile;

	cout << "Enter name of test run; press return;" << endl;
	cin >> test;
}