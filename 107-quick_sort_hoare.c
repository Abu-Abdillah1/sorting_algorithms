#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare - sorts an array using the hoare
 * partitioning scheme
 *
 * @array: pointer to the array
 * @size: size of the array
 * @low: starting index of the partition.
 * @high: ending index of the partition.
 */
void hoare(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	if (high <= low)
		return;

	pivot = array[high];
	for (i = low - 1, j = high + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap_ints(array + i, array + j);
			print_array(array, size);
		}
	}

	hoare(array, size, low, i - 1);
	hoare(array, size, i, high);

}


/**
 * quick_sort_hoare - sorts an array using the quick sort algorithm
 *
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare(array, size, 0, size - 1);
}
