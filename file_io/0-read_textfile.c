#include "main.h"
#include <stdlib.h>
#include <fcntl.h> /*File control, pour 0_RDONLY, open etc..*/
#include <unistd.h> /*read,write,close..*/

/**
 * read_textfile - lit un fichier et l'affiche sur la sortie standard.
 * @filename: nom du fichier à lire.
 * @letters: nombre de lettres à lire et afficher.
 *
 * Return: le nombre réel de lettres lues et affichées, ou 0 en cas d'erreur.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_wrote;
	char *buffer;

	if (filename == NULL) /*Si filename Null, return 0*/
		return (0);
	/* 1. Ouvrir le fichier */
	fd = open(filename, O_RDONLY); /*Gestion des erreurs*/
	if (fd == -1)
		return (0);
	/* 2. Allouer le buffer */
	buffer = malloc(sizeof(char) * letters); /*Gestion des erreurs*/
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	/* 3. Lecture du fichier */
	n_read = read(fd, buffer, letters); /*Gestion des erreurs*/
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	/* 4. Écriture sur la sortie standard */
	n_wrote = write(STDOUT_FILENO, buffer, n_read);
	if (n_wrote == -1 || n_wrote != n_read) /*Gestion des erreurs*/
	{
		free(buffer);
		close(fd);
		return (0);
	}
	/* 5. Nettoyage et fermeture */
	free(buffer);
	close(fd);

	return (n_wrote);
}
