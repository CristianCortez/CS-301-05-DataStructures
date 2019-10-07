#include "includes.h"

//Search Function
void searchMenu() {
	int opt = 0;
	string name, type, sciName;
	int num;
	DataBase db;

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


		switch (opt) {
		case 1: // common name
			cout << "Enter the name of the allergen you wish to search up: " << endl;
			cin >> name;

			db.findComName(name);

			break;
		case 2: // allergen type
			cout << "Enter the allergen type you wish to search up: " << endl;
			cin >> type;

			db.findType(type);

			break;
		case 3: // nomenclature
			cout << "Enter the Nomenclature you wish to search up: " << endl;
			cin >> sciName;

			db.findSciName(sciName);

			break;
		case 4: // ncbi number
			cout << "Enter the NCBI Number you wish to search up: " << endl;
			cin >> num;

			db.findNum(num);

			break;
		case 5: // exit
			break;

		default:
			cout << "\tNot a valid option." << endl;
		}
	}
	
}

//Delete Function
void deleteMenu() {
	int opt = 0;
	string name, sciName;
	int num;
	DataBase db;

	while (opt != 4) {
		cout << "\n***************************"
			<< "\n*	AllerCo Delete Menu		*"
			<< "\n*		1. Common Name		*"
			<< "\n*		2. Nomenclature		*"
			<< "\n*		3. NCBI Number		*"
			<< "\n*		4. Exit				*"
			<< "\n****************************" << endl;


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
			cin >> num;

			break;
		case 4: //exit
			break;

		default:
			cout << "\tNot a valid option" << endl;
			break;
		}
	}
}

//Main Menu
void runMainMenu() {
	int option = 0;
	bool sFlag = false;
	string name, sciName, type;
	int num;

	DataBase db;

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
				cout << "Enter the common name of the allergen: " << endl;
				cin >> name;

				cout << "Enter the type of the allergen: " << endl;
				cin >> type;

				cout << "Enter the nomenclature of the allergen: " << endl;
				cin >> sciName;

				cout << "Enter the NCBI number of the allergen: " << endl;
				cin >> num;

				db.addAl(name, type, sciName, num);
			}
			else {
				cout << "Please enter an allergen first." << endl;
			}
			break;
		case 2: // delete
			if (sFlag) {
				deleteMenu();
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
