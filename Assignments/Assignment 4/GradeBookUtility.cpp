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
	bool notTrue;

	int numsOf = 0;
	int total = 0;
	int id;
	int grade = 0;
	int idx = 0;

	string lName;
	string fName;

	char ptf;

	Semester smt;
	GradeBook stu;

	do {
		notTrue = false;
		cout << " Please Enter an option (S, A, P, T, F, C, G, O, Q) :";
		cin >> option;
		toupper(option);
		switch (option) {
		case 'S':
			do {
				cout << "How many programming assignments are there? (0-6)";
				cin >> numsOf;
				if (numsOf < 0 || numsOf > 6) {
					cout << "\nPlease enter correct amt of assignments." << endl;
				}
				else {
					smt.setNumP(numsOf);
					notTrue = true;
				}
			} while (notTrue);
			notTrue = false;
			do {
				cout << "How many tests are there? (0-4) ";
				cin >> numsOf;
				if (numsOf < 0 || numsOf > 4) {
					cout << "\nPlease enter correct amt of test." << endl;
				}
				else {
					smt.setNumT(numsOf);
					notTrue = true;
				}
			} while (notTrue);
			notTrue = false;
			do {
				cout << "How many final exams are there? (0-1) ";
				cin >> numsOf;
				if (numsOf < 0 || numsOf > 1)
					cout << "\nPlease enter correct amt of exams." << endl;
				else {
					smt.setNumF(numsOf);
					notTrue = true;
				}
			} while (notTrue);
			do {
				cout << "Please enter weights (1-9) for: "
					<< "\n\t Tests: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 0);
				cout << "\n\t Tests: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 1);
				cout << "\n\t FInals: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 2);
				total = 0;
				for (int i = 0; i < 3; i++)
					total += smt.getWeights(i);
				if (total != 10) {
					cout << "Weights not accepted.\n" << endl;
				}
			} while (total != 10);
			sFlag = true;
			break;
		case 'A':
			if (sFlag) {
				cout << "\nPlease enter Student's Last Name: ";
				cin >> lName;

				cout << "\nPlease enter Student's First Name: ";
				cin >> fName;

				cout << "\nPlease enter student ID number: ";
				cin >> id;
				stu.addStudent(lName, fName, id, smt.getNumP, smt.getNumT, smt.getNumF);
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'P':
			if (sFlag) {
				cout << "Enter the programming assignment you wish to access: ";
				cin >> idx;
				cout << "\n" << endl;
				if (idx >= 0 && idx < smt.getNumP()) {
					ptf = 'p';
					Students *temp;
					// temp = head;
					//while ()
				}
				else
					cout << "Invalid chosen programming assignment number\n" << endl;
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'T':
			if (sFlag) {
				cout << "Enter the test you wish to access: ";
				cin >> idx;
				cout << "\n" << endl;
				if (idx >= 0 && idx < smt.getNumT()) {

				}
				else
					cout << "Invalid chosen test number\n" << endl;
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
			break;
		default:
			cout << "\n NOT A VALID OPTION." << endl;
			break;
		}

	} while (option != 'Q');
}
