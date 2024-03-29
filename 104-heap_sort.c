#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
*/

void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (size < 2)
		return;

	for (i = size / 2 - 1; (int)i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - heapify the array
 * @array: array to sort
 * @size: size of the array
 * @i: index
 * @size2: size of the array
 * Return: void
*/

void heapify(int *array, size_t size, size_t i, size_t size2)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size2);
		heapify(array, size, largest, size2);
	}
}
