#include <stdio.h>
#include <strings.h>

int main()
{
	char dest[255] = "Bonj";
	char src[200] = "Comment ca va";
	printf("FT_MEMCPY __ Avant	; %s\n", dest);
	ft_memcpy(dest, src, 25);
	printf("FT_MEMCPY __ Apres	; %s\n", dest);

	char dest2[255] = "Bonj";
	char src2[200] = "Comment ca va";
	printf("THE TRUE MEMCPY __ Avant; %s\n", dest2);
	memcpy(dest2, src2, 25);
	printf("THE TRUE MEMCPY __ Apres; %s\n", dest2);


	return (0);
}
