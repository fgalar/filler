/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:14:43 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/20 17:10:01 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static int	ft_strclen(char *str, int c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

static char	*ft_strjoinfree(char *s1, char *s2, int option)
{
	char *s;

	s = ft_strjoin(s1, s2);
	if (option == 1)
		free(s1);
	else if (option == 2)
		free(s2);
	else if (option == 3)
	{
		free(s1);
		free(s2);
	}
	return (s);
}

int			ft_manage_line(char *buf, char **line, char **s_static)
{
	int		i;

	if ((i = ft_strclen(buf, '\n')) > -1)
	{
		if (!(*line = ft_strjoinfree(*s_static, ft_strsub(buf, 0, i), 3)))
			return (-1);
		if (!(*s_static = ft_strdup(buf + i + 1)))
			return (-1);
		return (1);
	}
	if (!(*s_static = ft_strjoinfree(*s_static, buf, 1)))
		return (-1);
	return (0);
}

int			ft_read(char **s_static, int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		retm;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		retm = ft_manage_line(buf, line, s_static);
		if (retm)
			return (retm);
	}
	if (ret == 0 && *s_static[0])
	{
		*line = *s_static;
		*s_static = NULL;
		return (1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s_static[4864];
	int			i;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || fd >= 4864 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (s_static[fd] == NULL)
		s_static[fd] = ft_strnew(1);
	if ((s_static[fd]) && ((i = ft_strclen(s_static[fd], '\n')) > -1))
	{
		tmp = s_static[fd];
		if (!(*line = ft_strsub(s_static[fd], 0, i)))
			return (-1);
		if (!(s_static[fd] = ft_strdup(&s_static[fd][i + 1])))
			return (-1);
		free(tmp);
		return (1);
	}
	return (ft_read(&s_static[fd], fd, line));
}
