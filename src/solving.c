/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:32:39 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/04 22:52:03 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	skip_endpoints(t_solver *pos)
{
	int		j;
	int		i;

	j = pos->hght_p - 1;
	i = pos->wdth_p;
	display(pos->piece, pos->hght_p);
	while (--i > 0 && pos->piece[j][i] == '.')
	{
		if (i == 1 && pos->piece[j][0] == '.' && (i = pos->wdth_p))
			--j;
	}
	pos->hght_p = j;
	i = pos->wdth_p - 1;
	dprintf(2, "pos->hght = %d\n", j);
	while (--j > 0 && pos->piece[j][i] == '.')
	{
		if (j == 1 && pos->piece[0][i] == '.' && (j = pos->hght_p))
			--i;
	}
	pos->wdth_p = i;
	dprintf(2, "pos->wdth = %d\n", i);
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
		if (j == pos->hght_p)
		{
			j = 0;
			i++;
		}
	}
	pos->x_less = i;
	j = 0;
	while (i < pos->wdth_p && pos->piece[j][i] == '.')
	{
		i++;
		if (i == pos->wdth_p)
		{
			i = 0;
			j++;
		}
	}
	pos->y_less = j;
//	skip_endpoints(pos);
}

int	can_put(t_info *info, t_solver *pos)
{
	int		i;
	int		j;
	int		nb_contact;

	j = pos->y_less;
	nb_contact = 0;
	while (j + pos->y < info->height && j < pos->hght_p)		
	{								
		i = pos->x_less;
		while (i + pos->x < info->width && i < pos->wdth_p)
		{	
			if (pos->map[pos->y + j][pos->x + i] == info->enemy && pos->piece[j][i] == '*')
				return (0);
			if (pos->map[pos->y + j][pos->x + i] == info->pawn && pos->piece[j][i] == '*')
				nb_contact++;
			i++;
		}
		j++;
	}
	return (nb_contact == 1 ? 1 : 0); 
}

int	solve(t_info *info, t_solver *pos)
{
	
	pos->y = -(pos->y_less);
	while (pos->y + pos->hght_p < info->height && pos->y + pos->y_less < info->height)
	{	
		pos->x = -(pos->x_less);
	
		pos->y == 0 ? (pos->x = 1) : (pos->x = 0);  
		while (pos->x + pos->wdth_p < info->width && pos->y + pos->x_less < info->width)
		{	
			if (can_put(info, pos))
			{
				dprintf(2, "can_put[%d][%d]\n", pos->y, pos->x);
				if (!pos->besty_pos && !pos->bestx_pos)
				{
					pos->besty_pos = pos->y;
					pos->bestx_pos = pos->x;
				}
				else if (pos->heat_m[pos->y + pos->y_less][pos->x + pos->x_less] > pos->heat_m[pos->besty_pos + pos->y_less][pos->bestx_pos + pos->x_less])
				{
					pos->besty_pos = pos->y;
					pos->bestx_pos = pos->x;
				}
				dprintf(2, "best[%d][%d]\n", pos->besty_pos, pos->bestx_pos);
			}
			pos->x++;
		}
		pos->y++;
	}
	ft_printf("%d %d\n", pos->besty_pos, pos->bestx_pos);
	display(pos->map, info->height);
	dprintf(2,"---sending---->%d %d<-------sending----------\n", pos->besty_pos, pos->bestx_pos);
	return (0);
}
