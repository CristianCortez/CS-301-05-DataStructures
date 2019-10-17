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
		for (int c = 1; c < len; c++)
			insertNode(root, arr[c]);
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
};

int main()
{
	Tree *tree = nullptr;
	int arr[100];
	int length = 0;

	ifstream inFile;
	inFile.open("BST.txt");
	if (!inFile)
	{
		cout << "Error: Cannot open file for reading.";
		exit(0);
	}

	while (!inFile.eof())
	{
		inFile >> arr[length++];
	}
	inFile.close();

	tree = tree->sortAscending(arr, length);

	tree->inOrder(tree);

	return 1;
}
