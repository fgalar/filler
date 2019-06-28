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

int	can_put(t_data *info, t_solver pos)
{
	int	i;
	int	j;
	bool	nb_p;

	j= 0;
	while (j + pos->y < info->height && j < hght_p)		
	{								
		i = 0;
		while (i + pos->y < info->width && i < wdth_p)
		{	
			if (info->map[pos.y + j][pos.x + i] != '.' 
				&& info->piece[j][i] == info->pawn)
				return (0);
			if (info->map[pos.y + j][pos.x + i] == info->enemy 
				&& info->piece[j][i] == info->pawn)
				return (0);
			if (info->map[pos.y + j][pos.x + i] == info->pawn
				&& info->piece[j][i] == info->pawn)
				nb_pawn++;
			i++;
		}
		j++;
	}
	return (nb_pawn != 1 ? 0 : 1) 
}

void	put_piece(t_data *info, t_solver *pos)
{
	while (y < parse->height)
	{	
		x = 0;
		while (x < parse->width)
			x++;
		y++;
	}
}

char	*solve(t_data *info, t_solver *pos)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (can_put(info, pos))
		return ("COUCOU");
	ft_putstr_fd("3 8\n", 1);
}
