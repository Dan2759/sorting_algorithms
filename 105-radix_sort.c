#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int j, i;

	for (j = array[0], i = 1; i < size; i++)
	{
		if (array[i] > j)
			j = array[i];
	}

	return (j);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @temp: Temporary array to store intermediate results.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *temp)
{
	int counting_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		counting_array[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		counting_array[i] += counting_array[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		temp[counting_array[(array[i] / sig) % 10] - 1] = array[i];
		counting_array[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array to be sorted.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int j, sig, *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	j = get_max(array, size);
	for (sig = 1; j / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, temp);
		print_array(array, size);
	}

	free(temp);
}
