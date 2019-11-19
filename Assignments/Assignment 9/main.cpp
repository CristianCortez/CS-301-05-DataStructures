// This program is a sorting algorithm tester.

// Input are sorting algorithm names plus Refresh for resetting the
//   values to be sorted to their previous values and Reinitialize for
//   creating a new set of values.
#include <algorithm> 
#include <chrono>

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
const int SIZE = 10000;
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "BubbleSort.h"
#include "ShortBubble.h"
#include "HeapSort.h"

using namespace std;
using namespace std::chrono;
typedef int ItemType;

// SIZE should be a multiple of 10.

void Print(ofstream&, int[]);	// Prints array
void InitValues(int[]);			// Creates random array 
void CopyValues(int[], int[]);	// Makes a copy of random array

//void Swap(ItemType& item1, ItemType& item2);

int main()
{

	ifstream inFile;       // file containing operations
	ofstream outFile;      // file containing output
	string inFileName;     // input file external name
	string outFileName;    // output file external name
	string outputLabel;
	string command;        // operation to be executed
	ItemType values[SIZE];
	int numCommands;
	ItemType copyValues[SIZE];


	// Prompt for file names, read file names, and prepare files
	cout << "Enter name of input command file; press return." << endl;
	cin >> inFileName;
	inFile.open(inFileName.c_str());

	cout << "Enter name of output file; press return." << endl;
	cin >> outFileName;
	outFile.open(outFileName.c_str());

	cout << "Enter name of test run; press return." << endl;
	cin >> outputLabel;
	outFile << outputLabel << endl;

	inFile >> command;
	InitValues(values);
	CopyValues(values, copyValues);
	outFile << "Initial values" << endl;
	Print(outFile, values);

	numCommands = 0;
	while (command != "Quit")
	{
		if (command == "SelectionSort")
		{
			auto start = high_resolution_clock::now();					
			SelectionSort(values, SIZE - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from SelectionSort: \n"
				<< "Time taken by function: "
					<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "BubbleSort")
		{
			auto start = high_resolution_clock::now();
			BubbleSort(values, SIZE - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from BubbleSort:\n"
				<< "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "ShortBubble")
		{
			auto start = high_resolution_clock::now();
			ShortBubble(values, SIZE - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from ShortBubble:\n"
				<< "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "MergeSort")
		{
			auto start = high_resolution_clock::now();
			MergeSort(values, 0, SIZE - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from MergeSort: \n"
				<< "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "QuickSort")
		{
			auto start = high_resolution_clock::now();
			QuickSort(values, 0, SIZE - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from QuickSort: \n"
				<< "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "QuickSort2")
		{
			auto start = high_resolution_clock::now();
			QuickSort2(values, 0, SIZE - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from QuickSort2: \n"
				<< "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "InsertionSort")
		{
			auto start = high_resolution_clock::now();
			InsertionSort(values, SIZE - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from InsertionSort: \n"
				<< "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "HeapSort")
		{
			auto start = high_resolution_clock::now();
			HeapSort(values, SIZE);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			outFile << "Results from HeapSort: \n"
				<< "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			Print(outFile, values);
			outFile << endl;
		}
		else if (command == "Refresh")
			CopyValues(copyValues, values);
		else if (command == "ReInitialize")
		{
			InitValues(values);
			CopyValues(values, copyValues);
			outFile << endl << "Initial Values: " << endl;
			Print(outFile, values);
		}
		else
			outFile << "Input not recognized." << endl;

		numCommands++;
		cout << " Command " << command << " completed."
			<< endl;
		inFile >> command;

	}

	cout << "Testing completed." << endl;
	inFile.close();
	outFile.close();
	return 0;
}

void InitValues(int values[])
// initializes the values array with random integers from 0 to 99
{
	for (int index = 0; index < SIZE; index++)
		values[index] = (std::rand() % 1000);
}

void Print(ofstream& outFile, int values[])
{
	using namespace std;
	for (int count = 0; count < SIZE; count = count + 10)
		outFile << values[count] << ", " << values[count + 1] << ", " << values[count + 2] << ", "
		<< values[count + 3] << ", " << values[count + 4] << ", " << values[count + 5] << ", "
		<< values[count + 6] << ", " << values[count + 7] << ", " << values[count + 8]
		<< ", " << values[count + 9] << endl << endl;

}
/*
void Swap(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped.
{
	ItemType tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}
*/
void CopyValues(int inData[], int outData[])
{
	for (int count = 0; count < SIZE; count++)
		outData[count] = inData[count];
}