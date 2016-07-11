/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 06:09:11 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/11 08:37:08 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_integer(int value)
{
	ft_putnbr(value);
}

void	print_octal_value(int value)
{
	char	*converted;

	converted = ft_uitoa_base(value, "01234567");
	ft_putstr(converted);
	free(converted);
}

void	print_pointer_value(void *ptr)
{
	int		decimal_value;
	char	*converted;

	// wrong size converted, 2 bytes missing
	decimal_value = (int)ptr;
	converted = ft_uitoa_base(decimal_value, "0123456789abcdef");
	ft_putstr("0x");
	ft_putstr(converted);
	free(converted);
}
