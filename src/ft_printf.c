/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:26:07 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/13 08:13:05 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"


long long	convert_var_size(long long value, t_vars *vars, int entry_type)
{
	if (vars->size_specifier == 1)
	{
		if (entry_type == 1)
			return ((long)value);
		else if (entry_type == 2)
			return ((unsigned long)value);
	}
	else if (vars->size_specifier == 2)
	{
		if (entry_type == 1)
			return ((long)value);
		else if (entry_type == 2)
			return ((unsigned long long)value);
	}
	else if (vars->size_specifier == 3)
	{
		if (entry_type == 1)
			return ((short)value);
		else if (entry_type == 2)
			return ((unsigned short)value);
	}
	else if (vars->size_specifier == 4)
	{
		if (entry_type == 1)
			return ((signed char)value);
		else if (entry_type == 2)
			return ((unsigned char)value);
	}
	else if (vars->size_specifier == 5)
	{
		if (entry_type == 1)
			return ((intmax_t)value);
		else if (entry_type == 2)
			return ((uintmax_t)value);
	}
	else if (vars->size_specifier == 6)
	{
		if (entry_type == 1)
			return ((size_t)value); //provisoire
		else if (entry_type == 2)
			return ((size_t)value);
	}
	return ((long long)value);
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
	else if (type == 'd' || type == 'i' || type == 'D')
	{
		vars->container = convert_var_size(va_arg(*list, int), vars, 1);
		increment_write_len(vars, NULL, print_integer(vars->container, vars));
	}
	else if (type == 'u')
	{
		//vars->container = va_arg(*list, int);
		vars->container = convert_var_size(va_arg(*list, int), vars, 2);
		increment_write_len(vars, NULL, print_uinteger(vars->container, vars));
	}
	else if (type == 'c')
	{
		vars->container = va_arg(*list, int);
		increment_write_len(vars, NULL, print_char(vars->container, vars));
	}
	else if (type == 'o' || type == 'O')
	{
		//vars->container = va_arg(*list, int);
		vars->container = convert_var_size(va_arg(*list, int), vars, 2);
		increment_write_len(vars, NULL, print_octal_value(vars->container, vars));
	}
	else if (type == 'x')
	{
		//vars->container = va_arg(*list, int);
		vars->container = convert_var_size(va_arg(*list, int), vars, 2);
		increment_write_len(vars, NULL, print_hex_value(vars->container, 0, vars));
	}
	else if (type == 'X')
	{
		//vars->container = va_arg(*list, int);
		vars->container = convert_var_size(va_arg(*list, int), vars, 2);
		increment_write_len(vars, NULL, print_hex_value(vars->container, 1, vars));
	}
	else if (type == 'p')
	{
		vars->ptr = va_arg(*list, void *);
		increment_write_len(vars, NULL, print_pointer_value(vars->ptr, vars));
	}
	else if (type == '%')
	{
		// make function
		increment_write_len(vars, NULL, print_char_string("%", vars));
	}
	else
		va_arg(*list, void *);
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
