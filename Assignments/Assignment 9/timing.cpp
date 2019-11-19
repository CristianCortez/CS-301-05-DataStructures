// C++ program to find out execution time of 
// of functions 
#include <algorithm> 
#include <chrono> //This requires compiler and library support for the ISO C++ 2011 standard. 
//This support must be enabled with the -std=c++11 or -std=gnu++11 compiler options.
#include <iostream> 
#include <vector>
using namespace std;
using namespace std::chrono;

// For demonstration purpose, we will fill up 
// a vector with random integers and then sort 
// them using sort function. We fill record 
// and print the time required by sort function 
int timing()
{

	vector<int> values(10000);

	// Generate Random values 
	auto f = []() -> int { return rand() % 10000; };

	// Fill up the vector 
	generate(values.begin(), values.end(), f);

	// Get starting timepoint 
	auto start = high_resolution_clock::now();

	// Call the function, here sort() 
	sort(values.begin(), values.end());

	// Get ending timepoint 
	auto stop = high_resolution_clock::now();

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

	return 0;
}