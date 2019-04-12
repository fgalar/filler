

#include <stdio.h>
#include <strings.h>
int main()
{
	char src[50] = "lorem ipsum dolor sit amet";
	char *dest = src + 1;
	printf("la vraie = %s\n", memmove(dest, src, 8));

	char src2[50] = "lorem ipsum dolor sit amet";
	char *dest2 = src2 + 1;
	printf("la fausse = %s\n", ft_memmove(dest2, src2, 8));

	char src3[50] = "lorem ipsum dolor sit amet";
	char *dst3 = src3 + 1;
	printf("ft_memcpy = %s\n", ft_memcpy(dst3, src3, 8));

	return (0);
}
