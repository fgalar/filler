/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:46:18 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/26 17:43:43 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (len > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (len > i && dst[i])
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
