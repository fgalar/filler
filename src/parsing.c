/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:10:32 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/06 22:47:56 by fanny            ###   ########.fr       */
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
		ft_strcpy(pos->piece[y], line);
		ft_strdel(&line);
		y++;
	}
	pos->piece[y] = 0;
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
	ft_strdel(&line);
	get_piece(pos, line);
}

void	get_map(t_info *info, t_solver *pos, char *line)
{
	int		y;
	int		x;

	y = -1;
	if (!(pos->map = (char**)malloc(sizeof(char*) * (info->height + 1))))
		return ;
	while (++y < info->height)
	{
		if (!(pos->map[y] = (char*)malloc(sizeof(char) * (info->width + 1)))
		|| !(get_next_line(0, &line)))
			return ;
		x = 0;
		if (ft_isdigit(line[4]))
		{
			ft_strdel(&line);
			if (!(get_next_line(0, &line)))
				return ;
		}
		while (ft_isdigit(line[x]))
			++x;
		ft_strcpy(pos->map[y], &line[++x]);
		ft_strdel(&line);
	}
	pos->map[y] = 0;
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
	ft_strdel(&line);
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
	ft_strdel(&line);
}
