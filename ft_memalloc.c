/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:49:50 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/26 17:49:57 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*tab;

	if (size == 0)
		return (NULL);
	if (!(tab = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
