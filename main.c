#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str;

	str = malloc(1);
	ft_printf("Bonjour voici un int '%d' lol. Et une affichee avec le i %i Ceci est une chaine '%s' issssmdr. Ceci est un char : '%c'\n", 10, 12345, "lol", 'c');
	ft_printf("%o\n", 1000000000);
	printf("%o\n", 1000000000);
	ft_printf("pointer : %p\n", str);
	printf("pointer : %p\n", str);
	free(str);
	return (0);
}
