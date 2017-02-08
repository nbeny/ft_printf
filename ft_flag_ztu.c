/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_ztu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:50:50 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:54:46 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handler_ju(t_flag *f, va_list *ap)
{
	f->arg = ft_umaxitoa((intmax_t)va_arg(*ap, intmax_t));
	return (0);
}

int		ft_handler_zu(t_flag *f, va_list *ap)
{
	f->arg = ft_usitoa((size_t)va_arg(*ap, size_t));
	return (0);
}
