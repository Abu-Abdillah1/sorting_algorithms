#include "sort.h"

void swap_ints(int *a, int *b);
void lomuto(int *arr, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swaps two integers in an array.
 * @a: pointer to the first integer.
 * @b: pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto - sorts an array using the lumuto
 * partitioning scheme
 *
 * @arr: pointer to the array
 * @size: size of the array
 * @low: starting index of the partition.
 * @high: ending index of the partition.
 */
void lomuto(int *arr, size_t size, int low, int high)
{
	int *pivot, i, j;

	if (high <= low)
		return;

	pivot = arr + high;
	for (i = j = low; j < high; j++)
	{
		if (arr[j] < *pivot)
		{
			if (i < j)
			{
				swap_ints(arr + j, arr + i);
				print_array(arr, size);
			}
			i++;
		}
	}

	if (arr[i] > *pivot)
	{
		swap_ints(arr + i, pivot);
		print_array(arr, size);
	}

	lomuto(arr, size, low, i - 1);
	lomuto(arr, size, i + 1, high);
}

/**
 * quick_sort - sorts an array using the quick sort algorithm
 *
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto(array, size, 0, size - 1);
}
