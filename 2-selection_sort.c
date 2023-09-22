#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of the array.
 *
 * Rerurn: NA
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx = 0;
	int min;

	if (!array || !size)
		return;

	for (j = 0; j < size; j++)
	{
		min = array[j];
		for (i = j + 1; i < size; i++)
		{
			if (min > array[i])
			{
				min = array[i];
				idx = i;
			}
		}
		if (min != array[j])
		{
			array[idx] = array[j];
			array[j] = min;
			print_array(array, size);
		}
	}
}
