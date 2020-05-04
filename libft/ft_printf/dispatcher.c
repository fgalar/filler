/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:24:26 by fanny             #+#    #+#             */
/*   Updated: 2020/02/24 16:18:04 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			dispatcher(t_data *data, const char *format)
{
	int			x;
	static char	conv[NB_CONV] = {'c', 's', 'p', 'd', 'o', 'u', 'x', 'X', 'f'};
	static int	(*go_ft[NB_CONV])(t_data *data) = {print_c, print_s, print_p,
		print_d, print_o, print_u, print_x, print_x, print_f};

	x = 0;
	if (!data->conv)
	{
		if ((data->field || data->flag[percent]) && format[data->index])
			print_a(data, format[data->index]);
		return (0);
	}
	if (data->conv == 'i')
		data->conv = 'd';
	while (conv[x] != data->conv)
		x++;
	if (conv[x] == data->conv && x < NB_CONV)
		return ((go_ft[x])(data));
	return (0);
}
