/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:23:44 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/15 11:38:02 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib>

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * (strlen(s1) + strlen(s2)))) == NULL)
		return (NULL);
	str = ft_strcat(s1, s2);
	return (str);
}
