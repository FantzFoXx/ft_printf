/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 06:21:02 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/05 16:55:37 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_vars_struct(t_vars *global)
{
	global->str = NULL;
	global->integer = 0;
	global->uint = 0;
	global->flt = 0;
	global->dbl = 0;
	global->shrt = 0;
	global->ptr = NULL;
	global->wch = 0;
	global->wchs = NULL;
	//global->padding = 0;
}

size_t	increment_write_len(t_vars *vars, char *print, int decimal_value)
{
	size_t len;

	if (decimal_value != -1)
		len = decimal_value;
	else
		len = ft_strlen(print);
	vars->write_len += len;
	return (len);
}

size_t	print_padding(int len)
{
	char	*padd;

	len = (len > 0) ? len : -len;
	padd = ft_strnew(len);
	ft_memset(padd, ' ', len);
	write(1, padd, len);
	free(padd);
	return (len);
}
