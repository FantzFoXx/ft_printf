/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:24:10 by udelorme          #+#    #+#             */
/*   Updated: 2016/09/07 18:35:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void			handle_flag_conflicts(t_vars *vars)
{
	if (HAS_FLAG_ZERO(vars->flags) && HAS_FLAG_RIGHT(vars->flags))
		vars->flags &= ~FLAG_ZERO;
	//if (HAS_FLAG_ZERO(vars->flags) && HAS_FLAG_SPACE(vars->flags))
	//	vars->flags &= ~FLAG_ZERO;
}

static int		get_flags(char **buf)
{
	int		ret;

	ret = 0;
	while (42)
	{
		if (**buf == '+')
			ret |= FLAG_SIGN;
		else if (**buf == ' ')
			ret |= FLAG_SPACE;
		else if (**buf == '-')
			ret |= FLAG_RIGHT;
		else if (**buf == '#')
			ret |= FLAG_OBV;
		else if (**buf == '0')
			ret |= FLAG_ZERO;
		else
			break ;
		(*buf)++;
	}
	return (ret);
}

static int		get_index_attr(char *buf)
{
	return ((int)*buf);
}

static int		get_size_specifier(char **buf)
{
	char	*tmp;

	tmp = *buf;
	*buf += 2;
	if (ft_strncmp(tmp, "ll", 2) == 0)
		return (2);
	else if (ft_strncmp(tmp, "hh", 2) == 0)
		return (4);
	*buf -= 1;
	if (ft_strncmp(tmp, "l", 1) == 0)
		return (1);
	else if (ft_strncmp(tmp, "h", 1) == 0)
		return (3);
	else if (ft_strncmp(tmp, "j", 1) == 0)
		return (5);
	else if (ft_strncmp(tmp, "z", 1) == 0)
		return (6);
	*buf -= 1;
	return (0);
}

int		parse_percent(char **buf, t_vars *vars)
{
	char	*tmp;
	int		ret;

	tmp = ++*buf;
	if (**buf == 0)
		return (0);
	vars->flags = get_flags(&tmp);
	handle_flag_conflicts(vars);
	vars->padding = ft_atoi(tmp);
	if (vars->padding > 0)
		while (ft_isdigit(*tmp))
			tmp++;
	if (*tmp == '.')
	{
		tmp++;
		vars->precision = ft_atoi(tmp);
		while (ft_isdigit(*tmp))
			tmp++;
	}
	vars->size_specifier = get_size_specifier(&tmp);
	ret = get_index_attr(tmp++);
	//ft_nbrtrace("ret", ret);
	//if (!IS_CONVERT_VALUE(ret))
	//	tmp--;
	*buf = tmp;
	return (ret);
}
