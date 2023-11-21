#include "sort.h"

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of the list.
 * @end: Pointer to the tail of the doubly-linked list.
 * @current: Pointer to the current node for swapping.
 */
void swap_node_ahead(listint_t **list, listint_t **end, listint_t **current)
{
	listint_t *tmp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current)->prev;
	(*current)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *current;
	else
		*end = *current;
	(*current)->prev = tmp;
	tmp->next = *current;
	*current = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: Pointer to the head of the doubly-linked list.
 * @end: Pointer to the tail of the doubly-linked list.
 * @current: Pointer to the current node for swapping.
 */
void swap_node_behind(listint_t **list, listint_t **end, listint_t **current)
{
	listint_t *tmp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	else
		*end = tmp;
	tmp->next = (*current)->next;
	(*current)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = tmp;
	tmp->prev = *current;
	*current = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *current;
	enum bool_t shaken_not_stirred = FALSE;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (shaken_not_stirred == FALSE)
	{
		shaken_not_stirred = TRUE;
		for (current = *list; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_ahead(list, &end, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = FALSE;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_behind(list, &end, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = FALSE;
			}
		}
	}
}
