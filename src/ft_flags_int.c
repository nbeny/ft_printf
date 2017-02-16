/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:46 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/16 14:59:49 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_Ox(t_flag *f)
{
	int i;

	i = 0;
	if (!(f->Ox = (char *)malloc(sizeof(char) * 3)))
		f->Ox = NULL;
	ft_bzero(f->Ox, 3);
	if (f->c == 'o' || f->c == 'O' ||
	    f->c == 'x' || f->c == 'X')
	{
		f->Ox[0] = '0';
		i++;
	}
	if (f->c == 'x')
	{
		f->Ox[1] = 'x';
		i++;
	}
	if (f->c == 'X')
	{
		f->Ox[1] = 'X';
		i++;
	}
	f->Ox[i] = 0;
	return (i);
}

static int	ft_flag_zero(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size;
	if (f->flag[2] == 1)
		i = i - ft_flag_Ox(f);
	if (i < 0)
		i = 0;
	if (f->sign == '+' && f->flag[5] == 1)
			ft_putchar('+');
	if (f->sign == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		ft_putchar('-');
	}
	if (f->flag[2] == 1)
	{
		ft_putstr(f->Ox);
		free(f->Ox);
	}
	ft_putcstr(48, i);
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_putstr(f->arg);
	return (0);
}

static int	ft_flag_moins(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size;
	if (f->flag[2] == 1)
		i = i - ft_flag_Ox(f);
	if (i < 0)
		i = 0;
	if ((f->c == 'd' || f->c == 'D' ||
	     f->c == 'i') && f->flag[5] == 1)
		if (f->sign == '+')
			ft_putchar('+');
	if (f->flag[2] == 1)
	{
		ft_putstr(f->Ox);
		free(f->Ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_putstr(f->arg);
	ft_putcstr(' ', i);
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size;
	if (f->flag[2] == 1)
		i = i - ft_flag_Ox(f);
	if ((f->c == 'd' || f->c == 'D' ||
	     f->c == 'i') && f->flag[5] == 1)
		if (f->sign == '+')
			ft_putchar('+');
	ft_putcstr(' ', i);
	if (f->flag[2] == 1)
	{
		ft_putstr(f->Ox);
		free(f->Ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int	ft_flags_int(t_flag *f)
{
	f->size = ft_strlen(f->arg);
	f->ret = f->flag[1];
	if (f->flag[5] == 1)
		f->sign = ft_sign(f->arg);
	if (f->flag[1] > ft_strlen(f->arg))
	{
		if (f->flag[3] == 1)
			return (ft_flag_zero(f));
		else if (f->flag[4] == 1)
			return (ft_flag_moins(f));
		else if (f->flag[5] == 1 || f->flag[6] == 1 ||
				 f->flag[1] > ft_strlen(f->arg))
			return (ft_flag_plus(f));
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_putstr(f->arg);
	return (0);
}
