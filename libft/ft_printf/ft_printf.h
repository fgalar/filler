/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:33:06 by fgarault          #+#    #+#             */
/*   Updated: 2020/05/01 18:56:43 by fanny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"
# define NB_CONV 10
# define NB_FLAGS 11

typedef enum			e_flags
{
	hh,
	h,
	ll,
	l,
	diese,
	most,
	space,
	less,
	zero,
	percent,
	point,
}						t_flags;

typedef struct			s_data
{
	va_list				arg;
	char				buffer[4096];
	char				argument[4096];
	char				prefix[3];
	char				conv;
	int					flag[NB_FLAGS];
	long				index;
	int					len;
	long				precis;
	long				field;
	long				width_max;
	long				size;
	int					neg;
	int					prfx;
	int					ad_pf;
}						t_data;

typedef union			u_float
{
	long double			fl;
	struct
	{
		unsigned long	mantisse : 64;
		unsigned int	exp : 15;
		unsigned int	sign : 1;
	}					b_count;
}						t_float;

void					pf_parsing(t_data *data, const char *format);
void					get_size(t_data *data, const char *format);
int						dispatcher(t_data *data, const char*format);
int						print_c(t_data *data);
int						print_s(t_data *data);
int						print_p(t_data *data);
int						print_d(t_data *data);
int						print_o(t_data *data);
int						print_u(t_data *data);
int						print_x(t_data *data);
int						print_f(t_data *data);
char					*ft_float(t_data *d, long double f);
void					handler(t_data *data, void *arg);
void					print_majhex(char *nb);
void					print_a(t_data *d, unsigned char c);
void					init_new_arg(t_data *d);
void					init_struct(t_data *d);
int						is_even(char n);
void					precis_float(t_data *d);
int						buff_purge(t_data *d);
int						print_buff(char *s, t_data *d);
void					write_while(char a, int len);
#endif
