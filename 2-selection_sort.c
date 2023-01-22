#include "sort.h"

/**
 * swap_array - swaps elements of an array at given indeces
 *
 * @arr: pointer to the array
 * @a: first index
 * @b: second index
 */

void swap_array(int *arr, int a, int b)
{
	int tmp = arr[a];

	arr[a] = arr[b];
	arr[b] = tmp;
}

/**
 * selection_sort - sorts an array using the insertion sort algorithm
 *
 * @array: pointer to the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size == 0)
		return;

	for (i = 1; i < size; i++)
	{
		min = i - 1;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i - 1 == min)
			continue;
		swap_array(array, i - 1, min);
		print_array(array, size);
	}
}
