/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:26:07 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/12 11:54:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		print_var_content(t_vars *vars, int type, va_list *list)
{
	size_t	len_write;

	len_write = 0;
	clear_vars_struct(vars);
	if (type == 's')
	{
		vars->str = va_arg(*list, char *);
		increment_write_len(vars, NULL, print_char_string(vars->str));
	}
	else if (type == 'd' || type == 'i')
	{
		vars->integer = va_arg(*list, int);
		print_integer(vars->integer);
	}
	else if (type == 'c')
	{
		vars->integer = va_arg(*list, int);
		increment_write_len(vars, NULL, print_char(vars->integer));
	}
	else if (type == 'o')
	{
		vars->integer = va_arg(*list, int);
		print_octal_value(vars->integer);
	}
	else if (type == 'p')
	{
		vars->ptr = va_arg(*list, void *);
		print_pointer_value(vars->ptr);
	}
	else if (type == '%')
	{
		// make function
		write(1, "%", 1);
		vars->write_len += 1;
	}
	else
		va_arg(*list, void *);
	return (1);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	lst;
	int		i;
	int		flag;
	int		type;
	t_vars	vars;
	
	va_start(lst, format);
	i = 0;
	type = 0;
	vars.write_len = 0;
	while (format[i])
	{
		increment_write_len(&vars, NULL, cross_buffer(format, &i));
		if (format[i])
		{
			if (format[i] == '%')
			{
				type = parse_percent((char *)format, &flag, &i);
				print_var_content(&vars, type, &lst);
			}
			i++;
		}
	}
	return (vars.write_len);
}
