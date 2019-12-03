/* Author(s): Cristian Cortez if2482
			Paulo Chu za8684
			Kevin Nguyen ta8783
 * Class: CS 301 - 05 (3675) Data Structures and Algorithms
 * Assignment: Group Project Phase 3
 * Date (Submitted): 12/02/2019
*/

#include "includes.h"
#include <string>
#include <iostream>

int main() {
	ifstream command_in_file;				// file that saves allergies to be built on startup
	ofstream write_file;					// file that allergies are written to
	DataBase* allergen_db = new DataBase;	// database obj
	Menu opt;								// menu obj
	char option, choice;					// menu option and choice
	string imp, med;						// string for symptom storing (see line 127 mainDriver.cpp)
	string file_contents;					// string that stores file contents
	string cN, sN, T, S;					// strings that store allergen info 
											/* common_name, science_name, Type, Symptoms */
	int N, cnt = 1;							// int for allergen number and file line count
	size_t found;							// size_t type obj for str.find() regular expression
	bool add_cmd = false;					// bool for read from file to see if 'add' cmd was found

	write_file.open("AllergenDataBase.out");
	write_file << "ALLERCO: Organizing The World's Allergies\n" << endl
		<< runDescription() << endl;
	command_in_file.open("AllyCo_Build.in");

	while (getline(command_in_file, file_contents)) {
		if (file_contents == "Add")
			add_cmd = true;
		else {
			if (add_cmd) { 
				if (cnt == 1)
					cN = file_contents;
				else if (cnt == 2)
					sN = file_contents;
				else if (cnt == 3)
					T = file_contents;
				else if (cnt == 4)
					N = getInt(file_contents);
				else if (cnt == 5) {
					S = file_contents;
					allergen_db->addAl(cN, sN, T, N, S);
					cnt = 0;
					add_cmd = false;
				}
				cnt++;
			}
		}
	}
	command_in_file.close();
	do {
		char ch = opt.getMenu();
		switch (ch) {
		case 'A':
			do {
				opt.setAdd(allergen_db);
				cout << "Do you want to add another allergen? (Y/N) " << endl;
				cin >> choice;
				choice = putchar(toupper(choice));
				cout << "\b" << "";
			} while (choice != 'N');
			break;
		case 'D':
			do {
				option = opt.getDelete();
				opt.setDelete(allergen_db, option);
				cout << "Do you want to delete another allergen? (Y/N) " << endl;
				cin >> choice;
				choice = putchar(toupper(choice));
				cout << "\b" << "";
			} while (choice != 'N');
			break;
		case 'S':
			do {
				option = opt.getSearch();
				opt.setSearch(allergen_db, option);
				cout << "Do you want to search another allergen? (Y/N) " << endl;
				cin >> choice;
				choice = putchar(toupper(choice));
				cout << "\b" << "";
			} while (choice != 'N');
			break;
		case 'Q': // option to quit the menu AND streams all allergens to the file.
			break;
		default:
			cout << ":: INVALID CHOICE ::" << endl;
		}
		cout << "Do you want to look at the MAIN MENU again? (Y/N) " << endl;
		cin >> choice;
		choice = putchar(toupper(choice));
		cout << "\b" << "";
	} while (choice != 'N');

	write_file << allergen_db->print();
	write_file.close();
	ofstream command_out_file;
	ifstream read_file;
	read_file.open("AllergenDataBase.out");
	command_out_file.open("AllyCo_Build.in", ofstream::trunc);

	while (getline(read_file, file_contents)) {
		found = file_contents.find("Common Name");
		if (found != string::npos) { //if the common name is found, then add
			command_out_file << "Add" << endl;
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);
		}
		found = file_contents.find("Scientific Name");
		if (found != string::npos) {
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);
		}
		found = file_contents.find("Type");
		if (found != string::npos) {
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);
		}
		found = file_contents.find("Number");
		if (found != string::npos) {
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);
		}
		found = file_contents.find("Symptoms");
		if (found != string::npos) {
			found = file_contents.find_first_of('.') + 1;
			imp = file_contents.substr(found);
			stringstream sym(imp);
			while (getline(sym, med, '.')) {
				command_out_file << stoi_symptoms(med);
			}
			
		}
		command_out_file << endl;
	}
	command_out_file.close();
	read_file.close();

	return 0;
}