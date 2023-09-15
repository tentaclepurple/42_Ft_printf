/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbru_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:29:12 by imontero          #+#    #+#             */
/*   Updated: 2023/08/24 19:33:48 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_put_spaces(unsigned int n, t_flag *f)
{
	if (f->zero == 1 && f->ncm > 0 && f->dotnbr > 0 && f->ncmnbr > 0)
		f->zero = 0;
	if (f->dot == 0 && f->zero == 0 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - unsigned_len(n, f));
	if (f->ncm > 0 && f->zero == 0 && f->dot == 1)
	{
		if (f->dotnbr > unsigned_len(n, f))
			f->count += ft_print_n_chars(' ', f->ncmnbr - f->dotnbr);
		else
			f->count += ft_print_n_chars(' ', f->ncmnbr - unsigned_len(n, f));
	}
	if (f->dot == 1 && f->dotnbr == 0 && f->zero == 1 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - unsigned_len(n, f));
}

void	ft_u_left_put_spaces(unsigned int n, t_flag *f)
{
	if (f->dot == 0 && f->zero == 0 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - unsigned_len(n, f));
	if (f->ncm > 0 && f->zero == 0 && f->dot == 1)
	{
		if (f->dotnbr > unsigned_len(n, f))
			f->count += ft_print_n_chars(' ', f->ncmnbr - f->dotnbr);
		else
			f->count += ft_print_n_chars(' ', f->ncmnbr - unsigned_len(n, f));
	}
	if (f->dot == 1 && f->zero == 1 && f->ncm > 0)
		f->count += ft_print_n_chars(' ', f->ncmnbr - unsigned_len(n, f));
}
