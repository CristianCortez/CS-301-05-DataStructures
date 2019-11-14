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
	//tmpHead = headPtr;
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
	Allergen* tmp = headPtr, * prev = tmp;
	bool delHead = false;
	if (tmp) {
		while (tmp) {

			if (tmp->comName == comN
				|| tmp->sciName == sciN
				|| tmp->num == n) {
				if (tmp == headPtr) {
					delHead = true;
				}
				prev->next = tmp->next;
				tmp->next = NULL;
				delete tmp;
				tmp = nullptr;
				if (delHead) {
					headPtr = nullptr;
				}
			}
			else {
				prev = tmp;
				tmp = tmp->next;
			}
		}
	}
	tmp = prev = NULL;
}
void DataBase::findComName(string comN) {
	Allergen* search = headPtr;
	if (search) {
		while (search) {
			if (search->comName == comN) {
				break;
			}
		}
		cout << "Common Name: \t\t" << search->comName
			<< "Scientific Name: \t\t" << search->sciName
			<< "Type: \t\t" << search->type
			<< "Number: \t\t" << search->num << endl;
	}
}
void DataBase::findSciName(string sciN) {
	Allergen* search = headPtr;
	if (search) {
		while (search) {
			if (search->comName == sciN) {
				break;
			}
		}
		cout << "Common Name: \t\t" << search->comName
			<< "Scientific Name: \t\t" << search->sciName
			<< "Type: \t\t" << search->type
			<< "Number: \t\t" << search->num << endl;
	}
}
void DataBase::findType(string ty) {
	Allergen* search = headPtr;
	if (search) {
		while (search) {
			if (search->type == ty) {
				cout << "Common Name: \t\t" << search->comName
					<< "Scientific Name: \t\t" << search->sciName
					<< "Type: \t\t" << search->type
					<< "Number: \t\t" << search->num << endl;
			}
		}
	}
}
void DataBase::findNum(int n) {
	Allergen* search = headPtr;
	if (search) {
		while (search) {
			if (search->num == n) {
				break;
			}
		}
		cout << "Common Name: \t\t" << search->comName
			<< "Scientific Name: \t\t" << search->sciName
			<< "Type: \t\t" << search->type
			<< "Number: \t\t" << search->num << endl;
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
	prtStr.str("");
	Allergen* tmp = headPtr;
	if (tmp) {
		while (tmp) {
			prtStr << "\nCommon Name: \t\t" << tmp->comName
				<< "\nScientific Name: \t\t" << tmp->sciName
				<< "\nType: \t\t" << tmp->type
				<< "\nNumber: \t\t" << tmp->num << endl;
			tmp = tmp->next;
		}
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

void DataBase::delComName(string s) {
	Allergen* temp = headPtr;
	Allergen* tempPrev = temp;
	if (temp) {
		while (temp->comName != "s") {
			tempPrev = temp;
			temp = temp->next;
		}
		tempPrev->next = temp->next;
		delete temp;
	}
}
void DataBase::delSciName(string s) {
	Allergen* temp = headPtr;
	Allergen* tempPrev = temp;
	if (temp) {
		while (temp->sciName != "s") {
			tempPrev = temp;
			temp = temp->next;
		}
		tempPrev->next = temp->next;
		delete temp;
	}
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














// c b a
