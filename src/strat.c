/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:01:03 by fgarault          #+#    #+#             */
/*   Updated: 2020/03/07 16:55:25 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		**switchto_int(int **map, t_data *info)
{
	int		y;
	int		x;

	y = info->height - 1;
	while (y > 0)
	{
		x = info->width - 1;
		while (x > 0)
		{
			map[y][x] = 0;
			if (info->map[y][x] == info->enemy)
				map[y][x] = 1;
			if (info->map[y][x] == info->pawn)
				map[y][x] = 2;
			ft_print_tab_int(map[y], info->width);
			--x;
		}
		--y;
	}
	return (map);
}

void	score_map(t_data *info, t_solver *mapping)
{
	int		score;
	int		y;

	score = 10;
	y = 0;
	(void)mapping;
	(void)mapping;
	if(!(mapping->heat_m = (int**)malloc((sizeof(int*) * (info->height + 2)))))
		return ;
	while (y < info->height)
	{
		if (!(mapping->heat_m[y] = (int*)malloc((sizeof(int) * (info->width + 1)))))
			return ;
		mapping->heat_m[y][info->width] = 0;
		y++;
	}
	ft_bzero(mapping->heat_m, info->height);
	mapping->heat_m = switchto_int(mapping->heat_m, info);	
}
