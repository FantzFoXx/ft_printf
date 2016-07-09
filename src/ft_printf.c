/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:26:07 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/09 21:32:58 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
	va_list	lst;
	int		i;
	int		flag;
	int		type;
	

	va_start(lst, format);
	i = 0;
	type = 0;
	while (format[i])
	{
		cross_buffer(format, &i);
		if (format[i])
		{
			if (format[i] == '%')
				type = parse_percent((char *)format, &flag, &i);
			i++;
		}
	}
	return (0);
}
