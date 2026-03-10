#include"main.h"
#include<stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes of s2 to concatenate
 *
 * Return: a pointer to the newly allocated space in memory
 * or NULL if the function fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
/* 1. Traitement des pointeurs NULL : 
Si s1 ou s2 sont NULL, traite-les comme des chaînes vides (""). */

/* 2. Calcul des longueurs : 
Calcule la longueur de s1 et la longueur de s2. 
Attention : si n >= longueur de s2, n devient la longueur de s2. */

/* 3. Allocation mémoire :
Réserve l'espace nécessaire : longueur de s1 + n + 1 (pour le '\0').
N'oublie pas de vérifier si malloc échoue ! */

/* 4. Copie des données :
Copie s1 dans le nouvel espace.
Ensuite, copie les n octets de s2. */

/* 5. Terminaison :
N'oublie pas d'ajouter le '\0' à la fin de la nouvelle chaîne. */

/* 6. Retourne le pointeur. */
}