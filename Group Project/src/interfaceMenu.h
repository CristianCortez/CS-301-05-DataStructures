/* Author(s): Cristian Cortez if2482
			Paulo Chu za8684
			Kevin Nguyen ta8783
 * Class: CS 301 - 05 (3675) Data Structures and Algorithms
 * Assignment: Group Project Phase 3
 * Date (Submitted): 12/02/2019
*/

#ifndef INTERFACEMENU_H
#define INTERFACEMENU_H
#include "includes.h"
#include "allergy.h"
//#include <string>
using namespace std;
class Menu {
public:
	char getMenu();
	char getDelete();
	char getSearch();
	void setAdd(DataBase*);
	void setSearch(DataBase*, char ch);
	void setDelete(DataBase*, char ch);
};

string runDescription(void);
int getInt(string str);

void display_symptoms();
string itos_symptoms(int);
int stoi_symptoms(string);

#endif // !INTERFACEMENU_H
