/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:58:14 by fgarault          #+#    #+#             */
/*   Updated: 2020/04/27 14:44:11 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_majhex(char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
	{
		if (ft_isalpha(nb[i]))
			nb[i] = ft_toupper(nb[i]);
		i++;
	}
}

void	print_a(t_data *d, unsigned char c)
{
	d->precis = 0;
	d->flag[point] = 0;
	handler(d, (char*)&c);
	ft_strcat(d->buffer, d->argument);
	d->len += ft_strlen(d->argument);
	d->index++;
	d->conv = 0;
}

void	init_new_arg(t_data *d)
{
	ft_bzero(d->argument, 100);
	ft_bzero(d->prefix, 3);
	d->conv = 0;
	ft_bzero(d->flag, sizeof(d->flag));
	d->precis = 0;
	d->field = 0;
	d->width_max = 0;
	d->neg = 0;
	d->prfx = 0;
	d->ad_pf = 0;
}

void	init_struct(t_data *d)
{
	ft_bzero(d->buffer, 4096);
	ft_bzero(d->argument, 100);
	ft_bzero(d->prefix, 3);
	d->conv = 0;
	ft_bzero(d->flag, NB_FLAGS);
	d->index = 0;
	d->len = 0;
	d->precis = 0;
	d->field = 0;
	d->width_max = 0;
	d->size = 0;
	d->neg = 0;
	d->prfx = 0;
	d->ad_pf = 0;
}

int		is_even(char n)
{
	if (n == '0' || n == '2' || n == '4' || n == '6' || n == '8')
		return (1);
	return (0);
}
