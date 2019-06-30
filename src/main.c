/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/24 21:06:20 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/filler.h"
#include "../libft/libft.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data *info;
	t_solver *pos;
	int ret;
	int y;

	ret = 1;
	if (!(pos = (t_solver*)malloc(sizeof(t_solver))))
		return (-1);
	while (ret == 1)
	{
		if (!(info = (t_data*)malloc(sizeof(t_data))))
			return (-1);
		parsing(info);
		ret = solve(info, pos);
		while (y < info->height)
		{
			ft_strdel(&info->map[y]);
			y++;
		}
		y = 0;
		while (y < info->hght_p)
		{
			ft_strdel(&info->piece[y]);
			y++;
		}
		free(info);
		pos->y = 0;
		pos->x = 0;
		info = NULL;
	}
	return (0);
}

