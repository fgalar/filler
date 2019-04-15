/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:32:58 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/13 20:12:45 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str;
	char	*to_find;

	i = 0;
	j = 0;
	str = (char*)haystack;
	to_find = (char*)needle;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while ((to_find[j] == str[i + j]) && to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
