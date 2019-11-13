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
	void setSearch(char ch);
	void setDelete(DataBase*, char ch, bool&);
	//void setSymptoms();

};

string runDescription(void);
//void runMainMenu();
#endif // !INTERFACEMENU_H