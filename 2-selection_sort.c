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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap operation.
 */
void selection_sort(int *array, size_t size)
{
	int *min_ptr;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_ptr = array + i;
		for (j = i + 1; j < size; j++)
			min_ptr = (array[j] < *min_ptr) ? (array + j) : min_ptr;

		if ((array + i) != min_ptr)
		{
			swap_ints(array + i, min_ptr);
			print_array(array, size);
		}
	}
}
