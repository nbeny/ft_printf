/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_jzd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:02:42 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/16 12:00:03 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_jd(t_flag *f, va_list *ap)
{
	f->arg = ft_max_itoa_base((intmax_t)va_arg(*ap, intmax_t), 10);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_zd(t_flag *f, va_list *ap)
{
	f->arg = ft_size_itoa_base((size_t)va_arg(*ap, size_t), 10);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}
