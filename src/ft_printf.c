/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:26:07 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/22 14:23:32 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_conv_select(intmax_t value, t_vars *vars,
		int entry_type, char *base_conv)
{
	if (vars->size_specifier == 1)
	{
		if (entry_type == 1)
			return (ft_ltoa_base((long)value, base_conv));
		else if (entry_type == 2)
			return (ft_ultoa_base((unsigned long)value, base_conv));
			//return ((unsigned long)value);
	}
	else if (vars->size_specifier == 2)
	{
		if (entry_type == 1)
			return (ft_ltoa_base((long)value, base_conv));
			//return ((long)value);
		else if (entry_type == 2)
			return (ft_lltoa_base((long)value, base_conv));
			//return ((unsigned long long)value);
	}
	else if (vars->size_specifier == 3)
	{
		if (entry_type == 1)
			return (ft_itoa((short)value));
		//	return ((short)value);
		else if (entry_type == 2)
			return (ft_uitoa_base((unsigned short)value, base_conv));
	}
	else if (vars->size_specifier == 4)
	{
		if (entry_type == 1)
			return (ft_itoa((signed char)value));
		else if (entry_type == 2)
			return (ft_uitoa_base((unsigned char)value, base_conv));
	}
	else if (vars->size_specifier == 5)
	{
		if (entry_type == 1)
			return (ft_imtoa_base((intmax_t)value, base_conv));
		else if (entry_type == 2)
			return (ft_uimtoa_base((intmax_t)value, base_conv));
			//return ((uintmax_t)value);
	}
	else if (vars->size_specifier == 6)
	{
		if (entry_type == 1)
			return (ft_ltoa_base((long)value, "0123456789")); //provisoire
		else if (entry_type == 2)
			return (ft_uitoa((size_t)value));
	}
#if 0
	return ((long long)value);
#endif
	if (entry_type == 2)
		return (ft_uitoa_base((unsigned int)value, base_conv));
	else
		return (ft_itoa_base((int)value, base_conv));
}

int		print_var_content(t_vars *vars, int type, va_list *list)
{
	size_t	len_write;

	len_write = 0;
	clear_vars_struct(vars);
	if (type == 's' || type == 'S')
	{
		vars->str = va_arg(*list, char *);
		increment_write_len(vars, NULL, print_char_string(vars->str, vars));
	}
	//else if (type == 'S')
	//{
	//	vars->wchs = va_arg(*list, wchar_t *);
	//	increment_write_len(vars, NULL, print_wchar_string(vars->wchs, vars));
	//}
	else if (type == 'd' || type == 'i')
	{
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 1);
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 1, "0123456789");
		increment_write_len(vars, NULL, print_integer(vars->str, vars));
	}
	else if (type == 'D')
	{
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 2);
		//increment_write_len(vars, NULL, print_uinteger(vars->container, vars));
		vars->size_specifier = 1;
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 1, "0123456789");
		increment_write_len(vars, NULL, print_integer(vars->str, vars));
	}
	else if (type == 'u')
	{
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 2);
		//increment_write_len(vars, NULL, print_uinteger(vars->container, vars));
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 2, "0123456789");
		increment_write_len(vars, NULL, print_uinteger(vars->str, vars));
	}
	else if (type == 'U')
	{
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 2);
		//increment_write_len(vars, NULL, print_uinteger(vars->container, vars));
		vars->size_specifier = 1;
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 2, "0123456789");
		increment_write_len(vars, NULL, print_integer(vars->str, vars));
	}
	else if (type == 'c' || type == 'C' ) //replace C with wchar function
	{
		vars->container = va_arg(*list, int);
		increment_write_len(vars, NULL, print_char(vars->container, vars));
	}
	else if (type == 'o')
	{
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 2, "01234567");
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 2);
		increment_write_len(vars, NULL, print_octal_value(vars->str, vars));
	}
	else if (type == 'O')
	{
		vars->size_specifier = 1;
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 2, "01234567");
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 2);
		increment_write_len(vars, NULL, print_octal_value(vars->str, vars));
	}
	else if (type == 'x')
	{
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 2);
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 2, "0123456789abcdef");
		increment_write_len(vars, NULL, print_hex_value(vars->str, 0, vars));
		//ft_nbrtrace("vars->write_len", vars->write_len);
	}
	else if (type == 'X')
	{
		//vars->str = convert_var_size(va_arg(*list, intmax_t), vars, 2);
		vars->str = ft_conv_select(va_arg(*list, intmax_t), vars, 2, "0123456789ABCDEF");
		increment_write_len(vars, NULL, print_hex_value(vars->str, 1, vars));
	}
	else if (type == 'p')
	{
		vars->ptr = va_arg(*list, void *);
		increment_write_len(vars, NULL, print_pointer_value(vars->ptr, vars));
	}
	else if (type == '%')
	{
		// make function
		increment_write_len(vars, NULL, print_percent("%", vars));
	}
	else
		va_arg(*list, void *);
	vars->precision = -1;
	return (1);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	lst;
	int		type;
	t_vars	vars;

	va_start(lst, format);
	type = 0;
	vars.write_len = 0;
	vars.precision = -1;
	vars.padding = 0;
	while (*format)
	{
		format += increment_write_len(&vars, NULL, cross_buffer(format));
		if (*format)
			if (*format == '%')
			{
				type = parse_percent((char **)&format, &vars);
				print_var_content(&vars, type, &lst);
			}
	}
	return (vars.write_len);
}
