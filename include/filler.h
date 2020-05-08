/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:12:51 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/08 19:04:18 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# define ERROR -1
# define SUCCESS 0

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

	int					yless;
	int					xless;

	char				**heat_m;
	int					besty;
	int					bestx;
}						t_solver;

int						get_player(t_info *info, char *line);
int						get_size_map(t_info *info, char *line);
int						get_map(t_info *info, t_solver *pos, char *line);
int						get_size_piece(t_solver *pos, char *line);
void					skip_points(t_solver *pos);
int						solve(t_info *info, t_solver *p);
void					score_map(t_info *info, t_solver *mapping);
void					clear_new_turn(t_info *info, t_solver *solver);
void					clear_all(t_solver *pos);
void					clean_tab(char **tab);

void					display(char **tab);
#endif
