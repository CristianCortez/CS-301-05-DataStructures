#include "includes2.h"

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

	return choice;
}

char Menu::getSearch() {
	char choice;

	cout << "AllerCo Search Menu: "
		<< "\n\tC - Search by common name "
		<< "\n\tS - Search by science name "
		<< "\n\tT - Search by type "
		<< "\n\tN - Search by NCBI number "
		<< "\n\tQ - Exits the menu "
		<< endl;
	cin >> choice;

	return choice;
}

void Menu::setDelete(char ch) {

}

void Menu::setSearch(char ch) {

}

void Menu::setAdd() {
	string comName, sciName, type;
	int num;

	cout << "Enter the common name of the allergen: " << endl;
	cin >> comName;

	cout << "Enter the scientific name of the allergen: " << endl;
	cin >> sciName;

	cout << "Enter the type of the allergen: " << endl;
	cin >> type;

	cout << "Enter the NCBI number of the allergen: " << endl;
	cin >> num;
}

/*
void Menu::setSymptoms(){
	cout << "Symptoms List: "
	<< "\n\t..."
}
*/