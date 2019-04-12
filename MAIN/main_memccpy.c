#include<stdio.h>
#include<string.h>
#include "libft.h"
int	main()
{
	char str_src2[50] = "zombie";
	char str_dest2[50] = "L'empereur sa femme";
	printf("dest avant la fonction = %s\n", str_dest2);
	printf("dest apres la fonction = %s\n", memccpy(str_dest2, str_src2, 'z', 3));

	char str_src[50] = "zombie";
	char str_dest[50] = "L'empereur sa femme";
	printf("dest avant ma fonction = %s\n", str_dest);
	printf("dest apres ma fonction = %s\n", ft_memccpy(str_dest, str_src, 'z', 3));

}
