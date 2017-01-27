#include "ft_printf.h"

static void	ft_ld(char **str, char **format, va_list argptr, int i)
{
	long c;
	char *tmp;

	c = va_arg(argptr, long);
	tmp = ft_long_itoa((long int)c);
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	tmp = NULL;
}

static void	ft_lo(char **str, va_list argptr, int i)
{
	unsigned long	c;
	char			*tmp;

	c = va_arg(argptr, unsigned long);
	tmp = ft_ulong_itoa((unsigned long int)c);
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	tmp = NULL;
}
/*
static void ft_ln()
{

}
*/
int			ft_l(char **str, char **format, va_list argptr, int i)
{
	int	ret;

	ret = 1;
	if (*format[2] == 'l' || *format[2] == 'L')
		ret += ft_ll(str, argptr, i);
	else if (*format[2] == 'd' || *format[2] == 'D' ||
			 *format[2] == 'i' || *format[2] == 'I')
		ret += ft_ld(str, argptr, i);
	else if (*format[2] == 'o' || *format[2] == 'O' ||
			 *format[2] == 'u' || *format[2] == 'U' ||
			 *format[2] == 'x' || *format[2] == 'X')
		ret += ft_lo(str, argptr, i);
	else if (*format[2] == 'n' || *format[2] == 'N')
		ret += ft_ln(str, argptr, i);
	else
		return (-2);
	return (ret);
}
