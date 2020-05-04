/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:11:39 by fgarault          #+#    #+#             */
/*   Updated: 2020/04/19 10:21:31 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		buff_purge(t_data *data)
{
	write(1, data->buffer, data->len);
	ft_bzero(data->buffer, data->len);
	data->size += data->len;
	data->len = 0;
	return (data->size);
}

int		print_buff(char *s, t_data *d)
{
	int		len;
	int		len_p;
	char	a;
	int		i;

	d->precis < (int)ft_strlen(s) && d->flag[point] ? (len = d->precis) :
	(len = ft_strlen(s));
	d->field > len ? (len_p = d->field - len) :
	(len_p = 0);
	d->flag[zero] && !d->flag[less] ? (a = '0') :
	(a = ' ');
	i = -1;
	buff_purge(d);
	if ((d->flag[zero] || d->field) && !d->flag[less])
	{
		while (len_p > ++i)
			write(1, &a, 1);
	}
	write(1, s, len);
	if (d->flag[less] && (i = -1))
	{
		while (len_p > ++i)
			write(1, &a, 1);
	}
	return (d->size += len + len_p);
}
