#ifndef TYPES_H
#define TYPES_H

/**
 * struct Ressources - Structure pour un ingrédient de craft
 * @name: Nom de la ressource (ex: Fer)
 * @quantity: Nombre d'unités nécessaires
 * @price: Prix unitaire en HDV
 * Description: Définit les composants de base pour le calcul du coût.
 */

typedef struct Ressources
{
	char name[100];
	int quantity;
	int price;
} Ressources;

/**
 * struct Object - Structure pour l'objet final à briser
 * @name: Nom de l'équipement
 * @totalCraftCost: Coût total de fabrication calculé
 * @estimatedRuneValue: Estimation du gain après brisage
 * @recipeSize: Nombre d'ingrédients réels dans le tableau
 * @recipe: Tableau contenant les ressources de la recette
 *
 * Description: Regroupe toutes les données nécessaires à l'analyse.
 */
typedef struct Object
{
	char name[100];
	int totalCraftCost;
	int estimatedRuneValue;
	int recipeSize;
	Ressources recipe[15];
} Object;

#endif
