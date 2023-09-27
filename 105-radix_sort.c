#include "sort.h"

int get_max(int *array, int size);
void count_sort(int *array, int *output, size_t size, size_t exp);

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of the array.
 *
 * Return NA
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *output;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, output, size, exp);
		print_array(array, size);
	}
	free(output);
}

/**
 * count_sort - Sort the significant digits of an array of integers
 * @array: array of integers.
 * @output: output array.
 * @size: size of array.
 * @exp: significant digit.
 *
 * Return: NA.
 */
void count_sort(int *array, int *output, size_t size, size_t exp)
{
	int i, count[10] = { 0 };

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * get_max - gets the max from a array.
 * @array: array to get the max from.
 * @size: size of the array.
 *
 * Return: max.
 */
int get_max(int *array, int size)
{
	int i, max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
