#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UP 0
#define DOWN 1

/**
 * enum bool_t - Enumeration of Boolean values.
 * @FALSE: Represents false (0).
 * @TRUE: Represents true (1).
 */
typedef enum bool_t
{
	FALSE = 0,
	TRUE
} bool_t;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function Declarations */
void swap_ints(int *x, int *y);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
void swap_node_ahead(listint_t **list, listint_t **end, listint_t **current);
void swap_node_behind(listint_t **list, listint_t **end, listint_t **current);
int get_max(int *array, int size);
void merge_subarr(int *subarr, int *temp, size_t l, size_t m, size_t r);
void merge_sort_recursive(int *subarr, int *temp, size_t l, size_t r);
void max_heapify(int *array, size_t size, size_t b, size_t root);
void radix_counting_sort(int *array, size_t size, int sig, int *temp);
void bitonic_merge(int *array, size_t size, size_t start, size_t s, char c);
void bitonic_seq(int *array, size_t size, size_t start, size_t s, char c);
int hoare_partition(int *array, size_t size, int l, int r);
void hoare_sort(int *array, size_t size, int l, int r);

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
