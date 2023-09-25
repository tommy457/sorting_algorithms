#include "sort.h"

void swap(int *x, int *y);

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of the array.
 *
 * Rerurn: NA
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (!array || !size)
		return;
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
				swap(&array[j], &array[j - gap]);
		}
		gap /= 3;
		print_array((const int *)array, size);
	}
}

/**
 * swap - swaps two elements.
 * @x: 1st element.
 * @y: 2nd element.
 *
 * Rerurn: NA
 */
void swap(int *x, int *y)
{
	int tmp;

	if (*x != *y)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
	}
}
