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