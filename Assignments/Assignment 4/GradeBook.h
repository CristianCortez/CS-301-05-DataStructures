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

struct Grades {
	int* prg;
	int* tst;
	int* fnl;
};

struct Students {
	string lastName;
	string firstName;
	int ID;
	int grd;
	Grades saddness;
	Students* next;
};

class GradeBook : public Semester {
private:
	Students* headPtr;
public:
	GradeBook();
	~GradeBook();	
	void addStudent(string, string, int, int, int, int);
	void addGrade(string, char, int, int);
	void alphaMe(Students*, Students*, int);
	void changeGrade(int, int, char, int);
	string printStuds();
	int getLength();
};

#endif // !GRADEBOOK_H