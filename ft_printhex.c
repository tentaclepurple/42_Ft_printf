/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:56:40 by imontero          #+#    #+#             */
/*   Updated: 2023/06/09 10:21:52 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int nbr, char format, t_flag *f)
{
	if (f->zero == 1 && f->ncm > 0 && f->dot > 0)
		f->zero = 0;
	if (f->dot == 0 && f->zero == 0 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - hex_len(nbr));
	if (f->ncm > 0 && f->zero == 0 && f->dot == 1)
	{
		if (f->dotnbr > hex_len(nbr))
			f->count += ft_print_n_chars(' ', f->ncmnbr - f->dotnbr - f->hast);
		else if (nbr == 0 && f->dotnbr == 0 && f->dot == 1)
			f->count += ft_print_n_chars(' ', f->ncmnbr);
		else
			f->count += ft_print_n_chars(' ', f->ncmnbr - hex_len(nbr) - \
				f->hast);
	}
	if (f->hast == 2 && nbr != 0)
		f->count += ft_hex_prefix(format);
	if (f->dot == 1 || f->zero == 0)
		f->count += ft_print_n_chars('0', f->dotnbr - hex_len(nbr));
	if (f->zero == 1 && f->dot == 0)
		f->count += ft_print_n_chars('0', f->ncmnbr - hex_len(nbr));
	if (nbr == 0 && f->dot == 1 && f->dotnbr == 0)
		return (f->count);
	f->count += ft_printhex(nbr, format);
	return (f->count);
}

int	ft_hex_prefix(char format)
{
	int	len;

	len = 0;
	if (format == 'x')
		len += write (1, "0x", 2);
	else if (format == 'X')
		len += write (1, "0X", 2);
	return (len);
}

int	hex_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_printhex(unsigned int nbr, char format)
{
	char	*base;
	int		len;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		len += ft_printhex(nbr / 16, format);
		len += ft_printhex(nbr % 16, format);
	}
	else
		len += write(1, &base[nbr], 1);
	return (len);
}

int	ft_hex_left(unsigned int nbr, char format, t_flag *f)
{
	f->zero = 0;
	if (f->hast == 2 && nbr != 0)
		f->count += ft_hex_prefix(format);
	if (f->dot == 1 || f->zero == 0)
		f->count += ft_print_n_chars('0', f->dotnbr - hex_len(nbr));
	if (f->zero == 1 && f->dot == 0)
		f->count += ft_print_n_chars('0', f->ncmnbr - hex_len(nbr));
	if ((nbr != 0) || (nbr == 0 && f->dot == 1 && f->dotnbr != 0)
		|| (nbr == 0 && f->dot == 0))
		f->count += ft_printhex(nbr, format);
	if (f->dot == 0 && f->zero == 0 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - hex_len(nbr));
	if (f->ncm > 0 && f->zero == 0 && f->dot == 1)
	{
		if (f->dotnbr > hex_len(nbr))
			f->count += ft_print_n_chars(' ', f->ncmnbr - f->dotnbr - f->hast);
		else if (nbr == 0 && f->dotnbr == 0 && f->dot == 1)
			f->count += ft_print_n_chars(' ', f->ncmnbr);
		else
			f->count += ft_print_n_chars(' ', f->ncmnbr - \
				hex_len(nbr) - f->hast);
	}
	return (f->count);
}
