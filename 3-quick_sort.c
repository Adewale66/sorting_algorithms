#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @low: low index
 * @high: high index
 * Return: void
*/

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}

/**
 * partition - partitions the array
 * @array: array to sort
 * @size: size of the array
 * @low: low index
 * @high: high index
 * Return: void
*/

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
