#include "ft_printf.h"
#include <stdio.h>

static int	ft_first_forest_if(char **str, char **format, va_list argptr)
{
	int	ret;

	ret = 1;
	if (*format[1] == 'h' || *format[1] == 'H')
		ret += ft_h(str, format, argptr);
	else if (*format[1] == 'l' || *format[1] == 'L')
		ret += ft_l(str, format, argptr);
	else if (*format[1] == 'j' || *format[1] == 'J')
		ret += ft_j(str, format, argptr);
	else if (*format[1] == 't' || *format[1] == 'T')
		ret += ft_t(str, format, argptr);
	else if (*format[1] == 'z' || *format[1] == 'Z')
		ret += ft_z(str, argptr);
	else if (*format[1] == 'q' || *format[1] == 'Q')
		ret += ft_q(str, format, argptr);
	else if (*format[1] == 'd' || *format[1] == 'D' ||
		 *format[1] == 'i' || *format[1] == 'I')
		ret += ft_d(str, format, argptr);
	else if (*format[1] == 'o' || *format[1] == 'O' ||
		 *format[1] == 'u' || *format[1] == 'U' ||
		 *format[1] == 'x' || *format[1] == 'X')
		ret += ft_o(str, format, argptr);
        else if (*format[1] == 'n' || *format[1] == 'N')
		ret += ft_n(str, format, rgptr);
	else if (*format[1] == '%')
	{
		ft_putchar('%');
		ret += 1;
	}
	else
		return (-1);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	char	*stop;
	char	*str;
	va_list	argptr;
	int	count;
	int	ret;
	int	i;

	count = 0;
	if (format == NULL)
		return (-1);
	str = ft_strnew(1);
	count = ft_count(char *format);
	while (*format)
	{
		stop = ft_strchr(*format, '%');
		*stop = '\0';
		if (*format && *format != *stop)
			ft_strjoin(*str, *format);
		*str = *stop;
		ret = 0;
		if (*str == *stop)
		{
			ret = ft_forest_if(&str, &format, argptr, count);
			count--;
		}
		*str = '\0';
		i = 0;
		while (i < ret)
			*str++;
		stop = NULL;
	}
	return (0);
}
