/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/08 18:07:03 by fanny            ###   ########.fr       */
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
	ft_bzero(&pos, sizeof(t_solver));
	if (get_player(&info, line) < 0)
		return (ERROR);
	while (1)
	{
		if (get_size_map(&info, line) < 0 || get_map(&info, &pos, line) < 0
			|| get_size_piece(&pos, line) < 0)
			break ;
		skip_points(&pos);
		score_map(&info, &pos);
		solve(&info, &pos);
		ft_printf("%d %d\n", pos.besty, pos.bestx);
		if (pos.besty == 0 && pos.bestx == 0)
			break ;
		clear_new_turn(&info, &pos);
		clear_all(&pos);
	}
	clear_all(&pos);
	return (0);
}
