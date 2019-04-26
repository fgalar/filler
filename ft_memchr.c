/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:02:06 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/26 17:40:06 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	size_t			i;
	unsigned char	*s_stock;

	cc = (char)c;
	i = 0;
	s_stock = (unsigned char*)s;
	while (n)
	{
		if (s_stock[i] == cc)
		{
			s_stock = &s_stock[i];
			return (s_stock);
		}
		i++;
		n--;
	}
	return (NULL);
}
