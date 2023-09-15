/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:37:05 by imontero          #+#    #+#             */
/*   Updated: 2023/08/14 19:25:09 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ncm_size_nbr(int len, t_flag *f)
{
	if (f->dotnbr > len)
		return (f->ncmnbr - len);
	else
		return (f->ncmnbr - f->dotnbr);
}
