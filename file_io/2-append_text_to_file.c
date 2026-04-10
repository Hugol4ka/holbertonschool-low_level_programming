#include"main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Ajoute du texte à la fin d'un fichier existant.
 * @filename: Le nom du fichier.
 * @text_content: La chaîne de caractères à ajouter (terminée par NULL).
 *
 * Return: 1 en cas de succès, -1 en cas d'échec (fichier inexistant,
 * problème de permissions ou d'écriture).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t n_wrote;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
		{
			len++;
		}

		n_wrote = write(fd, text_content, len);

		if (n_wrote == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
		return (1);
}
