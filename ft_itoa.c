/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:33:52 by imontero          #+#    #+#             */
/*   Updated: 2023/04/25 13:12:58 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Reserva memoria (con malloc(3)) y devuelve la cadena de caracteres
	que representa el número pasado como argumento. Se debe manejar
	la conversión de números negativos.
*/

static	int	ft_nlen(int n)
{
	int	nlen;

	nlen = 1;
	if (n < 0)
		nlen++;
	while (n / 10 != 0)
	{
		n /= 10;
		nlen++;
	}
	return (nlen);
}

static	char	*ft_newstr(char *str, long num, int nlen)
{
	int	i;

	i = 1;
	while (num / 10 != 0)
	{
		str[nlen - i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[nlen - i] = (num % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	int		i;
	long	num;

	i = 0;
	nlen = ft_nlen(n);
	str = malloc((nlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	num = n;
	if (num < 0)
	{
		str[i] = '-';
		num = num * -1;
		i++;
	}
	str[(nlen)] = '\0';
	ft_newstr(str, num, nlen);
	return (str);
}
