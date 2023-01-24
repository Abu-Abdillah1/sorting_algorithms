#include "sort.h"

/**
 * shell_sort - sorts an array using the shell sort algorithm
 *
 * @a: pointer to the array
 * @size: size of the array
 */
void shell_sort(int *a, size_t size)
{
	int temp;
	size_t i, gap, j;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = a[i];
			for (j = i; (j >= gap) && (a[j - gap] > temp); j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
		print_array(a, size);
	}
}
