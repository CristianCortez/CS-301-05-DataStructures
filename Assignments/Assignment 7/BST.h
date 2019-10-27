/* Author(s): Cristian Cortez if2482
			Paulo Chu za8684
			Kevin Nguyen ta8783
 * Class: CS 301 - 05 (3675) Data Structures and Algorithms
 * Assignment: Number 7
 * Date (Submitted): 10/27/2019
*/
#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>

using namespace std;

class BSTree {
private:
	int data;
	BSTree *left, *right;
public:
	typedef BSTree* treePtr;
	treePtr createNode(int);
	treePtr insertInOrder(treePtr, int);
	treePtr buildTreeInOrder(int[], int);
	void printTree(treePtr);
};

#endif // !BST_H
