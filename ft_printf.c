#include "ft_printf.h"
#include <stdio.h>

static t_var	*init_g(t_var *g)
{
	g->zero = 0;
	g->space = 0;
	return (g);
}

static int		ft_forest_if(const char *format, va_list arg, int i, t_var *g)
{
	if (format[i] == 's')
		ft_string(format, arg, i, g);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_int(format, arg, i, g);
	else if (format[i] == 'p')
		ft_addr(format, arg, i, g);
	else if (format[i] == 'o' || format[i] == 'O')
		ft_octal(format, arg, i , g);
	else if (format[i] == 'u' || format[i] == 'U')
		ft_unsigned_int(format, arg, i, g);
	else if (format[i] == 'x')
		ft_hexa_min(format, arg, i, g);
	else if (format[i] == 'X')
		ft_hexa_max(format, arg, i , g);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		ft_ll(format, arg, i, g);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		ft_hh(format, arg, i, g);
	else if (format[i] == 'l')
		ft_long(format, arg, i, g);
	else if (format[i] == 'h')
		ft_short(format, arg, i, g);
	return (0);
}

static int		ft_check(const char *format, va_list arg)
{
	int		i;
	t_var	*g;

	i = 1;
	while (format[i])
	{
		while (format[i] == ' ')
			i++;
		if (format[i] == '0')
			g->zero = ft_gestion_zero(format, i);
		if (format[i] == '+' || format[i] == '-')
		{
			if (format[i] == '+')
				g->space = ft_gestion_plus(format, i);
			else
				g->space = ft_gestion_moins(format, i);
		}
		else
		{
			g = init_g(g);
			ft_forest_if(format, arg, i, g);
			return (i);
		}
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	char	*stop;
	int		end;
	va_list	arg;
	int		count;
	int		ret;
	int		i;

	end = 1;
	if (format == NULL)
		return (-1);
	count = ft_count_arg(format);
	va_start(arg, format);
	while (end == 1)
	{
		stop = NULL;
		stop = ft_strchr(format, '%');
		if (*format && *format != '%')
			ft_putstr_printf(format);
		format = stop;
		ret = 0;
		i = 0;
		if (stop != NULL)
		{
			ret = ft_check(format, arg);
			format = format + ret + 1;
			//if (ret == 0)
			//	return (-1);
		}
		else
			end = 0;
	}
	va_end(arg);
	return (0);
}

int	main()
{
	char *str;
	char *t;
	int i;

	i = 90;
	t = NULL;
	str = ft_strdup("maybe");
	ft_printf("%  d    halo, %     s boum ! % s whethasd\n", i, str, t);
	return (0);
}
