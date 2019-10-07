#include "includes.h"

DataBase::~DataBase() {
	Allergen* tmp;
	if (headPtr) {
		while (headPtr) {
			tmp = headPtr;
			headPtr = headPtr->next;
			tmp->next = NULL;
			delete tmp;
		}
	}
}

void DataBase::delComName(string s) {
	Allergen* temp = headPtr;
	Allergen* tempPrev = nullptr;
	while (temp->comName != "s") {
		tempPrev = temp;
		temp = temp->next;
	}
	tempPrev->next = temp->next;
	delete temp;
}


void DataBase::delSciName(string s) {
	Allergen* temp = headPtr;
	Allergen* tempPrev = nullptr;
	while (temp->sciName != "s") {
		tempPrev = temp;
		temp = temp->next;
	}
	tempPrev->next = temp->next;
	delete temp;
}

void DataBase::delNum(int n) {
	Allergen* temp = headPtr;
	Allergen* tempPrev = nullptr;
	while (temp->num != n) {
		tempPrev = temp;
		temp = temp->next;
	}
	tempPrev->next = temp->next;
	delete temp;
}