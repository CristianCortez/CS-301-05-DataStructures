/* Author(s): Cristian Cortez if2482
			Paulo Chu za8684
			Kevin Nguyen ta8783
 * Class: CS 301 - 05 (3675) Data Structures and Algorithms
 * Assignment: Number 7
 * Date (Submitted): 10/27/2019
*/
#include "BST.h"
BSTree* BSTree::createNode(int num) {
	treePtr newNode = new BSTree;
	newNode->data = num;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTree* BSTree::insertInOrder(treePtr myTree, int num) {
	if (!myTree)
		return createNode(num);
	// Number smaller than root go left:
	if (num < myTree->data)
		myTree->left = insertInOrder(myTree->left, num);
	// Number larger than root go right:
	else if (num > myTree->data)
		myTree->right = insertInOrder(myTree->right, num);

	return myTree;
}

BSTree* BSTree::buildTreeInOrder(int arr[], int length) {
	treePtr root = NULL;
	root = insertInOrder(root, arr[0]);
	for (int i = 1; i < length; i++)
		insertInOrder(root, arr[i]);
	return root;
}

void BSTree::printTree(treePtr myTree) {
	if (myTree) {
		printTree(myTree->left);
		cout << myTree->data << " ";
		printTree(myTree->right);
	}
}
