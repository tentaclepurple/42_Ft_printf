/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_left_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:02:03 by imontero          #+#    #+#             */
/*   Updated: 2023/08/14 19:25:43 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_left(char *s, t_flag *f)
{
	f->count += ft_print_str_precision(s, f);
	if (f->ncm > 0)
	{
		if ((!s && f->dot == 0) || (!s && f->dot == 1 && f->dotnbr >= 6))
			f->count += ft_print_n_chars(' ', f->ncmnbr - 6);
		else if (!s && f->dot == 1 && f->dotnbr < 6)
			f->count += ft_print_n_chars(' ', f->ncmnbr - f->dotnbr);
		else
			f->count += ft_print_n_chars(' ', ft_ncm_size_str(ft_strlen(s), f));
	}
	return (f->count);
}
