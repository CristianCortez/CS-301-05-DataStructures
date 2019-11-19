#ifndef HEAPSORT_H
#define HEAPSORT_H
//#include "mainDriverUtility.h"
typedef int ItemType;
//void Swap(ItemType& item1, ItemType& item2);
template<class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom)
// Post: Heap property is restored.
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(elements, maxChild, bottom);
		}
	}
}

template<class ItemType>
void HeapSort(ItemType values[], int numValues)
// Pre:  Struct HeapType is available.
// Post: The elements in the array values are sorted by key.
{
	int index;

	// Convert the array of values into a heap.
	for (index = numValues / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);

	// Sort the array.
	for (index = numValues - 1; index >= 1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}
}
/*
void Swap(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped.
{
	ItemType tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}
*/

#endif // !HEAPSORT_H