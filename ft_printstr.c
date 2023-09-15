/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:16 by imontero          #+#    #+#             */
/*   Updated: 2023/08/14 19:23:11 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *s, t_flag *f)
{
	if (f->ncm > 0)
	{
		if ((!s && f->dot == 0) || (!s && f->dot == 1 && f->dotnbr >= 6))
			f->count += ft_print_n_chars(' ', f->ncmnbr - 6);
		else if (!s && f->dot == 1)
			f->count += ft_print_n_chars(' ', f->ncmnbr - f->dotnbr);
		else
			f->count += ft_print_n_chars(' ', ft_ncm_size_str(ft_strlen(s), f));
	}
	f->count += ft_print_str_precision(s, f);
	return (f->count);
}

int	ft_print_str_precision(char *s, t_flag *f)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (s == NULL)
	{
		return (ft_printstr_null(f));
	}
	while (s[i])
	{
		if (f->dot > 0 && i < f->dotnbr)
			len += write(1, &s[i], 1);
		else if (f->dot == 0)
			len += write(1, &s[i], 1);
		i++;
	}
	return (len);
}

int	ft_printstr_null(t_flag *f)
{
	int		i;
	int		len;
	char	*n;

	len = 0;
	n = ("(null)");
	i = 0;
	if (f->dot == 1)
	{	
		while (i < f->dotnbr && n[i])
		{
			len += write(1, &n[i], 1);
			i++;
		}
	}
	else
		len += write(1, "(null)", 6);
	return (len);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_ncm_size_str(int len, t_flag *f)
{
	if (f->dot == 1 && f->ncm > 0)
	{
		if (f->dotnbr > len)
			return (f->ncmnbr - len);
		else
			return (f->ncmnbr - f->dotnbr);
	}
	else
		return (f->ncmnbr - len);
}
