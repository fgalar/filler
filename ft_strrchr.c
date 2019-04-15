/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:12:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/13 20:33:03 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*strch;

	i = 0;
	cc = (char)c;
	strch = (char*)s;
	while (strch[i] != '\0')
		i++;
	if (cc == '\0')
		return (&strch[i]);
	while ((strch[i] != cc) && (i > 0))
		i--;
	if (strch[i] == cc)
		return (&strch[i]);
	return (0);
}
