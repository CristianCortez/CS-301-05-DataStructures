#include "BST.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

Tree* Tree::newNode(int num)
{
	Tree *newNode = new Tree;
	newNode->data = num;
	newNode->leftChild = newNode->rightChild = nullptr;
	return newNode;
}

void Tree::sortOrder(Tree *root, int arr[], int &location)
{
	if (root != nullptr)
	{
		sortOrder(root->leftChild, arr, location);
		arr[location++] = root->data;
		sortOrder(root->rightChild, arr, location);
	}
}

Tree* Tree::insertNode(Tree* root, int num)
{
	if (root == nullptr)
		return newNode(num);

	if (num < root->data)
		root->leftChild = insertNode(root->leftChild, num);

	else if (num > root->data)
		root->rightChild = insertNode(root->rightChild, num);

	return root;
}

Tree* Tree::sortAscending(int arr[], int length)
{
	Tree *root = nullptr;
	int l = 0;

	root = insertNode(root, arr[0]);
	for (int i = 1; i < length; i++)
		insertNode(root, arr[i]);
	sortOrder(root, arr, l);
	return root;
}

void Tree::inOrder(Tree* root)
{
	if (root == nullptr)
		return;
	inOrder(root->leftChild);
	cout << root->data << " ";
	inOrder(root->rightChild);
}

