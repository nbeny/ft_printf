/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:52:14 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:53:44 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handler_jd(t_flag *f, va_list *ap)
{
	f->arg = ft_maxitoa((intmax_t)va_arg(ap, intmax_t));
	return (0);
}

int		ft_handler_zd(t_flag *f, va_list *ap)
{
	f->arg = ft_sitoa((size_t)va_arg(ap, size_t));
	return (0);
}
