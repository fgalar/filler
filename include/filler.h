/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:12:51 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/04 22:25:20 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#ifndef FILLER_H
# define FILLER_H
# define TAB ft_putchar_fd('\t', 2)
# define BK_N ft_putchar_fd('\n', 2)
# define NBR(x) ft_putnbr_fd(x, 2)
# define STR(x) ft_putstr_fd(x, 2)
# define CHAR(x) ft_putchar_fd(x, 2)

typedef struct			s_info
{
	int					player;
	char				pawn;
	char				enemy;

	int					height;
	int					width;
}						t_info;

typedef struct			s_solver
{
	char				**map;
	int					hght_p;
	int					wdth_p;
	char				**piece;

	int					y;
	int					x;

	int					y_less;
	int					x_less;

	char				**heat_m;
	int					besty_pos;
	int					bestx_pos;
}						t_solver;

void					parsing(t_info *info);
void					get_player(t_info *info, char *line);
void					get_size_map(t_info *info, char *line);
void					get_map(t_info *info, t_solver *pos, char *line);
void					skip_points(t_solver *pos);
int						solve(t_info *info, t_solver *pos);
void					score_map(t_info *info, t_solver *mapping);
void					clear_new_turn(t_info *info, t_solver *solver);

void					display(char **tab, int y);
#endif
