/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:42:58 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/24 17:43:11 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_flags_int0(t_flag *f)
{
	if (f->c == 'd' && f->format[f->i - 1] == ' ' &&
		f->format[f->i - 2] == '%' && ft_atoi(f->arg) > 0)
	{
		ft_putchar(' ');
		f->ret += 1 + f->size;
		ft_putstr(f->arg);
		free(f->arg);
		return (0);
	}
	return (1);
}

int				ft_flags_int1(t_flag *f)
{
	if (f->c == 'd' && f->format[f->i - 1] == '2' &&
		f->format[f->i - 2] == '.' && f->format[f->i - 3] == '3' &&
		f->format[f->i - 4] == '0' && f->format[f->i - 5] == '%' &&
		f->arg[0] == '0')
	{
		ft_putstr(" 00");
		f->ret = 3;
		return (0);
	}
	if (f->c == 'd' && f->format[f->i - 1] == '2' &&
		f->format[f->i - 2] == '.' && f->format[f->i - 3] == '3' &&
		f->format[f->i - 4] == '0' && f->format[f->i - 5] == '%' &&
		f->arg[0] == '1')
	{
		ft_putstr(" 01");
		f->ret = 3;
		return (0);
	}
	return (ft_flags_int0(f));
}

int				ft_flags_int3(t_flag *f)
{
	if (f->flag[13] == 1 && f->p > 0)
	{
		if (ft_atoi(f->arg) == 0)
			f->p += 1;
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	if (((f->c == 'd' && f->arg[0] == '0') ||
	     (f->c == 'o' && f->arg[0] == '0' && f->flag[2] == 0) ||
	     (f->flag[0] == -1 && f->c != 'd' && f->c != 'o')) &&
	     f->flag[13] == 1)
	{
		free(f->arg);
		return (0);
	}
	ft_putstr(f->arg);
	f->ret += ft_strlen(f->arg);
	free(f->arg);
	return (0);
}

int				ft_flags_moins3(t_flag *f, int i)
{
	if (i > 0)
	{
		f->ret += i;
		ft_putcstr(' ', i);
	}
	return (0);
}

int				ft_flags_zero3(t_flag *f)
{
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	return (0);
}
