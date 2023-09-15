/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:29:12 by imontero          #+#    #+#             */
/*   Updated: 2023/06/05 13:29:26 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n, t_flag *f)
{
	ft_u_put_spaces(n, f);
	if (f->dot == 1 || f->zero == 0)
		f->count += ft_print_n_chars('0', f->dotnbr - unsigned_len(n, f));
	if (f->zero == 1 && f->dot == 0)
		f->count += ft_print_n_chars('0', f->ncmnbr - unsigned_len(n, f));
	if (n == 0 && f->dot == 1 && f->dotnbr == 0)
		return (f->count);
	if (f->plus == 0 && f->spa == 0)
		f->count += ft_printnbru(n, f);
	else if (f->spa > 0 && n >= 0)
	{
		if (f->ncm > 0)
			f->count += write(1, " ", 1);
		f->count += ft_printnbru(n, f);
	}
	return (f->count);
}

int	unsigned_len(long num, t_flag *f)
{
	int	len;

	len = 0;
	if (num == 0 && f->dot == 1 && f->dotnbr == 0)
		return (0);
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_printnbru(unsigned int n, t_flag *f)
{
	int	b;
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_printnbr(n / 10, f);
		i += ft_printnbr(n % 10, f);
	}
	else
	{
		b = n + 48;
		i += write(1, &b, 1);
	}
	return (i);
}

int	ft_u_left(unsigned int n, t_flag *f)
{
	if (f->dot == 1 && n != 0)
	{
		f->count += ft_print_n_chars('0', f->dotnbr - unsigned_len(n, f));
	}
	else if (f->dot == 1 && n == 0)
		f->count += ft_print_n_chars('0', f->dotnbr);
	if ((f->plus == 0 && f->spa == 0 && n != 0) || (n == 0 && f->dot == 0))
		f->count += ft_printnbru(n, f);
	else if (f->spa > 0 && n >= 0)
	{
		if (f->ncm > 0)
			f->count += write(1, " ", 1);
		f->count += ft_printnbru(n, f);
	}
	ft_u_left_put_spaces(n, f);
	return (f->count);
}
