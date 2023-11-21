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
 * counting_sort - Sort an array of integers using counting sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *sortedArr, j, i;

	if (array == NULL || size < 2)
		return;

	sortedArr = malloc(sizeof(int) * size);
	if (sortedArr == NULL)
		return;
	j = get_max(array, size);
	counting_array = malloc(sizeof(int) * (j + 1));
	if (counting_array == NULL)
	{
		free(sortedArr);
		return;
	}

	for (i = 0; i < (j + 1); i++)
		counting_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]] += 1;
	for (i = 0; i < (j + 1); i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, j + 1);

	for (i = 0; i < (int)size; i++)
	{
		sortedArr[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sortedArr[i];

	free(sortedArr);
	free(counting_array);
}
