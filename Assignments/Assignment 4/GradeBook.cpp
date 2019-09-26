#include "GradeBook.h"

Semester::Semester() {
	cout << "obj built. \n";
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

GradeBook::GradeBook() {
	headPtr = nullptr;
}
GradeBook::~GradeBook() {
	if (headPtr) {
		while (headPtr) {
			Students* tmp = headPtr;
			headPtr = headPtr->next;
			delete tmp->saddness.prg;
			delete tmp->saddness.tst;
			delete tmp->saddness.fnl;

			tmp->saddness.prg = nullptr;
			tmp->saddness.tst = nullptr;
			tmp->saddness.fnl = nullptr;

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
	Students* tmp = headPtr;
	while (tmp) {
		if (tmp->lastName == name) {
			switch (ptf) {
			case 'P':
				tmp->saddness.prg[idx] = grd;
				break;
			case 'T':
				tmp->saddness.tst[idx] = grd;
				break;
			case 'F':
				tmp->saddness.fnl[idx] = grd;
				break;
			}
			tmp = NULL;
		}
		else
			tmp = tmp->next;
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
void GradeBook::changeGrade(int id, int grd, char ptf, int idx) {
	Students* tmp = headPtr;
	if (tmp) {
		while (tmp) {
			if (tmp->ID == id) {				
				switch (ptf) {
				case 'P':
					tmp->saddness.prg[idx] = grd;
					break;
				case 'T':
					tmp->saddness.tst[idx] = grd;
					break;
				case 'F':
					tmp->saddness.fnl[idx] = grd;
					break;
				}
				tmp = NULL;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
}
string GradeBook::printStuds() {
	ostringstream prtList;
	Students* tmp = headPtr;
	if (tmp) {
		while (tmp) {
			prtList << "\nName: "
				<< tmp->lastName << ", "
				<< tmp->firstName << "\nID#: "
				<< tmp->ID
				<< "\nAverage Grade: "
				<< tmp->grd;
			tmp = tmp->next;
		}
	}
	return prtList.str();
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
