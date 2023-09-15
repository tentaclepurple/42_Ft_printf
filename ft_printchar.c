/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:31:30 by imontero          #+#    #+#             */
/*   Updated: 2023/06/05 13:31:54 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, t_flag *f)
{
	if (f->ncm > 0 && f->zero == 1)
		f->count += ft_print_n_chars('0', f->ncmnbr - 1);
	else if (f->ncm > 0 || f->dot == 1)
		f->count += ft_print_n_chars(' ', f->ncmnbr - 1);
	f->count += ft_printchar(c);
	return (f->count);
}

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_char_left(char c, t_flag *f)
{
	if (f->minus == 1)
		f->count += ft_printchar(c);
	if (f->ncm > 0 || f->dot == 1)
		f->count += ft_print_n_chars(' ', f->ncmnbr - 1);
	return (f->count);
}
