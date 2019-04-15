/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:04:12 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/14 18:59:18 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	stocker;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) * ft_strlen(s))) == NULL)
		return (NULL);
	ft_strcpy(str, s);
	while (str[i])
	{
		stocker = s[i];
		str[i] = f(stocker);
		i++;
	}
	return (str);
}
