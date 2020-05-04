/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:12:11 by fanny             #+#    #+#             */
/*   Updated: 2020/04/27 19:31:29 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d(t_data *data)
{
	char	*nb;

	if (data->flag[hh])
		nb = ft_itoa((char)va_arg(data->arg, int));
	else if (data->flag[h])
		nb = ft_itoa((short int)va_arg(data->arg, int));
	else if (data->flag[ll])
		nb = itoa_base(va_arg(data->arg, long long), 10);
	else if (data->flag[l])
		nb = itoa_base(va_arg(data->arg, long), 10);
	else
		nb = itoa_base(va_arg(data->arg, int), 10);
	if (nb[0] == '-' && (data->neg = 1))
		nb = &nb[1];
	data->width_max < 1000 ? handler(data, nb) : 0;
	if (data->width_max >= 1000)
	{
		data->size = print_buff(nb, data);
		return (0);
	}
	ft_strcat(data->buffer, data->argument);
	data->len += ft_strlen(data->argument);
	data->conv = 0;
	return (0);
}
