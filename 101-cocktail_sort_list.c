#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @list: Pointer to a pointer to the head of the list.
 * @left: The left node to swap.
 * @right: The right node to swap.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 *                      using the Cocktail Sort algorithm.
 * @list: Pointer to a pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		swapped = forward_pass(list, current, &swapped);
		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;

		swapped = backward_pass(list, current, &swapped);
	}
}

/**
 * forward_pass - Performs a forward pass of the Cocktail Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 * @current: The current node.
 * @swapped: Pointer to the swapped flag.
 * Return: 1 if any swaps are made, 0 otherwise.
 */
int forward_pass(listint_t **list, listint_t *current, int *swapped)
{
	while (current->next)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			*swapped = 1;
		}
		else
			current = current->next;
	}
	return (*swapped);
}

/**
 * backward_pass - Performs a backward pass of the Cocktail Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 * @current: The current node.
 * @swapped: Pointer to the swapped flag.
 * Return: 1 if any swaps are made, 0 otherwise.
 */
int backward_pass(listint_t **list, listint_t *current, int *swapped)
{
	while (current->prev)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			*swapped = 1;
		}
		else
			current = current->prev;
	}
	return (*swapped);
}
