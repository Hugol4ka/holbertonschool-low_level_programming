#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/**
 *operation - va executer l'opération
 *@choix: Apelle l'operation choisi par l'utilisateur
 *
 *Return: void
 */

void operation(int choix)
{
	float op1, op2, result;

printf("Veuillez entrer la première valeur: \n");
scanf("%f", &op1);
printf("Veuillez entrer la seconde valeur: \n");
scanf("%f", &op2);
			if (choix == 1)
			result = op1 + op2;
				else if (choix == 2)
				result = op1 - op2;
					if (choix == 3)
					result = op1 * op2;
				else if (choix == 4)
				{
					if (op1 && op2 == 0)
					{
						printf("Erreur: division par zero impossible\n");
						return;
					}
					else
					{
						result = op1 / op2;
					}

				}
				else if (choix == 5)
				{
					if (op1 && op2 == 0)
					{
					printf("Erreur: modulo par zero impossible\n");
					return;
					}
					else
					{
						result = (int)op1 % (int)op2; /*conversion de la valeur en int*/
					}
				}
	printf("Le resultat est :%.2f\n", result);
}

/**
*main - Entry point
*Menu for calculator
*Return: Always 0 (Success)
*/

int main(void)

{
	int choix;

		while (choix != 0)
			{
			printf("1. Addition\n");
			printf("2. Soustration\n");
			printf("3. Multiplication\n");
			printf("4. Division\n");
			printf("5. Modulo\n");
			printf("0. Quitter\n");
			printf("Merci d'entrer le chiffre correspondant a l'opération voulu :\n");
			scanf("%d", &choix);
				if (choix >= 1 && choix <= 5)
				{
				operation(choix);
				}
				else if (choix != 0)
				{
				printf("Merci de rentrer un chiffre entre 0 et 5\n");
				}
			}
	printf("Aurevoir.");
	putchar('\n');
	return (0);
}
