/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 06:09:11 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/12 11:54:36 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_integer(int value)
{
	char	*conv;
	size_t	len;

	len = 0;
	conv = ft_itoa(value);
	if (conv)
	{
		ft_putstr(conv);
		len = ft_strlen(conv);
		ft_strdel(&conv);
	}
	return (len);
}

size_t	print_octal_value(int value)
{
	char	*converted;
	size_t	len;

	len = 0;
	converted = ft_uitoa_base(value, "01234567");
	if (converted)
	{
		ft_putstr(converted);
		len = ft_strlen(converted);
		free(converted);
	}
	return (len);
}

size_t	print_pointer_value(void *ptr)
{
	long		decimal_value;
	char	*converted;
	size_t	len;

	len = 0;
	decimal_value = (long)ptr;
	converted = ft_ltoa_base(decimal_value, "0123456789abcdef");
	if (converted)
	{
		ft_putstr("0x");
		ft_putstr(converted);
		len = ft_strlen(converted);
		free(converted);
	}
	return (len);
}
