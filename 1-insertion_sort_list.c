#include"sort.h"
/**
 *insertion_sort_list - to sort a list
 *@list: poiner to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
	while (insert != NULL && iter->n < insert->n)
	{
		if (insert->prev != NULL)
			insert->prev->next = iter;
		if (iter->next != NULL)
			iter->next->prev = insert;

		insert->next = iter->next;
		iter->prev = insert->prev;

		iter->next = insert;
		insert->prev = iter;

		if (iter->prev == NULL)
		*list = iter;

		insert = iter->prev;

		print_list((const listint_t *)*list);
	}
	}
}
