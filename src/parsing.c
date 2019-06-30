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
		get_next_line(0, &line); 
		info->piece[y] = line;
		y++;
	}
}

void	get_size_piece(t_data *info, char *line)
{
	int	i;

	i = 0;
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
		get_next_line(0, &line);
		x = 0;
		if (ft_isdigit(line[4]))
			get_next_line(0, &line);
		while (ft_isdigit(line[x]))
			x++;
		x++;
		info->map[y] = &line[x];
		y++;
	}
	get_next_line(0, &line);
	get_size_piece(info, line);
}

void	get_size_map(t_data *info, char *line)
{
	int		i;

	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	info->height = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	info->width = ft_atoi(&line[i]);
	get_map(info, line);
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
	get_next_line(0, &line);
	get_size_map(info, line);
}

void 	parsing(t_data *info)
{
	(void)info;
	char	*line;
	
	get_next_line(0, &line);
	get_player(info, line);

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
