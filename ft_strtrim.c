/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:42:04 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/25 20:52:04 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	end = ft_strlen(s) - 1;
	if (s == NULL)
		return (NULL);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (end < start)
		end = start;
	if (!(str = ft_strsub(s, start, ((end - start) + 1))))
		return (NULL);
	str[(end - start) + 1] = '\0';
	return (str);
}
