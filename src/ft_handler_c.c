/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:00:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 19:51:16 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_handler_wc(t_flag *f, va_list *ap)
{
	wchar_t wc;
	wchar_t ws[2];

	if (f->flag[3] == 1)
		return (0);
	wc = va_arg(*ap, wchar_t);
	ws[0] = wc;
	ws[1] = 0;
	if (ws[0] < 0 && ws[0] > 55295 && ws[0] < 57344 && ws[0] > 1114111)
		return (-1);
	f->warg = ws;
	f->size = 1;
	if (f->flag[2] == 1 || f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	ft_strncpy(&g_buf[g_i], (char *)f->warg, f->size);
	g_i += f->size;
	return (0);
}

int	ft_handler_c(t_flag *f, va_list *ap)
{
	char c;
	char s[2];

	if (f->flag[3] == 1)
		return (0);
	if (f->flag[10] == 1)
	{
		ft_handler_wc(f, ap);
		return (0);
	}
	c = (char)va_arg(*ap, int);
	s[0] = c;
	s[1] = 0;
	f->arg = s;
	f->size = 1;
	if (f->flag[2] == 1 || f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	return (0);
}
