#include <stdio.h>
#include <strings.h>

int main()
{
	char str[255] = "Bonjour Queen Fanny";

	printf("Avant; %s\n", str);
	ft_bzero(str, 4);
	printf("Apres; %s\n", str);

	return (0);
}
