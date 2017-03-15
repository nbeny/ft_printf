/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:01:25 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/15 21:25:41 by nbeny            ###   ########.fr       */
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

void		ft_free(t_list *begin_lst)
{
	t_list *lst_nxt;

	while (begin_lst)
	{
		lst_nxt = begin_lst->next;
		free(begin_lst);
		begin_lst = NULL;
		begin_lst = lst_nxt;
	}
}
int		ft_print_and_free(t_list *begin_lst, int a)
{
	size_t	ret;
	t_list	*tmp;

	ret = 0;
	tmp = begin_lst;
	if (a != -1)
	{
		while (begin_lst)
		{
			ret += begin_lst->i;
			ft_putnstr(begin_lst->buf, begin_lst->i);
			begin_lst = begin_lst->next;
		}
	}
	else
	{
		begin_lst = tmp;
		ft_free(begin_lst);
		return(-1);
	}
	begin_lst = tmp;
	ft_free(begin_lst);
	return ((int)ret);
}

int				ft_fill_stdout(const char *format,
					       va_list *ap)
{
	size_t		i;
	t_flag		f;
	t_list		*begin_lst;
	int			a;

	i = -1;
	if (!(begin_lst = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	begin_lst->next = NULL;
	begin_lst->i = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
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
			i += f.i;
		}
		else
		{
			a = (int)ft_booster(format, i, &begin_lst) - 1;
			if (a == -2)
			{
				a = -1;
				break ;
			}
			else
				i = (size_t)a;
		}
	}
	return (ft_print_and_free(begin_lst, a));
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	ret = ft_fill_stdout(format, &ap);
	va_end(ap);
	return (ret);
}
