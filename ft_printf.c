#include "ft_printf.h"
#include <stdio.h>

static int	ft_forest_if(const char *format, va_list arg, int i)
{
	if (format[i] == 's')
		ft_putstr((char *)va_arg(arg, char *));
	if (format[i] == 'd')
		ft_putnbr((int)va_arg(arg, int));
	return (0);
}

static int	ft_check(const char *format, va_list arg)
{
	int i;
	int zero;
	int space;

	i = 1;
	while (format[i])
	{
		while (format[i] == ' ')
			i++;
		if (format[i] == '0')
			zero = ft_gestion_zero(format, i);
		if (format[i] == '+')
			space = ft_gestion_plus(format, i);
		if (format[i] == '-')
			space = ft_gestion_moins(format, i);
		else
		{
			ft_forest_if(format, arg, i);
			return (i);
		}
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	char	*stop;
	int	end;
	va_list	arg;
	int	count;
	int	ret;
	int	i;

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
