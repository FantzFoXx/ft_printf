/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:24:33 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/15 17:49:25 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

# define FLAG_SIGN	1
# define FLAG_SPACE	2
# define FLAG_RIGHT	4
# define FLAG_OBV	8
# define FLAG_ZERO	16

# define HAS_FLAG_SIGN(x)	((x >> 0) & 1)
# define HAS_FLAG_SPACE(x)	((x >> 1) & 1)
# define HAS_FLAG_RIGHT(x)	((x >> 2) & 1)
# define HAS_FLAG_OBV(x)	((x >> 3) & 1)
# define HAS_FLAG_ZERO(x)	((x >> 4) & 1)

typedef struct	s_vars
{
	uintmax_t		container;
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
	int				flags;
	int				size_specifier;
	int				precision;
}				t_vars;

int		ft_printf(const char * restrict format, ...);
size_t	cross_buffer(const char *buf);
size_t	print_char_string(char	*string, t_vars *vars);
int		parse_percent(char **buf, t_vars *vars);
size_t		print_percent(char	*string, t_vars *vars);
//size_t	print_integer(int value);
size_t	print_integer(int value, t_vars *vars);
size_t	print_uinteger(unsigned int value, t_vars *vars);
size_t	print_char(char c, t_vars *vars);
void	clear_vars_struct(t_vars *global);
size_t	print_octal_value(int value, t_vars *vars);
size_t	print_hex_value(int value, int case_ascii, t_vars *vars);
size_t	print_pointer_value(void *ptr, t_vars *vars);
size_t	increment_write_len(t_vars *vars, char *print, int decimal_value);
size_t	print_padding(int len);
int		print_str_padded(char *str, t_vars *vars);



void	dump_vars_struct(t_vars *global);

#endif
