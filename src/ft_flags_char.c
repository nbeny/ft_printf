/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 14:12:37 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_moins(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	ft_putcstr(' ', i);
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	ft_putcstr(' ', i);
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	return (0);
}

static int	ft_flag_zero(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	ft_putcstr('0', i);
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	return (0);
}

int			ft_flags_char(t_flag *f)
{
	if (f->arg != NULL)
		f->size = ft_strlen(f->arg);
	else if (f->warg != NULL)
		f->size = ft_strlen((char *)f->warg);
	if (f->flag[1] > f->size)
		f->ret = f->flag[1];
	if (f->flag[0] > f->flag[1] && f->flag[13] == 1)
		f->ret = f->flag[0];
	if (f->flag[4] == 1)
		return (ft_flag_moins(f));
	else if (f->flag[3] == 1)
		return (ft_flag_zero(f));
	else if (f->flag[5] == 1 || f->flag[6] == 1 ||
			f->flag[1] > f->size)
		return (ft_flag_plus(f));
	if (f->flag[13] == 1 && f->flag[0] < f->size)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	return (f->ret);
}
