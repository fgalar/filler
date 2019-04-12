/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:34:47 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/12 12:10:20 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s_cpy;

	if (s1 == NULL)
		return (NULL);
	s_cpy = (char *)malloc(sizeof(char) * ft_strlen(s1));
	ft_strcpy(s_cpy, s1);
	return (s_cpy);
}
