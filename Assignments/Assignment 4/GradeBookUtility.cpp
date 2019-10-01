#include "GradeBook.h"
#include "GradeBookUtility.h"

string runDescription() {
	ostringstream prt;
	prt << "Here is the description: "
		<< "\n\tS: build new semester"
		<< "\n\tA: add new student"
		<< "\n\tP: input program grades"
		<< "\n\tT: input test grades"
		<< "\n\tF: input final grades"
		<< "\n\tC: change grade for student"
		<< "\n\tG: calculate grade"
		<< "\n\tO: output grades to file"
		<< "\n\tQ: quit" << endl;
	return prt.str();
}

void runBookMenu() {
	ofstream trnFile;
	ofstream inFile;
	ofstream outFile;

	char option;
	char ptf;

	bool sFlag = false;
	bool notTrue;
	bool out = false;

	int numsOf = 0;
	int total = 0;
	int id;
	int assgNum;
	int grd;
	int idx;

	string lName;
	string fName;

	Semester smt;
	GradeBook stu;
	
	trnFile.open("Grades.trn");
	inFile.open("Grades.data");
	outFile.open("Grades.out");

	trnFile << runDescription();

	do {
		notTrue = false;
		out = false;
		cout << "\n Please Enter an option (S, A, P, T, F, C, G, O, Q) :";
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
			} while (!notTrue);
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
			} while (!notTrue);
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
			} while (!notTrue);
			do {
				cout << "Please enter weights (1-9) for: \n"
					<< "\t Programs: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 0);
				cout << "\t Tests: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 1);
				cout << "\t FInals: ";
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
				
				cout << "Please enter Student's First Name: ";
				cin >> fName;
				
				cout << "Please enter student ID number: ";
				cin >> id;
				stu.addStudent(lName, fName, id, smt.getNumP(), smt.getNumT(), smt.getNumF());
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'P':
			if (sFlag) {
				do {
					cout << "\nEnter the program number you want to access: ";
					cin >> assgNum;
					if (assgNum >= 0 && assgNum <= smt.getNumP()) {
						assgNum -= 1;
						stu.setAssgG(assgNum);
					}
					else
						cout << "The program number you have entered is invalid.\n" << endl;
					} while (assgNum < 0 && assgNum > smt.getNumP());
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'T':
			if (sFlag) {
				do {
					cout << "\nEnter the test number you want to access: ";
					cin >> assgNum;
					if (assgNum >= 0 && assgNum <= smt.getNumT()) {
						assgNum -= 1;
						stu.setTestG(assgNum);
					}
					else
						cout << "The program number you have entered is invalid.\n" << endl;
				} while (assgNum < 0 && assgNum > smt.getNumT());
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'F':
			if (sFlag) {
				do {
					cout << "\nEnter the program number you want to access: ";
					cin >> assgNum;
					if (assgNum >= 0 && assgNum <= smt.getNumF()) {
						assgNum -= 1;
						stu.setFinalG(assgNum);
					}
					else
						cout << "The program number you have entered is invalid.\n" << endl;
				} while (assgNum < 0 && assgNum > smt.getNumF());
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'C':
			if (sFlag) {
				cout << "\nPlease enter student ID name: ";
				cin >> id;
				cout << "\nPlease enter new grade: ";
				cin >> grd;
				do {
					cout << "Please enter the type of assignment (P, T, F): ";
					cin >> ptf;
				} while (ptf != 'P' && ptf != 'T' && ptf != 'F');
				cout << "Please enter the index of the type " << ptf << ": ";
				cin >> idx;
				stu.changeGrade(id, grd, ptf, idx);

			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'G':
			if (sFlag) {
				stu.calcGrade(smt.getNumP(), smt.getNumT(), smt.getNumF());
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'O':
			if (sFlag) {
				cout << "\nOutputting to \"Grades.out\"" << endl;
				outFile << stu.printStuds(out, smt.getNumP(), smt.getNumT(), smt.getNumF());
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'Q':
			if (sFlag) {
				out = true;
				cout << "\nOutputting to \"Grades.dat\"" << endl;
				inFile << stu.printStuds(out, smt.getNumP(), smt.getNumT(), smt.getNumF());				
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		default:
			cout << "\n NOT A VALID OPTION." << endl;
			break;
		}

	} while (option != 'Q');
	trnFile.close();
	inFile.close();
	outFile.close();
}