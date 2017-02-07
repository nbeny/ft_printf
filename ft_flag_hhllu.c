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

#include "ft_printf.h"

int		ft_handler_hhu(t_flag *f, va_list *ap)
{
	f->arg = ft_uitoa((unsigned int)va_arg(ap, unsigned char));
	return (0);
}

int		ft_handler_hd(t_flag *f, va_list *ap)
{
	f->arg = ft_uitoa((unsigned int)va_arg(ap, unsigned short int));
	return (0);
}

int		ft_handler_lld(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa((unsigned long long int)va_arg(ap, unsigned long long int));
	return (0);
}

int		ft_handler_ld(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa((unsigned long long int)va_arg(ap, unsigned long int));
	return (0);
}
