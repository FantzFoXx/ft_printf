/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 06:21:02 by udelorme          #+#    #+#             */
/*   Updated: 2016/09/07 23:38:39 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_vars_struct(t_vars *global)
{
	global->container = 0;
	global->str = NULL;
	//global->integer = 0;
	//global->uint = 0;
	//global->flt = 0;
	//global->dbl = 0;
	//global->shrt = 0;
	global->ptr = NULL;
	global->wch = 0;
	global->wchs = NULL;
	//global->precision = 0;
	//global->padding = 0;
}

#ifdef FT_PRINTF_DEBUG
void	dump_vars_struct(t_vars *global)
{
	ft_putendl("###### DEBUG ######");
	ft_trace("global->str",global->str);
	ft_nbrtrace("global->integ",global->integer);
	ft_nbrtrace("global->uint",global->uint);
	ft_nbrtrace("global->shrt",global->shrt);
	ft_putendl("###################");
}
#endif

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

size_t	print_padding(int len, t_vars *vars)
{
	char	*padd;
	char	c;

	len = (len > 0) ? len : -len;
	padd = ft_strnew(len);
	if (HAS_FLAG_ZERO(vars->flags))
		c = '0';
	else
		c = ' ';
	ft_memset(padd, c, len);
	write(1, padd, len);
	free(padd);
	return (len);
}
