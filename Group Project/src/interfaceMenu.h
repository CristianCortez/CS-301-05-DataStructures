#pragma once
#ifndef INTERFACEMENU_H
#define INTERFACEMENU_H
#include "includes.h"

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

#endif // !INTERFACEMENU_H
