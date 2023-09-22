#include "sort.h"

void swap(listint_t *curr, listint_t *prev);
/**
 * insertion_sort_list - sorts an list of integers in ascending order
 * @list: list to sort.
 *
 * Rerurn: NA
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *curr;

	if (!list)
		return;

	head = (*list)->next;

	while (head)
	{
		curr = head;
		head = head->next;
		while (curr && curr->prev)
		{
			if (curr->prev->n > curr->n)
			{
				swap(curr->prev, curr);
				if (curr->prev == NULL)
				{
					*list = curr;
				}
				print_list((const listint_t *)*list);
			}
			else
				curr = curr->prev;
		}
	}
}

/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @curr: first node
 * @prev: second node
 *
 * Return: NA
 */
void swap(listint_t *curr, listint_t *prev)
{
	if (curr->prev)
		curr->prev->next = prev;

	if (prev->next)
		prev->next->prev = curr;

	curr->next = prev->next;
	prev->prev = curr->prev;
	curr->prev = prev;
	prev->next = curr;
}
