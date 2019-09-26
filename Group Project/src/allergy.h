#ifndef ALLERGY_H
#define ALLERGY_H
#include "includes.h"

class Allergen {
// 'al' used for all memebers of Allergen.
private:
	string alName;
	string alType;
	int alNum;

	Allergen* next;
public:
	void setAlName();
	void getAlName();
	void setAlType();
	void getAlType();
	void setAlNum();
	void getAlNum();


	
};

#endif // !ALLERGY_H