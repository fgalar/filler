/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/06 23:42:54 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		main(void)
{
	t_info		info;
	t_solver	pos;
	char		*line;

	line = NULL;
	ft_bzero(&info, sizeof(t_info));
	get_player(&info, line);
	while (1)
	{
		get_size_map(&info, line);
		get_map(&info, &pos, line);
		skip_points(&pos);
		score_map(&info, &pos);
		solve(&info, &pos);
		ft_printf("%d %d\n", pos.besty, pos.bestx);
		if (pos.besty == 0 && pos.bestx == 0)
			break ;
		clear_new_turn(&info, &pos);
		clear_all(&pos);
	}
	return (0);
}
