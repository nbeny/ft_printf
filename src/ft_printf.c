/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:01:25 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/07 11:07:28 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_flag	*ft_init_f(t_flag *f)
{
	int i;

	i = -1;
	f->ret = 0;
	f->i = 0;
	f->c = 0;
	f->arg = NULL;
	f->warg = NULL;
	f->sign = 0;
	while (++i < 14)
		f->flag[i] = 0;
	f->size = 0;
	f->x = 0;
	f->p = 0;
	f->free = 0;
	f->wc[0] = 0;
	f->wc[1] = 0;
	f->what = 0;
	return (f);
}

int				ft_for_handred(t_flag *f, va_list *ap)
{
	ft_bzero(g_buf, 4096);
	g_i = 0;
	f = ft_init_f(f);
	ft_dispatcher(f, ap);
	if (f->free == 1)
		free(f->arg);
	ft_putnstr(g_buf, g_i);
	return (0);
}

int				ft_fill_stdout(const char *format, va_list *ap)
{
	int			i;
	int			ret;
	t_flag		f;

	i = -1;
	ret = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%')
		{
			f.format = (char *)&format[++i];
			ft_for_handred(&f, ap);
			i += f.i;
			ret += g_i;
		}
		else
		{
			ft_putchar(format[i]);
			ret += 1;
		}
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	ret = ft_fill_stdout(format, &ap);
	va_end(ap);
	return (ret);
}
