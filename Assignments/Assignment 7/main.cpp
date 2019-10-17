#include "BST.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


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