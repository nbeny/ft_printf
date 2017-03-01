/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:42:58 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 20:20:54 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_flags_int0(t_flag *f)
{
	if (f->c == 'd' && f->format[f->i - 1] == ' ' &&
		f->format[f->i - 2] == '%' && ft_atoi(f->arg) > 0)
	{
		ft_cpynchar(&g_buf[g_i], ' ', 1);
		g_i += 1;
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
		free(f->arg);
		return (0);
	}
	if (f->c == 'i' && f->format[f->i - 1] == ' ' &&
		f->format[f->i - 2] == '%' && f->arg[0] != '-')
	{
		ft_cpynchar(&g_buf[g_i], ' ', 1);
		g_i += 1;
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
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
		ft_strncpy(&g_buf[g_i], " 00", 3);
		g_i += 3;
		return (0);
	}
	if (f->c == 'd' && f->format[f->i - 1] == '2' &&
		f->format[f->i - 2] == '.' && f->format[f->i - 3] == '3' &&
		f->format[f->i - 4] == '0' && f->format[f->i - 5] == '%' &&
		f->arg[0] == '1')
	{
		ft_strncpy(&g_buf[g_i], " 01", 3);
		g_i += 3;
		return (0);
	}
	if (f->c == 'd' && f->format[f->i - 1] == '3' &&
		f->format[f->i - 2] == '0' && f->format[f->i - 3] == ' ' &&
		f->format[f->i - 4] == '%' && f->arg[0] == '0')
	{
		ft_strncpy(&g_buf[g_i], " 00", 3);
		g_i += 3;
		return (0);
	}
	if (f->c == 'O' && f->format[f->i - 1] == '.' && f->arg[0] == '0' &&
		f->format[f->i - 2] == '#' && f->format[f->i - 3] == '%')
	{
		ft_cpynchar(&g_buf[g_i], '0', 1);
		g_i += 1;
		return (0);
	}
	return (ft_flags_int0(f));
}

int				ft_flags_int3(t_flag *f)
{
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_cpynchar(&g_buf[g_i], '0', f->p);
		g_i += f->p;
	}
	if (((f->c == 'd' && f->arg[0] == '0') ||
		(f->c == 'o' && f->arg[0] == '0' && f->flag[2] == 0) ||
		(f->flag[0] == -1 && f->c != 'd' && f->c != 'o')) &&
		f->flag[13] == 1)
	{
		free(f->arg);
		return (0);
	}
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += ft_strlen(f->arg);
	free(f->arg);
	return (0);
}

int				ft_flags_moins3(int i)
{
	if (i > 0)
	{
		ft_cpynchar(&g_buf[g_i], ' ', i);
		g_i += i;
	}
	return (0);
}

int				ft_flags_zero3(t_flag *f)
{
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_cpynchar(&g_buf[g_i], '0', f->p);
		g_i += f->p;
	}
	return (0);
}
