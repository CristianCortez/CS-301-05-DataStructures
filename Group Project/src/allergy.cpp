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
	Allergen* newNode = new Allergen;
	newNode->comName = comN;
	newNode->sciName = sciN;
	newNode->type = ty;
	newNode->num = n;
	newNode->next = NULL;
	alphaMe(newNode);
}
void DataBase::alphaMe(Allergen* newAl) {
	Allergen* tmpHead = nullptr;
	Allergen* previous = tmpHead;
	int i = 0;
	if (headPtr == nullptr || headPtr->sciName[0] > newAl->sciName[0]) {
		newAl->next = headPtr;
		headPtr = newAl;
	}
	else {
		tmpHead = headPtr;
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
void DataBase::delAl(string comN, string sciN, int n) {
	Allergen* tmp = headPtr, *prev = NULL;	
	if (tmp && tmp->comName == comN
		|| tmp->sciName == sciN
		|| tmp->num == n) {
		headPtr = tmp->next;
		delete tmp;
		return;
	}
	while (tmp && (tmp->comName != comN
		|| tmp->sciName != sciN
		|| tmp->num != n)) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp) return;
	
	prev->next = tmp->next;
	delete tmp;
}
void DataBase::findComName(string comN) {
	Allergen* search = headPtr;
	if (search) {
		while (search && comN != search->comName) {
			search = search->next;
		}
		cout << "\nCommon Name:..................." << search->comName
			<< "\nScientific Name:..............." << search->sciName
			<< "\nType:.........................." << search->type
			<< "\nNumber:........................" << search->num << endl;
	}
}
void DataBase::findSciName(string sciN) {
	Allergen* search = headPtr;
	if (search) {
		while (search && sciN != search->sciName) {
			search = search->next;
		}
		if (search) {
			cout << "\nCommon Name:..................." << search->comName
				<< "\nScientific Name:..............." << search->sciName
				<< "\nType:.........................." << search->type
				<< "\nNumber:........................" << search->num << endl;
		}
		else {
			cout << "\t\t NO SUCH ALLERGEN WITH SCI. NAME [" << sciN << "]." << endl;
		}
	}
	cout << "\t\t THE DATABASE IS EMPTY." << endl;
}
void DataBase::findType(string ty) {
	Allergen* search = headPtr;
	if (search) {
		while (search) {
			if (search->type == ty) {
				cout << "\nCommon Name:..................." << search->comName
					<< "\nScientific Name:..............." << search->sciName
					<< "\nType:.........................." << search->type
					<< "\nNumber:........................" << search->num << endl;
			}
		}
	}
}
void DataBase::findNum(int n) {
	Allergen* search = headPtr;
	if (search) {
		while (search && n != search->num) {
			search = search->next;
		}
		cout	<< "\nCommon Name:..................." << search->comName
				<< "\nScientific Name:..............." << search->sciName
				<< "\nType:.........................." << search->type
				<< "\nNumber:........................" << search->num << endl;
	}
}
bool DataBase::isCommonName(string str) {
	int j = -1;
	for (size_t i = 0; i < str.length(); i++) {
		j++;
		if (str[j] >= 48 && str[j] <= 57)
			return false;
	}
	return true;
}
bool DataBase::isSciName(string str) {
	int j = -1;
	for (size_t i = 0; i < str.length(); i++) {
		j++;
		if (str[j] >= 48 && str[j] <= 57)
			return false;
	}
	return true;
}
bool DataBase::isType(string str) {
	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;
	//else
		//str[0] += 32;
	if (str == "Food" || str == "Plant" || str == "Animal")
		return true;
	else
		return false;
}
bool DataBase::isNum(string str) {
	int j = -1;
	for (size_t i = 0; i < str.length(); i++) {
		j++;
		if (str[j] < 48 && str[j] > 57)
			return false;
	}
	return true;
}
string DataBase::print() {
	stringstream prtStr;
	Allergen* tmp = headPtr;
	while (tmp) {
		prtStr << "\nCommon Name:..................." << tmp->comName
			<< "\nScientific Name:..............." << tmp->sciName
			<< "\nType:.........................." << tmp->type
			<< "\nNumber:........................" << tmp->num << endl;
		tmp = tmp->next;
	}
	return prtStr.str();
}
int DataBase::getLength() {
	Allergen* tmp = headPtr;
	int len = 0;
	if (tmp) {
		while (tmp) {
			len++;
			tmp = tmp->next;
		}
	}
	return len;
}
