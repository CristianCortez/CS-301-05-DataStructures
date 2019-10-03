#ifndef ALLERGY_H
#define ALLERGY_H
#include "includes.h"



class DataBase {
private:
	struct Allergen {
		string comName;
		string sciName;
		string type;
		int num;
		Allergen* next;
	};
	Allergen* headPtr;
public:
	DataBase() { headPtr = nullptr; }
	~DataBase();

	void addAl(string, string, string, int);
	void delAl(int, string, string, int);
	void findComName(string);
	void findSciName(string);
	void findType(string);
	void findNum(int);

	void print();
	int getLength();

	
};

#endif // !ALLERGY_H