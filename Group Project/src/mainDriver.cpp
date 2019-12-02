#include "includes.h"
#include <string>
#include <iostream>

int main() {
	ifstream command_in_file;
	ofstream write_file;
	write_file.open("AllergenDataBase.txt");
	write_file << "ALLERCO: Organizing The World's Allergies\n" << endl
		<< runDescription() << endl;
	command_in_file.open("AllyCo_Build.in");
	DataBase* allergen_db = new DataBase;
	Menu opt;
	char option, choice;
	string file_contents;
	string cN, sN, T;
	int N, cnt = 1;
	size_t found;
	bool add_ally = false;
	while (getline(command_in_file, file_contents)) {
		if (file_contents == "Add")
			add_ally = true;
		else {
			if (add_ally) { // then we have part of the allergen
				if (cnt == 1)
					cN = file_contents;
				else if (cnt == 2)
					sN = file_contents;
				else if (cnt == 3)
					T = file_contents;
				else if (cnt == 4) {
					N = getInt(file_contents);
					allergen_db->addAl(cN, sN, T, N);
					cnt = 0;
					add_ally = false;
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
		/*case 'H':
			int m;
			option = opt.getSymptoms();
			break;*/
		case 'Q': // option to quit the menu AND streams all allergens to the file.

			break;
		default:
			cout << ":: INVALID CHOICE ::" << endl;
		}

		cout << "Do you want to look at the menu again? (Y/N) " << endl;
		cin >> choice;
		choice = putchar(toupper(choice));
		cout << "\b" << "";
	} while (choice != 'N');

	write_file << allergen_db->print();
	write_file.close();
	ofstream command_out_file;
	ifstream read_file;
	read_file.open("AllergenDataBase.txt");
	command_out_file.open("AllyCo_Build.in", ofstream::trunc);
	while (getline(read_file, file_contents)) {
		found = file_contents.find("Common Name");
		if (found != string::npos) { //if the common name is found, then add
			command_out_file << "Add" << endl;
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);// << endl;
		}
		found = file_contents.find("Scientific Name");
		if (found != string::npos) {
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);// << endl;
		}
		found = file_contents.find("Type");
		if (found != string::npos) {
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);// << endl;
		}
		found = file_contents.find("Number");
		if (found != string::npos) {
			found = file_contents.find_last_of('.') + 1;
			command_out_file << file_contents.substr(found);// << endl;
		}
		command_out_file << endl;
	}
	command_out_file.close();
	read_file.close();

	return 0;
}