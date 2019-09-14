#ifndef ITEMTYPEUTILITY_H
#define ITEMTYPEUTILITY_H
#include "ItemType.h"
#include <string>
#include <sstream>
#include <fstream>

using std::string;

struct node {
	int num;
	node* next;
};


class List {
private:
	node* headPtr;
public:
	List() { headPtr = nullptr; }
	~List();
	int getLength();
	void PutItem(int);
	string printList();
	bool getItem(int);
	bool isFull();
	bool deleteItem(int);
	
	string extractInt(string, int*);
};
void runMenu();


#endif // !ITEMTYPEUTILITY_H
