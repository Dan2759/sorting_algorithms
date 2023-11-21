#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer.
 * @y: The second integer.
 */
void swap_ints(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array each time the interval decreases.
 */
void shell_sort(int *array, size_t size)
{
	size_t h, i, j;

	if (array == NULL || size < 2)
		return;

	for (h = 1; h < (size / 3);)
		h = h * 3 + 1;

	for (; h >= 1; h /= 3)
	{
		for (i = h; i < size; i++)
		{
			j = i;
			while (j >= h && array[j - h] > array[j])
			{
				swap_ints(array + j, array + (j - h));
				j -= h;
			}
		}
		print_array(array, size);
	}
}
