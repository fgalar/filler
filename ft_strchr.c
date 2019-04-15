/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:44:50 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/13 16:32:29 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;
	char	*strch;

	cc = (char)c;
	i = 0;
	strch = (char *)s;
	while ((s[i] != '\0') && (s[i] != cc))
		i++;
	if (cc == s[i])
		return (&strch[i]);
	if (cc == '\0')
		return (&strch[i]);
	return (0);
}
