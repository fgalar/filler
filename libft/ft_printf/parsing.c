/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:10:36 by fanny             #+#    #+#             */
/*   Updated: 2020/05/01 18:55:25 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_flag(t_data *d, const char *format)
{
	static char *flags[NB_FLAGS] = {"hh", "h", "ll", "l", "#", "+", " ", "-",
	"0", "%", "."};
	int			y;

	y = -1;
	while (++y < NB_FLAGS)
	{
		format[d->index] == 'L' && d->index++ ? d->flag[ll] = 1 : 0;
		if (!ft_strncmp(flags[y], &format[d->index], ft_strlen(flags[y])))
		{
			((d->flag[hh] || d->flag[h] || d->flag[ll] || d->flag[l]) && y <= 3)
			? init_new_arg(d) : 0;
			d->flag[y] = 1;
			if (d->flag[percent])
				return (1);
			d->index += ft_strlen(flags[y]);
			if (y == 10)
				format[d->index] == '0' ? d->index++ && (d->precis = 0) :
				(d->precis = 0);
			get_flag(d, format);
		}
		if (ft_isdigit(format[d->index]) && format[d->index] != '0')
			get_size(d, format);
	}
	return (0);
}

void			get_size(t_data *data, const char *format)
{
	int		n_size;

	n_size = ft_atoi(&format[data->index]);
	if (n_size < 0)
	{
		buff_purge(data);
		write(1, "inf", 3);
		data->size = -1;
		data->index = ft_strlen(format);
		return ;
	}
	if (format[data->index - 1] == '.'
		|| (data->flag[point] && data->precis == 0))
		data->precis = n_size;
	else
		data->field = n_size;
	data->index += ft_nbrlen(n_size);
	if (data->precis || data->field)
	{
		if (data->field > data->precis)
			data->width_max = data->field;
		else
			data->width_max = data->precis;
	}
	get_flag(data, format);
}

static void		get_conv(t_data *data, const char *format)
{
	static char	conv[NB_CONV] = {'c', 's', 'p', 'd',
						'i', 'o', 'u', 'x', 'X', 'f'};
	int			y;
	char		c;

	y = 0;
	c = format[data->index];
	if (ft_ismaj(c) && c != 'X' && (c = ft_tolower(format[data->index])))
	{
		init_new_arg(data);
		data->flag[ll] = 1;
	}
	while (y < NB_CONV)
	{
		if (c == conv[y] && data->index++ && (data->conv = conv[y]))
			return ;
		y++;
	}
}

void			pf_parsing(t_data *data, const char *format)
{
	if (format[data->index] == '%')
	{
		if (data->len >= 100)
			buff_purge(data);
		data->index++;
		init_new_arg(data);
		if (!get_flag(data, format))
			get_conv(data, format);
		dispatcher(data, format);
	}
	else
	{
		data->buffer[data->len] = format[data->index];
		data->len++;
		if (format[data->index] == '\n')
			buff_purge(data);
		data->index++;
	}
}
