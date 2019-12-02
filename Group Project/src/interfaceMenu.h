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
void display_symptoms();
string itos_symptoms(int);
int stoi_symptoms(string);
string runDescription(void);
int getInt(string str);

#endif // !INTERFACEMENU_H
