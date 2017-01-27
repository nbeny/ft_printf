#include "ft_printf.h"

static void ft_hhd(char **str, va_list argptr, int i)
{
	signed char	c;
	char		*tmp;

	c = va_arg(argptr, signed char);
	tmp = ft_itoa((int)c);
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	tmp == NULL;
}

static void	ft_hho(char *str, va_list argptr, int i)
{
	unsigned char c;
	char		*tmp;

	c = va_arg(argptr, signed char);
	tmp = ft_itoa(c);
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	tmp = NULL;
}

static void ft_hhn(char *str, va_list argptr, int i)
{

}

int	      ft_hh(char **str, char ***format, va_list argptr, int i)
{
	int     ret;

	ret = 1;
	if (*format[3] == 'd' || *format[3] == 'D' ||
	    *format[3] == 'i' || *format[3] == 'I')
		ret += ft_hhd(str, format, argptr, i);
	else if (*format[3] == 'o' || *format[3] == 'O' ||
			 *format[3] == 'u' || *format[3] == 'U' ||
			 *format[3] == 'x' || *format[3] == 'X')
		ret += ft_hho(str, format, argptr, i);
	else if (*format[3] == 'n' || *format[3] == 'N')
		ret += ft_hhn(str, format, argptr, i);
	else
		return (-3);
	return (ret);
}

