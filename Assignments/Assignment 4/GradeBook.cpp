#include "GradeBook.h"

Semester::Semester() {
	//cout << "obj built.";
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
			delete[] tmp->saddness.prg;
			delete[] tmp->saddness.tst;
			delete[] tmp->saddness.fnl;

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
	Students* head = headPtr;
	newStu->lastName = lName;
	newStu->firstName = fName;
	newStu->ID = id;
	newStu->pGrd = 0;
	newStu->tfGrd = 0;
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
	alphaMe(newStu);
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
void GradeBook::alphaMe(Students* newStu) {
	Students* tmpHead = headPtr;
	Students* previous = tmpHead;
	int i = 0;
	if (headPtr == NULL || headPtr->lastName[0] > newStu->lastName[0]) {
		newStu->next = headPtr;
		headPtr = newStu;
	}
	else {
		do {
			previous = tmpHead;
			if (tmpHead->lastName[i] == newStu->lastName[i]) {
				i++;
			}
			
			else {
				i = 0;
				
				tmpHead = tmpHead->next;
			}
		} while (tmpHead && tmpHead->lastName[i] <= newStu->lastName[i]);
		if (previous->lastName.compare(newStu->lastName) == 0) {
			if (previous->ID > newStu->ID) {
				newStu->next = previous;
				previous = newStu;
			}
			else {
				newStu->next = previous->next;
				previous->next = newStu;
			}
		}
		else {
			newStu->next = previous->next;
			previous->next = newStu;
		}
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
string GradeBook::printStuds(bool out, int pNum, int tNum, int fNum) {
	ostringstream prtList;
	Students* tmp = headPtr;
	int i;
	if (tmp) {
		while (tmp) {
			prtList << "\nName: "
				<< tmp->lastName << ", "
				<< tmp->firstName << "\nID#: "
				<< tmp->ID
				<< "\nAverage Prgrogram Grade: "
				<< tmp->pGrd
				<< "\nAverage Test Grade: "
				<< tmp->tfGrd;
			if (out) {
				prtList << "\n\nGrades: \n\tPrograms: ";
				for (i = 0; i < pNum; i++) {
					if (tmp->saddness.prg[i] != -1) {
						prtList << "\n\t\tProgram #" << i + 1 << ": "
							<< tmp->saddness.prg[i];
					}
				}
				prtList << "\n\tTests: ";
				for (i = 0; i < tNum; i++) {
					if (tmp->saddness.tst[i] != -1) {
						prtList << "\n\t\tTest #" << i + 1 << ": "
							<< tmp->saddness.tst[i];
					}
				}
				prtList << "\n\tFinal: ";
				for (i = 0; i < fNum; i++) {
					if (tmp->saddness.fnl[i] != -1) {
						prtList << "\n\t\tFinal #" << i + 1 << ": "
							<< tmp->saddness.fnl[i];
					}
				}
			}
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
void GradeBook::setAssgG(int indx) {
	Students* tmp = headPtr;
	int grade;
	if (tmp) {
		while (tmp) {
			cout << "\n\tName: " << tmp->lastName << ", " << tmp->firstName
				<< "\n\tProgramming Assingment #" << indx << ": "
				<< "\n\t\t:Grade: ";
			cin >> grade;
			tmp->saddness.prg[indx] = grade;
			tmp = tmp->next;
		}
	}
}
void GradeBook::setTestG(int indx) {
	Students* tmp = headPtr;
	int grade;
	if (tmp) {
		while (tmp) {
			cout << "\n\tName: " << tmp->lastName << ", " << tmp->firstName
				<< "\n\tTest #" << indx <<": "
				<< "\n\t\t:Grade: ";
			cin >> grade;
			tmp->saddness.tst[indx] = grade;
			tmp = tmp->next;
		}
	}
}
void GradeBook::setFinalG(int indx) {
	Students* tmp = headPtr;
	int grade;
	if (tmp) {
		while (tmp) {
			cout << "\n\tName: " << tmp->lastName << ", " << tmp->firstName
				<< "\n\tFinal #" << indx << ": "
				<< "\n\t\t:Grade: ";
			cin >> grade;
			tmp->saddness.fnl[indx] = grade;
			tmp = tmp->next;
		}
	}
}
void GradeBook::calcGrade(int pNum, int tNum, int fNum) {
	Students* tmp = headPtr;
	int pAvg = 0, tfAvg = 0;
	int counter = 0, i;
	if (tmp) {
		while (tmp) {
			for (i = 0; i < pNum; i++) {
				pAvg += tmp->saddness.prg[i];
			}
			tmp->pGrd = pAvg / i;
			for (i = 0; i < tNum; i++) {
				tfAvg += tmp->saddness.tst[i];
				counter++;
			}
			for (i = 0; i < fNum; i++) {
				tfAvg += tmp->saddness.fnl[i];
				counter++;
			}
			tmp->tfGrd = tfAvg / counter;
			tmp = tmp->next;
		}
		cout << "\nGrade Calulated.";
	}
}