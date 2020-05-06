/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:18:32 by fanny             #+#    #+#             */
/*   Updated: 2020/05/07 00:19:50 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	clear_new_turn(t_info *info, t_solver *solver)
{
	int		i;

	i = -1;
	while (++i < info->height)
	{
		ft_bzero(solver->map[i], info->width);
		ft_bzero(solver->heat_m[i], info->width);
	}
	i = -1;
	while (++i < solver->hght_p)
		ft_bzero(solver->piece[i], solver->wdth_p);
	solver->hght_p = 0;
	solver->wdth_p = 0;
	solver->y = 0;
	solver->x = 0;
	solver->yless = 0;
	solver->xless = 0;
	solver->besty = 0;
	solver->bestx = 0;
}

void	clean_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			ft_strdel(&tab[i++]);
		if (tab)
			free(tab);
	}
}

void	clear_all(t_solver *pos)
{
	clean_tab(pos->map);
	clean_tab(pos->piece);
	clean_tab(pos->heat_m);
}

void	display(char **tab)
{
	int		i = 0;
	while (tab[i])
		dprintf(2, "%s\n", tab[i++]);
}
