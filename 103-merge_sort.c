#include "sort.h"

void merge_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);


/**
 * merge_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid, i, j, k = 0;

	if (back <= (front + 1))
		return;

	mid = front + (back - front) / 2;
	merge_recursive(subarr, buff, front, mid);
	merge_recursive(subarr, buff, mid, back);

	/* Prints the merge */
	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);

}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (!b)
		return;

	merge_recursive(array, b, 0, size);

	free(b);
}

