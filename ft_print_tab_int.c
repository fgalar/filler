/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:20:54 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/26 22:36:31 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max);

void	ft_print_tab_int(const int *tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putnbr(tab[i]);
		ft_putchar('\t');
		i++;
	}
}
int main()
{
	ft_print_tab_int(ft_range(5, 15));
	return (0);
}	
