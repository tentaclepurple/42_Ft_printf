/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:12:06 by imontero          #+#    #+#             */
/*   Updated: 2023/08/24 20:01:47 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr(int n, t_flag *f)
{
	ft_nbr_signs(&n, f);
	ft_nbr_spaces(n, f);
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
	return (f->count);
}

int	nbr_len(int n, t_flag *f)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	free(str);
	if (n < 0 && f->dot == 1)
		len--;
	if (f->plus > 0 || f->neg_w_zero == 1)
		len++;
	if (n == 0 && f->dotnbr == 0 && f->dot == 1)
		len--;
	return (len);
}

int	ft_printnbr(int n, t_flag *f)
{
	int	i;

	i = 0;
	if (n == -2147483648 && f->dot == 0 && f->zero == 0)
		i += write(1, "-2147483648", 11);
	else if (n == -2147483648)
		i += write(1, "2147483648", 10);
	else if (n < 0)
	{
		i += write(1, "-", 1);
		i += ft_printnbr(-n, f);
	}
	else if (n >= 10)
	{
		i += ft_printnbr(n / 10, f);
		i += ft_printnbr(n % 10, f);
	}
	else
		i += ft_printchar(n + 48);
	return (i);
}

int	ft_nbr_left(int n, t_flag *f)
{
	if (n < 0 && ((f->dot == 1 && f->plus != 1)
			|| (f->zero == 1 && f->plus != 1)))
	{
		if (f->dot == 1 && f->ncm > 0)
		{
			f->neg_w_dotncm = 1;
			n = -n;
		}
		else
		{
			f->count += write(1, "-", 1);
			n = -n;
			if (f->zero == 1)
			f->neg_w_zero = 1;
		}
	}
	ft_nbr_left_sign_zero(n, f);
	ft_nbr_left_spaces(n, f);
	return (f->count);
}
