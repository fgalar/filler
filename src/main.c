/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/04 22:48:42 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		main(void)
{
	t_info 		*info;
	t_solver 	*pos;
	char		*line;

	line = NULL;
	if (!(pos = (t_solver*)malloc(sizeof(t_solver))))
		return (-1);
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (-1);
	ft_bzero(info, sizeof(t_info));
	get_player(info, line);
	while (1)
	{
		clear_new_turn(info, pos);
		get_size_map(info, line);
		get_map(info, pos, line);
		skip_points(pos);
		score_map(info, pos);
		display(pos->heat_m, info->height);
		solve(info, pos);
		if (pos->besty_pos == 0 && pos->bestx_pos == 0)
			break ;
	}
	free(info);
	free(pos);
	return (0);
}

