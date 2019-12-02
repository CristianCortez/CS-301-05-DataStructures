#ifndef ALLERGY_H
#define ALLERGY_H
#include "includes.h"
#include <string>

using namespace std;

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
	void alphaMe(Allergen*);
	void delAl(string, string, int);
	void findComName(string);
	void findSciName(string);
	void findType(string);
	void findNum(int);	
	bool isCommonName(string);
	bool isSciName(string);
	bool isType(string);
	bool isNum(string);

	//string syms();

	string print();
	int getLength();


};

#endif // !ALLERGY_H