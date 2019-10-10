#include "includes.h"

void runDescription() {
	cout << "Here is the description: "
		<< "\n\tSearch the allergen database. "
		<< "\n\tDelete an allergen from the database. "
		<< "\n\tAdd an allergen to the database. "
		// << "\n\tShow symptoms from the allergic reaction. "
		// << "\n\tGo back feature to the menu. "
		<<"\n\tExits the menu. "
		<< endl;
}

char Menu::getMenu() {
	char choice;

	cout << "AllerCo Main Menu: "
		<< "\n\tA - Add allergen to database "
		<< "\n\tD - Delete allergen from the database "
		<< "\n\tS - Search allergen in the database "
		// "\n\tH - Show symptoms from the allergic reaction "
		<< "\n\tQ - Exits the menu "
		<< endl;
	cin >> choice;

	putchar(toupper(choice));

	return choice;
}

char Menu::getDelete() {
	char choice;
	
	cout << "Allerco Delete Menu: "
		<< "\n\tC - Deletes by common name "
		<< "\n\tS - Deletes by science name "
		<< "\n\tN - Deletes by NCBI number "
		<< "\n\tQ - Exits the menu "
		<< endl;
	cin >> choice;

	putchar(toupper(choice));

	return choice;
}

char Menu::getSearch() {
	char choice;

	cout << "AllerCo Search Menu: "
		<< "\n\tC - Search by common name "
		<< "\n\tS - Search by science name "
		// << "\n\tT - Search by type "
		<< "\n\tN - Search by NCBI number "
		<< "\n\tQ - Exits the menu "
		<< endl;
	cin >> choice;

	putchar(toupper(choice));

	return choice;
}

void Menu::setDelete(char input) {
	string comName, sciName;
	int num;
	DataBase db;

	//deletes by common name
	if (input == 'C') {
		cout << "Enter the common name of the allergen you wish to delete: " << endl;
		cin >> comName;
	}

	// deletes by scientific name
	else if (input == 'C') {
		cout << "Enter the scientific name of the allergen you wish to delete: " << endl;
		cin >> sciName;
	}

	//deletes by ncbi number
	else if (input == 'N') {
		cout << "Enter the NCBI number of the allergen you wish to delete: " << endl;
		cin >> num;
	}

	else
		exit(1);
}

void Menu::setSearch(char input) {
	string comName, sciName, type;
	int num;
	DataBase db;

	//searches by common name
	if (input == 'C') {
		cout << "Enter the Common Name of the allergen: " << endl;
		cin >> comName;
		db.findComName(comName);
	}

	//searches by scientific name
	else if (input == 'S') {
		cout << "Enter the Scientific Name of the allergen: " << endl;
		cin >> sciName;
		db.findSciName(sciName);
	}

	//searches by type
	/*
	else if (input == 'T') {
		cout << "Enter the type of the allergen: " << endl;
		cin >> type;
		db.findType(type);
	}
	*/
	//searches by ncbi number
	else if (input == 'N') {
		cout << "Enter the NCBI Number of the allergen: " << endl;
		cin >> num;
		db.findNum(num);
	}

	else
		exit(1);
}

void Menu::setAdd() {
	string comName, sciName, type;
	int num;
	DataBase db;

	cout << "Enter the common name of the allergen: " << endl;
	cin >> comName;

	cout << "Enter the scientific name of the allergen: " << endl;
	cin >> sciName;

	cout << "Enter the type of the allergen: " << endl;
	cin >> type;

	cout << "Enter the NCBI number of the allergen: " << endl;
	cin >> num;

	db.addAl(comName, sciName, type, num);
}

/*
void Menu::getSymptoms(){
	cout << "Symptoms List: "
	<< "\n\t..."
}
*/

/*
void Menu::setSymptoms(int input){
	if (input < 6){
		cout << "You have a mild case of allergic reaction. " << endl;
	}
	else {
		cout << " You have a severve case of allergic reaction. Please get medical help ASAP. " << endl;
	}
}
*/
