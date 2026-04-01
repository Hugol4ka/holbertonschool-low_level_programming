#include"lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list.
 * @head: double pointer to the head of the list.
 * @index: index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
	return (-1);

	/*On veut supprimer le premier wagon */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	/*On cherche le wagon plus loin (index > 0)*/
	while (i < index && temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	/* Si on a parcouru tout le train sans trouver l'index */
	if (temp == NULL)
		return (-1);
	/* On débranche le wagon temp */
	temp->prev->next = temp->next;
	if (temp->next != NULL)
	temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
