#include "sort.h"


void heapify(int *array, size_t size);
void sift_down(int *array, size_t size, size_t start, size_t end);
void swap(int *array, size_t size, int *x, int *y);

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of the array.
 *
 * Return: NA
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	heapify(array, size);
	end = size - 1;

	while (end > 0)
	{
		swap(array, size, &array[end], &array[0]);
		end--;
		sift_down(array, size, 0, end);
	}
}

/**
 * swap - swaps two elements.
 * @array: array of ints.
 * @size: size of the array.
 * @x: 1st element.
 * @y: 2nd element.
 *
 * Return: NA
 */
void swap(int *array, size_t size, int *x, int *y)
{
	int tmp;

	if (*x != *y)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
	}
	print_array((const int *)array, size);
}

/**
 * sift_down - shifts down
 * @array: array to sort.
 * @size: size of the array.
 * @start: starting index.
 * @end: end index.
 *
 * Return: NA
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root, child, swp;

	root = start;
	while (iLeftChild(root) <= end)
	{
		child = iLeftChild(root);
		swp = root;

		if (array[swp] < array[child])
			swp = child;

		if (child + 1 <= end && array[swp] < array[child + 1])
			swp = child + 1;

		if (swp == root)
			return;

		swap(array, size, &array[root], &array[swp]);
		root = swp;
	}
}

/**
 * heapify - Put elements of array in heap order, in-place.
 * @array: array.
 * @size: size of array.
 *
 * Return: NA
 */
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = iParent(size - 1);

	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}

}


