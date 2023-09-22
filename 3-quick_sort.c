#include "sort.h"

void swap(int *array, size_t size, int *x, int *y);
size_t partition(int *array, size_t size, ssize_t low, ssize_t high);
void quick_sort_recursion(int *array, size_t size, ssize_t low, ssize_t high);

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of the array.
 *
 * Rerurn: NA
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, size, 0, size - 1);
}

/**
 * quick_sort_recursion - sorts an array of integers in a recursive way.
 * @array: array to sort.
 * @size: size of the array.
 * @low: start point index.
 * @high: end point index.
 *
 * Rerurn: NA
 */
void quick_sort_recursion(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot_idx = partition(array, size, low, high);

		quick_sort_recursion(array, size, low, pivot_idx - 1);
		quick_sort_recursion(array, size, pivot_idx + 1, high);
	}
}

/**
 * swap - swaps two elements.
 * @array: array of integers.
 * @size: size of the array.
 * @x: 1st element.
 * @y: 2nd element.
 *
 * Rerurn: NA
 */
void swap(int *array, size_t size, int *x, int *y)
{
	int tmp;

	if (*x != *y)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
		print_array((const int *)array, size);
	}
}

/**
 * partition - slices an array into two portions.
 * @array: array of integers.
 * @size: size of the array.
 * @low: start point.
 * @high:end point.
 *
 * Return: index of the pivot.
 */
size_t partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot_val;

	pivot_val = array[high];
	j = low;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot_val)
		{
			swap(array, size, &array[i], &array[j]);
			j++;
		}
	}
	swap(array, size, &array[j], &array[high]);
	return (j);
}
