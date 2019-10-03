#include "includes.h"

void runDescription() {
	cout << " This is an allergen database used to help users\n"
		<< " build profiles for the various allergies of the human species.\n\n"
		<< " Please make sure to have all information on hand to allow\n"
		<< " easy data entry and access.\n" << endl;
}

//Search Function
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

//Delete Function
void deleteMenu() {
	int opt = 0;
	string name, sciName;
	int number;

	while (opt != 4) {
		cout << "\n***************************"
			<< "\n*		Aller Delete Menu	*"
			<< "\n*		1. Common Name		*"
			<< "\n*		2. Nomenclature		*"
			<< "\n*		3. NCBI Number		*"
			<< "\n*		4. Exit				*"
			<< "\n****************************" << endl;
	}

	switch (opt) {
		case 1: // common name
			cout << "Please enter the name of the allergen you wish to delete: " << endl;
			cin >> name;
			break;

		case 2: // Nomenclature
			cout << "Please enter the Nomenclature of the allergen you wish to delete: " << endl;
			cin >> sciName;
			break;

		case 3: //NCBI Number
			cout << "Please enter the NCBI Number of the allergen you wish to delete: " << endl;
			cin >> number;
			break;

		case 4: //exit
			break;

		default:
			cout << "\tNot a valid option" << endl;
			break;
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
				cout << "Please enter an allergen first." << endl;
			}
			break;
		case 2: // delete
			if (sFlag) {

			}
			else {
				cout << "Please enter an allergen first." << endl;
			}
			break;
		case 3: // searches
			if (sFlag) {
				searchMenu();
			}
			else {
				cout << "Please enter an allergen first." << endl;
			}
				break;
			case 4: // quit
				if (sFlag) {

				}
				else {
					cout << "Please enter an allergen first." << endl;
				}
				break;
			default:
				cout << "\tNot a valid option." << endl;
				break;
		}
	} while (option = !5);
}
