/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:57:46 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/27 18:35:32 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int		res;

	res = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
