/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:32:39 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/08 19:04:11 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	skip_endpoints(t_solver *pos)
{
	int		j;
	int		i;

	j = pos->hght_p - 1;
	i = pos->wdth_p;
	while (--i > 0 && pos->piece[j][i] == '.')
	{
		if (i == 1 && pos->piece[j][0] == '.' && (i = pos->wdth_p))
			--j;
	}
	pos->hght_p = j + 1;
	i = pos->wdth_p - 1;
	j++;
	while (--j > 0 && pos->piece[j][i] == '.')
	{
		if (j == 1 && pos->piece[0][i] == '.' && (j = pos->hght_p))
			--i;
	}
	pos->wdth_p = i + 1;
}

void	skip_points(t_solver *pos)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < pos->hght_p && pos->piece[j][i] == '.')
	{
		j++;
		if (j == pos->hght_p && (pos->xless = i + 1))
		{
			j = 0;
			i++;
		}
	}
	j = 0;
	while (i < pos->wdth_p && pos->piece[j][i] == '.')
	{
		i++;
		if (i == pos->wdth_p && (pos->yless = j + 1))
		{
			i = 0;
			j++;
		}
	}
	skip_endpoints(pos);
}

int		can_put(t_info *info, t_solver *pos)
{
	int		i;
	int		j;
	int		nb_contact;

	j = pos->yless;
	nb_contact = 0;
	while (j + pos->y < info->height && j < pos->hght_p)
	{
		i = pos->xless;
		while (i + pos->x < info->width && i < pos->wdth_p)
		{
			if (pos->map[pos->y + j][pos->x + i] == info->enemy
			&& pos->piece[j][i] == '*')
				return (0);
			if (pos->map[pos->y + j][pos->x + i] == info->pawn
			&& pos->piece[j][i] == '*')
				nb_contact++;
			i++;
		}
		j++;
	}
	return (nb_contact == 1 ? 1 : 0);
}

int		solve(t_info *info, t_solver *p)
{
	p->y = -(p->yless);
	while (p->y + p->hght_p < (info->height + 1)
	&& p->y + p->yless < info->height)
	{
		p->x = -(p->xless);
		(p->y == 0 && p->x == 0) && (p->besty || p->bestx) ? (p->x = 1) : 0;
		while (p->x + p->wdth_p < (info->width + 1)
		&& p->y + p->xless < info->width)
		{
			if (can_put(info, p))
			{
				if ((!p->besty && !p->bestx)
				|| p->heat_m[p->y + p->yless][p->x + p->xless]
				> p->heat_m[p->besty + p->yless][p->bestx + p->xless])
				{
					p->besty = p->y;
					p->bestx = p->x;
				}
			}
			p->x++;
		}
		p->y++;
	}
	return (0);
}
