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
	Semester(int, int, int);
	
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