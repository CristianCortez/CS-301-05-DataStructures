#include "includes.h"

int main() {
	runDescription();
	Menu opt;
	char option, choice;

	do {
		char ch = opt.getMenu();

		switch (ch) {
		case 'A':
			do {
				opt.setAdd();

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
		case 'Q':
			//exit(1);
			break;
		default:
			cout << ":: INVALID CHOICE ::" << endl;
		}

		cout << "Do you want to look at the menu again? (Y/N) " << endl;
		cin >> choice;
		choice = putchar(toupper(choice));
		cout << "\b" << "";
	} while (choice != 'N');

	return 0;
}
