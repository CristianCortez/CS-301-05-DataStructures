#include "GradeBook.h"

Semester::Semester() {
	cout << "obj built.";
}

void Semester::setNumP(int num) {
	numPrograms = num;
}
void Semester::setNumT(int num) {
	numTest = num;
}
void Semester::setNumF(int num) {
	numFinal = num;
}
void Semester::setWeigths(int num, int idx) {
	weights[idx] = num;
}
int Semester::getNumP() {
	return numPrograms;
}
int Semester::getNumT() {
	return numTest;
}
int Semester::getNumF() {
	return numFinal;
}
int Semester::getWeights(int idx) {
	return weights[idx];
}

Student::Student(){}

void Student::setLast(string name) {
	lastName = name;
}
void Student::setFirst(string name) {
	firstName = name;
}
void Student::setID(int num) {
	ID = num;
}
string Student::getLast() {
	return lastName;
}
string Student::getFirst() {
	return firstName;
}
int Student::getID() {
	return ID;
}
void Student::printStu() {
	cout << "\n Name: " << getLast()
		<< ", " << getFirst()
		<< "\n ID number: " << getID();
}