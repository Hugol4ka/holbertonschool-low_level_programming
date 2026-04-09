#include "main.h"
#include <stdlib.h>
#include <fcntl.h> /*File control, pour 0_RDONLY, open etc..*/
#include <unistd.h> /*read,write,close..*/

/**
 * create_file - crée un fichier et écrit du contenu dedans.
 * @filename: le nom du fichier à créer.
 * @text_content: une chaîne de caractères terminée par NULL à écrire.
 *
 * Return: 1 en cas de succès, -1 en cas d'échec.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t n_wrote;

	if (filename == NULL)
	return (-1);

    /* 1. Ouverture avec gestion d'erreur */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
		if (fd == -1)
			return (-1);

    /* 2. Calcul de la longueur */
	if (text_content != NULL)
	{
	while (text_content[len] != '\0')
		len++;
	}

    /* 3. Écriture avec gestion d'erreur */
	n_wrote = write(fd, text_content, len);
	if (n_wrote == -1 || n_wrote != (ssize_t)len)
	{
		close(fd);
		return (-1);
	}

    /* 4. Fermeture et succès */
	close(fd);
	return (1);
}
