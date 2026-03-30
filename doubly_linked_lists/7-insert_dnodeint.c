#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index of the list where the new node should be added
 * @n: data to insert in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp;
	unsigned int i = 0;
	dlistint_t *new;

	if (h == NULL)
	return (NULL);

	if (idx == 0)
	return (add_dnodeint(h, n));

	temp = *h;

	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	new->next = temp->next; /*pointe vers l'avant*/
	new->prev = temp; /*pointe vers l'arrière*/

	/*Si on n'est pas à la toute fin, le wagon d'après doit pointer vers N */
	if (temp->next != NULL)
		temp->next->prev = new;

	temp->next = new;

	return (new);
}
