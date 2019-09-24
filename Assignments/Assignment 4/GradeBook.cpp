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
int getNumP() {
	return numPrograms;
}
