#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_hoare_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_hoare_recursion - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @low: low index
 * @high: high index
 * Return: void
*/

void quick_sort_hoare_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_hoare(array, low, high, size);
		quick_sort_hoare_recursion(array, low, pivot, size);
		quick_sort_hoare_recursion(array, pivot + 1, high, size);
	}
}

/**
 * partition_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @low: low index
 * @high: high index
 * Return: void
*/

int partition_hoare(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
