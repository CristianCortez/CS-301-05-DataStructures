/* Author(s): Cristian Cortez if2482
			Paulo Chu za8684
			Kevin Nguyen ta8783
 * Class: CS 301 - 05 (3675) Data Structures and Algorithms
 * Assignment: Group Project Phase 3
 * Date (Submitted): 12/02/2019
*/

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
		int symptoms[9];
		Allergen* next;
	};
	Allergen* headPtr;
public:
	DataBase() { headPtr = nullptr; }
	~DataBase();

	void addAl(string, string, string, int, string);
	void alphaMe(Allergen*);
	void delAl(string, string, int);
	void findComName(string);
	void findSciName(string);
	void findType(string);
	void findNum(int);
	void findSyms(int);
	bool isCommonName(string);
	bool isSciName(string);
	bool isType(string);
	bool isNum(string);
	string print();
	int getLength();
};

#endif // !ALLERGY_H