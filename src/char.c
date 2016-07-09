/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 18:19:25 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/09 21:33:01 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_string(char	*string)
{
	ft_putstr(string);
}

void	print_sub_str(const char *str, int begin, size_t len)
{
	write(1, &str[begin], len);
}

void	cross_buffer(const char *buf, int	*i)
{
	int		begin;
	size_t	len;

	begin = *i;
	len = 0;
	while (buf[*i] && buf[*i] != '%')
	{
		len++;
		(*i)++;
	}
	print_sub_str(buf, begin, len);
}
