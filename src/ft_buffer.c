#include "../include/ft_printf.h"

int		ft_multibuf_ox(t_flag *f, t_list **begin_lst, size_t size)
{
	t_list	*lst;
	t_list	*new;
	size_t	i[2];

	*begin_lst = lst;
	if (begin_lst == NULL)
		return (-1);
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
	{
		i[1] = 4095 - lst->i;
		ft_strncpy(new->buf[lst->i], &f->ox[0], i[1]);
		i[0] += i[1];
		while (size != 0)
		{
			if (size > 4095)
				i[1] = 4095;
			else
				i[1] = size;
			if (!(new = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst->next = new;
			new->i = 0;
			ft_bzero(new->buf, 4095);
			new->buf = ft_strncpy(new->buf[lst->i], &f->ox[i[0]], i[1]);
			size -= i[1];
			i[0] += i[1];
			lst->i += i[1];
			lst = lst->next;
		}
		lst->next = NULL;
	}
	else
	{
		lst->buf = ft_strncpy(&new->buf[lst->i], f->ox, size);
		lst->i += size;
	}
	lst->next = NULL;
	return (0);
}

int		ft_multibuf_arg(t_flag *f, t_list **begin_lst, size_t size)
{
	t_list	*lst;
	t_list	*new;
	size_t	i[2];

	*begin_lst = lst;
	if (begin_lst == NULL)
		return (-1);
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
	{
		i[1] = 4095 - lst->i;
		ft_strncpy(new->buf[lst->i], &f->arg[0], i[1]);
		i[0] += i[1];
		while (size != 0)
		{
			if (size > 4095)
				i[1] = 4095;
			else
				i[1] = size;
			if (!(new = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst->next = new;
			new->i = 0;
			ft_bzero(new->buf, 4095);
			new->buf = ft_strncpy(new->buf[lst->i], &f->arg[i[0]], i[1]);
			size -= i[1];
			i[0] += i[1];
			lst->i += i[1];
			lst = lst->next;
		}
		lst->next = NULL;
	}
	else
	{
		lst->buf = ft_strncpy(&new->buf[lst->i], f->arg, size);
		lst->i += size;
	}
	lst->next = NULL;
	return (0);
}

int		ft_multibuf_nchar(t_flag *f, t_list **begin_lst, int c, size_t size)
{
	t_list	*lst;
	t_list	*new;
	size_t	i;

	lst = *begin_lst;
	if (begin_lst == NULL)
		return (-1);
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
	{
		lst->next;
		i = 4095 - lst->i;
		lst->buf = ft_cpynchar(&lst->buf[lst->i], c, i);
		while (size != 0)
		{
			if (size > 4095)
				i = 4095;
			else
				i = size;
			if (!(new = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst->next = new;
			new->i = 0;
			ft_bzero(new->buf, 4096);
			new->buf = ft_cpynchar(&new->buf[new->i], c, i);
			new->i += i;
			size -= i;
			lst = lst->next;
		}
	}
	else
	{
		lst->buf = ft_cpynchar(&lst->buf[lst->i], f->arg, size);
		lst->i += size;
	}
	lst->next = NULL;
	return (0);
}

size_t		ft_booster(const char *format, size_t i, t_lst **begin_lst)
{
	size_t	ret;
	size_t	n;
	size_t	stock;
	t_list	*lst;


	lst = *begin_lst;
	n = 0;
	while (format[i + n] != '\0' && format[i + n] != '%')
		n++;
	while (lst->next)
		lst = lst->next;
	if ((lst->i + n) < 4095)
	{
		ft_strncpy(&lst->buf[lst->i], (char *)&format[i], n);
		lst->i += n;
	}
	else
	{
		size = 4095 - lst->i;
		ft_strncpy(&lst->buf[lst->i], (char *)&format[i], size);
		i += size;
		n -= size;
		while (n != 0)
		{
			if (n > 4095)
				size = 4095;
			else
				size = n;
			if (!(lst->next = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst = lst->next;
			lst->i = 0;
			ft_bzero(lst->buf, 4096);
			ft_strncpy(&lst->buf[lst->i], (char *)&format[i], size);
			lst->i += size;
			n -= size;
			i += size;
		}
	}
	lst->next = NULL;
	return (n);
}

char    *ft_cpynchar(char *dest, int c, size_t n)
{
        size_t i;

        i = 0;
        if (dest)
	{
		while (i < n)
		{
			dest[i] = c;
			i++;
		}
	}
	return (dest);
}