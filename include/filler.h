/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:12:51 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/25 19:07:26 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_board
{
	int			player;
	char			pawn;
	char			enemy;
	int			width;
	int			height;
	char			**map;

}				t_data;

void			parsing(t_data *info);
