#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//starts new semester book
void getNewSemester(int programmingAssignments, int exams, int finalExam) {

}

//add a new student
void getNewStudent(string lastName, string firstName, int studentID) {

}
void gradeBook() {
	//file to read from
	ifstream inFile;
	//file to write to
	ofstream outFile;

	string inFile;
	string outFile;

	char input;

	int assignments;
	int exams;
	int finalExam;

	//asks the user for command instruction
	cout << "Type 'S' to start a new semester. " << endl;
	cin >> input;

	if (input = 'S') {
		cout << "How many programming assignments are there? (0-6)" << endl;
		cin >> assignments;

		cout << "How many tests are there? (0-4) " << endl;
		cin >> exams;

		cout << "How many final exams are there? (0-1) " << endl;
		cin >> finalExam;

		getNewSemester(assignments, exams, finalExam);

		cout << "Type in 'A' to add a student, 'P' to record a programming assignment,  'T' to record a test grade, 'F' to record a final exam, 'C' to change a grade for a student, 'G' to calculate the final grade, 'O' to output the grade data, or 'Q' to exit." << endl;
		cin >> input;

	}
	else
		"Please type in 'S' to start a new semester. ";

	if (input = 'A') {

	}
	else if (input = 'P') {

	}
	else if (input = 'T') {

	}
	else if (input = 'F') {

	}
	else if (input = 'C') {

	}
	else if (input = 'G') {

	}
	else if (input = 'O') {

	}
	else {

	}

}
