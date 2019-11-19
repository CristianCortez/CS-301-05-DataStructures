#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
template<class ItemType>
void InsertItem(ItemType values[], int startIndex, int
	endIndex)
	// Post: values[0]..values[endIndex] are now sorted.
{
	bool finished = false;
	int current = endIndex;
	bool moreToSearch = (current != startIndex);

	while (moreToSearch && !finished)
	{
		if (values[current] < values[current - 1])
		{
			Swap(values[current], values[current - 1]);
			current--;
			moreToSearch = (current != startIndex);
		}
		else
			finished = true;
	}
}

template<class ItemType>
void InsertionSort(ItemType values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
	for (int count = 0; count < numValues; count++)
		InsertItem(values, 0, count);
}



#endif // !INSERTIONSORT_H