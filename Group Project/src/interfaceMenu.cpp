#include "includes.h"
#include "allergy.h"
#include "interfaceMenu.h"
string runDescription(void) {
	stringstream prtStr;
	prtStr << "Description: How to use this program: "
		<< "\n\tSearch the allergen database. "
		<< "\n\tDelete an allergen from the database. "
		<< "\n\tAdd an allergen to the database."
		<< "\n\t(Alphabatized by Science Name)"
		// << "\n\tShow symptoms from the allergic reaction. "
		// << "\n\tGo back feature to the menu. "
		<< "\n\tExits the menu. "
		<< "\n\t:: THE FOLLOWING IS A COLLECTION OF ALLERGENS ::" << endl;
	return prtStr.str();
}

char Menu::getMenu() {
	char choice;

	cout << "*AllerCo Main Menu:                        *"
		 << "\n\t*A - Add allergen to database          *"
		 << "\n\t*D - Delete allergen from the database *"
		 << "\n\t*S - Search allergen in the database   *"
		 // "\n\t*H - Show symptoms from the allergic reaction "
		 << "\n\t*Q - Exits the menu                    *"
		<< endl;
	cin >> choice;

	choice = putchar(toupper(choice));
	/*cout << "\b" << "";*/

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
	choice = putchar(toupper(choice));
	//cout << "\b" << "";

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

	choice = putchar(toupper(choice));
	//cout << "\b" << "";

	return choice;
}

void Menu::setDelete(DataBase* db, char input) {
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	string comName, sciName;
	int num;
	//deletes by common name
	if (input == 'C') {
		cout << "Enter the common name of the allergen you wish to delete:.......... ";
		cin >> comName;
		(db)->delAl(comName, "", 0);
	}
	// deletes by scientific name
	else if (input == 'S') {
		cout << "Enter the scientific name of the allergen you wish to delete:...... ";
		cin >> sciName;
		db->delAl("", sciName, 0);
	}
	//deletes by ncbi number
	else if (input == 'N') {
		cout << "Enter the NCBI number of the allergen you wish to delete:...........";
		cin >> num;
		db->delAl("", "", num);
	}
	else {
		cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
		return;
	}
}

void Menu::setSearch(DataBase* db, char input) {
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	string comName, sciName, type;
	int num;
	//searches by common name
	if (input == 'C') {
		cout << "Enter the Common Name of the allergen:.......... ";
		cin >> comName;
		db->findComName(comName);
	}
	//searches by scientific name
	else if (input == 'S') {
		cout << "Enter the Scientific Name of the allergen:...... ";
		cin >> sciName;
		db->findSciName(sciName);
	}
	//searches by type
	
	else if (input == 'T') {
		cout << "Enter the Type of the allergen:................. ";
		cin >> type;
		db->findType(type);
	}
	
	//searches by ncbi number
	else if (input == 'N') {
		cout << "Enter the NCBI Number of the allergen:.......... ";
		cin >> num;
		db->findNum(num);
	}
	else {
		cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
		return;
	}
}

void Menu::setAdd(DataBase* myDataBase) {
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	string comName, sciName, type, num, syms;
	int n;
	bool loop = true;

	do {
		cout << "Enter the Common Name of the allergen:.......... ";
		cin >> comName;
		//getline(cin, comName);
		if ((myDataBase)->isCommonName(comName)) {
			loop = false;
		}
		else {
			cout << "\n::INVALID ENTRY::" << endl;
		}
	} while (loop);

	loop = true;
	do {
		cout << "Enter the Scientific Name of the allergen:...... ";
		cin >> sciName;
		if ((myDataBase)->isSciName(sciName))
			loop = false;
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	do {
		cout << "Enter the Type of the allergen:................. ";
		cin >> type;
		if ((myDataBase)->isType(type))
			loop = false;
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	do {
		cout << "Enter the NCBI Number of the allergen:.......... ";
		cin >> num;
		if ((myDataBase)->isNum(num)) {
			n = stoi(num);
			loop = false;
		}
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	do {
		cout << "Enter the single digit numbers for each symptom:..."
			<< "\n::Press \"0\" to see list of symptoms::\n"
			<< ".....";
		cin >> syms;
		n = getInt(num);
		if (n == 0)
			display_symptoms();
		else
			loop = false;
	} while (loop);

	((myDataBase)->addAl(comName, sciName, type, n, syms));
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
}

int getInt(string str) {
	int num = 0;
	int tens = 1;
	for (int i = str.size() - 1; i >= 0; i--) {

		if (str[i] <= '9' && str[i] >= '0') {
			num += ((str[i] - 48)* tens);
			str.erase(i);
		}
		tens *= 10;
	}
	return num;
}

void display_symptoms() {
	cout << "Symptoms List: "
		<< "\n\t1. Runny / Stuffy Nose"
		<< "\n\t2. Coughing"
		<< "\n\t3. Sneezing"
		<< "\n\t4. Breathing Problems"
		<< "\n\t5. Watery Eyes"
		<< "\n\t6. Itching"
		<< "\n\t7. Rash"
		<< "\n\t8. Swollen Mucous Membranes"
		<< "\n\t9. Gastrointestinal Problems";
	return;
}
string itos_symptoms(int idx){
	if (idx == 1)
		return "Runny / Stuffy Nose";
	else if (idx == 2)
		return "Coughing";
	else if (idx == 3)
		return "Sneezing";
	else if (idx == 4)
		return "Breathing Problems";
	else if (idx == 5)
		return "Watery Eyes";
	else if (idx == 6)
		return "Itching";
	else if (idx == 7)
		return "Rash";
	else if (idx == 8)
		return "Swollen Mucous Membranes";
	else if (idx == 9)
		return "Gastrointestinal Problems";
	else
		return "";
}
int stoi_symptoms(string str) {	
	if (str == "Runny / Stuffy Nose")
		return 1;
	else if (str == "Coughing")
		return 2;
	else if (str == "Sneezing")
		return 3;
	else if (str == "Breathing Problems")
		return 4;
	else if (str == "Watery Eyes")
		return 5;
	else if (str == "Itching")
		return 6;
	else if (str == "Rash")
		return 7;
	else if (str == "Swollen Mucous Membranes")
		return 8;
	else if (str == "Gastrointestinal Problems")
		return 9;
	else
		return 0;
}
