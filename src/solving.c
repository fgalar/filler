/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:32:39 by fgarault          #+#    #+#             */
/*   Updated: 2020/03/06 17:30:36 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	skip_points(t_data *info, t_solver *pos)
{
	int	i;
	int	j;
	char score;

	j = 0;
	i = 0;
	score = '9';
	while (j < info->hght_p && info->piece[j][i] == '.')
	{
		j++;
		if (j == info->hght_p)
		{
			j = 0;
			i++;
		}
	}
	pos->x_less = i;
	j = 0;
	while (i < info->wdth_p && info->piece[j][i] == '.')
	{
		i++;
		if (i == info->wdth_p)
		{
			i = 0;
			j++;
		}
	}
	pos->y_less = j;
	score_map(info, pos);
	
}

int	can_put(t_data *info, t_solver *pos)
{
	int	i;
	int	j;
	bool	nb_contact;

	j = pos->y_less;
	nb_contact = 0;
	while (j + pos->y < info->height && j < info->hght_p)		
	{								
		i = pos->x_less;
		while (i + pos->x < info->width && i < info->wdth_p)
		{	
			if (info->map[pos->y + j][pos->x + i] == info->enemy && info->piece[j][i] == '*')
				return (0);
			if (info->map[pos->y + j][pos->x + i] == info->pawn && info->piece[j][i] == '*')
				nb_contact++;
			i++;
		}
		j++;
	}
	return (nb_contact == 1 ? 1 : 0); 
}

int	solve(t_data *info, t_solver *pos)
{
	
	pos->y = -(pos->y_less);
	while (pos->y + info->hght_p < info->height)
	{	
		pos->x = -(pos->x_less);
	
		pos->y == 0 ? (pos->x = 1) : (pos->x = 0);  
		while (pos->x + info->wdth_p < info->width)
		{	
			if (can_put(info, pos))
			{	
				ft_putstr(ft_itoa(pos->y));
				ft_putchar_fd(' ', 1);
				ft_putstr_fd(ft_itoa(pos->x), 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			pos->x++;
		}
		pos->y++;
	}
	pos->y = 0;
	pos->x = 0;
	ft_putstr(ft_itoa(pos->y));
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(ft_itoa(pos->x), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
