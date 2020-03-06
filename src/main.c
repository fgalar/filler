/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2020/03/04 17:52:44 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data 		*info;
	t_solver 	*pos;
	char		*line;
	int y;

	y = 0;
	line = NULL;
	if (!(pos = (t_solver*)malloc(sizeof(t_solver))))
		return (-1);
	if (!(info = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	get_player(info, line);
	while (1)
	{
		get_size_map(info, line);
		get_map(info, line);
		
		//display(info);
		
		skip_points(info, pos);
		solve(info, pos);

	/*	while (y < info->height)
		{
			ft_strdel(&info->map[y]);
			y++;
		}
		free(info->map);

		y = 0;
		while (y < info->hght_p)
		{
			ft_strdel(&info->piece[y]);
			y++;
		}
		free(info->piece);*/
		if (pos->y == 0 && pos->x ==0)
			break ;
	}
	free(info);
	return (0);
}

