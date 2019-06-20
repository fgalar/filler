/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/20 17:41:50 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../include/filler.h"
#include "../libft/libft.h"

void	parsing(int fd);

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*line;
	char 	*tmp;

	while ((get_next_line(0, &line)) > 0)
		if (!(tmp = ft_strjoin(tmp, line)))
			return (-1);
	ft_putstr_fd(tmp, 2);
	return (0);
}
