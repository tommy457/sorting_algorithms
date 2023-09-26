#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of the array.
 *
 * Rerurn: NA
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count_arr, *sort_arr;

	if (!array || size < 2)
		return;

	sort_arr = malloc(sizeof(int) * size);
	if (!sort_arr)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_arr = malloc(sizeof(int) * (max + 1));
	if (!count_arr)
	{
		free(sort_arr);
		return;
	}

	for (i = 0; i <= max; ++i)
	{
		count_arr[i] = 0;
	}

	for (i = 0; i < (int)size; i++) {
		count_arr[array[i]] += 1;
	}

	for (i = 0; i <= max; i++) {
		count_arr[i] += count_arr[i - 1];
	}

	print_array(count_arr, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sort_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++) {
		array[i] = sort_arr[i];
	}

	free(sort_arr);
	free(count_arr);
}
