#include "includes.h"

void runDescription() {
	cout << " This is an allergen database used to help users\n"
		<< " build profiles for the various allergies of the human species.\n\n"
		<< " Please make sure to have all information on hand to allow\n"
		<< " easy data entry and access.\n" << endl;
}
void runMainMenu() {
	
	int option = 0;
	while (option != 3) {
		cout <<"\n*************************"
			<< "\n*   AllerCo DataBase    *"
			<< "\n* 1. Add Entry          *"
			<< "\n* 2. Delete Entry       *"
			<< "\n* 3. Quit               *"
			<< "\n*************************" << endl;
		cin >> option;
		
	
		switch (option) {
		case 1: // add
			break;
		case 2: // delete
			break;
		case 3: // quit
			break;
		default:
			cout << "\tNot a valid option." << endl;
			break;
		}
	}

}