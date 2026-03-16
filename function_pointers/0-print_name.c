#include"main.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * print_name - Exécute une fonction sur une chaîne de caractères donnée.
 * @name: La chaîne de caractères à traiter (le nom).
 * @f: Un pointeur vers une fonction qui prend un char * en argument
 * et ne retourne rien (void).
 * * Description: Cette fonction utilise un pointeur de fonction pour appliquer
 * une méthode d'affichage spécifique (passée en argument) au nom fourni.
 * * Return: Rien.
 */
void print_name(char *name, void (*f)(char *))
{
	if ((name == NULL) || (f == NULL))
	return;

	f(name);
}
