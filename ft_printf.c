/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:55:52 by imontero          #+#    #+#             */
/*   Updated: 2023/07/21 19:12:01 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatspec_bonus(char format, t_flag *f, va_list args)
{
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

char	checkflags(char *s, t_flag *f)
{
	f->idx += 1;
	while (ft_strchr("cspdiuxX%", s[f->idx]) == NULL && s[f->idx])
	{
		if (s[f->idx] == '#')
			f->hast++;
		if (s[f->idx] == ' ')
			f->spa++;
		if (s[f->idx] == '+')
			f->plus++;
		if (s[f->idx] == '-')
			f->minus++;
		if (s[f->idx] == '0' && f->ncm == 0)
			f->zero++;
		if (s[f->idx] == '.')
			f->dot++;
		if (((s[f->idx] > '0' && s[f->idx] <= '9') && f->ncm == 0))
			atoi_ncm(s, f);
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

/*int main()
{
	int a;
	int b;
	//char *s;

	//s = NULL;
	a = printf("[%-23.10d]", -10);
	printf("\n%i\n", a);
	b = ft_printf("[%-23.10d]", -10);
	printf("\n%i\n", b);
	return(0);
}*/