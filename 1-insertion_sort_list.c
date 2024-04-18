#include "sort.h"

/**
 *swap- function that swaps two nodes in a listn_t dbl list.
 *@h: a pointer to the head
 *@n1: a pointer to first node to swap
 *@n2: the second node to swap
 */

void swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
	{
		n2->next->prev = *n1;
	}
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 *insertion_sort_list -a function that sorts a doubly linked list of integers
 *using the insertion sort algorithm.
 *
 *@list: a poiinter
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter;
	listint_t *insert;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
