#include "includes.h"
#include "allergy.h"
#include "interfaceMenu.h"
string runDescription(void) {
	stringstream prtStr;
	prtStr << "Description: How to use this program: "
		<< "\n\tSearch the allergen database. "
		<< "\n\tDelete an allergen from the database. "
		<< "\n\tAdd an allergen to the database. "
		// << "\n\tShow symptoms from the allergic reaction. "
		// << "\n\tGo back feature to the menu. "
		<< "\n\tExits the menu. "
		<< "\n\t:: THE FOLLOWING IS A COLLECTION OF ALLERGENS ::" << endl;
	return prtStr.str();
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

	choice = putchar(toupper(choice));
	cout << "\b" << "";

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
	cout << "\b" << "";

	choice = putchar(toupper(choice));

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
	cout << "\b" << "";

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
	else if (input == 'S') {
		cout << "Enter the scientific name of the allergen you wish to delete: " << endl;
		cin >> sciName;
	}

	//deletes by ncbi number
	else if (input == 'N') {
		cout << "Enter the NCBI number of the allergen you wish to delete: " << endl;
		cin >> num;
	}

	else
		return;
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
		return;
}

void Menu::setAdd(DataBase* myDataBase) {
	string comName, sciName, type, num;
	int n;
	bool loop = true;
	
	do {
		cout << "Enter the common name of the allergen: " << endl;
		cin >> comName;
		if (myDataBase->isCommonName(comName)) {
			loop = false;
		}
		else {
			cout << "\n::INVALID ENTRY::" << endl;
		}
	} while (loop);

	loop = true;
	do {
		cout << "Enter the scientific name of the allergen:
		     << (First 3 Letters of your Common Name & Last 3 digits of your NCBI# \"Pea345\")" << endl;
		cin >> sciName;
		if (myDataBase->isSciName(sciName))
			loop = false;
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	do {
		cout << "Enter the type of the allergen: " << endl;
		cin >> type;
		if (myDataBase->isType(type))
			loop = false;
		else 
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	do {
		cout << "Enter the NCBI number of the allergen: " << endl;
		cin >> num;
		if (myDataBase->isNum(num)) {
			n = stoi(num);
			loop = false;
		}
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);
	myDataBase->addAl(comName, sciName, type, n);
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
