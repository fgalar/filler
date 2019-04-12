/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:56:10 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/10 15:20:52 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ch_t_dest;
	char	*ch_t_src;
	int		i;

	ch_t_dest = (char*)dst;
	ch_t_src = (char*)src;
	i = 0;
	while (n && (ch_t_dest[i] || ch_t_src[i]))
	{
		ch_t_dest[i] = ch_t_src[i];
		i++;
		n--;
	}
	return (dst);
}
