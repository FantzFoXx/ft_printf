#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int		main(void)
{
	char *str;
	int i = -1000;
	wint_t t = L'啊';

	str = malloc(1);
	ft_printf("Bonjour voici un int '%d' lol. Et une affichee avec le i %i Ceci est une chaine '%s' issssmdr. Ceci est un char : '%c'\n", 10, 12345, "lol", 'c');
	ft_printf("%o\n", 1000000000);
	printf("%o\n", 1000000000);
	ft_printf("pointer : %p\n", str);
	printf("pointer : %p\n", str);
	free(str);
	printf("wchar_t string : %s\n", "∑´ç˚啊爱安暗按八把爸吧白百拜班般板 lol G pété");
	ft_printf("wchar_t string : %s\n", "∑´ç˚啊爱安暗按八把爸吧白百拜班般板 lol G pété");
	//printf("%ll10.5%llX", 4294967296);
	ft_printf("%ll10....5..5..7%llX\n", 4294967296);
	printf("%.5%llX\n", 4294967296);

	return (0);
}
