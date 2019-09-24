#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Semester {
private:
	int numPrograms;
	int numTest;
	int numFinal;
	int weights[3];
public:
	
	Semester();
	void setNumP(int);
	void setNumT(int);
	void setNumF(int);
	void setWeigths(int, int);
	int getNumP();
	int getNumT();
	int getNumF();
	int getWeights(int);
};

class Student : public Semester{
private:
	string lastName;
	string firstName;
	int stdNum;
	Student* next;
public:

};

class Grades : public Student {
private:
	int num;
	int denom;
public:

};

#endif // !GRADEBOOK_H