#include "GradeBook.h"
#include "GradeBookUtility.h"

void runDescription() {
	cout << "Here is the description: "
		<< "\n\tS: build new semester"
		<< "\n\tA: add new student"
		<< "\n\tP: input program grades"
		<< "\n\tT: input test grades"
		<< "\n\tF: input final grades"
		<< "\n\tC: change grade for student"
		<< "\n\tG: calculate grade"
		<< "\n\tO: output grades to file"
		<< "\n\tQ: quit" << endl;
	return;
}

void runBookMenu() {
	char option;
	bool sFlag = false;
	int numsOf = 0;
	Semester smt;
	do {
		cout << " Please Enter an option (S, A, P, T, F, C, G, O, Q) :";
		cin >> option;
		toupper(option);
		switch (option) {
		case 'S':			
			cout << "How many programming assignments are there? (0-6)" << endl;
			cin >> numsOf;
			smt.setNumP(numsOf);

			cout << "How many tests are there? (0-4) " << endl;
			cin >> numsOf;
			smt.setNumT(numsOf);

			cout << "How many final exams are there? (0-1) " << endl;
			cin >> numsOf;
			smt.setNumF(numsOf);

			cout << "Please enter weights for: "
				<< "\n\t Tests: ";
			cin >> numsOf;
			smt.setWeigths(numsOf, 0);
			cout << "\n\t Tests: ";
			cin >> numsOf;
			smt.setWeigths(numsOf, 1);
			cout << "\n\t FInals: ";
			cin >> numsOf;
			smt.setWeigths(numsOf, 2);
			
			sFlag = true;
			break;
		case 'A':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'P':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'T':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'F':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'C':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'G':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'O':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'Q':
			if (sFlag) {
				//
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		default:
			cout << "\n NOT A VALID OPTION." << endl;
			break;
		}

	} while (option != 'Q' ||
		option != 'q');
}