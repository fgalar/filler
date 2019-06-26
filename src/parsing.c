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

#include <unistd.h>
#include <stdlib.h>
#include "../include/filler.h"
#include "../libft/libft.h"

void	get_map(t_data *info, char *line)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	if (!(info->map = (char**)malloc(sizeof(char*) * (info->height))))
		return ;
	if (!(info->map[y] = (char*)malloc(sizeof(char) * (info->width))))
		return ;
	while (get_next_line(0, &line) > 0 && ft_atoi(line) < info->height)
	{
		i = 0;
		while (ft_isdigit(line[i]))
			i++;
		i++;
		info->map[y] = &line[i];
		y++;
	}
}

void	get_map_size(t_data *info, char *line)
{
	int		i;

	i = 0;

	if (ft_strstr(line, "Plateau"))
	{
		while (!(ft_isdigit(line[i])))
			i++;
		info->height = ft_atoi(&line[i - 1]);
		while (ft_isdigit(line[i]))
			i++;
		info->width = ft_atoi(&line[i]);
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
		if (i == 1)
			get_map_size(info, line);
		if (i == 2)	
			get_map(info, line);
		i++;
	}
	ft_putnbr_fd(info->player, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd(info->pawn, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(info->width, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(info->height, 2);
	int o;
	int p;

	o = 0;
	p = 0;
	while (o < (info->height + 1))
	{
		ft_putchar_fd('\n', 2);
		ft_putstr_fd(info->map[o], 2);
		o++;
	}

}
