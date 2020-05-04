/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:10:32 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/04 22:47:17 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	get_piece(t_solver *pos, char *line)
{
	int	y;

	y = 0;
	if (!(pos->piece = (char**)malloc(sizeof(char*) * (pos->hght_p + 1))))
		return ;
	while (y < pos->hght_p)
	{
		if (!(pos->piece[y] = (char*)malloc(sizeof(char) * (pos->wdth_p + 1))))
			return ;
		if (!(get_next_line(0, &line)))
			return ;
		pos->piece[y] = line;
		y++;
	}
}

void	get_size_piece(t_solver *pos, char *line)
{
	int	i;

	i = 0;
	if (!(get_next_line(0, &line)))
		return ;
	while (!(ft_isdigit(line[i])))
		i++;
	pos->hght_p = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	pos->wdth_p = ft_atoi(&line[i]);
	get_piece(pos, line);
}

void	get_map(t_info *info, t_solver *pos, char *line)
{
	int	y;
	int	x;

	y = 0;
	if (!(pos->map = (char**)malloc(sizeof(char*) * (info->height + 1))))
		return ;
	while (y < info->height)
	{
		if (!(pos->map[y] = (char*)malloc(sizeof(char) * (info->width + 1))))
			return ;
		if (!(get_next_line(0, &line)))
			return ;
		x = 0;
		if (ft_isdigit(line[4]))
			get_next_line(0, &line);
		while (ft_isdigit(line[x]))
			x++;
		x++;
		pos->map[y] = &line[x];
		y++;
	}
	get_size_piece(pos, line);
}

void	get_size_map(t_info *info, char *line)
{
	int		i;

	i = 0;
	if (!(get_next_line(0, &line)))
		return ;
	while (!(ft_isdigit(line[i])))
		i++;
	info->height = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	info->width = ft_atoi(&line[i]);
}

void	get_player(t_info *info, char *line)
{
	if (!(get_next_line(0, &line)))
		return ;
	if (ft_strstr(line, "p1"))
	{
		info->player = 1;
		info->pawn = 'O';
		info->enemy = 'X';
	}
	else
	{
		info->player = 2;
		info->pawn = 'X';
		info->enemy = 'O';
	}
}

void	display(char **tab, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		ft_putstr_fd(tab[i], 2);
		BK_N;
		i++;
	}
	BK_N;
}
