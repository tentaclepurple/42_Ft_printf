/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:10:48 by imontero          #+#    #+#             */
/*   Updated: 2023/08/14 19:24:52 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_n_chars(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

void	reinit_flags(t_flag *f)
{
	f->invalid = 0;
	f->hast = 0;
	f->spa = 0;
	f->dot = 0;
	f->zero = 0;
	f->plus = 0;
	f->minus = 0;
	f->ncm = 0;
	f->ncmnbr = 0;
	f->len_putnbr = 0;
	f->dotnbr = 0;
	f->neg_w_zero = 0;
	f->neg_w_dotncm = 0;
}

void	ft_atoi_ncm(char *s, t_flag *f)
{
	int	i;

	i = f->idx;
	while ((s[i] >= '0' && s[i] <= '9') && s[i])
	{
		f->ncmnbr = (f->ncmnbr * 10) + (s[i] - '0');
		f->ncm++;
		i++;
	}	
}

void	ft_atoi_dot(char s, t_flag *f)
{
	f->dotnbr = (f->dotnbr * 10) + (s - '0');
	f->dot = 1;
}
