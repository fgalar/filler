/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:18:32 by fanny             #+#    #+#             */
/*   Updated: 2020/05/04 11:01:35 by fanny            ###   ########.fr       */
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
	solver->y_less = 0;
	solver->x_less = 0;
	solver->besty_pos = 0;
	solver->bestx_pos = 0;
}
