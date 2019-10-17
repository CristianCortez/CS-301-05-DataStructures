#ifndef BST_H
#define BST_H


class Tree
{
	int data;
	Tree *leftChild, *rightChild;
public:

	Tree *newNode(int num);
	void sortOrder(Tree *root, int arr[], int &location);
	Tree* insertNode(Tree* root, int num);
	Tree * sortAscending(int arr[], int length);
	void inOrder(Tree* root);

#endif // !BST_H

