/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:16:13 by fgarault          #+#    #+#             */
/*   Updated: 2020/03/03 17:08:34 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_prefix(t_data *d, int len_t, int len_arg)
{
	int		len;

	if ((d->conv == 'd' || d->conv == 'f') && (d->neg || d->flag[most]))
		d->neg ? ft_strcpy(d->prefix, "-") : ft_strcpy(d->prefix, "+");
	if (d->conv == 'o')
		ft_strcpy(d->prefix, "0");
	if (d->conv == 'x' || d->conv == 'X' || d->conv == 'p')
		ft_strcpy(d->prefix, "0x");
	len = ft_strlen(d->prefix);
	if (d->flag[less] || d->flag[zero])
	{
		ft_strncpy(d->argument, d->prefix, len);
		d->ad_pf = len;
	}
	else if (d->precis >= len_arg)
	{
		ft_strncpy(&d->argument[(len_t) - (d->precis + len)], d->prefix, len);
		d->ad_pf = ((len_t - 1) - d->precis) + len;
	}
	else
	{
		ft_strncpy(&d->argument[(len_t) - (len_arg + len)], d->prefix, len);
		d->ad_pf = (len_t - 1) - (len_arg + len);
	}
}

static int		get_arg_size(t_data *d, void *arg)
{
	int		a_len;
	int		p_len;
	int		t_len;

	p_len = 0;
	t_len = 0;
	d->flag[point] && !d->precis && !ft_strcmp(arg, "0") ? (a_len = 0) :
		(a_len = ft_strlen(arg));
	if (((d->conv == 'x' || d->conv == 'X' || d->conv == 'o') && d->flag[diese])
		|| ((d->conv == 'd' || d->conv == 'f')
			&& (d->flag[space] || d->flag[most] || d->neg)))
	{
		if ((d->conv == 'X' || d->conv == 'x') && ft_strcmp(arg, "0"))
			p_len = 2;
		else if (d->conv == 'd' || d->conv == 'f' || d->conv == 'o')
			p_len = 1;
		(ft_strcmp(arg, "0") || d->flag[most] || d->flag[space]) ? d->prfx = 1 :
			0;
	}
	else if (d->conv == 'p')
		p_len = 2;
	d->precis >= a_len ? t_len = d->precis + p_len :
		(t_len = p_len + a_len);
	d->field > t_len ? t_len = d->field : 0;
	return (t_len);
}

static void		get_precis(t_data *d, int len_t)
{
	int		width_precis;
	int		len_prfx;

	len_prfx = ft_strlen(d->prefix);
	if (!d->flag[less] && d->precis)
		d->ad_pf = len_t - d->precis;
	if (d->flag[zero])
		width_precis = len_t - len_prfx;
	else
		width_precis = d->precis;
	ft_memset(&d->argument[d->ad_pf], '0', width_precis);
	d->ad_pf += width_precis;
}

static void		get_arg(t_data *d, char *arg, int len)
{
	int		len_p;
	int		len_arg;
	int		place;

	len_p = ft_strlen(d->prefix);
	len_arg = ft_strlen(arg);
	place = 0;
	if (d->flag[less] && d->width_max >= len)
	{
		if (!d->prfx)
			d->precis > len_arg ? (place = d->precis - len_arg) :
			(place = 0);
		else if (d->prfx)
			d->precis > len_arg ? (place = (d->precis + len_p) - len_arg) :
			(place = len_p);
		ft_strncpy(&d->argument[place], arg, len_arg);
	}
	else if (d->precis > (len_arg + len_p) && d->precis > d->field)
		ft_strncpy(&d->argument[d->ad_pf - len_arg], arg, len_arg);
	else
		ft_strncpy(&d->argument[(len) - len_arg], arg, len_arg);
}

void			handler(t_data *d, void *arg)
{
	int		len;
	int		len_brut;

	len = get_arg_size(d, arg);
	len_brut = ft_strlen(arg);
	if (!ft_strcmp(arg, "0") && !d->precis && d->flag[point] && (!d->flag[diese]
		|| d->conv != 'o'))
		len_brut = 0;
	if ((d->flag[zero] && d->flag[less]) || d->flag[point])
		d->flag[zero] = 0;
	ft_memset(d->argument, ' ', len);
	if (d->prfx || d->conv == 'p' || d->neg)
		get_prefix(d, len, len_brut);
	if (d->flag[space] && !d->neg)
	{
		d->prfx = 1;
		d->prefix[0] = ' ';
		d->ad_pf = 1;
		d->field = d->precis + 1;
	}
	if (d->precis > len_brut || d->flag[zero])
		get_precis(d, len);
	if (len_brut)
		get_arg(d, arg, len);
	d->argument[len] = '\0';
}
