/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hhllx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:44:27 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:46:06 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_hhx(t_flag *f, va_list *ap)
{
	f->arg = ft_uchar_itoa_base((unsigned char)va_arg(*ap, unsigned int), 16);
	return (0);
}

int		ft_handler_hx(t_flag *f, va_list *ap)
{
	f->arg = ft_ushort_itoa_base((unsigned short int)va_arg(*ap, unsigned int), 16);
	return (0);
}

int		ft_handler_llx(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa_base((unsigned long long int)va_arg(*ap, unsigned long long int), 16);
	return (0);
}

int		ft_handler_lx(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa_base((unsigned long int)va_arg(*ap, unsigned long int), 16);
	return (0);
}
