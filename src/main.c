/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:23:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/21 16:36:20 by fgarault         ###   ########.fr       */
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
	char	*str;
	char 	tmp[4096];
	int		ret;

	
	while ((ret = get_next_line(0, &str)) > 0)
		ft_strcat(tmp, str);
	ft_putstr_fd(tmp, 2);
	return (0);
}
