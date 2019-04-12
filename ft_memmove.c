/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:47:39 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/11 15:38:05 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_zone;

	tmp_zone = (char*)malloc(sizeof(char) * len);
	memcpy(tmp_zone, src, len);
	memcpy(dst, tmp_zone, len);
	return (dst);
}
