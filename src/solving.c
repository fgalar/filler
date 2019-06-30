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

int	can_put(t_data *info, t_solver *pos)
{
	int	i;
	int	j;
	bool	nb_pawn;

	j= 0;
	nb_pawn = 0;
	while (j + pos->y < info->height && j < info->hght_p)		
	{								
		i = 0;
		while (i + pos->y < info->width && i < info->wdth_p)
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

void	send_position(t_solver *pos)
{
	ft_putstr_fd(ft_itoa(pos->y), 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(ft_itoa(pos->x), 1);
	ft_putchar_fd('\n', 1);

	BK_N;
	STR("X = ", 2);
	NBR(pos->x, 2);
	BK_N;
	STR("Y = ", 2);
	NBR(pos->y, 2);
	CHAR('\n', 2);

}

int	solve(t_data *info, t_solver *pos)
{
	while (pos->y < info->height)
	{	
		pos->x = 0;
		while (pos->x < info->width)
		{
			if (can_put(info, pos))
			{
				send_position(pos);
				return (1);
			}
			pos->x++;
		}
		pos->y++;
	}
	return (0);
}
