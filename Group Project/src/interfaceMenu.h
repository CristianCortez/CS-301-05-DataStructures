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
	//char getSymptoms();
	void setAdd(DataBase*);
	void setSearch(DataBase*, char ch);
	void setDelete(DataBase*, char ch);
	//void setSymptoms(DataBase*, char ch);

};

string runDescription(void);
int getInt(string str);
//void runMainMenu();
#endif // !INTERFACEMENU_H
