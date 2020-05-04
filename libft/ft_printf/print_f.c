/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:40 by fanny             #+#    #+#             */
/*   Updated: 2020/04/27 20:18:06 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_f_core(t_data *data, char *f_char)
{
	if (data->width_max < 1000)
		handler(data, f_char);
	else
	{
		print_buff(f_char, data);
		return (0);
	}
	return (1);
}

static void	reinit_precis(t_data *d)
{
	d->precis = 0;
	d->flag[point] = 0;
	d->width_max = d->field;
	d->flag[diese] = 0;
	if (d->flag[most])
	{
		d->prfx = 1;
		ft_strcpy(d->prefix, "+");
	}
}

int			print_f(t_data *data)
{
	long double		n;
	char			f_char[4096];
	t_float			f_nbr;

	if (data->flag[ll])
		n = va_arg(data->arg, long double);
	else
		n = va_arg(data->arg, double);
	ft_bzero(f_char, 4096);
	f_nbr.fl = n;
	f_nbr.b_count.sign ? (data->neg = 1 && ft_strcat(data->prefix, "-")) : 0;
	if (f_nbr.b_count.exp == 0b111111111111111)
	{
		ft_strcat(f_char, "inf");
		data->flag[zero] = 0;
	}
	else if (data->width_max < 100)
		ft_strcpy(f_char, ft_float(data, n));
	reinit_precis(data);
	if (!ft_print_f_core(data, f_char))
		return (0);
	ft_strcat(data->buffer, data->argument);
	data->len = ft_strlen(data->buffer);
	data->conv = 0;
	return (0);
}
