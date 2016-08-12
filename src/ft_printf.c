/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:26:07 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/12 11:29:22 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
		vars->integer = va_arg(*list, int);
		increment_write_len(vars, NULL, print_integer(vars->integer, vars));
	}
	else if (type == 'u')
	{
		vars->integer = va_arg(*list, int);
		increment_write_len(vars, NULL, print_uinteger(vars->integer, vars));
	}
	else if (type == 'c')
	{
		vars->integer = va_arg(*list, int);
		increment_write_len(vars, NULL, print_char(vars->integer, vars));
	}
	else if (type == 'o' || type == 'O')
	{
		vars->integer = va_arg(*list, int);
		increment_write_len(vars, NULL, print_octal_value(vars->integer, vars));
	}
	else if (type == 'x')
	{
		vars->integer = va_arg(*list, int);
		increment_write_len(vars, NULL, print_hex_value(vars->integer, 0, vars));
	}
	else if (type == 'X')
	{
		vars->integer = va_arg(*list, int);
		increment_write_len(vars, NULL, print_hex_value(vars->integer, 1, vars));
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
