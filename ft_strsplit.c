/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:46:23 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/25 20:52:43 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strduptil(const char *src, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] != c && src[i])
		i++;
	if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strcount(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

int		ft_strclen(const char *s, char c)
{
	int		upper;
	int		lower;

	upper = 0;
	lower = 0;
	while (s[upper] == c && s[upper])
		upper++;
	lower = upper;
	while (s[upper] != c && s[upper])
		upper++;
	return (upper - lower);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tabstr;
	int		y;
	int		x;
	int		words;

	y = 0;
	x = 0;
	words = ft_strcount(s, c);
	if (s == NULL)
		return (NULL);
	if (!(tabstr = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (y < words && s[x])
	{
		while (s[x] == c)
			x++;
		if (!(tabstr[y] = ft_strduptil(&s[x], c)))
			return (NULL);
		y++;
		x += ft_strclen(&s[x], c);
	}
	tabstr[y] = NULL;
	return (tabstr);
}
