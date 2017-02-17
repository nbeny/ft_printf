/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 06:10:03 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_moins(t_flag *f)
{
	int	i;

	i = f->flag[1] - f->size;
	if (f->arg != NULL)
		ft_putstr(f->arg);
	else if (f->warg != NULL)
		ft_putstr((char *)f->warg);
	ft_putcstr(' ', i);
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	int	i;

	i = f->flag[1] - f->size;
	ft_putcstr(' ', i);
	if (f->arg != NULL)
		ft_putstr(f->arg);
	else if (f->warg != NULL)
		ft_putstr((char *)f->warg);
	return (0);
}

static int	ft_flag_zero(t_flag *f)
{
	int	i;

	i = f->flag[1] - f->size;
	ft_putcstr('0', i);
	if (f->arg != NULL)
		ft_putstr(f->arg);
	else if (f->warg != NULL)
		ft_putstr((char *)f->warg);
	return (0);
}

int			ft_flags_char(t_flag *f)
{
	f->size = ft_strlen(f->arg);
	f->ret = f->flag[1];
	if (f->flag[4] == 1)
		return (ft_flag_moins(f));
	else if (f->flag[3] == 1)
		return (ft_flag_zero(f));
	else if (f->flag[5] == 1 || f->flag[6] == 1 || f->flag[1] > f->size)
		return (ft_flag_plus(f));
	if (f->arg != NULL)
		ft_putstr(f->arg);
	else if (f->warg != NULL)
		ft_putstr((char *)f->warg);
	return (f->ret);
}
