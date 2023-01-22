#include "sort.h"

/**
 * swap_list - swaps elements of a list
 *
 * @lft: pointer to left node
 * @rt: pointer to right node
 * @list: pointer to the list head pointer
 */
void swap_list(listint_t *lft, listint_t *rt, listint_t **list)
{
	listint_t *tmp;

	tmp = lft->prev;
	if (tmp)
		tmp->next = rt;
	else
		*list = rt;

	rt->prev = tmp;
	lft->prev = rt;
	lft->next = rt->next;
	rt->next = lft;
	if (lft->next)
		lft->next->prev = lft;

	print_list(*list);
}


/**
 * insertion_sort_list - sorts a list using the insertion sort
 * algorithm.
 *
 * @list: pointer to the list head pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *swap, *last;

	if (!list || !*list)
		return;

	node = *list;
	while (node->next)
	{
		if ((node->n) > (node->next->n))
		{
			swap_list(node, node->next, list);
			last = node;
			node = node->prev;
			while (node->prev)
			{
				swap = node;
				if ((swap->n) < (swap->prev->n))
				{
					swap_list(node->prev, swap, list);
				}
				else
				{
					break;
				}
			}
			node = last;
		}
		else
		{
			node = node->next;
		}
	}
}
