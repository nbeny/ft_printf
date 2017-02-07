/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:14:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:49:11 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_modifier_u(t_flag *f)
{
	if (flag[7] == 1)
		return (ft_handler_hhu(f, ap));
	if (flag[8] == 1)
		return (ft_handler_hu(f, ap));
	if (flag[9] == 1)
		return (ft_handler_llu(f, ap));
	if (flag[10] == 1)
		return (ft_handler_lu(f, ap));
	if (flag[11] == 1)
		return (ft_handler_zu(f, ap));
	if (flag[12] == 1)
		return (ft_handler_tu(f, ap));
	return (0);
}

intft_handler_wu(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa((unsigned long long int)va_arg(ap, unsigned long int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}

intft_handler_u(t_flag *f, va_list *ap)
{
	if (flag[7] == 1 || flag[8] == 1 ||
		    flag[9] == 1 || flag[10] == 1 ||
		flag[11] == 1 || flag[12] == 1)
		ft_modifier_u(f, ap);
	if (flag[7] != 1 && flag[8] != 1 &&
		flag[9] != 1 && flag[10] != 1 &&
		flag[11] != 1 && flag[12] != 1)
		f->arg = ft_uitoa((unsigned int)va_arg(ap, unsigned int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}