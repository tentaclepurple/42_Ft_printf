/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:14:24 by imontero          #+#    #+#             */
/*   Updated: 2023/08/25 10:12:16 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_formatspec_bonus(char format, t_flag *f, va_list args)
{
	if (f->minus == 1)
		return (ft_formatspec_left(format, f, args));
	if (format == '%')
		return (ft_char('%', f));
	else if (format == 'i' || format == 'd')
		return (ft_nbr(va_arg(args, int), f));
	else if (format == 'c')
		return (ft_char(va_arg(args, int), f));
	else if (format == 's')
		return (ft_str(va_arg(args, char *), f));
	else if (format == 'u')
		return (ft_u(va_arg(args, unsigned int), f));
	else if (format == 'x' || format == 'X')
		return (ft_hex(va_arg(args, unsigned long int), format, f));
	else if (format == 'p')
		return (ft_ptr(va_arg(args, char *), f));
	else
		return (0);
}

int	ft_formatspec_left(char format, t_flag *f, va_list args)
{
	if (format == '%')
		return (ft_char_left('%', f));
	else if (format == 'i' || format == 'd')
		return (ft_nbr_left(va_arg(args, int), f));
	else if (format == 'c')
		return (ft_char_left(va_arg(args, int), f));
	else if (format == 's')
		return (ft_str_left(va_arg(args, char *), f));
	else if (format == 'u')
		return (ft_u_left(va_arg(args, unsigned int), f));
	else if (format == 'x' || format == 'X')
		return (ft_hex_left(va_arg(args, unsigned long int), format, f));
	else if (format == 'p')
		return (ft_ptr_left(va_arg(args, void *), f));
	else
		return (0);
}

char	checkflags(char *s, t_flag *f)
{
	f->idx += 1;
	while (ft_strchr("cspdiuxX%", s[f->idx]) == NULL && s[f->idx])
	{
		if (s[f->idx] == '#')
			f->hast = 2;
		if (s[f->idx] == ' ')
			f->spa++;
		if (s[f->idx] == '+')
			f->plus++;
		if (s[f->idx] == '-')
			f->minus++;
		if ((s[f->idx] == '0' && f->ncm == 0)
			|| (s[f->idx] == '0' && f->dot == 1))
			f->zero++;
		if (s[f->idx] == '.')
			f->dot++;
		if (((s[f->idx] > '0' && s[f->idx] <= '9')
				&& f->ncm == 0 && f->dot != 1))
			ft_atoi_ncm(s, f);
		if (((s[f->idx] >= '0' && s[f->idx] <= '9') && f->dot == 1))
			ft_atoi_dot(s[f->idx], f);
		f->idx++;
	}
	return (s[f->idx]);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flag	f;

	va_start(args, s);
	ft_memset(&f, 0, sizeof(struct s_f));
	while (s[f.idx])
	{
		if (s[f.idx] == '%')
		{
			ft_formatspec_bonus(checkflags((char *)s, &f), &f, args);
			reinit_flags(&f);
		}		
		else
			f.count += write(1, &s[f.idx], 1);
		f.idx++;
	}
	return (f.count);
	va_end(args);
}
