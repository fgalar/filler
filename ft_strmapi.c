/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:48:50 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/14 19:50:59 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	char			stocker;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) * ft_strlen(s))) == NULL)
		return (NULL);
	ft_strcpy(str, s);
	while (str[i])
	{
		stocker = str[i];
		str[i] = f(i, stocker);
		i++;
	}
	return (str);
}
