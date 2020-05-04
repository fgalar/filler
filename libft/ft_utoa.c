/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:05:20 by fanny             #+#    #+#             */
/*   Updated: 2020/05/01 14:05:25 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		unbrlen(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned long nb)
{
	int		len;
	char	*n;

	len = unbrlen(nb);
	if (!(n = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (n == 0)
		n[0] = '0';
	n[len] = '\0';
	while (len)
	{
		n[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	free(n);
	return (n);
}
