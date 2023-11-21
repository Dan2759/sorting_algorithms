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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The number of elements in the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, current_above, below;

	pivot = array + right;
	for (current_above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (current_above < below)
			{
				swap_ints(array + below, array + current_above);
				print_array(array, size);
			}
			current_above++;
		}
	}

	if (array[current_above] > *pivot)
	{
		swap_ints(array + current_above, pivot);
		print_array(array, size);
	}

	return (current_above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers.
 * @size: The number of elements in the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p_index;

	if (right - left > 0)
	{
		p_index = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p_index - 1);
		lomuto_sort(array, size, p_index + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The number of elements in the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
