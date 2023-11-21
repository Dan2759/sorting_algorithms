#include "sort.h"

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @temp: Temporary array to store intermediate results.
 * @l: The left index of the subarray.
 * @m: The middle index of the array.
 * @r: The right index of the subarray.
 */
void merge_subarr(int *subarr, int *temp, size_t l, size_t m,
		size_t r)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + l, m - l);

	printf("[right]: ");
	print_array(subarr + m, r - m);

	for (i = l, j = m; i < m && j < r; k++)
		temp[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < m; i++)
		temp[k++] = subarr[i];
	for (; j < r; j++)
		temp[k++] = subarr[j];
	for (i = l, k = 0; i < r; i++)
		subarr[i] = temp[k++];

	printf("[Done]: ");
	print_array(subarr + l, r - l);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion
 * @subarr: A subarray of an array of integers to sort.
 * @temp: Temporary array to store intermediate results.
 * @l: The left index of the subarray.
 * @r: The right index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *temp, size_t l, size_t r)
{
	size_t m;

	if (r - l > 1)
	{
		m = l + (r - l) / 2;
		merge_sort_recursive(subarr, temp, l, m);
		merge_sort_recursive(subarr, temp, m, r);
		merge_subarr(subarr, temp, l, m, r);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array to be sorted.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
