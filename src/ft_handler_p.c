/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:00:49 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 22:09:44 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_handler_p(t_flag *f, va_list *ap)
{
	f->flag[2] = 1;
	f->arg = ft_ulitoa_base(
		(unsigned long long int)va_arg(*ap, void *), 16);
	if (f->arg[0] == '0')
		return (-1);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	free(f->arg);
	return (0);
}
