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

static t_flag	ft_init_f(t_flag f)
{
	int i;

	i = -1;
	f.ret = 0;
	f.i = 0;
	f.c = 0;
	f.arg = NULL;
	f.warg = NULL;
	f.sign = 0;
	while (++i < 14)
		f.flag[i] = 0;
	f.size = 0;
	f.x = 0;
	f.p = 0;
	f.free = 0;
	f.wc[0] = 0;
	f.wc[1] = 0;
	f.what = 0;
	return (f);
}

int				ft_fill_stdout(const char *format,
					       va_list *ap)
{
	size_t		i;
	size_t		ret;
	t_flag		f;
	t_list		*begin_lst;
	int			a;

	i = -1;
	ret = 0;
	if (!(begin_lst = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	begin_lst->next = NULL;
	ft_bzero(begin_lst->buf, 4096);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			a = -1;
			break ;
		}
		if (format[i] == '%')
		{
			f = ft_init_f(f);
			f.format = (char *)&format[++i];
			if ((a = ft_dispatcher(&f, ap, &begin_lst)) == -1)
			{
				if (f.free == 1)
					free(f.arg);
				break ;
			}
			if (f.free == 1)
				free(f.arg);
			ret += f.ret;
			i += f.i;
		}
		else
			i = ft_booster(format, i, &begin_lst) - 1;
	}
	while (begin_lst && a != -1)
	{
		ft_putstr(begin_lst->buf);
		begin_lst = begin_lst->next;
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
