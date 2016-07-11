/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 06:21:02 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/11 08:37:10 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_vars_struct(t_vars *global)
{
	global->str = NULL;
	global->integer = 0;
	global->flt = 0;
	global->dbl = 0;
	global->shrt = 0;
	global->ptr = NULL;
}
