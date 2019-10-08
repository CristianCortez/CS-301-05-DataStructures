#include "includes2.h"

int main() {
	runDescription();
	Menu opt;
	char option, choice;

	do {
		char ch = opt.getMenu();

		switch (ch) {
			case 'A':
				opt.setAdd();
				break;
			case 'D':
				do {
					option = opt.getDelete();
					opt.setDelete(option);

					cout << "Do you want to delete another allergen? (Y\N) " << endl;
					cin >> choice;
				} while (choice != 'N');
				break;
			case 'S':
				do {
					option = opt.getSearch();
					opt.setSearch(option);

					cout << "Do you want to search another allergen? (Y\N) " << endl;
					cin >> choice;
				} while (choice != 'N');
				break;
			/*case 'H':
				break;
				*/
			case 'Q':
				exit(1);
				break;
			default:
				cout << "Enter a choice: " << endl;
		}

		cout << "Do you want to look at the menu again? (Y\N) " << endl;
		cin >> choice;
	} while (choice != 'Q');
}