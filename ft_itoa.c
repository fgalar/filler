/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:29:05 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/19 21:30:31 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		len_int(int n)
{
	int				len;
	int				sign;
	unsigned int	nb;

	len = 1;
	sign = -1;
	if (n < 0)
	{
		len++;
		n *= sign;
	}
	nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str_nb;
	int				i;
	unsigned int	nb;

	i = len_int(n);
	if (!(str_nb = ft_strnew(i)))
		return (NULL);
	if (n <= 0)
	{
		if (n == 0)
		{
			str_nb[0] = '0';
			return (str_nb);
		}
		str_nb[0] = '-';
		n *= -1;
	}
	str_nb[i] = '\0';
	nb = n;
	while (i > 0 && nb > 0)
	{
		str_nb[--i] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str_nb);
}
