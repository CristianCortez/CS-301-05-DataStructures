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
	do {
		cout << " Please Enter an option (S, A, P, T, F, C, G, O, Q) :";
		cin >> option;
		toupper(option);
		switch (option) {
		case 'S':
			break;
		case 'A':
			break;
		case 'P':
			break;
		case 'T':
			break;
		case 'F':
			break;
		case 'C':
			break;
		case 'G':
			break;
		case 'O':
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