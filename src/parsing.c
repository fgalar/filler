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

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../include/filler.h"
#include "../libft/libft.h"

/*void	get_map(t_data *info, char *line)
{
	(void)info;
	while (get_next_line(0, &line))
	{
		ft_putstr_fd(line, 2);
		ft_putchar_fd('\n', 2);
	}
}
*/
void	get_map_size(t_data *info, char *line)
{
	int		i;

	i = 0;

	if (ft_strstr(line, "Plateau"))
	{
		while (!(ft_isdigit(line[i])))
			i++;
		info->width = ft_atoi(&line[i - 1]);
		while (ft_isdigit(line[i]))
			i++;
		info->height = ft_atoi(&line[i]);
	}
}

void	get_player(t_data *info, char *line)
{
	if (ft_strstr(line, "p1"))
	{
		info->player = 1;
		info->pawn = 'O';
	}
	else
	{
		info->player = 2;
		info->pawn = 'X';
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
		if (i > 1)	
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
}
