/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:17:11 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/26 17:39:23 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*dest;
	unsigned char	*srce;
	size_t			i;

	cc = (unsigned char)c;
	dest = (unsigned char*)dst;
	srce = (unsigned char*)src;
	i = 0;
	while (n)
	{
		dest[i] = srce[i];
		if (dest[i] == cc)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
