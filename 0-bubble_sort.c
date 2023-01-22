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
 * bubble_sort - sorts an array using bubble sort algorithm
 *
 * @array: pointer to the array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;

	if (array == NULL || size == 0)
		return;

	while (i < size - 1)
	{
		i = 1;
		while (i < size && array[i - 1] < array[i])
			i++;
		j = i;
		while (j < size && array[j - 1] > array[j])
		{
			swap_array(array, j - 1, j);
			print_array(array, size);
			j++;
		}
	}
}
