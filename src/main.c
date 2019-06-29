/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/24 21:06:20 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../include/filler.h"
#include "../libft/libft.h"


int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data *info;
	t_solver *pos;

	if (!(info = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	pos = NULL;
	parsing(info);
	solve(info, pos);
	return (0);
}
