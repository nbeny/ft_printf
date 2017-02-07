/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:25:16 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:49:58 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_modifier_o(t_flag *f, va_list *ap)
{
	if (flag[7] == 1)
		return (ft_handler_hho(f, ap));
	if (flag[8] == 1)
		return (ft_handler_ho(f, ap));
	if (flag[9] == 1)
		return (ft_handler_llo(f, ap));
	if (flag[10] == 1)
		return (ft_handler_lo(f, ap));
	if (flag[11] == 1)
		return (ft_handler_zo(f, ap));
	if (flag[12] == 1)
		return (ft_handler_to(f, ap));
	return (0);
}

int		ft_handler_wo(t_flag *f, va_list *ap)
{
	f->arg = ft_olitoa((unsigned long long int)va_arg(ap, unsigned long int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_o(t_flag *f, va_list *ap)
{
	if (flag[7] == 1 || flag[8] == 1 ||
		flag[9] == 1 || flag[10] == 1 ||
		flag[11] == 1 || flag[12] == 1)
		ft_modifier_o(f, ap);
	if (flag[7] != 1 && flag[8] != 1 &&
		flag[9] != 1 && flag[10] != 1 &&
		flag[11] != 1 && flag[12] != 1)
		f->arg = ft_oitoa((unsigned int)va_arg(ap, unsigned int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}
