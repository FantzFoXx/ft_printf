/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 18:19:25 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/12 11:54:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		print_char_string(char	*string)
{
	ft_putstr(string);
	return (ft_strlen(string));
}

size_t		print_char(char c)
{
	ft_putchar(c);
	return (1);
}

static void	print_sub_str(const char *str, int begin, size_t len)
{
	write(1, &str[begin], len);
}

size_t		cross_buffer(const char *buf, int	*i)
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
	return (len);
}
