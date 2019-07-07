/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   !!!!!!!HEADER A REGERER  A L   ECCOOOOOLE  !!!     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:10:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/25 22:20:42 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../libft/libft.h"

void	skip_points(t_data *info, t_solver *pos)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < info->hght_p && info->piece[j][i] == '.')
	{
		j++;
		if (j == info->hght_p)
		{
			j = 0;
			i++;
		}
	}
	pos->x_less = i * -1;
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
	pos->y_less = j * -1;
}

int	can_put(t_data *info, t_solver *pos)
{
	int	i;
	int	j;
	bool	nb_pawn;

	j = 0;
	nb_pawn = 0;
	while (j + pos->y < info->height && j < info->hght_p)		
	{								
		i = 0;
		while (i + pos->x < info->width && i < info->wdth_p)
		{	
			if (info->map[pos->y + j][pos->x + i] == info->enemy && info->piece[j][i] == '*')
				return (0);
			if (info->map[pos->y + j][pos->x + i] == info->pawn && info->piece[j][i] == '*')
				nb_pawn++;
			i++;
		}
		j++;
	}
	return (nb_pawn != 1 ? 0 : 1); 
}

int	solve(t_data *info, t_solver *pos)
{
	pos->y = 0;
	while (pos->y + info->hght_p <= info->height)
	{	
		pos->y == 0 ? (pos->x = 0) : (pos->x = 0);  
		while (pos->x + info->wdth_p <= info->width)
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
