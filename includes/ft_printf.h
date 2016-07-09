/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:24:33 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/09 21:33:02 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

int		ft_printf(const char * restrict format, ...);
void	cross_buffer(const char *buf, int	*i);
void	print_sub_str(const char *str, int begin, size_t len);
void	print_char_string(char	*string);
int		parse_percent(char *buf, int *flag, int *i);

#endif
