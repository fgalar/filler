/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:15:50 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/20 18:57:44 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_g;

	len_s1 = ft_strlen(s1);
	ft_strcpy(&s1[len_s1], s2);
	len_g = ft_strlen(s1);
	s1[len_g] = '\0';
	return (s1);
}
