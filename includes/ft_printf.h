/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:24:33 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/05 16:50:53 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

typedef struct	s_vars
{
	char			*str;
	int				integer;
	unsigned int	uint;
	float			flt;
	double			dbl;
	short			shrt;
	void			*ptr;
	size_t			write_len;
	wchar_t			wch;
	wchar_t			*wchs;
	int				padding;
	int				len_padded_var;
	int				flag;
}				t_vars;

int		ft_printf(const char * restrict format, ...);
size_t	cross_buffer(const char *buf, int	*i);
//void	print_sub_str(const char *str, int begin, size_t len);
size_t	print_char_string(char	*string);
//size_t	print_wchar_string(wchar_t *string);
//int		parse_percent(char *buf, int *flag, int *i, t_vars *vars);
int		parse_percent(char *buf, int *flag, t_vars *vars);
size_t	print_integer(int value);
size_t	print_uinteger(unsigned int value);
size_t	print_char(char c);
void	clear_vars_struct(t_vars *global);
size_t	print_octal_value(int value);
size_t	print_hex_value(int value, int case_ascii);
size_t	print_pointer_value(void *ptr);
size_t	increment_write_len(t_vars *vars, char *print, int decimal_value);
size_t	print_padding(int len);

#endif
