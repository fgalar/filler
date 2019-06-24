/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:10:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/24 21:06:14 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../include/filler.h"
#include "../libft/libft.h"

void	get_map(t_data *info, char *line)
{
	char	*sch_str;
	int		height;
	int 	width;

	if (sch_str = ft_strstr(line, "Plateau"))
		width = ft_atoi(sch_str[6]);
		height = ft_atoi(sch_str[8]);
	
		
}
void	get_player(t_data *info, char *line)
{
	if (ft_strstr(line, "p1"))
	{
		info->player = 1;
		info->pawn = 'O';
	}
	else
		info->player = 2;
		info->pawn = 'X';

}

void 	parsing(t_data *info)
{
	(void)info;
	char	*line;
	int		ret;


	while (get_next_line(0, &line) > 0)
	{	
		if (i == 0)
		{
			get_player(info, line);
			i++;
		}
	}
	ft_putnbr_fd(info->player, 2);
	ft_putchar_fd(info->pawn, 2);
}
