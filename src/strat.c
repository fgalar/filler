/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:01:03 by fgarault          #+#    #+#             */
/*   Updated: 2020/03/05 18:22:27 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	heat_map2(t_data *info, t_solver *mapping)
{
	int		i;
	int		y;

	i = 0;
	while (i < info->width)
	{
		y = 0;
		while (y < info->height)
		{
			if (mapping->heat_m[y + 1][i] == info->enemy && mapping->heat_m[y][i] != info->enemy)
				mapping->heat_m[y][i] = '5';
			y++;
		}
		i++;
	}

}

void	heat_map(t_data *info, t_solver *mapping)
{
	int		i;
	int		y;

	y = 0;
	mapping->heat_m = info->map;
	//heat_map2(info, mapping);
	while (y < info->height)
	{
		i = 0;
		while (i < info->width)
		{
			if (mapping->heat_m[y][i] == info->enemy && mapping->heat_m[y][i] != info->enemy)
				mapping->heat_m[y][i] = '5';
			i++;

		}
		y++;
		write(2, mapping->heat_m[y], info->width);
		write(2, "\n", 1);
	}
	write(2, "\n", 1);
}
