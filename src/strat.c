/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:01:03 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/05 11:56:59 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	clr_tab(t_info *info, t_solver *pos, char **hmap)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			pos->map[y][x] == info->enemy ? (hmap[y][x] = 126) :
			(hmap[y][x] = '.');
			x++;
		}
		hmap[y][x] = '\0';
		y++;
	}
	hmap[y] = 0;
}

void	fill_score(char **hmap, int y, int x, int score)
{
	if (y > 0)
	{
		if (x > 0 && hmap[y - 1][x - 1] == '.')
			hmap[y - 1][x - 1] = score;
		if (hmap[y - 1][x] == '.')
			hmap[y - 1][x] = score;
		if (hmap[y - 1][x + 1] != '\0' && hmap[y - 1][x + 1] == '.')
			hmap[y - 1][x + 1] = score;
	}
	if (x > 0 && hmap[y][x - 1] == '.')
		hmap[y][x - 1] = score;
	if (hmap[y][x + 1] != '\0' && hmap[y][x + 1] == '.')
		hmap[y][x + 1] = score;
	if (hmap[y + 1] != 0)
	{
		if (hmap[y + 1][x] == '.')
			hmap[y + 1][x] = score;
		if (hmap[y + 1][x - 1] == '.')
			hmap[y + 1][x - 1] = score;
		if (hmap[y + 1][x + 1] == '.')
			hmap[y + 1][x + 1] = score;
	}
}

void	set_score(char **hmap, char target, char score)
{
	int		y;
	int		x;

	y = 0;
	while (hmap[y] != 0)
	{
		x = 0;
		while (hmap[y][x] != '\0')
		{
			if (hmap[y][x] == target)
				fill_score(hmap, y, x, score);
			x++;
		}
		y++;
	}
}

void	score_map(t_info *info, t_solver *pos)
{
	int		y;
	char	score;

	y = 0;
	score = 126;
	if (!(pos->heat_m = (char**)malloc(sizeof(char*) * info->height + 1)))
		return ;
	while (y < info->height)
	{
		if (!(pos->heat_m[y] = (char*)malloc(sizeof(char) * info->width + 1)))
			return ;
		y++;
	}
	clr_tab(info, pos, pos->heat_m);
	while (score > 47)
	{
		set_score(pos->heat_m, score, score - 1);
		score--;
	}
	pos->heat_m[0][0] = 0;
}
