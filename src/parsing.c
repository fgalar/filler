/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:10:32 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/19 20:31:23 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../include/filler.h"
#include "../libft/libft.h"


void 	parsing(int fd)
{
	int		ret;
	char	buffer[4096];
	while ((ret = read(0, buffer, 4096)) > 0)
		;
	ft_putstr_fd(buffer, fd);
}
