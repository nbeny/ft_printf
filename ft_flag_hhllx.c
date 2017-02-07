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

#include "ft_printf.h"

int		ft_handler_hhx(t_flag *f, va_list *ap)
{
	f->arg = ft_xitoa((unsigned int)va_arg(ap, unsigned char));
	return (0);
}

int		ft_handler_hx(t_flag *f, va_list *ap)
{
	f->arg = ft_xitoa((unsigned int)va_arg(ap, unsigned short int));
	return (0);
}

int		ft_handler_llx(t_flag *f, va_list *ap)
{
	f->arg = ft_xlitoa((unsigned long long int)va_arg(ap, unsigned long long int));
	return (0);
}

int		ft_handler_lx(t_flag *f, va_list *ap)
{
	f->arg = ft_xlitoa((unsigned long long int)va_arg(ap, unsigned long int));
	return (0);
}
