#pragma once
#ifndef ALLERGY_H
#define ALLERGY_H
#include "includes.h"

class Allergen {
	// 'al' used for all memebers of Allergen.
private:
	string alName;
	string alType;
	int alNum;
	string alNomen;

	Allergen* next;
public:
	void setAlName();
	void getAlName();
	void setAlType();
	void getAlType();
	void setAlNum();
	void getAlNum();
	void setAlNomen();
	void getAlNomen();

};

struct Allergen {
	string name;
	string type;
	int number;
	string nomenclature;
};
#endif // !ALLERGY_H