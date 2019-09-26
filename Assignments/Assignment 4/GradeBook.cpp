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

GradeBook::GradeBook() {
	//gHead = nullptr;
	headPtr = nullptr;
}
GradeBook::~GradeBook() {
	if (headPtr) {
		while (headPtr) {
			Students* tmp = headPtr;
			headPtr = headPtr->next;
			delete tmp;
		}
	}
}
void GradeBook::addStudent(string lName, string fName, int id, 
								int pNum, int tNum, int fNum) {
	int i;
	Students* newStu = new Students;
	newStu->lastName = lName;
	newStu->firstName = fName;
	newStu->ID = id;
	newStu->saddness.prg = new int[pNum];
	newStu->saddness.tst = new int[tNum];
	newStu->saddness.fnl = new int[fNum];
	for (i = 0; i < pNum; i++) 
		newStu->saddness.prg[i] = -1;
	for (i = 0; i < tNum; i++)
		newStu->saddness.tst[i] = -1;
	for (i = 0; i < fNum; i++)
		newStu->saddness.fnl[i] = -1;
	newStu->next = NULL;
	alphaMe(headPtr, newStu, 0);
	//newStu->next = headPtr;
	//headPtr = newStu;
}
void GradeBook::addGrade(string name, char ptf, int grd, int idx) {
	Students* fwdPtr = headPtr;
	while (fwdPtr) {
		if (fwdPtr->lastName == name) {
			switch (ptf) {
			case 'P':
				fwdPtr->saddness.prg[idx] = grd;
				break;
			case 'T':
				fwdPtr->saddness.prg[idx] = grd;
				break;
			case 'F':
				fwdPtr->saddness.prg[idx] = grd;
				break;
			}
		}
		else
			fwdPtr = fwdPtr->next;
	}
}
void GradeBook::alphaMe(Students* head, Students* newStu, int idx) {
	Students* tmp = head;
	if (tmp == NULL || tmp->lastName[idx] > newStu->lastName[idx]) {
		newStu->next = tmp;
		tmp = newStu;
	}
	else if (tmp->lastName[idx] == newStu->lastName[idx]) {
		alphaMe(tmp, newStu, idx++);
	}
	else {
		//while (tmp->next != NULL && tmp->lastName[idx] < newStu->lastName[idx]) {
			tmp = tmp->next;
		//}
		/*newStu->next = tmp->next;
		tmp->next = newStu;*/
		alphaMe(tmp, newStu, idx);
	}
}
int GradeBook::getLength() {
	Students* currentNodeAddr = headPtr;
	int classSize = 0;
	if (currentNodeAddr) {
		do {
			classSize++;
			currentNodeAddr = currentNodeAddr->next;
		} while (currentNodeAddr);
	}
	return classSize;
}