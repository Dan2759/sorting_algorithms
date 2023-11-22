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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @l: The left index of the subset to order.
 * @r: The right index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int l, int r)
{
	int pivot, up, down;

	pivot = array[r];
	for (up = l - 1, down = r + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array to be sorted.
 * @size: The size of the array.
 * @l: The left index of the array partition to order.
 * @r: The right index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int l, int r)
{
	int part;

	if (r - l > 0)
	{
		part = hoare_partition(array, size, l, r);
		hoare_sort(array, size, l, part - 1);
		hoare_sort(array, size, part, r);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array to be sorted.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
