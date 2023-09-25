#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 *                        using the Insertion Sort algorithm.
 * @list: Pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* list is empty*/

	current = (*list)->next;

	while (current)
	{
		prev = current->prev; /* Initializes prev to the previous node*/
		temp = current->next; /* Stores the next node for the next iteration*/



		while (prev && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;
			prev = current->prev;
			print_list(*list);
		}

		current = temp; /* Moving to the next node for the next iteration*/
	}


}
