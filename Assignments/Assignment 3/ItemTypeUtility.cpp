#include "ItemType.h"
#include "ItemTypeUtility.h"

using namespace std;

List::~List() {
	while (headPtr) {
		node *tmp = headPtr;
		headPtr = headPtr->next;
		delete tmp;
		cout << "Node Destoyed by destructor..." << endl;
	}
}
int List::getLength() {
	node *currentNodeAddr = headPtr;
	int size = 0;
	do {
		size++;
		currentNodeAddr = currentNodeAddr->next;
	} while (currentNodeAddr);

	return size;
}
void List::PutItem(int n) {
	node *tmp = new node;
	tmp->num = n;
	tmp->next = headPtr;
	headPtr = tmp;
	cout << n << " is in list" << endl;
}
string List::printList() {
	ostringstream prtList;
	
	node* listAddr = headPtr;
	while (listAddr) {
		cout << listAddr->num << endl;
		prtList << listAddr->num;

	}
	return prtList.str();
}
bool List::getItem(int num) {
	bool found = false;
	node* listAddr = headPtr;
	while (listAddr) {
		if (listAddr->num == num) {
			found = true;
		}
		listAddr = listAddr->next;
	}
	return found;
}
bool List::isFull() {
	int counter = 0;
	node* listAddr = headPtr;
	while (listAddr) {
		counter++;
		listAddr = listAddr->next;
	}
	if (counter == 5)
		return true;
	return false;
}
bool List::deleteItem(int n) {
	node* listAddr = headPtr, *previousNode = NULL;
	if (listAddr && listAddr->num == n) {
		headPtr = listAddr->next;
		delete listAddr;
		return true;
	}
	while (listAddr && listAddr->num != n) {
		previousNode = listAddr;
		listAddr = listAddr->next;
	}
	if (listAddr == NULL) return false;
	previousNode->next = listAddr->next;
	delete listAddr;
	return true;
}

string List::extractInt(string str, int* num) {
	
	for (int i = 0; i < str.size(); i++) {
		// if the char is a num:
		if (str[i] <= '9' && str[i] >= '0') {
			*num = str[i] - 48;
			str.erase(i);
			PutItem(*num);
		}
	}
	return str;
}

void runMenu() {
	ifstream fileIn; // file to read from
	ofstream fileOut; // file to write to
	string inFile;
	string outFile;
	string test;
	string fileContents;
	int commandCount = 0, commandFlag;
	int* extractedNum;
	extractedNum = new int;
	List* head = NULL;
	head = new List();
	bool quit = false;
	cout << "Enter name of input command file; press return." << endl;
	cin >> inFile;

	cout << "Enter name of output file; press return." << endl;
	cin >> outFile;

	cout << "Enter name of test run; press return;" << endl;
	cin >> test;

	fileIn.open(inFile.c_str()); 
	fileOut.open(outFile.c_str());
	// we want to follow the commands found within the input file
	// the commands will then tell us what to do 
	// each todo from the commands should be written to the output file
	// the console should just display wether we the command is valid or not
	while (getline(fileIn, fileContents) || quit != true) {
		if (!head)
			head = new List();
		commandFlag = 0;
		commandCount++;
		// NOTE: We need a way to find the null character from line from input file
		// there is a gap between the comamnd name and the number 
		// maybe we need to fill an char array with the string command.

		/* We need to extract the integer from string
		 and we need to remove the integer from string*/
		
		fileContents = head->extractInt(fileContents, extractedNum);
		if (fileContents == "GetLength ") {
			int length = 0;
			length = head->getLength();
			fileOut << "Length is " << length << endl;

		}
		else if (fileContents == "PutItem ") {
			head->PutItem(*extractedNum);
			fileOut << *extractedNum << " is in List" << endl;

		}
		else if (fileContents == "PrintList ") {
			fileOut << head->printList();
		}
		else if (fileContents == "GetItem ") {
			bool found = head->getItem(*extractedNum);
			if (found)
				fileOut << *extractedNum << " found in list." << endl;
			else
				fileOut << *extractedNum << " not in list." << endl;
		}
		else if (fileContents == "IsFull ") {
			bool full = head->isFull();
			if (full)
				fileOut << "List is full." << endl;
			else
				fileOut << "List is not full." << endl;
		}
		else if (fileContents == "DeleteItem ") {
			bool deletedItem = head->deleteItem(*extractedNum);
			if (deletedItem)
				fileOut << extractedNum << " is deleted" << endl;
			else
				fileOut << extractedNum << " was not found and cannot delete." << endl;
		}
		else if (fileContents == "MakeEmpty ") {
			delete head;
			head = NULL;
		}
		else if (fileContents == "Quit ") {
			quit = true;
		}
		else {
			commandFlag = 1;
			cout << "\" " << fileContents << "\" is not a valid command." << endl;
		}

		if (commandFlag = 0)
			cout << " Command number " << commandCount << " completed." << endl;
		
		
	}
	if (head) {
		delete head;
		head = NULL;
	}
	cout << "Testing completed." << endl;
	fileIn.close();
	fileOut.close();
}
