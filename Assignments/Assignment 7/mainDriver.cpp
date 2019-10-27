/* Author(s): Cristian Cortez if2482
			Paulo Chu za8684
			Kevin Nguyen ta8783
 * Class: CS 301 - 05 (3675) Data Structures and Algorithms
 * Assignment: Number 7
 * Date (Submitted): 10/27/2019
*/
#include "BST.h"

int main() {
	BSTree* root = NULL;
	int itemArray[100];
	int length = 0;
	ifstream inFile;

	inFile.open("BSTNum.txt");
	if (!inFile) {
		cout << "\nError: Cannot open file for reading."
			 << "\nClosing Program.";
	}
	else {

		while (!inFile.eof()) inFile >> itemArray[length++];
		inFile.close();

		root = root->buildTreeInOrder(itemArray, length);
		root->printTree(root);
	}
	return 0;
}