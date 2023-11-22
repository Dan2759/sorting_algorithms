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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @s: The size of the sequence to sort.
 * @c: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t s, char c)
{
	size_t i, jump = s / 2;

	if (s > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((c == UP && array[i] > array[i + jump]) ||
			    (c == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, c);
		bitonic_merge(array, size, start + jump, jump, c);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array to be sorted.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @s: The size of the sequence to sort.
 * @c: The direction to sort in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t s, char c)
{
	size_t cut = s / 2;
	char *str = (c == UP) ? "UP" : "DOWN";

	if (s > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", s, size, str);
		print_array(array + start, s);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, s, c);

		printf("Result [%lu/%lu] (%s):\n", s, size, str);
		print_array(array + start, s);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
