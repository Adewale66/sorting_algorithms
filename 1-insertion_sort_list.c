#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;
			print_list(*list);
			prev = current->prev;
		}
		current = next;
	}
}
