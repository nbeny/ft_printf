/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hhlld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:08:51 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:46:30 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_handler_hhd(t_flag *f, va_list *ap)
{
	f->arg = ft_itoa((int)va_arg(*ap, signed char));
	return (0);
}

int		ft_handler_hd(t_flag *f, va_list *ap)
{
	f->arg = ft_itoa((int)va_arg(*ap, short int));
	return (0);
}

int		ft_handler_lld(t_flag *f, va_list *ap)
{
	f->arg = ft_litoa((long long int)va_arg(*ap, long long int));
	return (0);
}

int		ft_handler_ld(t_flag *f, va_list *ap)
{
	f->arg = ft_litoa((long long int)va_arg(*ap, long int));
	return (0);
}
