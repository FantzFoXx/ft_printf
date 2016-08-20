/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 06:09:11 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/20 16:48:07 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*decimal_precision(char *str, int precision)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	len = ft_strlen(str);
	tmp = str;
	if (precision > len)
	{
		tmp = ft_strnew(precision);
		ft_memset(tmp, '0', (size_t)precision);
		tmp += precision - len;
		while (*str)
		{
			*tmp = *str;
			str++;
			tmp++;
		}
		tmp -= precision;
		free(str - len);
	}
	return (tmp);
}

char	*ft_rot_string(char *str, unsigned int rot)
{
	char	*ret;

	ret = str;
	str += rot;
	while (*str)
	{
		*(str - rot) = *str;
		str++;
	}
	*(str - rot) = 0;
	return (ret);
}

size_t	print_integer(char *value, t_vars *vars)
{
	char	*conv;
	size_t	len;
	int		padding;
	int		negative;

	len = 0;
	if (*value == '-')
	{
		negative = 1;
		conv = ft_strdup(value + 1);
	}
	else
	{
		negative = 0;
		conv = ft_strdup(value);
	}
	if (vars->precision > 0)
	{
		vars->flags &= ~FLAG_ZERO;
		conv = decimal_precision(conv, vars->precision);
	}
	padding = vars->padding - ft_strlen(conv);
	if (HAS_FLAG_SIGN(vars->flags) || negative)
		padding -= 1;
	if (padding > 0 && HAS_FLAG_ZERO(vars->flags))
		conv = add_padding(conv, (size_t)padding, vars);
	if (HAS_FLAG_SIGN(vars->flags) && *value != '-')
		conv = ft_strjoin("+", conv); // leak
	else if (negative)
		conv = ft_strjoin("-", conv); //leak
	else if (HAS_FLAG_SPACE(vars->flags) && !HAS_FLAG_ZERO(vars->flags) && vars->precision <= 0)
		conv = ft_strjoin(" ", conv); //leak
	if (padding > 0 && !HAS_FLAG_ZERO(vars->flags))
		conv = add_padding(conv, (size_t)padding, vars);
	if (conv)
	{
		ft_putstr(conv);
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
	conv = ft_uitoa(value);
	if (vars->precision >= 0)
		conv = decimal_precision(conv, vars->precision);
	if (HAS_FLAG_SIGN(vars->flags) && value > 0)
		conv = ft_strjoin("+", conv); // leak
	if (conv)
	{
		len = print_str_padded(conv, vars, NULL);
		ft_strdel(&conv);
	}
	return (len);
}

size_t	print_octal_value(char *value, t_vars *vars)
{
	char	*converted;
	char	*prec = NULL;
	size_t	len;

	len = 0;
	//converted = ft_uitoa_base(value, "01234567");
	converted = value;
	if (vars->precision > 0)
		converted = decimal_precision(converted, vars->precision);
	if (converted)
	{
		if (HAS_FLAG_OBV(vars->flags) && value > 0)
		{
			prec = "0";
			ft_str_renew(&converted, ft_strjoin(prec, converted));
		}
		len = print_str_padded(converted, vars, NULL);
		free(converted);
	}
	return (len);
}

size_t	print_hex_value(char *value, int case_ascii, t_vars *vars)
{
	char	*converted;
	char	*prec = NULL;
	size_t	len;

	converted = value;

	len = 0;
	/*
	if (case_ascii == 1)
		converted = ft_uitoa_base(value, "0123456789ABCDEF");
	else
		converted = ft_uitoa_base(value, "0123456789abcdef");
		*/
	if (converted)
	{
		if (HAS_FLAG_OBV(vars->flags) && ft_strcmp(value, "0") != 0)
		{
			prec = (case_ascii == 1) ? "0X" : "0x";
			//ft_str_renew(&converted, ft_strjoin(prec, converted));
		}
		len = print_str_padded(converted, vars, prec);
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
		print_str_padded(converted, vars, NULL);
		len = ft_strlen(converted);
		free(converted);
	}
	return (len);
}
