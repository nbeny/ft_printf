/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hhllo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:38:35 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:46:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handler_hho(t_flag *f, va_list *ap)
{
	f->arg = ft_oitoa((unsigned int)va_arg(*ap, unsigned char));
	return (0);
}

int		ft_handler_ho(t_flag *f, va_list *ap)
{
	f->arg = ft_oitoa((unsigned int)va_arg(*ap, unsigned short int));
	return (0);
}

int		ft_handler_llo(t_flag *f, va_list *ap)
{
	f->arg = ft_olitoa((unsigned long long int)va_arg(*ap, unsigned long long int));
	return (0);
}

int		ft_handler_lo(t_flag *f, va_list *ap)
{
	f->arg = ft_olitoa((unsigned long long int)va_arg(*ap, unsigned long int));
	return (0);
}
