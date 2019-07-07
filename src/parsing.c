/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:10:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/25 22:20:42 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/filler.h"
#include "../libft/libft.h"

void	get_piece(t_data *info, char *line)
{
	int	y;
	
	y = 0;
	if (!(info->piece = (char**)malloc(sizeof(char*) * (info->hght_p))))
		return ;
	if (!(info->piece[y] = (char*)malloc(sizeof(char) * (info->wdth_p))))
		return ;
	while (y < info->hght_p)
	{
		if (!(get_next_line(0, &line)))
			return ;
		info->piece[y] = line;
		y++;
	}
}

void	get_size_piece(t_data *info, char *line)
{
	int	i;

	i = 0;
	if (!(get_next_line(0, &line)))
		return ;
	while (!(ft_isdigit(line[i])))
		i++;
	info->hght_p = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	info->wdth_p = ft_atoi(&line[i]);
	get_piece(info, line);
}

void	get_map(t_data *info, char *line)
{
	int	y;
	int	x;

	y = 0;
	if (!(info->map = (char**)malloc(sizeof(char*) * (info->height))))
		return ;
	if (!(info->map[y] = (char*)malloc(sizeof(char) * (info->width))))
		return ;
	while (y < info->height)
	{
		if (!(get_next_line(0, &line)))
			return ;
		x = 0;
		if (ft_isdigit(line[4]))
			get_next_line(0, &line);
		while (ft_isdigit(line[x]))
			x++;
		x++;
		info->map[y] = &line[x];
		y++;
	}
	get_size_piece(info, line);
}

void	get_size_map(t_data *info, char *line)
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

void	get_player(t_data *info, char *line)
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

void 	display(t_data *info)
{
	STR("PLAYER\n");
	NBR(info->player);
	CHAR('\t');
	CHAR(info->pawn);
	CHAR('\n');
	
	STR("TABLEAU\n");
	NBR(info->height);
	CHAR('\t');
	NBR(info->width);
	
	int o;
	o = 0;
	while (o < info->height)
	{
		CHAR('\n');
		STR(info->map[o]);
		o++;
	}
	CHAR('\n');
	NBR(info->hght_p);
	CHAR('\t');
	NBR(info->wdth_p);
	int p;
	p = 0;
	while (p < info->hght_p)
	{
		CHAR('\n');
		STR(info->piece[p]);
		p++;
	}
	BK_N;
}
