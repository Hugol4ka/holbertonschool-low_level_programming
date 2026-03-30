#include"lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Description: frees all nodes of a doubly linked list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *next_node;

	while (head != NULL)
	{
	/* Sauvegarde de l'adresse du suivant */
	next_node = head->next;

	/* On libère le wagon actuel */
	free(head);

	head = next_node;
	}
}