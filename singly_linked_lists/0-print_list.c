#include"lists.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_num - prints an unsigned int using _putchar
 * @n: the number to print
 */
void print_num(unsigned int n)
{
	if (n / 10)
	print_num(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the start of the list
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t nodes = 0;
	unsigned int i;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			_putchar('[');
			_putchar('0');
			_putchar(']');
			_putchar(' ');
			_putchar('(');
			_putchar('n');
			_putchar('i');
			_putchar('l');
			_putchar(')');
			_putchar('\n');
		}
		else
		{
				_putchar(h->str[i]);
				_putchar('[');
				print_num(h->len);
				_putchar(']');
				_putchar(' ');
			for (i = 0; h->str[i] != '\0'; i++)
			{
				_putchar(h->str[i]);
			}
				_putchar('\n');
		}
		nodes++;
		h = h->next;
	}
	return (nodes);
}
