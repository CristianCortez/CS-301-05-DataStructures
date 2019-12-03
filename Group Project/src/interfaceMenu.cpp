/* Author(s): Cristian Cortez if2482
			Paulo Chu za8684
			Kevin Nguyen ta8783
 * Class: CS 301 - 05 (3675) Data Structures and Algorithms
 * Assignment: Group Project Phase 3
 * Date (Submitted): 12/02/2019
*/

#include "includes.h"
#include "allergy.h"
#include "interfaceMenu.h"

char Menu::getMenu() {
	char choice;

	cout << "AllerCo Main Menu: "
		 << "\n\tA - Add allergen to database  "
		 << "\n\tD - Delete allergen from the database"
		 << "\n\tS - Search allergen in the database"
		 << "\n\tQ - Exits the menu"
		<< endl << "...";
	cin >> choice;

	if (choice >= 97 && choice <= 122)
		choice -= 32;

	return choice;
}
char Menu::getDelete() {
	char choice;

	cout << "Allerco Delete Menu: "
		<< "\n\tC - Deletes by common name "
		<< "\n\tS - Deletes by science name "
		<< "\n\tN - Deletes by NCBI number "
		<< "\n\tQ - Exits the menu "
		<< endl << "...";
	cin >> choice;
	if (choice >= 97 && choice <= 122)
		choice -= 32;

	return choice;
}
char Menu::getSearch() {
	char choice;

	cout << "AllerCo Search Menu: "
		<< "\n\tC - Search by common name "
		<< "\n\tS - Search by science name "
		<< "\n\tT - Search by type "
		<< "\n\tN - Search by NCBI number "
		<< "\n\tM - Search by Symptom"
		<< "\n\tQ - Exits the menu "
		<< endl << "...";
	cin >> choice;

	if (choice >= 97 && choice <= 122)
		choice -= 32;

	return choice;
}

void Menu::setAdd(DataBase* myDataBase) {
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	string comName, sciName, type, num, syms;
	int n, m;
	bool loop = true;

	do {
		cout << "Enter the Common Name of the allergen:.......... ";
		cin.ignore();
		getline(cin, comName);
		if (comName[0] >= 97 && comName[0] <= 122)
			comName[0] -= 32;
		if ((myDataBase)->isCommonName(comName)) {
			loop = false;
		}
		else {
			cout << "\n::INVALID ENTRY::" << endl;
		}
	} while (loop);

	loop = true;
	cin.ignore();
	do {
		cout << "Enter the Scientific Name of the allergen:...... ";
		getline(cin, sciName);
		if (sciName[0] >= 97 && sciName[0] <= 122)
			sciName[0] -= 32;
		if ((myDataBase)->isSciName(sciName))
			loop = false;
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	cin.ignore();
	do {
		cout << "Enter the Type of the allergen:................. ";
		getline(cin, type);
		if (type[0] >= 97 && type[0] <= 122)
			type[0] -= 32;
		if ((myDataBase)->isType(type))
			loop = false;
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	cin.ignore();
	do {
		cout << "Enter the NCBI Number of the allergen:.......... ";
		getline(cin, num);
		if ((myDataBase)->isNum(num)) {
			n = stoi(num);
			loop = false;
		}
		else
			cout << "\n::INVALID ENTRY::" << endl;
	} while (loop);

	loop = true;
	cin.ignore();
	do {
		cout << "Enter the single digit numbers for each symptom:..."
			<< "\n::Press \"0\" to see list of symptoms::\n"
			<< ".....";
		getline(cin, syms);
		m = getInt(syms);
		if (m == 0)
			display_symptoms();
		else
			loop = false;
	} while (loop);

	((myDataBase)->addAl(comName, sciName, type, n, syms));
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
}
void Menu::setDelete(DataBase* db, char input) {
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	string comName, sciName;
	int num;
	//deletes by common name
	if (input == 'C') {
		cout << "Enter the common name of the allergen you wish to delete:.......... ";
		cin.ignore();
		getline(cin, comName);
		if (comName[0] >= 97 && comName[0] <= 122)
			comName[0] -= 32;
		(db)->delAl(comName, "", 0);
	}
	// deletes by scientific name
	else if (input == 'S') {
		cout << "Enter the scientific name of the allergen you wish to delete:...... ";
		cin.ignore();
		getline(cin, sciName);
		if (sciName[0] >= 97 && sciName[0] <= 122)
			sciName[0] -= 32;
		db->delAl("", sciName, 0);
	}
	//deletes by ncbi number
	else if (input == 'N') {
		cout << "Enter the NCBI number of the allergen you wish to delete:...........";
		cin.ignore();
		cin >> num;
		db->delAl("", "", num);
	}
	else {
		cout << "\n::INVALID ENTRY::" << endl;
	}
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	return;
}
void Menu::setSearch(DataBase* db, char input) {
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	string comName, sciName, type, syms;
	int num;
	bool loop = true;
	//searches by common name
	if (input == 'C') {
		cout << "Enter the Common Name of the allergen:.......... ";
		cin.ignore();
		getline(cin, comName);
		if (comName[0] >= 97 && comName[0] <= 122)
			comName[0] -= 32;
		db->findComName(comName);
	}
	//searches by scientific name
	else if (input == 'S') {
		cout << "Enter the Scientific Name of the allergen:...... ";
		cin.ignore();
		getline(cin, sciName);
		if (sciName[0] >= 97 && sciName[0] <= 122)
			sciName[0] -= 32;
		db->findSciName(sciName);
	}
	//searches by type
	
	else if (input == 'T') {
		cout << "Enter the Type of the allergen:................. ";
		cin.ignore();
		getline(cin, type);
		if (type[0] >= 97 && type[0] <= 122)
			type[0] -= 32;
		db->findType(type);
	}
	
	//searches by ncbi number
	else if (input == 'N') {
		cout << "Enter the NCBI Number of the allergen:.......... ";
		cin.ignore();
		cin >> num;
		db->findNum(num);
	}
	//searches by symptom
	else if (input == 'M') {
		cin.ignore();
		do {
			cout << "Enter the single digit number of the symptom:..."
				<< "\n::Press \"0\" to see list of symptoms::\n"
				<< ".....";
			
			getline(cin, syms);
			num = getInt(syms);
			if (num == 0)
				display_symptoms();
			else {
				db->findSyms(num);
				loop = false;
			}
		} while (loop);
	}
	else {
		cout << "\n::INVALID ENTRY::" << endl;
	}
	cout << "'''''''''''''''''''''''''''''''''''''''''''''" << endl;
	return;
}

string runDescription(void) {
	stringstream prtStr;
	prtStr << "Description: How to use this program: "
		<< "\n\tSearch the allergen database. "
		<< "\n\tDelete an allergen from the database. "
		<< "\n\tAdd an allergen to the database."
		<< "\n\t(Alphabatized by Science Name)"
		<< "\n\tShow symptoms from the allergic reaction. "
		<< "\n\tExits the menu. "
		<< "\n\t:: THE FOLLOWING IS A COLLECTION OF ALLERGENS ::" << endl;
	return prtStr.str();
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
