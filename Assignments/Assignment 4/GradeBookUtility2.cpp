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
	Student *headStudent;
	Semester smt;

	int total = 0;
	do {
		cout << " Please Enter an option (S, A, P, T, F, C, G, O, Q) :";
		cin >> option;
		toupper(option);
		switch (option) {
		case 'S':
			do {
				cout << "How many programming assignments are there? (0-6)" << endl;
				cin >> numsOf;
				if (numsOf < 0 || numsOf > 6)
					cout << "\nPlease enter correct amt of assignments." << endl;
				else
					smt.setSizeP(numsOf);
			} while (numsOf < 0 || numsOf > 6);
			cout << "How many tests are there? (0-4) " << endl;
			cin >> numsOf;
			smt.setSizeT(numsOf);

			cout << "How many final exams are there? (0-1) " << endl;
			cin >> numsOf;
			smt.setSizeF(numsOf);
			do {
				cout << "Please enter weights (1-9) <weights must total to 10> for: "
					<< "\n\t Assignment Programs: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 0);
				cout << "\n\t Tests: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 1);
				cout << "\n\t Finals: ";
				cin >> numsOf;
				smt.setWeigths(numsOf, 2);
				total = 0;
				for (int i = 0; i < 3; i++)
					total += smt.getWeights(i);
				if (total != 10) {
					cout << "Weights do not equal 10" << endl
						 << "Weights not accepted.\n" << endl;
				}
			} while (total != 10);
			sFlag = true;
			break;
		case 'A':
			if (sFlag) {
				Student *std = new Student();
				string firstName;
				string lastName;
				int studentID;
				do {
					cout << "Enter student first name (20 characters max): ";
					cin >> firstName;
					cout << "\n" << endl;
					if (firstName.size() < 20 && firstName.size() > 0) {
						do {
							cout << "Enter student last name (20 characters max): ";
							cin >> lastName;
							cout << "\n" << endl;
							if (lastName.size() < 20 && lastName.size() > 0) {
								do {
									cout << "Enter student ID (1 - 9999): " << endl;
									cin >> studentID;
									cout << "\n" << endl;
									if (studentID > 9999 || studentID < 0)
										cout << "Invalid student ID\n" << endl;
									else {
										std->setFirst(firstName);
										std->setLast(lastName);
										std->setID(studentID);
										if (std->getStdSize == 1) {
											headStudent = std;
											std->next = NULL;
										}
										else {
											Student* temp;
											Student* prev;
											temp = headStudent;
											string tempName = temp->getLast;
											bool alpha = false; 
											while (temp->next != NULL) {
												for (int i = 0; i < 20; i++) {
													char compA = std->getLast.get(i);
													char compB = temp->getLast.getFirst(i);

												}
												prev = temp;
												temp = temp->next;
											}
											prev->next = std;
											std->next = NULL;
										}
									}
								} while (studentID <= 9999 || studentID >= 0);
							}
							else
								cout << "Invalid student last name\n" << endl;
						} while (lastName.size() < 20 && lastName.size() > 0);
					}
					else
						cout << "Invalid student first name\n" << endl;
				} while (firstName.size() < 20 && firstName.size() > 0);
			}
			else {
				cout << "Please enter a semester first." << endl;
			}
			break;
		case 'P':
			if (sFlag) {
				do {
					cout << "Enter the program number you wish to access: ";
					cin >> numsOf;
					cout << "\n" << endl;
					if (numsOf >= 0 && numsOf < smt.getSizeP) {
						//
					}
					else
						cout << "The program number you have entered is invalid.\n" << endl;
				} while (numsOf >= 0 && numsOf < smt.getSizeP);
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
			break;
		default:
			cout << "\n NOT A VALID OPTION." << endl;
			break;
		}

	} while (option != 'Q' ||
		option != 'q');
}
