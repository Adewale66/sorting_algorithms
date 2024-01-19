#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
*/

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * get_max - gets the max value in an array
 * @array: array to get max value from
 * @size: size of the array
 * Return: max value
*/

int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * count_sort - sorts an array of integers in ascending order using the Count
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @exp: exponent
*/

void count_sort(int *array, size_t size, int exp)
{
	int *output, *count, i;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	count = malloc(sizeof(int) * 10);
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
