/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:59:15 by fanny             #+#    #+#             */
/*   Updated: 2020/05/04 22:42:56 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		conv_len(long long n, int base)
{
	int					len;
	unsigned long long	nb;
	int					sign;

	len = 0;
	sign = 1;
	if (n == 0)
		return (1);
	if (base == 10 && n < 0)
	{
		len++;
		sign = -1;
	}
	nb = n * sign;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

void	convert(unsigned long long n, int b, char *nb, int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 0)
	{
		convert(n / b, b, nb, (i - 1));
		nb[i] = base[n % b];
	}
}

char	*itoa_base(long long n, int base)
{
	int					len;
	char				*nb;

	len = conv_len(n, base);
	if (base < 2 || base > 16
			|| !(nb = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
	{
		free(nb);
		return ("0");
	}
	if (n < 0 && base == 10)
	{
		nb[0] = '-';
		n *= -1;
	}
	convert(n, base, nb, (len - 1));
	nb[len] = '\0';
	free(nb);
	return (nb);
}
