#include <stdio.h> /* dprintf */
#include <stdlib.h> /* exit */
#include <fcntl.h> /* O_WRONLY | O_CREAT | O_TRUNC */
#include <unistd.h> /* read, write, close, STDERR_FILENO */

/**
 * main - Programme qui copie le contenu d'un fichier dans un autre.
 * @ac: Nombre d'arguments.
 * @av: Tableau des arguments (source et destination).
 * Return: 0 en cas de succès, ou codes d'erreur 97, 98, 99, 100.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	char buffer[1024];
	ssize_t n_read, n_wrote;

	/* 1. Vérification du nombre d'arguments */
	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	/* 2. Ouverture de la source */
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);

	/* 3. Ouverture/Création de la destination (0664 = rw-rw-r--) */
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);

	/* 4. Boucle de lecture et d'écriture */
	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_wrote = write(fd_to, buffer, n_read);
		if (n_wrote == -1 || n_wrote != n_read)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	}

	/* Vérif si la boucle s'est arrêtée à cause d'une erreur de lecture */
	if (n_read == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);

	/* 5. Fermeture des File Descriptors */
	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);

	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}
