#include "sort.h"

void swap(listint_t *curr, listint_t *prev, listint_t **list);

/**
 * cocktail_sort_list - sorts an array of integers in ascending order
 * @list: doubly-linked list.
 *
 * Rerurn: NA
 */
void cocktail_sort_list(listint_t **list)
{
	bool sorted = false;
	listint_t *head, *tail;

	if (!list)
		return;

	while (!sorted)
	{
		sorted = true;
		for (head = (*list)->next; head; head = head->next)
		{
			if (head->n < head->prev->n)
			{
				swap(head->prev, head, list);
				print_list(*list);
				sorted = false;
			}
			tail = head;
		}
		if (sorted)
			break;
		for (head = tail->prev; head; head = head->prev)
		{
			if (head->n > head->next->n)
			{
				swap(head, head->next, list);
				print_list(*list);
				sorted = false;
			}
		}
	}
}

/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @curr: first node.
 * @prev: second node.
 * @list: doubly-linked list.
 *
 * Return: NA
 */
void swap(listint_t *curr, listint_t *prev, listint_t **list)
{
	if (curr->prev != NULL)
		curr->prev->next = prev;
	else
		*list = prev;
	if (prev->next != NULL)
		prev->next->prev = curr;
	curr->next = prev->next;
	prev->prev = curr->prev;
	curr->prev = prev;
	prev->next = curr;
}

