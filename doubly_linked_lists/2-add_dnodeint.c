#include"lists.h"
#include<stdlib.h>
#include<stdio.h>

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer to be included in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	/*Mettre le wagon new en tête de liste*/
	new->prev = NULL;
	new->next = *head;

	/*Dire au premier wagon d'origine qu'il se situe aprés new*/
	if (*head != NULL)
		(*head)->prev = new;

	/*Permet de dire au main que la chiane commence par new*/
	*head = new;
	return (new);
}
