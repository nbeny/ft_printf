/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hhllo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:38:35 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/16 11:57:31 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_hho(t_flag *f, va_list *ap)
{
	f->arg = ft_uchar_itoa_base((unsigned char)va_arg(*ap, unsigned int), 8);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_ho(t_flag *f, va_list *ap)
{
	f->arg = ft_ushort_itoa_base((unsigned short int)va_arg(*ap, unsigned int), 8);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_llo(t_flag *f, va_list *ap)
{
	f->arg = ft_ullitoa_base((unsigned long long int)va_arg(*ap, unsigned long long int), 8);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_lo(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa_base((unsigned long int)va_arg(*ap, unsigned long int), 8);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}
