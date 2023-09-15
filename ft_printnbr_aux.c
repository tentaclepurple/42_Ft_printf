/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:12:06 by imontero          #+#    #+#             */
/*   Updated: 2023/08/24 20:05:46 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbr_signs(int *n, t_flag *f)
{
	if (*n < 0 && ((f->dot == 1 && f->plus != 1)
			|| (f->zero == 1 && f->plus != 1)))
	{
		if (f->dot == 1 && f->ncm > 0)
		{
			f->neg_w_dotncm = 1;
			*n = -*n;
		}
		else
		{
			f->count += write(1, "-", 1);
			*n = -*n;
			if (f->zero == 1)
				f->neg_w_zero = 1;
		}
	}
}

void	ft_nbr_spaces(int n, t_flag *f)
{
	if (f->dot == 0 && f->zero == 0 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - nbr_len(n, f));
	if (f->ncm > 0 && f->dot == 1)
	{
		if (f->dotnbr > nbr_len(n, f))
			f->count += ft_print_n_chars(' ', f->ncmnbr - \
				f->dotnbr - f->neg_w_dotncm);
		else
			f->count += ft_print_n_chars(' ', f->ncmnbr - \
				nbr_len(n, f) - f->neg_w_dotncm);
	}
}

void	ft_nbr_left_spaces(int n, t_flag *f)
{
	if ((f->plus == 0 && f->spa == 0) || n < 0)
		f->count += ft_printnbr(n, f);
	else if (f->plus == 1 && n >= 0)
		f->count += ft_printnbr(n, f);
	else if (f->spa > 0 && n >= 0)
	{
		if (f->ncm == 0)
			f->count += write(1, " ", 1);
		f->count += ft_printnbr(n, f);
	}
	if (f->dot == 0 && f->zero == 0 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - nbr_len(n, f));
	if (f->ncm > 0 && f->dot == 1)
	{
		if (f->dotnbr > nbr_len(n, f))
			f->count += ft_print_n_chars(' ', f->ncmnbr - \
				f->dotnbr - f->neg_w_dotncm);
		else
			f->count += ft_print_n_chars(' ', f->ncmnbr - \
				nbr_len(n, f) - f->neg_w_dotncm);
	}
}

int	ft_nbr_left_sign_zero(int n, t_flag *f)
{
	if (f->plus == 1 && n >= 0)
		f->count += write(1, "+", 1);
	if (f->dot == 1 || f->zero == 0)
	{
		if (f->neg_w_dotncm == 1)
			f->count += write(1, "-", 1);
		f->count += ft_print_n_chars('0', f->dotnbr - nbr_len(n, f));
	}
	if (f->zero == 1 && f->dot == 0)
		f->count += ft_print_n_chars('0', f->ncmnbr - nbr_len(n, f));
	if (n == 0 && f->dot == 1 && f->dotnbr == 0)
		return (f->count);
	return (f->count);
}
