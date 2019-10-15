#ifndef INTERFACEMENU_H
#define INTERFACEMENU_H
#include "includes.h"
//#include <string>
using namespace std;
class Menu {
public:
	char getMenu();
	char getDelete();
	char getSearch();
	void setAdd();
	void setSearch(char ch);
	void setDelete(char ch);
	//void setSymptoms();

};

string runDescription(void);
//void runMainMenu();
#endif // !INTERFACEMENU_H