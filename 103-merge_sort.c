#include "sort.h"

void merge_sort_recursive(
		int *array, size_t left, size_t right, int *array_cpy);
void merge_sorted(int *array_cpy, size_t left, size_t right, int *array);

/**
 * merge_sort - sorts an array of integers in ascending order.
 * @array: array to sort.
 * @size: size of the array.
 *
 * Return: NA.
 */
void merge_sort(int *array, size_t size)
{
	int *array_cpy;
	size_t i;

	if (!array || size < 2)
		return;

	array_cpy = malloc(sizeof(int) * size);
	if (!array_cpy)
		return;

	for (i = 0; i < size; i++)
		array_cpy[i] = array[i];

	merge_sort_recursive(array, 0, size, array_cpy);
	free(array_cpy);
}
/**
 * merge_sort_recursive - sorts top-down recursively
 * @array: array to sort
 * @left: left index
 * @right: right index
 * @array_cpy: the output array
 *
 * Return: NA.
 */
void merge_sort_recursive(
		int *array, size_t left, size_t right, int *array_cpy)
{
	if (right - left >= 2)
	{
		size_t mid = (left + right) / 2;

		merge_sort_recursive(array_cpy, left, mid, array);
		merge_sort_recursive(array_cpy, mid, right, array);
		merge_sorted(array_cpy, left, right, array);
	}
}

/**
 * merge_sorted - merges sorted sub-arrays
 * @array_cpy: array to sort
 * @left: left index
 * @right: right index
 * @array: the output array
 *
 * Return: NA.
 */
void merge_sorted(int *array_cpy, size_t left, size_t right, int *array)
{
	size_t i, j, k, mid;

	i = left;
	j = mid = (left + right) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_cpy + left, mid - left);
	printf("[right]: ");
	print_array(array_cpy + mid, right - mid);
	for (k = left; k < right; k++)
	{
		if (i < mid && (j >= right || array_cpy[i] <= array_cpy[j]))
		{
			array[k] = array_cpy[i];
			i++;
		}
		else
		{
			array[k] = array_cpy[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}
