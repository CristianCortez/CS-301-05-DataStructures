#ifndef SORTBUBBLE_H
#define SORTBUBBLE_H
template<class ItemType>
void BubbleUp2(ItemType values[], int startIndex, int endIndex,
	bool& sorted)
	// Post: Adjacent pairs that are out of order have been switched 
	//       between values[startIndex]..values[endIndex] beginning at 
	//       values[endIndex].
	//       sorted is false if a swap was made; otherwise, true.
{
	sorted = true;
	for (int index = endIndex; index > startIndex; index--)
		if (values[index] < values[index - 1])
		{
			Swap(values[index], values[index - 1]);
			sorted = false;
		}
}

typedef int ItemType;
template<class ItemType>
void ShortBubble(ItemType values[], int numValues)
// Post: The elements in the array values are sorted by key.
//       The process stops as soon as values is sorted.
{
	int current = 0;
	bool sorted = false;
	while (current < numValues - 1 && !sorted)
	{
		BubbleUp2(values, current, numValues - 1, sorted);
		current++;
	}
}





#endif // !SORTBUBBLE_H