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
void DataBase::addAl(string comN, string sciN, string ty, int n) {
	Allergen* newNode;
	newNode->comName = comN;
	newNode->sciName = sciN;
	newNode->type = ty;
	newNode->num = n;
	newNode->next = NULL;
	alphaMe(newNode);
}
void DataBase::alphaMe(Allergen* newAl) {
	Allergen* tmpHead = headPtr;
	Allergen* previous = NULL;
	int i = 0;
	if (headPtr == NULL || headPtr->sciName[0] > newAl->sciName[0]) {
		newAl->next = headPtr;
		headPtr = newAl;
	}
	else {
		do {
			previous = tmpHead;
			if (tmpHead->sciName[i] == newAl->sciName[i])
				i++;
			else {
				i = 0;
				tmpHead = tmpHead->next;
			}

		} while (tmpHead && tmpHead->sciName[i] <= newAl->sciName[i]);
		if (previous->sciName.compare(newAl->sciName) == 0) {
			if (previous->num > newAl->num) {
				newAl->next = previous->next;
				previous->next = newAl;
			}
		}
		else {
			newAl->next = previous->next;
			previous->next = newAl;
		}
	}
}
void DataBase::delAl(int x, string comN, string sciN, int n) {
	Allergen* tmp = headPtr, *prev = NULL;
	if (tmp) {
		while (tmp) {
			if (tmp->comName == comN
				|| tmp->sciName == sciN
				|| tmp->num == n) {
				prev->next = tmp->next;
				tmp->next = NULL;
				delete tmp;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
	tmp = prev = NULL;
}
void DataBase::findComName(string comN) {
	Allergen* search = headPtr;

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