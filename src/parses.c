/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:24:10 by udelorme          #+#    #+#             */
/*   Updated: 2016/08/05 16:55:40 by udelorme         ###   ########.fr       */
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


int		parse_percent(char *buf, int *flag, t_vars *vars)
{
	int		i;
	int		ret;

	i = 1;
	if (buf[i])
	{
		if ((ret = ft_atoi(&buf[i])) != 0)
		{
			vars->padding = ret;
			while (ft_isdigit(buf[i]))
				i++;
			if (buf[i] == '.')
				i++;
			if ((ret = ft_atoi(&buf[i])) != 0)
				vars->len_padded_var = ret;
			while (ft_isdigit(buf[i]))
				i++;
		}
		if (buf[i])
			vars->flag = get_flag(&buf[i], &i);
		*flag = get_index_attr(&buf[i]);
	}
	return (i);
}

#if 0
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
	{
		if ((ret = ft_atoi(&buf[*i])) == 0)
		{
			*i = bak;
			return (get_index_attr(&buf[*i]));
		}
		while (ft_isdigit(buf[*i]) || buf[*i] == '.')
			(*i)++;
		increment_write_len(vars, NULL, ret - 1);
		vars->padding = ret -1;
	}
	return (get_index_attr(&buf[*i]));
}
#endif
