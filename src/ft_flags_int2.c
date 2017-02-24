/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:51:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/24 17:48:22 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_flags_zero2(t_flag *f, int i)
{
	if (f->arg[0] == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		ft_putchar('-');
	}
	if (f->flag[2] == 1)
	{
		if (ft_atoi(f->arg) != 0 && f->flag[0] != -1)
		{
			ft_putstr(f->ox);
			f->ret += f->x;
		}
		free(f->ox);
	}
	if (i > 0)
	{
		ft_putcstr('0', i);
		f->ret += i;
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	return (0);
}

int		ft_flags_moins2(t_flag *f)
{
	if (f->flag[2] == 1)
	{
		if (f->arg[0] != '0' && f->flag[0] != -1)
		{
			ft_putstr(f->ox);
			f->ret += f->x;
		}
		free(f->ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	if (f->flag[0] != -1)
	{
		ft_putstr(f->arg);
		f->ret += f->size;
		free(f->arg);
	}
	return (0);
}

int		ft_flags_plus2(t_flag *f)
{
	if (f->flag[2] == 1)
	{
		if (f->arg[0] != '0' && f->flag[0] != -1)
		{
			ft_putstr(f->ox);
			f->ret += f->x;
		}
		free(f->ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	ft_flags_int3(f);
	return (0);
}

int		ft_flags_plus3(t_flag *f)
{
	if (f->flag[0] != -1)
	{
		if (f->c == 'd' && f->format[f->i - 1] == ' ' &&
			f->format[f->i - 2] == '%' && f->arg[0] != '-')
		{
			ft_putchar(' ');
			f->ret += 1;
		}
		ft_putstr(f->arg);
		f->ret += f->size;
		free(f->arg);
	}
	return (0);
}

int		ft_flags_int2(t_flag *f)
{
	if (ft_atoi(f->arg) < 0 && f->flag[13] == 1)
	{
		f->arg = ft_rotcstring(f->arg);
		ft_putchar('-');
		f->p += 1;
		f->ret += 1;
	}
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' && f->flag[0] != -1) ||
			f->c == 'o')
		{
			ft_putstr(f->ox);
			f->ret += f->x;
		}
		free(f->ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_flags_int3(f);
	return (0);
}
