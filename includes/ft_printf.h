/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:24:33 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/11 08:37:07 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

typedef struct	s_vars
{
	char	*str;
	int		integer;
	float	flt;
	double	dbl;
	short	shrt;
	void	*ptr;
}				t_vars;

int		ft_printf(const char * restrict format, ...);
void	cross_buffer(const char *buf, int	*i);
void	print_sub_str(const char *str, int begin, size_t len);
void	print_char_string(char	*string);
int		parse_percent(char *buf, int *flag, int *i);
void	print_integer(int value);
void	print_char(char c);
void	clear_vars_struct(t_vars *global);
void	print_octal_value(int value);
void	print_pointer_value(void *ptr);

#endif
