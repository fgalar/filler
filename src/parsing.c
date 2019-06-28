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
	while (get_next_line(0, &line) && y < info->hght_p)
	{
		info->piece[y] = line;
		y++;
	}
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
	while (get_next_line(0, &line) > 0 && y < info->height)
	{
		x = 0;
		if (ft_isdigit(line[4]))
			get_next_line(0, &line);
		while (ft_isdigit(line[x]))
			x++;
		x++;
		info->map[y] = &line[x];
		y++;
	}
	get_size(info, line);
}

void	get_size(t_data *info, char *line)
{
	int		i;
	int		obj_hght;
	int		obj_wdth;

	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	obj_hght = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	obj_wdth = ft_atoi(&line[i]);
	if (ft_strstr(line, "Plateau"))
	{
		info->height = obj_hght;
		info->width = obj_wdth;
		get_map(info, line);
	}
	if (ft_strstr(line, "Piece"))
	{
		info->hght_p = obj_hght;
		info->wdth_p = obj_wdth;
		get_piece(info, line);
	}
}

void	get_player(t_data *info, char *line)
{
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

void 	parsing(t_data *info)
{
	(void)info;
	char	*line;
	int		i;
	
	i = 0;
	while (get_next_line(0, &line) > 0)
	{	
		if (i == 0)
			get_player(info, line);
		else
			get_size(info, line);
		i++;
	}
	/*************test***************/
	ft_putnbr_fd(info->player, 2);
	ft_putchar_fd('\t', 2);
	ft_putchar_fd(info->pawn, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(info->height, 2);
	ft_putchar_fd('\t', 2);
	ft_putnbr_fd(info->width, 2);
	int o;

	o = 0;
	while (o < info->height)
	{
		ft_putchar_fd('\n', 2);
		ft_putstr_fd(info->map[o], 2);
		o++;
	}

	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(info->hght_p, 2);
	ft_putchar_fd('\t', 2);
	ft_putnbr_fd(info->wdth_p, 2);

	int p;

	p = 0;
	while (p < info->hght_p)
	{
		ft_putchar_fd('\n', 2);
		ft_putstr_fd(info->piece[p], 2);
		p++;
	}

}
