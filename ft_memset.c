/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:47:39 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/09 18:53:42 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *cpy;

	cpy = (char*)b;
	if (b == NULL)
		return (NULL);
	while (len)
	{
		*cpy = c;
		cpy++;
		len--;
	}
	return (b);
}
