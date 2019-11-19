#ifndef QUICKSORT_H
#define QUICKSORT_H
template <class ItemType>
void Split(ItemType values[], int first, int last, int& splitPoint)
{
	ItemType splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do
	{
		onCorrectSide = true;
		while (onCorrectSide)         // Move first toward last.
			if (values[first] > splitVal)
				onCorrectSide = false;
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}

		onCorrectSide = (first <= last);
		while (onCorrectSide)             // Move last toward first.
			if (values[last] <= splitVal)
				onCorrectSide = false;
			else
			{
				last--;
				onCorrectSide = (first <= last);
			}

		if (first < last)
		{
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	} while (first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}


template<class ItemType>
void QuickSort(ItemType values[], int first, int last)
{
	if (first < last)
	{
		int splitPoint;

		Split(values, first, last, splitPoint);
		// values[first]..values[splitPoint-1] <= splitVal
		// values[splitPoint] = splitVal
		// values[splitPoint+1]..values[last] > splitVal

		QuickSort(values, first, splitPoint - 1);
		QuickSort(values, splitPoint + 1, last);
	}
}
#endif // !QUICKSORT_H