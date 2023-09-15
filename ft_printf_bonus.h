/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:47:36 by imontero          #+#    #+#             */
/*   Updated: 2023/06/06 14:47:36 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_f
{
	int		invalid;
	int		hast;
	int		spa;
	int		dot;
	int		zero;
	int		plus;
	int		minus;
	int		ncm;
	int		ncmnbr;
	int		dotnbr;
	int		idx;
	int		len_putnbr;
	int		neg_w_zero;
	int		neg_w_dotncm;
	int		count;
}			t_flag;

/* AUX */
char	*ft_strchr(const char *s, int c);
int		ft_printnbr(int n, t_flag *f);
int		ft_printnbru(unsigned int n, t_flag *f);
int		ft_printstr(char *s);
int		ft_printchar(char c);
int		ft_printhex(unsigned int nbr, char format);
int		ft_printpointer(void *addr);
int		ft_printhexptr(unsigned long long int nbr);
int		ft_strlen(char *str);
void	*ft_memset(void *ptr, int c, size_t n);
int		ft_isdigit(int c);
int		ft_formatspec(char format, va_list args);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);

/* BONUS */

//int		ft_printf(const char *s, ...);
int		ft_printf(const char *s, ...);
int		ft_formatspec_bonus(char format, t_flag *f, va_list args);
char	*ft_checkerror(char *str);
char	checkflags(char *s, t_flag *f);
void	reinit_flags(t_flag *f);
void	ft_atoi_ncm(char *s, t_flag *f);
void	ft_atoi_dot(char s, t_flag *f);
int		ft_hex(unsigned int nbr, char format, t_flag *f);
int		ft_hex_left(unsigned int nbr, char format, t_flag *f);
int		ft_str(char *s, t_flag *f);
int		ft_str_left(char *s, t_flag *f);
int		ft_ptr(void *addr, t_flag *f);
int		ft_ptr_left(void *addr, t_flag *f);
int		ft_char(char c, t_flag *f);
int		ft_u(unsigned int n, t_flag *f);
int		ft_u_left(unsigned int n, t_flag *f);
int		ft_nbr(int n, t_flag *f);
int		ft_nbr_left(int n, t_flag *f);
int		nbr_len(int n, t_flag *f);
int		ptr_len(unsigned long long int n);
int		unsigned_len(long num, t_flag *f);
int		hex_len(unsigned int n);
int		ft_print_n_chars(char c, int n);
int		ft_hex_prefix(char format);
int		ft_print_str_precision(char *s, t_flag *f);
int		ft_formatspec_left(char format, t_flag *f, va_list args);
int		ft_char_left(char c, t_flag *f);
int		ft_ncm_size_str(int len, t_flag *f);
int		ft_ncm_size_nbr(int len, t_flag *f);
int		ft_printstr_null(t_flag *f);
void	ft_u_put_spaces(unsigned int n, t_flag *f);
void	ft_u_left_put_spaces(unsigned int n, t_flag *f);
void	ft_nbr_spaces(int n, t_flag *f);
void	ft_nbr_signs(int *n, t_flag *f);
void	ft_nbr_left_spaces(int n, t_flag *f);
int		ft_nbr_left_sign_zero(int n, t_flag *f);

#endif
