/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 06:09:11 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/13 09:51:20 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_integer(int value, t_vars *vars)
{
	char	*conv;
	size_t	len;

	len = 0;
	conv = ft_itoa(value);
	if (HAS_FLAG_SIGN(vars->flags) && value > 0)
		conv = ft_strjoin("+", conv); // leak
	if (conv)
	{
		print_str_padded(conv, vars);
		len = ft_strlen(conv);
		ft_strdel(&conv);
	}
	return (len);
}

size_t	print_uinteger(unsigned int value, t_vars *vars)
{
	char	*conv;
	size_t	len;

	len = 0;
	if (HAS_FLAG_SIGN(vars->flags) && value > 0)
		conv = ft_strjoin("+", conv); // leak
	conv = ft_uitoa(value);
	if (conv)
	{
		print_str_padded(conv, vars);
		len = ft_strlen(conv);
		ft_strdel(&conv);
	}
	return (len);
}

size_t	print_octal_value(int value, t_vars *vars)
{
	char	*converted;
	size_t	len;

	len = 0;
	converted = ft_uitoa_base(value, "01234567");
	if (converted)
	{
		print_str_padded(converted, vars);
		len = ft_strlen(converted);
		free(converted);
	}
	return (len);
}

size_t	print_hex_value(int value, int case_ascii, t_vars *vars)
{
	char	*converted;
	char	*prec;
	size_t	len;

	len = 0;
	if (case_ascii == 1)
		converted = ft_uitoa_base(value, "0123456789ABCDEF");
	else
		converted = ft_uitoa_base(value, "0123456789abcdef");
	if (converted)
	{
		//ft_trace("x", "pass");
		if (HAS_FLAG_OBV(vars->flags))
		{
			prec = (case_ascii == 1) ? "0X" : "0x";
			ft_str_renew(&converted, ft_strjoin(prec, converted));
		}
		print_str_padded(converted, vars);
		len = ft_strlen(converted);
		free(converted);
	}
	return (len);
}

size_t	print_pointer_value(void *ptr, t_vars *vars)
{
	long		decimal_value;
	char	*converted;
	size_t	len;

	len = 0;
	decimal_value = (long)ptr;
	converted = ft_ltoa_base(decimal_value, "0123456789abcdef");
	if (converted)
	{
		ft_str_renew(&converted, ft_strjoin("0x", converted));
		print_str_padded(converted, vars);
		len = ft_strlen(converted);
		free(converted);
	}
	return (len);
}
