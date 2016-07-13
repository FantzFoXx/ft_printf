/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:24:10 by udelorme          #+#    #+#             */
/*   Updated: 2016/07/13 17:21:09 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int		get_flag(char *buf, int *size)
{
	*size = 2;
	if (ft_strncmp(buf, "ll", 2) == 0)
		return (2);
	else if (ft_strncmp(buf, "hh", 2) == 0)
		return (4);
	*size = 1;
	if (ft_strncmp(buf, "l", 1) == 0)
		return (1);
	else if (ft_strncmp(buf, "h", 1) == 0)
		return (3);
	else if (ft_strncmp(buf, "j", 1) == 0)
		return (5);
	else if (ft_strncmp(buf, "z", 1) == 0)
		return (6);
	*size = 0;
	return (0);
}

int		get_index_attr(char *buf)
{
	return ((int)*buf);
}

int		parse_percent(char *buf, int *flag, int *i, t_vars *vars)
{
	int		flag_size;
	int		ret;
	int		bak;

	(*i)++;
	*flag = get_flag(&buf[*i], &flag_size);
	*i += flag_size;
	ret = 0;
	bak = *i;
	if (buf[*i])
		if ((ret = ft_atoi(&buf[*i])) == 0)
		{
			*i = bak;
			return (get_index_attr(&buf[*i]));
		}
	while (ft_isdigit(buf[*i]) || buf[*i] == '.')
		(*i)++;
	increment_write_len(vars, NULL, print_padding(ret - 1));
	vars->padding = 1;
	return (get_index_attr(&buf[*i]));
	//return (ret);
}
