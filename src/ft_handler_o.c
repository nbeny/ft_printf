/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:25:16 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/16 14:21:16 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_modifier_o(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1)
		return (ft_handler_hho(f, ap));
	if (f->flag[8] == 1)
		return (ft_handler_ho(f, ap));
	if (f->flag[9] == 1)
		return (ft_handler_llo(f, ap));
	if (f->flag[10] == 1)
		return (ft_handler_lo(f, ap));
	if (f->flag[11] == 1)
		return (ft_handler_jo(f, ap));
	if (f->flag[12] == 1)
		return (ft_handler_zo(f, ap));
	return (0);
}

int		ft_handler_wo(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1 || f->flag[8] == 1 ||
		f->flag[9] == 1 || f->flag[10] == 1 ||
		f->flag[11] == 1 || f->flag[12] == 1)
		return (ft_modifier_o(f, ap));
	f->arg = ft_ulitoa_base((unsigned long int)va_arg(*ap, unsigned long int), 8);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_o(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1 || f->flag[8] == 1 ||
		f->flag[9] == 1 || f->flag[10] == 1 ||
		f->flag[11] == 1 || f->flag[12] == 1)
		return (ft_modifier_o(f, ap));
	if (f->flag[7] != 1 && f->flag[8] != 1 &&
		f->flag[9] != 1 && f->flag[10] != 1 &&
		f->flag[11] != 1 && f->flag[12] != 1)
		f->arg = ft_uitoa_base((unsigned int)va_arg(*ap, unsigned int), 8);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}
