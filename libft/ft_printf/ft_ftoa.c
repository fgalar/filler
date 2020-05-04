/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanny <fgarault@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:54:18 by fanny             #+#    #+#             */
/*   Updated: 2020/04/27 17:45:24 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_floatlen(long double f, int precision, t_data *d)
{
	long long		len;

	precision ? len = precision + 1 :
	(len = 0);
	if (f < 0)
		f *= -1.0;
	if (f <= 1.0)
		return (len + 1);
	while (f >= 1.0 && len < 4096)
	{
		len++;
		f /= 10;
	}
	f >= 0.99 ? d->prfx = 1 : 0;
	return (len + d->prfx);
}

static void			ft_round(char *tab, long double f, int len, t_data *d)
{
	int		i;
	int		ret;

	i = ft_strlen(tab) - 1;
	ret = 1;
	(f >= 5 && f < 6) ? (f -= (int)f) && (f *= 10) : 0;
	while (i + 1 > -len + d->prfx)
	{
		if (f < 1.0 && d->precis > 1)
			!is_even(tab[i]) ? (tab[i]++ && (ret = 0)) : 0;
		else if (ft_isdigit(tab[i]) && (tab[i] += 1))
			ret = 0;
		if (!ft_isdigit(tab[i]))
		{
			if (tab[i] == '.')
				ret ? (tab[i - 1] += 1) && (i -= 2) : 0;
			else
				tab[i] == ' ' ? (tab[i] = '1') :
				(tab[i] = '0');
			i--;
		}
		else
			return ;
	}
}

static void			memset_integer_part(char *tab, long double *f,
int len, t_data *d)
{
	int		i;

	i = 0;
	if (*f < 0)
	{
		*f *= -1.0;
		d->flag[most] = 0;
		d->flag[space] = 0;
	}
	while (*f >= 10.0)
		*f /= 10;
	while (len - d->prfx > i)
	{
		tab[i] = (int)*f + '0';
		*f -= (int)*f;
		*f *= 10;
		i++;
	}
}

static void			memset_decimal_part(char *tab, long double f, int len,
t_data *d)
{
	int		i;

	i = 0;
	while (i < d->precis)
	{
		tab[i] = (int)f + '0';
		f -= (int)f;
		f *= 10;
		i++;
	}
	if ((int)f >= 5)
		ft_round(tab, f, len, d);
}

char				*ft_float(t_data *d, long double f)
{
	long long	len;
	char		*tab;

	precis_float(d);
	len = ft_floatlen(f, d->precis, d);
	if (!(tab = ft_strnew(len + 1)))
		return (NULL);
	ft_memset(tab, ' ', len);
	memset_integer_part(&tab[d->prfx], &f, len - (d->precis + 1), d);
	if (d->precis == -1 && d->flag[point])
	{
		if ((int)f >= 5)
			ft_round(tab, f, len, d);
		if (d->flag[diese])
			ft_strcat(tab, ".");
		d->prfx = 0;
		free(tab);
		return (tab);
	}
	tab[(len - 1) - d->precis] = '.';
	memset_decimal_part(&tab[len - d->precis], f, len, d);
	free(tab);
	tab[0] == ' ' ? ++tab : 0;
	d->prfx = 0;
	return (tab);
}
