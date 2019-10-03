#include "includes.h"

void runDescription() {
	cout << " This is an allergen database used to help users\n"
		<< " build profiles for the various allergies of the human species.\n\n"
		<< " Please make sure to have all information on hand to allow\n"
		<< " easy data entry and access.\n" << endl;
}

void searchMenu() {
	int opt = 0;
	string name, type, sciName;
	int number;

	while (opt != 5) {
		cout << "\n*************************"
			<< "\n*	 Allerco Search		*"
			<< "\n* 1. Common Name		*"
			<< "\n* 2. Allergen Type	*"
			<< "\n* 3. Nomenclature		*"
			<< "\n* 4. NCBI Number		*"
			<< "\n* 5. Exit				*"
			<< "\n*************************" << endl;
		cin >> opt;
	}
	
	switch (opt) {
		case 1: // common name
			cout << "Enter the name of the allergen you wish to search up: " << endl;
			cin >> name;
			break;

		case 2: // allergen type
			cout << "Enter the allergen type you wish to search up: " << endl;
			cin >> type;
			break;

		case 3: // nomenclature
			cout << "Enter the Nomenclature you wish to search up: " << endl;
			cin >> sciName;
			break;

		case 4: // ncbi number
			cout << "Enter the NCBI Number you wish to search up: " << endl;
			cin >> number;
			break;

		case 5: // exit
			break;

		default:
			cout << "\tNot a valid option." << endl;
	}
	
}

void runMainMenu() {
	int option = 0;
	bool sFlag = false;

	do{
		cout << "\n*************************"
				<< "\n*   AllerCo DataBase    *"
				<< "\n* 1. Add Entry          *"
				<< "\n* 2. Delete Entry       *"
				<< "\n* 3. Search Entry       *"
				<< "\n* 4. Quit               *"
				<< "\n*************************" << endl;
		cin >> option;

		switch (option) {
			case 1: // add
				if (sFlag) {

				}
				else {
					cout << "Please enter an allergen first" << endl;
				}
				break;
			case 2: // delete
				if (sFlag) {

				}
				else {
					cout << "Please enter an allergen first" << endl;
				}
				break;
			case 3: // searches
				searchMenu();
				break;
			case 4: // quit
				break;
			default:
				cout << "\tNot a valid option." << endl;
				break;
		}
	} while (option = !5);
}
