#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @a: The first string.
 * @b: The second string.
 *
 * Return: Positive byte difference if a > b
 *         0 if a == b
 *         Negative byte difference if a < b
 */
int _strcmp(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}

	if (*a != *b)
		return (*a - *b);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *current, *insert, *temp;

	for (current = (*deck)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert = current->prev;
		while (insert != NULL && insert->card->kind > current->card->kind)
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *current, *insert, *temp;

	for (current = (*deck)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert = current->prev;
		while (insert != NULL &&
		       insert->card->kind == current->card->kind &&
		       get_value(insert) > get_value(current))
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
