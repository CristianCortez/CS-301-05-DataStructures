#pragma once
#ifndef INTERFACEMENU2_H
#define INTERFACEMENU2_H
#include "includes2.h"

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

void runDescription();
void runMainMenu();

#endif // !INTERFACEMENU2_H