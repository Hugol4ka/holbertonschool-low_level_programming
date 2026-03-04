#include"main.h"
/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to be modified
 *
 * Return: A pointer to the changed string
 */
char *cap_string(char *str)
{
	int i = 0;
	int c;
	char carac[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		if ((i == 0) && (str[i] >= 'a' && str[i] <= 'z'))
		{
		str[i] = str[i] - 32;
		}
		if (i > 0)
		{
			c = 0;
			while (carac[c] != '\0')
			{
				if ((str[i - 1] == carac[c]) && (str[i] >= 'a' && str[i] <= 'z'))
				{
				str[i] = str[i] - 32;
				}
				c++;
			}
		}
			i++;
	}
	return (str);
}
