/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:47:29 by imontero          #+#    #+#             */
/*   Updated: 2023/06/09 10:22:41 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *addr, t_flag *f)
{
	if (f->ncm > 0 && (addr == NULL))
		f->count += ft_print_n_chars(' ', f->ncmnbr - 3);
	else if (f->ncm > 1)
		f->count += ft_print_n_chars(' ', f->ncmnbr - \
			ptr_len((unsigned long long int)addr));
	f->count += ft_printpointer(addr);
	return (f->count);
}

int	ft_printpointer(void *addr)
{
	int	len;

	len = 0;
	if (addr == NULL)
		len += (write(1, "0x0", 3));
	else
	{
		len = ft_printstr("0x");
		len += ft_printhexptr((unsigned long long int)addr);
	}
	return (len);
}

int	ptr_len(unsigned long long int n)
{
	int	len;

	len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		len++;
	}
	len += 2;
	return (len);
}

int	ft_ptr_left(void *addr, t_flag *f)
{
	f->count += ft_printpointer(addr);
	if (f->ncm > 0 && addr == NULL)
		f->count += ft_print_n_chars(' ', f->ncmnbr - 3);
	else if (f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - \
			ptr_len((unsigned long long int)addr));
	return (f->count);
}
