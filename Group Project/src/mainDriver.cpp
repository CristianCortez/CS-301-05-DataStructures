#include "includes.h"

int main() {
	//ifstream read_file;
	ofstream write_file;
	write_file.open("AllergenDataBase.txt");
	write_file << "ALLERCO: Organizing The World's Allergies\n" << endl
		<< runDescription() << endl;

	DataBase* allergen_db = new DataBase;
	Menu opt;
	char option, choice;

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
				opt.setDelete(option);

				cout << "Do you want to delete another allergen? (Y/N) " << endl;
				cin >> choice;
				choice = putchar(toupper(choice));
				cout << "\b" << "";
			} while (choice != 'N');
			break;
		case 'S':
			do {
				option = opt.getSearch();
				opt.setSearch(option);

				cout << "Do you want to search another allergen? (Y/N) " << endl;
				cin >> choice;
				choice = putchar(toupper(choice));
				cout << "\b" << "";
			} while (choice != 'N');
			break;
			/*case 'H':
				opt.setSymptoms();
				break;
				*/
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

	return 0;
}