/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 18:19:25 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/13 11:10:33 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t		print_char_string(char	*string, t_vars *vars)
{
	if (!string)
		string = "(null)";
	print_str_padded(string, vars);
	return (ft_strlen(string));
}

size_t		print_char(char c, t_vars *vars)
{
	char	to_str[2];
	to_str[0] = c;
	to_str[1] = 0;
	print_str_padded(to_str, vars);
	return (1);
}

static void	print_sub_str(const char *str, int begin, size_t len)
{
	write(1, &str[begin], len);
}

size_t		cross_buffer(const char *buf)
{
	size_t	len;
	char	*begin;

	len = 0;
	begin = (char *)buf;
	while (*buf && *buf != '%')
	{
		len++;
		buf++;
	}
	print_sub_str(begin, 0, len);
	return (len);
}

char		*add_padding(char *str, size_t len_padding, t_vars *vars)
{
	char	*tmp;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (HAS_FLAG_ZERO(vars->flags))
		tmp = (char *)ft_memallocset(sizeof(char) * str_len + len_padding, '0');
	else
		tmp = (char *)ft_memallocset(sizeof(char) * str_len + len_padding, ' ');
	tmp[str_len + len_padding] = 0;
	if (HAS_FLAG_RIGHT(vars->flags))
		len_padding = 0;
	else
		tmp += len_padding;
	while (*str)
	{
		*tmp = *str;
		str++;
		tmp++;
	}
	tmp -= (str_len + len_padding);
	return (tmp);
}

void		print_str_padded(char *str, t_vars *vars)
{
	size_t	len_str;
	int		padding;

	len_str = ft_strlen(str);
	padding = vars->padding - len_str;
	if (padding > 0)
	{
		vars->write_len += padding;
		str = add_padding(str, (size_t)padding, vars);
	}
	ft_putstr(str);
}
