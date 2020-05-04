/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:13:30 by fanny             #+#    #+#             */
/*   Updated: 2020/05/02 14:58:49 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	display_info(t_info *info)
{
	NBR(info->player);
	BK_N;
	NBR(info->pawn);
	BK_N;
	NBR(info->enemy);
	BK_N;
	NBR(info->height);
	BK_N;
	NBR(info->width);
	BK_N;
	display(info->map, info->height);
	BK_N;
	NBR(info->hght_p);
	BK_N;
	NBR(info->wdth_p);
	BK_N;
	display(info->piece, info->hght_p);
	BK_N;
}
