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
#ifndef FILLER_H
# define FILLER_H
# define bool int
# define TAB ft_putchar_fd('\t', 2)
# define BK_N ft_putchar_fd('\n', 2)
# define NBR ft_putnbr_fd
# define STR ft_putstr_fd
# define CHAR ft_putchar_fd

typedef struct			s_data
{
	int			player;
	char			pawn;
	char			enemy;
	
	int			height;
	int			width;	
	char			**map;

	int			hght_p;
	int			wdth_p;
	char			**piece;

}				t_data;

typedef struct			s_solver
{
	int	y;
	int	x;
}				t_solver;

void				parsing(t_data *info);
void				get_player(t_data *info, char *line);
void				get_map(t_data *info,  char *line);


int				solve(t_data *info, t_solver *pos);

#endif
