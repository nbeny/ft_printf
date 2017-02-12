/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaghhllu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:18:59 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 23:11:15 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_hhu(t_flag *f, va_list *ap)
{
	f->arg = ft_uchar_itoa_base((unsigned char)va_arg(*ap, unsigned int), 10);
	return (0);
}

int		ft_handler_hu(t_flag *f, va_list *ap)
{
	f->arg = ft_ushort_itoa_base((unsigned short int)va_arg(*ap, unsigned int), 10);
	return (0);
}

int		ft_handler_llu(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa_base((unsigned long long int)va_arg(*ap, unsigned long long int), 10);
	return (0);
}

int		ft_handler_lu(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa_base((unsigned long int)va_arg(*ap, unsigned long int), 10);
	return (0);
}
