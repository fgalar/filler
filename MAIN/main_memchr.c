#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char s[50] = "Lorem ipsum dolor sit amet";
	printf("the true :%s\n", memchr(s, 'e', 10));

	char s1[50] = "Lorem ipsum dolor sit amet";
	printf("the false:%s\n", ft_memchr(s1, 'e', 10));

	char s3[50] = "Lorem ipsum dolor sit amet";
	char dest[50]= "Lorem ipsum dolor sit amet";
	printf("memccpy: %s \n", memccpy(dest, s3, 'e', 10));

	return (0);
}
